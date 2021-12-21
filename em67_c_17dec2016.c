/*_____Euromap67 Robot Interface Tester_____________

 * 2021-12-21 ....................................................................  
 * The code is not finished. Project made only for learning purposes.
 *
 * USE AT YOUR OWN RISK. Electrical documentation for this project not included.
 * ...............................................................................
 *
 * last update: 29/01/2017 18:01
 * 
 * 
 * .
 * to do: 
 * to do: 
 * to do: 
 * to do: 
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <math.h> // round()
#include <linux/input.h> //touch?
#include "VG/openvg.h" //graphics
#include "VG/vgu.h"    //graphics
#include "fontinfo.h"  //graphics
#include "shapes.h"    //graphics
#include <wiringPi.h> //wiring pi
#include <mcp23017.h> //mcp23017 comunication
#include <time.h>// sleep
#include "em67_c_labels.h" //labels definitions
#include "em67_c_buttons.h" //button definitions
#include <pthread.h> //threading
#include <sys/types.h> // needed for pid
#include <unistd.h> // needed foor pid and gettimeofday(unix)
#include <sys/time.h> //timer
//_____________________________________________________18 INCLUDES ABOVE
#define MOUSEFILE "/dev/input/event0"
//_____________________________________________________________threading
PI_THREAD (myThread);

//___________________________________________________Function prototypes
void check_exit(void);
void check_stop_manual(void);
void check_all_estops(void);
void update_labels(void);
int manual(void);   //manual work loop
int automatic(void); // automatic work

//________________________________________________________some variables


int zegar=0; //                             timer for automatic function
int ttt3=0;
int ttt2=5; //       number of cycles elapsed before touchscreen is read
int ttt=50; //        timer of cycles already elapsed in manual function
int i=2; //   so called i
int j;


// _______________________________________________________buttons ON/OFF
char b1,b2,b3,b4,b5,b6,b7,b8,b9,b10,b11,b12,b13,b14,b15,b16,b50,b52,b60,b61,b62=0;
//______________________________________________________________________
char b51=1;//                    manual is now  ON (- GREEN when manual)

//______________________________________________________________________
char ej_have_moved=0;
char cp1_have_moved=0;
char cp2_have_moved=0;
char part_taken=0;
char full=0;//                                 --> automatic , ms=5 part
char full2=0;//                                 --> automatic, ms=4 part
char intermed=0;//                     if intermediate fubction was used
//______________________________________________E-Stop / Fence variables
char r_estop=0;
char imm_estop=0;
char imm_fence=0;
char mushroom=0;
char auto_on=0;

// _______________________________________________ GPIO pin  definitions     
const int startPin = 23; //     start /automatic
const int stopPin = 24; //      stop /manual
const int estopPin = 27; //     estop / mushroom
const int interruPin = 25; //   spare

//________________________________________________________touch handling
int fd;
struct input_event ie;
int x,y=0;
int xtemp, ytemp=0;
// _____________________________________rolex!!! / IMM cycle time var's
struct timeval start;
struct timeval end;
struct timeval total;

char elapsed;
char lastcyc1[25]={'-','-',':','-','-','.','-','-'};
char* lastcycptr1;
char lastcyc2[25]={'-','-',':','-','-','.','-','-'};
char* lastcycptr2;
//_________________________________________________________MAIN FUNCTION
int main() {
	b50=0;b52=0;b60=0;b61=0;b62=0;
	
	lastcycptr1=lastcyc1;//              pointer to time array (elapsed)
	lastcycptr2=lastcyc2 ;//           pointer totime array (last cycle)
	//______________________________________________START ANOTHER THREAD
	x= piThreadCreate (myThread);
	if (x !=0){
		printf("unable to run new thread");
		exit(0);}
	
	
	
	//________________________________________________________GPIO SETUP    
	wiringPiSetupGpio(); //      initialise using broadcom pin numbers
	pinMode(estopPin, INPUT); //   pin 22 as input
	pinMode(startPin, INPUT); //   pin 23 as input
	pinMode(stopPin, INPUT); //    pin 22 as input
	pinMode(interruPin, INPUT); // pin 22 as input
	//___________________________________________________________pullups
	pullUpDnControl(startPin, PUD_UP);
	pullUpDnControl(stopPin, PUD_UP);
	pullUpDnControl(estopPin, PUD_UP);
	pullUpDnControl(interruPin, PUD_DOWN);
		
	//__________________________________initialise MCP23017 communication
	mcp23017Setup(101, 0x20); // inputs  --101 is just random number of 1st in
	mcp23017Setup(201, 0x21); // outputs  -- 201 is just random number of 1st out
	
	//______________________________________________set MCP23017 pinmode
	
	for (i=0; i<16; i++){
		pinMode (101+i, INPUT);
		pinMode (201+i, OUTPUT);
		pullUpDnControl(100+i,PUD_UP);
	}
	//______________________________________________turn off all outputs
	for (i=0; i<16; i++){
		digitalWrite (201+i, 1);
	}	
		
	
	int width, height;
	
	init(&width, &height);					// Graphics initialization

// __________________________________________________________ INTRO ____	
	Start(width, height);					// Start the picture
	Background(0, 0, 22);					// Black background
	Fill(44, 77, 232, 1);					// 
	Circle(width / 6, 0, width);			// 
	Fill(255, 255, 255, 1);					// White text
	TextMid((width / 2)+20, (height / 2)-60, "          67", SerifTypeface, width / 6);	// Greetings 
	

	Fill(414, 17, 132, 1);					// 
	Circle(width / 9, 0, width);			//
	Fill(0xaF,0xFF,0x30, 1);					//  text colour
	TextMid((width / 2)-125, ((height / 2)-60), "EUROMAP", SerifTypeface, width / 10);	// Greetings 
	
	StrokeWidth(1);
	Stroke(0,0,0,1);
	
	End();
	
	for (i=1; i<3; i++){sleep(1);} //_______________show intro 2 seconds
	Background(0, 0, 22);
	StrokeWidth(10);
	Stroke(40,155,154,1);
	Line(0,235,1200,235);
	StrokeWidth(1);
	Stroke(0,0,0,1);

	
	// ______________________________________________reject, check boxes
	but_61_OFF();  // REJECT checkbox
	but_62_OFF();  // intermed po checkbox
	
	
	
	// ______________________________________________put lamps on screen
	lamp_1_OFF(); lamp_9_OFF();lamp_2_OFF(); lamp_3_OFF(); lamp_4_OFF(); lamp_6_OFF();
	lamp_7_OFF(); lamp_8_OFF(); lamp_12_OFF(); lamp_14_OFF();
	lamp_15_OFF(); lamp_16_OFF();
	
	//some labels
	lamp_90_ON();// "robot" label
	lamp_91_ON();
	
	
	// ____________________________________________________ reset estops
	// __________________________________________________and reset fence
	if ((digitalRead(101)==0)&&(digitalRead(109)==0)){ //if not r_estop
		r_estop=0; lamp_1_ON(); lamp_9_ON();
		}

	End(); // ______________________________________________show screen!
	//__________________________________________________go to the manual
	manual();
	return 0;
}

//######################################################################

int manual(){
	// put buttons on the screen
	// change middle line
	StrokeWidth(10); Stroke(40,155,154,1); Line(0,235,1200,235);
	//__fence__ok at start______________________________________________
	but_2_ON(); digitalWrite(202, 0);  digitalWrite(210, 0); 
	imm_fence=0; //______________________fence closed at start of manual
	//__________________________________________________________________
	but_3_OFF(); digitalWrite(203, 1);
	but_4_OFF(); digitalWrite(204, 1);
	but_5_OFF(); digitalWrite(205, 1);
	but_6_OFF(); digitalWrite(206, 1);
	but_7_OFF(); digitalWrite(207, 1);
	but_8_OFF(); digitalWrite(208, 1);
	but_12_OFF(); digitalWrite(212, 1);
	but_13_OFF(); digitalWrite(213, 1);
	but_14_OFF(); digitalWrite(214, 1);
	but_15_OFF(); digitalWrite(215, 1);
	but_16_OFF(); digitalWrite(216, 1);
	but_50_OFF();  //injection
	but_51_ON();   // green, automatic = off
	but_52();      // exit button
	
	hiderolex(); // timer not visible
	End();
	
	//############################ MANUAL LOOP #########################
	while(1){
		//_______________________________________________check estops
		// if mushroom is not pressed, and robot estop is not pressed
		// show estops okay
		if ((digitalRead(estopPin)==0)&&((digitalRead(101)==0)&&(digitalRead(109)==0))){
			sleep(0.001);
			if ((digitalRead(estopPin)==0)&&((digitalRead(101)==0)&&(digitalRead(109)==0))){
			imm_estop=0; but_1_ON(); lamp_1_ON(); lamp_9_ON(); b1=1;
			digitalWrite(201, 0);digitalWrite(209,0); //        relay on
			r_estop=0;	//                              restop=false
			mushroom=0;
			but_51_ON(); //u1000
			b51=1;       //u1001
			End(); 		//                                 Show me that!
			}
		}
		
		else { 
			imm_estop=1; but_1_OFF(); b1=0;
			digitalWrite(201, 1);digitalWrite(209,1);	 //    relay off
			End(); 										 //
			if (digitalRead(estopPin)==1){ mushroom=1;}
			if (digitalRead(101)==1) {r_estop=1; lamp_1_OFF();}
			if (digitalRead(109)==1) {r_estop=1; lamp_9_OFF();}
			
			if (digitalRead(estopPin)==0){ mushroom=0;}
			if (digitalRead(101)==0) {r_estop=0; lamp_1_ON();}
			if (digitalRead(109)==0) {r_estop=0; lamp_9_ON();}
		}
		
		
		
		//______________________________________________WANT AUTOMATIC ?
		if (digitalRead(23)==0){
			fd = open(MOUSEFILE, O_RDONLY);
			if ((r_estop==0)&&(imm_estop==0)&&(imm_fence==0)&&(mushroom==0)){
				sleep(0.001);
				if ((r_estop==0)&&(imm_estop==0)&&(imm_fence==0)&&(mushroom==0)){
				auto_on=1; //____________________________automatic is ON
				but_51_OFF();
				b51=0;	
				End();
				automatic(); //__________________________go to automatic
				}
			}
		}
	
		
		
		// OTHER BUTTONS_______________________________________________________
		// apply x and y each 20-th time and check up which button was pressed
	
		ttt--; //_________________________time since last button pressed
		if (ttt<1){
			ttt=1;
		}
		
		//______________________________________start auto touch button51
		if ( (ttt==1)&&(x>800)&&(x<1010) &&(y>5)&&(y<120) && (b51==1)){ 
			if ((r_estop==0)&&(imm_estop==0)&&(imm_fence==0)&&(mushroom==0)){
				auto_on=1; //____________________________automatic is ON
				but_51_OFF();	
				End();
				b51=0;
				ttt=ttt2;
				x=0;y=0;
				automatic(); //__________________________go to automatic
			}
		}

		
			//____________________________________ EXIT BUTTON__________
	
		if ((x>395)&&(x<505) &&(y>10)&&(y<60)){ 
			
			if ((b1==0)&&(b2==0)&&(b3==0)&&(b13==0)&&(b4==0)
			&&(b5==0)&&(b15==0)&&(b6==0)&&(b8==0)
			&&(b12==1)&&(b14==1)&&(b16==1)&&(b7==1)){
				close(fd);
				finish();
				End();
				exit(0);
			}
			else {
				system("shutdown -P now");
			}
		}
		//                                                         button 2
		
		if ( (ttt==1)&&(x>10)&&(x<110) &&(y>455)&&(y<520) && (b2==0)){ 
			but_2_ON();
			b2=1;
			imm_fence=0;
			digitalWrite(202, 0); digitalWrite(210, 0);
			ttt=ttt2;
			//sleep(0.1);
			End();
			x=0;y=0;
			
			}
		if((ttt==1)&&(x>10)&&(x<110) &&(y>460)&&(y<515) && (b2==1)){
			but_2_OFF();
			b2=0;
			imm_fence=1;
			digitalWrite(202, 1); digitalWrite(210, 1);
			ttt=ttt2;
			//sleep(0.1);
			End();
			x=0;y=0;
			}
			
		//                                                         button 3
		
		if ( (ttt==1)&&(x>135)&&(x<245) &&(y>385)&&(y<445) && (b3==0)){ 
			but_3_ON();
			b3=1;
			digitalWrite(203, 0);
			ttt=ttt2;
			//sleep(0.1);
			End();
			x=0;y=0;
			
			}
		if((ttt==1)&&(x>135)&&(x<245) &&(y>385)&&(y<445) && (b3==1)){
			but_3_OFF();
			b3=0;
			digitalWrite(203, 1);
			ttt=ttt2;
			//sleep(0.1);
			End();
			x=0;y=0;
			}
			
		//                                                         button 4
		
		if ( (ttt==1)&&(x>265)&&(x<375) &&(y>385)&&(y<445) && (b4==0)){ 
			but_4_ON();
			b4=1;
			digitalWrite(204, 0);
			ttt=ttt2;
			//sleep(0.1);
			End();
			x=0;y=0;
			
			}
		if((ttt==1)&&(x>265)&&(x<375) &&(y>385)&&(y<445) && (b4==1)){
			but_4_OFF();
			b4=0;
			digitalWrite(204, 1);
			ttt=ttt2;
			//sleep(0.1);
			End();
			x=0;y=0;
			}
		
		//                                                         button 5
		
		if ( (ttt==1)&&(x>655)&&(x<765) &&(y>385)&&(y<445) && (b5==0)){ 
			but_5_ON();
			b5=1;
			digitalWrite(205, 0);
			ttt=ttt2;
			//sleep(0.1);
			End();
			x=0;y=0;
			
			}
		if((ttt==1)&&(x>655)&&(x<765) &&(y>385)&&(y<445) && (b5==1)){
			but_5_OFF();
			b5=0;
			digitalWrite(205, 1);
			ttt=ttt2;
			//sleep(0.1);
			End();
			x=0;y=0;
			}
		//                                                         button 6
		
		if ( (ttt==1)&&(x>915)&&(x<1025) &&(y>385)&&(y<445) && (b6==0)){ 
			but_6_ON();
			b6=1;
			digitalWrite(206, 0);
			ttt=ttt2;
			//sleep(0.1);
			End();
			x=0;y=0;
			
			}
		if((ttt==1)&&(x>915)&&(x<1025) &&(y>385)&&(y<445) && (b6==1)){
			but_6_OFF();
			b6=0;
			digitalWrite(206, 1);
			ttt=ttt2;
			//sleep(0.1);
			End();
			x=0;y=0;
			}
			
		//                                                         button 7
		
		if ( (ttt==1)&&(x>915)&&(x<1025) &&(y>460)&&(y<520) && (b7==0)){ 
			but_7_ON();
			b7=1;
			digitalWrite(207, 0);
			ttt=ttt2;
			//sleep(0.1);
			End();
			x=0;y=0;
			
			}
		if((ttt==1)&&(x>915)&&(x<1025) &&(y>460)&&(y<520) && (b7==1)){
			but_7_OFF();
			b7=0;
			digitalWrite(207, 1);
			ttt=ttt2;
			//sleep(0.1);
			End();
			x=0;y=0;
			}
			
		//                                                         button 8
		
		if ( (ttt==1)&&(x>915)&&(x<1025) &&(y>535)&&(y<600) && (b8==0)){ 
			but_8_ON();
			b8=1;
			digitalWrite(208, 0);
			ttt=ttt2;
			//sleep(0.1);
			End();
			x=0;y=0;
			
			}
		if((ttt==1)&&(x>915)&&(x<1025) &&(y>535)&&(y<600) && (b8==1)){
			but_8_OFF();
			b8=0;
			digitalWrite(208, 1);
			ttt=ttt2;
			//sleep(0.1);
			End();
			x=0;y=0;
			}
			
		//                                                        button 12
		
		if ( (ttt==1)&&(x>655)&&(x<765) &&(y>460)&&(y<520) && (b12==0)){ 
			but_12_ON();
			b12=1;
			digitalWrite(212, 0);
			ttt=ttt2;
			//sleep(0.1);
			End();
			x=0;y=0;
			
			}
		if((ttt==1)&&(x>655)&&(x<765) &&(y>460)&&(y<520) && (b12==1)){
			but_12_OFF();
			b12=0;
			digitalWrite(212, 1);
			ttt=ttt2;
			//sleep(0.1);
			End();
			x=0;y=0;
			}
			
		//                                                        button 13
		
		if ((ttt==1)&&(x>525)&&(x<645)&&(y>385)&&(y<445)&&(b13==0)){ 
			but_13_ON();
			b13=1;
			digitalWrite(213, 0);
			ttt=ttt2;
			//sleep(0.1);
			End();
			x=0;y=0;
			
			}
		if((ttt==1)&&(x>525)&&(x<645)&&(y>385)&&(y<445)&&(b13==1)){
			but_13_OFF();
			b13=0;
			digitalWrite(213, 1);
			ttt=ttt2;
			//sleep(0.1);
			End();
			x=0;y=0;
			}
			
		//                                                        button 14
		
		if ( (ttt==1)&&(x>785)&&(x<905) &&(y>385)&&(y<445) && (b14==0)){ 
			but_14_ON();
			b14=1;
			digitalWrite(214, 0);
			ttt=ttt2;
			//sleep(0.1);
			End();
			x=0;y=0;
			
			}
		if((ttt==1)&&(x>785)&&(x<905) &&(y>385)&&(y<445) && (b14==1)){
			but_14_OFF();
			b14=0;
			digitalWrite(214, 1);
			ttt=ttt2;
			//sleep(0.1);
			End();
			x=0;y=0;
			}
		
		//                                                        button 15
		
		if ( (ttt==1)&&(x>785)&&(x<905) &&(y>460)&&(y<520) && (b15==0)){ 
			but_15_ON();
			b15=1;
			digitalWrite(215, 0);
			ttt=ttt2;
			//sleep(0.1);
			End();
			x=0;y=0;
			
			}
		if((ttt==1)&&(x>785)&&(x<905) &&(y>460)&&(y<520) && (b15==1)){
			but_15_OFF();
			b15=0;
			digitalWrite(215, 1);
			ttt=ttt2;
			//sleep(0.1);
			End();
			x=0;y=0;
			}
			
		//                                                        button 16
		
		if ( (ttt==1)&&(x>785)&&(x<905) &&(y>535)&&(y<600) && (b16==0)){ 
			but_16_ON();
			b16=1;
			digitalWrite(216, 0);
			ttt=ttt2;
			//sleep(0.1);
			End();
			x=0;y=0;
			
			}
		if((ttt==1)&&(x>785)&&(x<905) &&(y>535)&&(y<600) && (b16==1)){
			but_16_OFF();
			b16=0;
			digitalWrite(216, 1);
			ttt=ttt2;
			//sleep(0.1);
			End();
			x=0;y=0;
			}
			
		//                                        button 61 REJECT CHECKBOX
		
		if ( (ttt==1)&&(x>530)&&(x<640) &&(y>540)&&(y<600) && (b61==0)){ 
			but_61_ON();
			b61=1;
			ttt=ttt2;
			sleep(0.9);sleep(0.9);sleep(0.9);
			End();
			x=0;y=0;
			
			}
		if((ttt==1)&&(x>530)&&(x<640) &&(y>540)&&(y<600) && (b61==1)){
			but_61_OFF();
			b61=0;
			ttt=ttt2;
			sleep(0.9);sleep(0.9);sleep(0.9);
			End();
			x=0;y=0;
			}
			
		//                             button 62 intermed position CHECKBOX
		
		if ( (ttt==1)&&(x>660)&&(x<760) &&(y>540)&&(y<600) && (b62==0)){ 
			but_62_ON();
			b62=1;
			ttt=ttt2;
			sleep(0.9);sleep(0.9);sleep(0.9);
			End();
			x=0;y=0;
			
			}
		if((ttt==1)&&(x>660)&&(x<760) &&(y>540)&&(y<600) && (b62==1)){
			but_62_OFF();
			b62=0;
			ttt=ttt2;
			sleep(0.9);sleep(0.9);sleep(0.9);
			End();
			x=0;y=0;
			}
		// ________________________________Inputs from robot____________
		
		// _______________________________________lamp 2 mould area free
		if (digitalRead(102)==0){
			sleep(0.001);if (digitalRead(102)==0){lamp_2_ON();}
		}
			else {lamp_2_OFF();}	
		//__________________________________________lamp 3 oper with IMM
		if (digitalRead(103)==0){
			sleep(0.001);if (digitalRead(103)==0){lamp_3_ON();}
		}
			else {lamp_3_OFF();}
		//___________________________________lamp 4 enable mould closure
		if (digitalRead(104)==0){
			sleep(0.001);if (digitalRead(104)==0){lamp_4_ON();}
		}
			else {lamp_4_OFF();}
		//____________________________________________lamp 6 ejetors fwd
		if (digitalRead(106)==0){
			sleep(0.001);if (digitalRead(106)==0){lamp_6_ON();}
			}
			else {lamp_6_OFF();}
		//__________________________________lamp 7 core pull 1 fwd pos 2
		if (digitalRead(107)==0){
			sleep(0.001);if (digitalRead(107)==0){lamp_7_ON();}
		}
			else {lamp_7_OFF();}
		//___________________________________lamp 8 core pul 2 fwd pos 2
		if (digitalRead(108)==0){
			sleep(0.001);if (digitalRead(108)==0){lamp_8_ON();}
		}
			else {lamp_8_OFF();}
			
		//_______________________________________lamp 12 mould full open
		if (digitalRead(112)==0){
			sleep(0.001);if (digitalRead(112)==0){lamp_12_ON();}
		}
			else {lamp_12_OFF();} 
		//_____________________________________________lamp 14 eject bwd
		if (digitalRead(114)==0){
			sleep(0.001);if (digitalRead(114)==0){lamp_14_ON();}
		}
			else {lamp_14_OFF();}
		//_________________________________lamp 15 core pull 1 pos 1 bwd
		if (digitalRead(115)==0){
			sleep(0.001);if (digitalRead(115)==0){lamp_15_ON();}
		}
			else {lamp_15_OFF();}
		//_________________________________lamp 16 core pull 2 pos 1 bwd
		if (digitalRead(116)==0){
			sleep(0.001);if (digitalRead(116)==0){lamp_16_ON();}
		}
			else {lamp_16_OFF();}

			
	}
	
	
	End();						   			// __________End the picture
	finish();					            // _________Graphics cleanup
	close(fd);
	exit(0);//_____________________________________________bye bye !
		
}

//############################## AUTOMATIC #############################

int automatic(){
	char ms; //machine state 0,1,2,3,4,5,6,7
	
	ms=0;
	//____________________________________________________reset ejectors
	ej_have_moved=0;
	cp1_have_moved=0;
	cp2_have_moved=0;
	part_taken=0;
	
	// start conting time! (first initialization of time)
	gettimeofday(&start, NULL);
	
	// ____________________________________________________reset buttons
	but_3_ON(); digitalWrite(203, 1); //     enable operation with ROBOT
	but_4_OFF(); digitalWrite(204, 1); //        mould is not closed yet
	but_5_OFF(); digitalWrite(205, 1);//                        not open
	but_6_OFF(); digitalWrite(206, 1);//                      ej not fwd
	but_7_OFF(); digitalWrite(207, 1);//                   cp1 not pos 2
	but_8_OFF(); digitalWrite(208, 1);//                   cp2 not pos 2
	but_12_OFF(); digitalWrite(212, 1);//                     not reject
	but_13_OFF(); digitalWrite(213, 1);//              not at interm pos
	but_50_OFF();  //not injection
	
	//################################   INFINITE LOOP (Automatic work)
	
	while(1){ 
		ttt3++;if(ttt3>100){ttt3=0;}
		zegar++; if(zegar>1000000){zegar=1000000;}
		//                        do not check if exit , go manual, exit
		check_stop_manual();
		check_all_estops();
		update_labels();
		End();
		
		if(ttt3>1){
			ttt3=0;
			gettimeofday(&end, NULL);
			timersub(&end, &start, &total);
			
			sprintf(lastcycptr1, "%ld:%ld.%.02ld", (total.tv_sec/60), 
			(total.tv_sec % 60), ((total.tv_usec*10)/100000));
			
			rolex(lastcycptr1,lastcycptr2);
		}
		
		//_______________________________________________________startup
		if(ms==0){ 
			//line pos 1
			StrokeWidth(10);
			Stroke(20,75,75,1);Line(0,235,1200,235);
			Stroke(0xFF,0xFF,0x00,1);Line(0,235,120,235);
			//___________________________________________
			zegar=0; ttt=50;
			but_13_OFF(); digitalWrite(213, 1);//             reject off
			but_14_ON();digitalWrite(214,0);//  ejectors bwd as standard
			//but_15_OFF();digitalWrite(215,1);//     cp1 NULL as standard
			//but_16_OFF();digitalWrite(216,1);//     cp2 NULL as standard
			
			// work with robot enabled
			if (digitalRead(103)==1){digitalWrite(203,0);but_3_ON();End();ms=1;}
			else {digitalWrite(203,1);but_3_OFF();End();}
			zegar=0;
		}
		//__________ _______________________________________close mould?
		if((ms==1)&&(zegar>10)){ 
			//line pos 2
			StrokeWidth(10);
			Stroke(20,75,75,1);Line(0,235,1200,235);
			Stroke(0xFF,0xFF,0x00,1);Line(130,235,250,235);
			//___________________________________________
			if((digitalRead(102)==0)&&(digitalRead(103)==1) 
			&&(digitalRead(104)==0)&&(digitalRead(106)==1)
			&&(digitalRead(107)==1)&&(digitalRead(108)==1)
			&&(digitalRead(112)==1)&&(zegar>10)){
			
			but_5_OFF(); digitalWrite(205, 1); //               not open
			but_12_OFF(); digitalWrite(212, 1);//      not intermed open
			End();ms=2;zegar=0;
			
			// ___________________________start counting time
			gettimeofday(&end, NULL);
			timersub(&end, &start, &total);
			
			sprintf(lastcycptr2, "%ld:%ld.%.02ld", (total.tv_sec/60), 
			(total.tv_sec % 60), ((total.tv_usec*10)/100000));
			rolex(lastcycptr1,lastcycptr2);
			
			gettimeofday(&start, NULL);//new cycle starts at this moment
			}
			zegar=0;
		}
		
		// _____________________________one moment sir, the -------------mould is closing 
		if((ms==2)&&(zegar>50)){
			//line pos 3
			StrokeWidth(10);
			Stroke(20,75,75,1);Line(0,235,1200,235);
			Stroke(0xFF,0xFF,0x00,1);Line(260,235,380,235);
			//__________________________________________________________
			if ((zegar>30)&&(digitalRead(102)==0)&&(digitalRead(104)==0)&&(digitalRead(112)==1)){
				digitalWrite(204,0);but_4_ON(); //mould closed
			zegar=0;ms=3;
			}
			End();
			
		}
		//_________________________________________________ do injection 
		if(ms==3){
			//line pos 4
			StrokeWidth(10);
			Stroke(20,75,75,1);Line(0,235,1200,235);
			Stroke(0xFF,0xFF,0x00,1);Line(390,235,510,235);
			//__________________________________________________________
			if (zegar==10){but_50_ON();End();}
			if (zegar==20){but_50_OFF();End();}
			if (zegar==30){but_50_ON();End();}
			if (zegar==40){but_50_OFF();End();}
			if (zegar==54){but_50_ON();End();}
			if (zegar==70){but_50_OFF();End();}
			if (zegar==75){but_50_ON();End();}
			if (zegar==90){but_50_OFF();End();}
			if (zegar==105){but_50_ON();End();}
			if (zegar==120){but_50_OFF();End();ms=4;zegar=0;}
			//if (zegar==275){but_50_ON();End();}
			//if (zegar==300){but_50_OFF();End();}
			//if (zegar==325){but_50_ON();End();}
			//if (zegar==350){but_50_OFF();End();}
			//if (zegar==375){but_50_ON();End();}
			//if (zegar==400){but_50_OFF();End();ms=4;zegar=0;}
			End();
		
		}
		
		//______________________________________intermediate position???
		if(ms==4){
			//line pos 6
			StrokeWidth(10);
			Stroke(20,75,75,1);Line(0,235,1200,235);
			Stroke(0xFF,0xFF,0x00,1);Line(520,235,770,235);
			//__________________________________________________________ 
			
			
			but_4_OFF(); digitalWrite(204,1); //    mould not closed now
			End();
			
			// fully open
			if(b62==0){
				ms=5;
			} 
			// intermed
			else {
				if((zegar>20)&&(digitalRead(102)==0)&&(full2==0)){
					but_5_OFF(); digitalWrite(205, 1);
					but_12_ON(); digitalWrite(212, 0); //  slightly open
					intermed=1;full2=1;
				}
				if ((zegar>30)&&(full2==1)){
					if(b61==1){but_13_ON(); digitalWrite(213, 0);} //reject on
					else{but_13_OFF(); digitalWrite(213, 1);}      //reject off
					ms=6; zegar=0; full2=0;
				}
				
					
			}
			
			End();
		}	
		//__________________________________________________________OPEN
		if(ms==5){
			printf("ms=05, b61= %d", b61);
			//line pos 6
			StrokeWidth(10);
			Stroke(20,75,75,1);Line(0,235,1200,235);
			Stroke(0xFF,0xFF,0x00,1);Line(520,235,770,235);
			//___________________________________________
			if((zegar>20)&&(digitalRead(102)==0)&&(full==0)){
				but_5_ON(); digitalWrite(205, 0); // and fully open
				but_12_OFF(); digitalWrite(212, 1);
				full=1;
			}
			if ((zegar>30)&&(full==1)){
				if(b61==1){but_13_ON(); digitalWrite(213, 0);} //reject on
				else{but_13_OFF(); digitalWrite(213, 1);}      //reject off
				ms=6; zegar=0; full=0;
			}
			intermed=0;
			End();
		}	
		
		//____________________________ejectors / core pullers procedure
		if((ms==6)&&(digitalRead(102)==1)&&(digitalRead(104)==1)){
			//line pos 7,8
			StrokeWidth(10);
			Stroke(20,75,75,1);Line(0,235,1200,235);
			Stroke(0xFF,0xFF,0x00,1);Line(780,235,1200,235);
			//___________________________________________
			
			
			// extend
			if((digitalRead(106)==0)&&(digitalRead(114)==1)&&(ej_have_moved==0)){
				ej_have_moved=1;part_taken=1;
				but_6_ON();digitalWrite(206,0);
				but_14_OFF();digitalWrite(214,1);
			}
			if((digitalRead(107)==0)&&(digitalRead(115)==1)&&(cp1_have_moved==0)){
				cp1_have_moved=1;part_taken=1;
				but_7_ON();digitalWrite(207,0);
				but_15_OFF();digitalWrite(215,1);
			}
			if((digitalRead(108)==0)&&(digitalRead(116)==1)&&(cp2_have_moved==0)){
				cp2_have_moved=1;part_taken=1;
				but_8_ON();digitalWrite(208,0);
				but_16_OFF();digitalWrite(216,1);
			}
			// Retract
			if((digitalRead(106)==1)&&(digitalRead(114)==0)&&(ej_have_moved==1)){
				ej_have_moved=0;
				but_6_OFF();digitalWrite(206,1);
				but_14_ON();digitalWrite(214,0);
			}
			if((digitalRead(107)==1)&&(digitalRead(115)==0)&&(cp1_have_moved==1)){
				cp1_have_moved=0;
				but_7_OFF();digitalWrite(207,1);
				but_15_ON();digitalWrite(215,0);
			}
			if((digitalRead(108)==1)&&(digitalRead(116)==0)&&(cp2_have_moved==1)){
				cp2_have_moved=0;
				but_8_OFF();digitalWrite(208,1);
				but_16_ON();digitalWrite(216,0);
			}
			
			//_____________________________all retracted and part taken?
			if((part_taken==1)&&(ej_have_moved==0)
			&&(cp1_have_moved==0)&&(cp2_have_moved==0)){
				;
			part_taken=0; //                              ejectors  done 
			ms=7; zegar=0; End();
			}
		}
			End();
			
		//_____________________________ only when intermed position used
		if (ms==7){
			if((zegar>25)&&(intermed==1)&&(digitalRead(102)==1)&&(digitalRead(104)==1)&&(digitalRead(112)==0)){
				but_5_ON(); digitalWrite(205, 0); //      and fully open
				but_12_OFF(); digitalWrite(212, 1);
				ms=0;intermed=0;zegar=0;
			}	
			if(intermed==0){
				ms=0;zegar=0;
				}
		}
			
			
		
		
		
		ttt--; //_________________________time since last button pressed
		if (ttt<1){
			ttt=1;
		}
			//                                    but 61 REJECT CHECKBOX
		
		if ( (ttt==1)&&(x>530)&&(x<640) &&(y>540)&&(y<600) && (b61==0)){ 
			but_61_ON();
			b61=1;
			ttt=ttt2;
			End();
			x=0;y=0;
			
			}
		if((ttt==1)&&(x>530)&&(x<640) &&(y>540)&&(y<600) && (b61==1)){
			but_61_OFF();
			b61=0;
			ttt=ttt2;
			End();
			x=0;y=0;
			}
			
		//                             but 62 intermed position CHECKBOX
		
		if ( (ttt==1)&&(x>660)&&(x<760) &&(y>540)&&(y<600) && (b62==0)){ 
			but_62_ON();
			b62=1;
			ttt=ttt2;
			End();
			x=0;y=0;
			
			}
		if((ttt==1)&&(x>660)&&(x<760) &&(y>540)&&(y<600) && (b62==1)){
			but_62_OFF();
			b62=0;
			ttt=ttt2;	
			End();
			x=0;y=0;
			}
			
			
		
	}	
	return 0;
	}



void check_exit(){
	// accesible only from automatic() !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	if ((x>395)&&(x<505) &&(y>10)&&(y<60)){ 
			close(fd);
			finish();
			End();
			exit(0);
			
			}
	return;
	}
void check_stop_manual(){
	// accesible only from automatic() !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//__________________________________________________STOP/ MANUAL
		if ((digitalRead(24)==0)&&(b51==0)){
			sleep(0.01);
			if ((digitalRead(24)==0)&&(b51==0)){
			auto_on=0; //automatic is now off
			but_51_ON();//going green	
			b51=1;//is on
			End();
			manual();
		}
		} 
		
		//______________________________________star auto touch button51
		if ( (x>800)&&(x<1010) &&(y>5)&&(y<120) && (b51==0)){ 
			auto_on=0; //                           automatic is now off
			but_51_ON();//                                   going green					
			b51=1;//                                               is on
			x=0;y=0;
			End();
			manual(); 

		}
	return;
	}
void check_all_estops(){
	// accesible only from automatic() !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	
	if ((digitalRead(estopPin)==1)||((digitalRead(101)==1)||(digitalRead(109)==1))){
		sleep(0.001);
		if ((digitalRead(estopPin)==1)||((digitalRead(101)==1)||(digitalRead(109)==1))){
			
			imm_estop=1; but_1_OFF(); b1=0;
			digitalWrite(201, 1);digitalWrite(209,1); //       relay off
			End(); //                                      Show me that!
			if (digitalRead(estopPin)==1){ mushroom=1;}
			if (digitalRead(101)==1) {r_estop=1; lamp_1_OFF();}
			if (digitalRead(109)==1) {r_estop=1; lamp_9_OFF();}
			
			if (digitalRead(estopPin)==0){ mushroom=0;}
			if (digitalRead(101)==0) {r_estop=0; lamp_1_ON();}
			if (digitalRead(109)==0) {r_estop=0; lamp_9_ON();}
			auto_on=0;
			End();
			manual();
		}
	}
	return;
	}
void update_labels(){
		// ________________________________Inputs from robot____________
		
		// _______________________________________lamp 2 mould area free
		if (digitalRead(102)==0){
			sleep(0.001);if (digitalRead(102)==0){lamp_2_ON();}
		}
			else {lamp_2_OFF();}	
		//__________________________________________lamp 3 oper with IMM
		if (digitalRead(103)==0){
			sleep(0.001);if (digitalRead(103)==0){lamp_3_ON();}
		}
			else {lamp_3_OFF();}
		//___________________________________lamp 4 enable mould closure
		if (digitalRead(104)==0){
			sleep(0.001);if (digitalRead(104)==0){lamp_4_ON();}
		}
			else {lamp_4_OFF();}
		//____________________________________________lamp 6 ejetors fwd
		if (digitalRead(106)==0){
			sleep(0.001);if (digitalRead(106)==0){lamp_6_ON();}
			}
			else {lamp_6_OFF();}
		//__________________________________lamp 7 core pull 1 fwd pos 2
		if (digitalRead(107)==0){
			sleep(0.001);if (digitalRead(107)==0){lamp_7_ON();}
		}
			else {lamp_7_OFF();}
		//___________________________________lamp 8 core pul 2 fwd pos 2
		if (digitalRead(108)==0){
			sleep(0.001);if (digitalRead(108)==0){lamp_8_ON();}
		}
			else {lamp_8_OFF();}
			
		//_______________________________________lamp 12 mould full open
		if (digitalRead(112)==0){
			sleep(0.001);if (digitalRead(112)==0){lamp_12_ON();}
		}
			else {lamp_12_OFF();} 
		//_____________________________________________lamp 14 eject bwd
		if (digitalRead(114)==0){
			sleep(0.001);if (digitalRead(114)==0){lamp_14_ON();}
		}
			else {lamp_14_OFF();}
		//_________________________________lamp 15 core pull 1 pos 1 bwd
		if (digitalRead(115)==0){
			sleep(0.001);if (digitalRead(115)==0){lamp_15_ON();}
		}
			else {lamp_15_OFF();}
		//_________________________________lamp 16 core pull 2 pos 1 bwd
		if (digitalRead(116)==0){
			sleep(0.001);if (digitalRead(116)==0){lamp_16_ON();}
		}
			else {lamp_16_OFF();}

}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  PI-THREAD
PI_THREAD (myThread) // _____________________________________touchscreen 
{
	if((fd = open(MOUSEFILE, O_RDONLY)) < 0) {
			printf("not enough cable ties....\n and touchscreen is probably on different port (event x) than expected");
			exit (77);}			
	int*ptr;
//_________________________________________________________infinite loop			
	while(1){ 
		
		read(fd, &ie, sizeof(struct input_event));
		ptr = (int*)&ie;
		
		if (ptr[2]==21626881){
			if (ptr[3]==1){
				read(fd, &ie, sizeof(struct input_event));
				if (ptr[2]==3) {
					x=ptr[3];
				}
				read(fd, &ie, sizeof(struct input_event));
				if (ptr[2]==65539) {
					y=ptr[3];
				}
			}
			
		}
		

	
	}
close(fd);
}



