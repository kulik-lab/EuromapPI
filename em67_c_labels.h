// 	________________________________________________________	LAMP 1
void lamp_1_OFF(void);// 1 .
void lamp_1_ON(void);
void lamp_2_OFF(void);// 2
void lamp_2_ON(void);
void lamp_3_OFF(void);// 3
void lamp_3_ON(void);
void lamp_4_OFF(void);// 4
void lamp_4_ON(void);
void lamp_6_OFF(void);// 6
void lamp_6_ON(void);
void lamp_7_OFF(void);// 7
void lamp_7_ON(void);
void lamp_8_OFF(void);// 8
void lamp_8_ON(void);
void lamp_9_OFF(void);// 9
void lamp_9_ON(void);
void lamp_12_OFF(void);// 12
void lamp_12_ON(void);
void lamp_14_OFF(void);// 14
void lamp_14_ON(void);
void lamp_15_OFF(void);// 15
void lamp_15_ON(void);
void lamp_16_OFF(void);// 16
void lamp_16_ON(void);
void lamp_50_OFF(void);// 50
void lamp_50_ON(void);
void rollex(char*, char*); // IMM cycle time
void hiderollex(); //hide IMM cycle time
void lamp_90_ON(void);// "robot" label
void lamp_91_ON(void);// "moulding machine" label

void lamp_90_ON(void){
	int xx=398; int yy=325;
	Fill(0x20,0x28,0x4a, 1);//	52, 52, 22, 1	          // OFF / FALSE / 0
	StrokeWidth(1);
	Stroke(52,52,22,1);
	Rect(0,245, 1200,230);
	Fill(190, 108, 255, 1);	
	Text(xx, yy+50,"  ROBOT ", SansTypeface, 35);
	
	return;
}

void lamp_91_ON(void){
	int xx=390; int yy=0;
	Fill(22, 22, 22, 1);					            // OFF / FALSE / 0
	StrokeWidth(1);
	Stroke(22,22,22,1);
	Fill(190, 108, 255, 1);	
	Text(xx, yy+110,"    MOULDING  ", SansTypeface, 22);
	Text(xx, yy+80,"     MACHINE ", SansTypeface, 22);
	
	return;
}


//______________________ROLLEX__________________________________________
void rolex(char*ti1, char*ti2){
	
	int xx=0; int yy=500;
	Fill(22, 22, 22, 1);					            // OFF / FALSE / 0
	StrokeWidth(1);
	Stroke(22,22,22,1);
	Roundrect(xx,yy, 250,100,20,20);
	Fill(170, 88, 255, 1);	
	Text(xx, yy+5, ti1, SansTypeface, 26);
	Fill(170, 188, 255, 1);
	Text(xx, yy+50, ti2, SansTypeface, 42);
	return;
}

void hiderolex(){
	
	int xx=0; int yy=500;
	Fill(22, 22, 22, 1);					            // OFF / FALSE / 0
	StrokeWidth(1);
	Stroke(22,22,22,1);
	Roundrect(xx,yy, 250,100,20,20);
	Fill(170, 88, 255, 1);	
	Text(xx, yy+50,"   manual / ", SansTypeface, 22);
	Fill(170, 88, 255, 1);
	Text(xx, yy+5, "   testing ", SansTypeface, 22);
	return;
}
//_____________________________________________________________estop ch1

void lamp_1_OFF(void){
	int xx=0; int yy=400;
	Fill(255, 0, 0, 1);					            // OFF / FALSE / 0
	StrokeWidth(3);
	Stroke(20,80,80,1);
	Roundrect(xx,yy, 120,70,20,20);
	Fill(0, 0, 0, 1);	
	Text(xx, yy+45, "    ROBOT", SansTypeface, 14);
	Text(xx, yy+25, "    E-STOP", SansTypeface, 14);
	Text(xx, yy+5, "      CH 1 ", SansTypeface, 14);
	return;
}

void lamp_1_ON(void){
	int xx=0; int yy=400;
	Fill(0, 255, 0, 1);					             // ON / TRUE / 1
	StrokeWidth(3);
	Stroke(20,80,80,1);
	Roundrect(xx,yy, 120,70,20,20);
	Fill(0, 0, 0, 1);	
	Text(xx, yy+45, "    ROBOT", SansTypeface, 14);
	Text(xx, yy+25, "    E-STOP", SansTypeface, 14);
	Text(xx, yy+5, "      CH 1 ", SansTypeface, 14);
	return;
}

//_____________________________________________________mould areea free

void lamp_2_OFF(void){
	int xx=260; int yy=400;
	Fill(255, 0, 0, 1);					            // OFF / FALSE / 0
	StrokeWidth(3);
	Stroke(20,80,80,1);
	Roundrect(xx,yy, 120,70,20,20);
	Fill(0, 0, 0, 1);	
	Text(xx-2, yy+45, "     MOULD", SansTypeface, 14);
	Text(xx+10, yy+25, "    AREA", SansTypeface, 14);
	Text(xx+5, yy+5, "     FREE", SansTypeface, 14);
	return;
}

void lamp_2_ON(void){
	int xx=260; int yy=400;
	Fill(0, 255, 0, 1);					             // ON / TRUE / 1
	StrokeWidth(3);
	Stroke(20,80,80,1);
	Roundrect(xx,yy, 120,70,20,20);
	Fill(0, 0, 0, 1);	
	Text(xx-2, yy+45, "     MOULD", SansTypeface, 14);
	Text(xx+10, yy+25, "    AREA", SansTypeface, 14);
	Text(xx+5, yy+5, "     FREE", SansTypeface, 14);
	return;
}

//____________________________________________________operation with IMM

void lamp_3_OFF(void){
	int xx=130; int yy=400;
	Fill(255, 0, 0, 1);					            // OFF / FALSE / 0
	StrokeWidth(3);
	Stroke(20,80,80,1);
	Roundrect(xx,yy, 120,70,20,20);
	Fill(0, 0, 0, 1);	
	Text(xx, yy+45, " OPERATION", SansTypeface, 14);
	Text(xx, yy+25, "     WITH", SansTypeface, 14);
	Text(xx, yy+5, "      IMM", SansTypeface, 14);
	return;
}

void lamp_3_ON(void){
	int xx=130; int yy=400;
	Fill(0, 255, 0, 1);					             // ON / TRUE / 1
	StrokeWidth(3);
	Stroke(20,80,80,1);
	Roundrect(xx,yy, 120,70,20,20);
	Fill(0, 0, 0, 1);	
	Text(xx, yy+45, " OPERATION", SansTypeface, 14);
	Text(xx, yy+25, "      WITH", SansTypeface, 14);
	Text(xx, yy+5, "       IMM", SansTypeface, 14);
	return;
}

//__________________________________________________enable mould closure

void lamp_4_OFF(void){
	int xx=260; int yy=325;
	Fill(255, 0, 0, 1);					            // OFF / FALSE / 0
	StrokeWidth(3);
	Stroke(20,80,80,1);
	Roundrect(xx,yy, 120,70,20,20);
	Fill(0, 0, 0, 1);	
	Text(xx+4, yy+45, "   ENABLE", SansTypeface, 14);
	Text(xx, yy+25, "    MOULD", SansTypeface, 14);
	Text(xx+2, yy+5, "    CLOSE", SansTypeface, 14);
	return;
}

void lamp_4_ON(void){
	int xx=260; int yy=325;
	Fill(0, 255, 0, 1);					             // ON / TRUE / 1
	
	StrokeWidth(3);
	Stroke(20,80,80,1);
	Roundrect(xx,yy, 120,70,20,20);
	Fill(0, 0, 0, 1);	
	Text(xx+4, yy+45, "   ENABLE", SansTypeface, 14);
	Text(xx, yy+25, "    MOULD", SansTypeface, 14);
	Text(xx+2, yy+5, "    CLOSE", SansTypeface, 14);
	return;
}


//__________________________________________________enable eject FWD

void lamp_6_OFF(void){
	int xx=910; int yy=400;
	Fill(255, 0, 0, 1);					            // OFF / FALSE / 0
	
	StrokeWidth(3);
	Stroke(20,80,80,1);
	Roundrect(xx,yy, 120,70,20,20);
	Fill(0, 0, 0, 1);	
	Text(xx+4, yy+45, "   ENABLE", SansTypeface, 14);
	Text(xx+5, yy+25, " EJECTORS", SansTypeface, 14);
	Text(xx+7, yy+5, "     FWD", SansTypeface, 14);
	return;
}

void lamp_6_ON(void){
	int xx=910; int yy=400;
	Fill(0, 255, 0, 1);					             // ON / TRUE / 1
	
	StrokeWidth(3);
	Stroke(20,80,80,1);
	Roundrect(xx,yy, 120,70,20,20);
	Fill(0, 0, 0, 1);	
	Text(xx+4, yy+45, "   ENABLE", SansTypeface, 14);
	Text(xx+5, yy+25, " EJECTORS", SansTypeface, 14);
	Text(xx+7, yy+5, "     FWD", SansTypeface, 14);
	return;
}

//______________________________________________core pullers 1 FWD

void lamp_7_OFF(void){
	int xx=910; int yy=325;
	Fill(255, 0, 0, 1);					            // OFF / FALSE / 0
	
	StrokeWidth(3);
	Stroke(20,80,80,1);
	Roundrect(xx,yy, 120,70,20,20);
	Fill(0, 0, 0, 1);	
	Text(xx+4, yy+45, "   ENABLE", SansTypeface, 14);
	Text(xx+5, yy+25, "core pullers I", SansTypeface, 12);
	Text(xx+7, yy+5, "     pos 2", SansTypeface, 14);
	return;
}

void lamp_7_ON(void){
	int xx=910; int yy=325;
	Fill(0, 255, 0, 1);					             // ON / TRUE / 1

	StrokeWidth(3);
	Stroke(20,80,80,1);
	Roundrect(xx,yy, 120,70,20,20);
	Fill(0, 0, 0, 1);	
	Text(xx+4, yy+45, "   ENABLE", SansTypeface, 14);
	Text(xx+5, yy+25, "core pullers I", SansTypeface, 12);
	Text(xx+7, yy+5, "     pos 2", SansTypeface, 14);
	return;
}

//______________________________________________core pullers 2 FWD

void lamp_8_OFF(void){
	int xx=910; int yy=250;
	Fill(255, 0, 0, 1);					            // OFF / FALSE / 0	
	StrokeWidth(3);
	Stroke(20,80,80,1);
	Roundrect(xx,yy, 120,70,20,20);
	Fill(0, 0, 0, 1);	
	Text(xx+4, yy+45, "   ENABLE", SansTypeface, 14);
	Text(xx+5, yy+25, "core pullers II", SansTypeface, 12);
	Text(xx+7, yy+5, "     pos 2", SansTypeface, 14);
	return;
}

void lamp_8_ON(void){
	int xx=910; int yy=250;
	Fill(0, 255, 0, 1);		
	StrokeWidth(3);
	Stroke(20,80,80,1);			             // ON / TRUE / 1
	Roundrect(xx,yy, 120,70,20,20);
	Fill(0, 0, 0, 1);	
	Text(xx+4, yy+45, "   ENABLE", SansTypeface, 14);
	Text(xx+5, yy+25, "core pullers II", SansTypeface, 12);
	Text(xx+7, yy+5, "     pos 2", SansTypeface, 14);
	return;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//_____________________________________________________________estop ch2

void lamp_9_OFF(void){
	int xx=0; int yy=325;
	Fill(255, 0, 0, 1);		
	StrokeWidth(3);
	Stroke(20,80,80,1);			            // OFF / FALSE / 0
	Roundrect(xx,yy, 120,70,20,20);
	Fill(0, 0, 0, 1);	
	Text(xx, yy+45, "    ROBOT", SansTypeface, 14);
	Text(xx, yy+25, "    E-STOP", SansTypeface, 14);
	Text(xx, yy+5, "      CH 2 ", SansTypeface, 14);
	return;
}

void lamp_9_ON(void){
	int xx=0; int yy=325;
	Fill(0, 255, 0, 1);	
	StrokeWidth(3);
	Stroke(20,80,80,1);				             // ON / TRUE / 1
	Roundrect(xx,yy, 120,70,20,20);
	Fill(0, 0, 0, 1);	
	Text(xx, yy+45, "    ROBOT", SansTypeface, 14);
	Text(xx, yy+25, "    E-STOP", SansTypeface, 14);
	Text(xx, yy+5, "      CH 2 ", SansTypeface, 14);
	return;
}

//_____________________________________________________enable full OPEN

void lamp_12_OFF(void){
	int xx=650; int yy=400;
	Fill(255, 0, 0, 1);		
	StrokeWidth(3);
	Stroke(20,80,80,1);			            // OFF / FALSE / 0
	Roundrect(xx,yy, 120,70,20,20);
	Fill(0, 0, 0, 1);	
	Text(xx+4, yy+45, "   ENABLE", SansTypeface, 14);
	Text(xx, yy+25, "    MOULD ", SansTypeface, 14);
	Text(xx+3, yy+5, "full opening ", SansTypeface, 14);
	return;
}

void lamp_12_ON(void){
	int xx=650; int yy=400;
	Fill(0, 255, 0, 1);		
	StrokeWidth(3);
	Stroke(20,80,80,1);			             // ON / TRUE / 1
	Roundrect(xx,yy, 120,70,20,20);
	Fill(0, 0, 0, 1);	
	Text(xx+4, yy+45, "   ENABLE", SansTypeface, 14);
	Text(xx, yy+25, "    MOULD ", SansTypeface, 14);
	Text(xx+3, yy+5, "full opening ", SansTypeface, 14);
	return;
}

//__________________________________________________enable eject BWD

void lamp_14_OFF(void){
	int xx=780; int yy=400;
	Fill(255, 0, 0, 1);	
	StrokeWidth(3);
	Stroke(20,80,80,1);				            // OFF / FALSE / 0
	Roundrect(xx,yy, 120,70,20,20);
	Fill(0, 0, 0, 1);	
	Text(xx+4, yy+45, "   ENABLE", SansTypeface, 14);
	Text(xx+5, yy+25, " EJECTORS", SansTypeface, 14);
	Text(xx+7, yy+5, "     BWD", SansTypeface, 14);
	return;
}

void lamp_14_ON(void){
	int xx=780; int yy=400;
	Fill(0, 255, 0, 1);	
	StrokeWidth(3);
	Stroke(20,80,80,1);				             // ON / TRUE / 1
	Roundrect(xx,yy, 120,70,20,20);
	Fill(0, 0, 0, 1);	
	Text(xx+4, yy+45, "   ENABLE", SansTypeface, 14);
	Text(xx+5, yy+25, " EJECTORS", SansTypeface, 14);
	Text(xx+7, yy+5, "     BWD", SansTypeface, 14);
	return;
}

//______________________________________________core pullers 1 BWD

void lamp_15_OFF(void){
	int xx=780; int yy=325;
	Fill(255, 0, 0, 1);	
	StrokeWidth(3);
	Stroke(20,80,80,1);				            // OFF / FALSE / 0
	Roundrect(xx,yy, 120,70,20,20);
	Fill(0, 0, 0, 1);	
	Text(xx+4, yy+45, "   ENABLE", SansTypeface, 14);
	Text(xx+5, yy+25, "core pullers I", SansTypeface, 12);
	Text(xx+7, yy+5, "     pos 1", SansTypeface, 14);
	return;
}

void lamp_15_ON(void){
	int xx=780; int yy=325;
	Fill(0, 255, 0, 1);	
	StrokeWidth(3);
	Stroke(20,80,80,1);				             // ON / TRUE / 1
	Roundrect(xx,yy, 120,70,20,20);
	Fill(0, 0, 0, 1);	
	Text(xx+4, yy+45, "   ENABLE", SansTypeface, 14);
	Text(xx+5, yy+25, "core pullers I", SansTypeface, 12);
	Text(xx+7, yy+5, "     pos 1", SansTypeface, 14);
	return;
}

//______________________________________________core pullers 2 BWD

void lamp_16_OFF(void){
	int xx=780; int yy=250;
	Fill(255, 0, 0, 1);	
	StrokeWidth(3);
	Stroke(20,80,80,1);				            // OFF / FALSE / 0
	Roundrect(xx,yy, 120,70,20,20);
	Fill(0, 0, 0, 1);	
	Text(xx+4, yy+45, "   ENABLE", SansTypeface, 14);
	Text(xx+5, yy+25, "core pullers II", SansTypeface, 12);
	Text(xx+7, yy+5, "     pos 1", SansTypeface, 14);
	return;
}

void lamp_16_ON(void){
	int xx=780; int yy=250;
	Fill(0, 255, 0, 1);		
	StrokeWidth(3);
	Stroke(20,80,80,1);			             // ON / TRUE / 1
	Roundrect(xx,yy, 120,70,20,20);
	Fill(0, 0, 0, 1);	
	Text(xx+4, yy+45, "   ENABLE", SansTypeface, 14);
	Text(xx+5, yy+25, "core pullers II", SansTypeface, 12);
	Text(xx+7, yy+5, "     pos 1", SansTypeface, 14);
	return;
}
