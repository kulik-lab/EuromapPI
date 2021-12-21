// 	________________________________________________________	but 1
void but_1_OFF(void);// 1 .
void but_1_ON(void);
void but_2_OFF(void);// 2
void but_2_ON(void);
void but_3_OFF(void);// 3
void but_3_ON(void);
void but_4_OFF(void);// 4
void but_4_ON(void);
void but_5_OFF(void);// 5
void but_5_ON(void);
void but_6_OFF(void);// 6
void but_6_ON(void);
void but_7_OFF(void);// 7
void but_7_ON(void);
void but_8_OFF(void);// 8
void but_8_ON(void);
void but_12_OFF(void);// 12
void but_12_ON(void);
void but_13_OFF(void);// 13
void but_13_ON(void);
void but_14_OFF(void);// 14
void but_14_ON(void);
void but_15_OFF(void);// 15
void but_15_ON(void);
void but_16_OFF(void);// 16
void but_16_ON(void);
void but_50_OFF(void);// 50  INJECTION
void but_50_ON(void);
void but_51_OFF(void);// 51 automatic/ manual
void but_51_ON(void);
void but_52(void);// 52 EXIT button
void but_61_OFF(void); //61 reject checkbox
void but_61_ON(void);
void but_62_OFF(void); //interm pos
void but_62_ON(void);
VGfloat* xxx1; VGfloat* yyy1;
VGfloat xxx[4]; VGfloat yyy[4];
//

 
//__________________________________________________robot estop ch1 + 2

void but_1_OFF(void){
	int xx=0; int yy=150;
	Fill(255, 0, 0, 1);					            // OFF / FALSE / 0
	StrokeWidth(3);
	Stroke(20,80,80,1);
	Roundrect(xx,yy, 120,70,20,20);
	Fill(0, 0, 0, 1);
	Text(xx, yy+45, "       IMM", SansTypeface, 14);
	Text(xx, yy+25, "    E-STOP", SansTypeface, 14);
	Text(xx, yy+5, " CH 1 + CH 2 ", SansTypeface, 13);
	return;
}

void but_1_ON(void){
	int xx=0; int yy=150;
	Fill(0, 255, 0, 1);					             // ON / TRUE / 1
	StrokeWidth(3);
	Stroke(20,80,80,1);
	Roundrect(xx,yy, 120,70,20,20);
	Fill(0, 0, 0, 1);
	Text(xx, yy+45, "       IMM", SansTypeface, 14);
	Text(xx, yy+25, "    E-STOP", SansTypeface, 14);
	Text(xx, yy+5, " CH 1 + CH 2 ", SansTypeface, 13);
	return;
}

//__________________________________________________safety devices 1 + 2

void but_2_OFF(void){
	int xx=0; int yy=75;
	Fill(255, 0, 0, 1);					            // OFF / FALSE / 0
	StrokeWidth(3);
	Stroke(20,80,80,1);
	Roundrect(xx,yy, 120,70,20,20);
	Fill(0, 0, 0, 1);	
	Text(xx-2, yy+45, "       IMM ", SansTypeface, 14);
	Text(xx+10, yy+25, "   FENCE", SansTypeface, 14);
	Text(xx+5, yy+5, "CH 1 + CH 2", SansTypeface, 13);
	return;
}

void but_2_ON(void){
	int xx=0; int yy=75;
	Fill(0, 255, 0, 1);					             // ON / TRUE / 1
	StrokeWidth(3);
	Stroke(20,80,80,1);
	Roundrect(xx,yy, 120,70,20,20);
	Fill(0, 0, 0, 1);	
	Text(xx-2, yy+45, "       IMM ", SansTypeface, 14);
	Text(xx+10, yy+25, "   FENCE", SansTypeface, 14);
	Text(xx+5, yy+5, "CH 1 + CH 2", SansTypeface, 13);
	return;
}

//__________________________________________________operation with ROBOT

void but_3_OFF(void){
	int xx=130; int yy=150;
	Fill(255, 0, 0, 1);					            // OFF / FALSE / 0
	StrokeWidth(3);
	Stroke(20,80,80,1);
	Roundrect(xx,yy, 120,70,20,20);
	Fill(0, 0, 0, 1);	
	Text(xx, yy+45, " ", SansTypeface, 14);
	Text(xx, yy+25, " AUTOMATIC", SansTypeface, 14);
	Text(xx, yy+5, "    ", SansTypeface, 14);
	return;
}

void but_3_ON(void){
	int xx=130; int yy=150;
	Fill(0, 255, 0, 1);					             // ON / TRUE / 1
	StrokeWidth(3);
	Stroke(20,80,80,1);
	Roundrect(xx,yy, 120,70,20,20);
	Fill(0, 0, 0, 1);	
	Text(xx, yy+45, " ", SansTypeface, 14);
	Text(xx, yy+25, " AUTOMATIC", SansTypeface, 14);
	Text(xx, yy+5, "", SansTypeface, 14);
	return;
}

//__________________________________________________mould closed

void but_4_OFF(void){
	int xx=260; int yy=150;
	Fill(255, 0, 0, 1);					            // OFF / FALSE / 0
	StrokeWidth(3);
	Stroke(20,80,80,1);
	Roundrect(xx,yy, 120,70,20,20);
	Fill(0, 0, 0, 1);	
	Text(xx+4, yy+45, "    MOULD   ", SansTypeface, 14);
	Text(xx+4, yy+25, "   CLOSED", SansTypeface, 14);
	Text(xx+2, yy+5, "", SansTypeface, 14);
	return;
}

void but_4_ON(void){
	int xx=260; int yy=150;
	Fill(0, 255, 0, 1);					             // ON / TRUE / 1
	StrokeWidth(3);
	Stroke(20,80,80,1);
	Roundrect(xx,yy, 120,70,20,20);
	Fill(0, 0, 0, 1);	
	Text(xx+4, yy+45, "    MOULD   ", SansTypeface, 14);
	Text(xx+4, yy+25, "   CLOSED", SansTypeface, 14);
	Text(xx+2, yy+5, " ", SansTypeface, 14);
	return;
}

//__________________________________________________REJECT

void but_13_OFF(void){
	int xx=520; int yy=150;
	Fill(255, 0, 0, 1);					            // OFF / FALSE / 0
	StrokeWidth(3);
	Stroke(20,80,80,1);
	Roundrect(xx,yy, 120,70,20,20);
	Fill(0, 0, 0, 1);	
	Text(xx+4, yy+45, "    ", SansTypeface, 14);
	Text(xx+4, yy+25, "   REJECT", SansTypeface, 14);
	Text(xx+2, yy+5, "    ", SansTypeface, 14);
	return;
}

void but_13_ON(void){
	int xx=520; int yy=150;
	Fill(0, 255, 0, 1);					             // ON / TRUE / 1
	StrokeWidth(3);
	Stroke(20,80,80,1);
	Roundrect(xx,yy, 120,70,20,20);
	Fill(0, 0, 0, 1);	
	Text(xx+4, yy+45, "   ", SansTypeface, 14);
	Text(xx+4, yy+25, "   REJECT", SansTypeface, 14);
	Text(xx+2, yy+5, "    ", SansTypeface, 14);
	return;
}


//__________________________________________________intermediate pos

void but_12_OFF(void){
	int xx=650; int yy=75;
	Fill(255, 0, 0, 1);					            // OFF / FALSE / 0
	StrokeWidth(3);
	Stroke(20,80,80,1);
	Roundrect(xx,yy, 120,70,20,20);
	Fill(0, 0, 0, 1);	
	Text(xx+4, yy+45, "   OPEN at", SansTypeface, 14);
	Text(xx+5, yy+25, "intermediate", SansTypeface, 13);
	Text(xx+7, yy+5, "   position", SansTypeface, 14);
	return;
}

void but_12_ON(void){
	int xx=650; int yy=76;
	Fill(0, 255, 0, 1);					             // ON / TRUE / 1
	StrokeWidth(3);
	Stroke(20,80,80,1);
	Roundrect(xx,yy, 120,70,20,20);
	Fill(0, 0, 0, 1);	
	Text(xx+4, yy+45, "    OPEN at", SansTypeface, 14);
	Text(xx+5, yy+25, "intermediate", SansTypeface, 13);
	Text(xx+7, yy+5, "   position", SansTypeface, 14);
	return;
}

//______________________________________________ejectors FWD

void but_6_OFF(void){
	int xx=910; int yy=150;
	Fill(255, 0, 0, 1);					            // OFF / FALSE / 0
	StrokeWidth(3);
	Stroke(20,80,80,1);
	Roundrect(xx,yy, 120,70,20,20);
	Fill(0, 0, 0, 1);	
	Text(xx+4, yy+45, " EJECTORS ", SansTypeface, 14);
	Text(xx+5, yy+25, "     FWD", SansTypeface, 14);
	Text(xx+7, yy+5, "   ", SansTypeface, 14);
	return;
}

void but_6_ON(void){
	int xx=910; int yy=150;
	Fill(0, 255, 0, 1);					             // ON / TRUE / 1
	StrokeWidth(3);
	Stroke(20,80,80,1);
	Roundrect(xx,yy, 120,70,20,20);
	Fill(0, 0, 0, 1);	
	Text(xx+4, yy+45, " EJECTORS ", SansTypeface, 14);
	Text(xx+5, yy+25, "     FWD", SansTypeface, 14);
	Text(xx+7, yy+5, "   ", SansTypeface, 14);
	return;
}

//______________________________________________core pullers 1 FWD

void but_7_OFF(void){
	int xx=910; int yy=75;
	Fill(255, 0, 0, 1);					            // OFF / FALSE / 0
	StrokeWidth(3);
	Stroke(20,80,80,1);
	Roundrect(xx,yy, 120,70,20,20);
	Fill(0, 0, 0, 1);	
	Text(xx+4, yy+45, "core pullers I", SansTypeface, 12);
	Text(xx+5, yy+25, "     pos 2", SansTypeface, 14);
	Text(xx+7, yy+5, "    ", SansTypeface, 14);
	return;
}

void but_7_ON(void){
	int xx=910; int yy=75;
	Fill(0, 255, 0, 1);					             // ON / TRUE / 1
	StrokeWidth(3);
	Stroke(20,80,80,1);
	Roundrect(xx,yy, 120,70,20,20);
	Fill(0, 0, 0, 1);	
	Text(xx+4, yy+45, "core pullers I", SansTypeface, 12);
	Text(xx+5, yy+25, "     pos 2", SansTypeface, 14);
	Text(xx+7, yy+5, "    ", SansTypeface, 14);
	return;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++



//________________________________________________core pull 2 pos 2

void but_8_OFF(void){
	int xx=910; int yy=0;
	Fill(255, 0, 0, 1);					            // OFF / FALSE / 0
	StrokeWidth(3);
	Stroke(20,80,80,1);
	Roundrect(xx,yy, 120,70,20,20);
	Fill(0, 0, 0, 1);	
	Text(xx+3, yy+45, "core pullers II", SansTypeface, 12);
	Text(xx+5, yy+25, "     pos 2", SansTypeface, 14);
	Text(xx+7, yy+5, "    ", SansTypeface, 14);
	return;
}

void but_8_ON(void){
	int xx=910; int yy=0;
	Fill(0, 255, 0, 1);					             // ON / TRUE / 1
	StrokeWidth(3);
	Stroke(20,80,80,1);
	Roundrect(xx,yy, 120,70,20,20);
	Fill(0, 0, 0, 1);	
	Text(xx+3, yy+45, "core pullers II", SansTypeface, 12);
	Text(xx+5, yy+25, "     pos 2", SansTypeface, 14);
	Text(xx+7, yy+5, "    ", SansTypeface, 14);
	return;
}

//__________________________________________________eject BWD

void but_14_OFF(void){
	int xx=780; int yy=150;
	Fill(255, 0, 0, 1);					            // OFF / FALSE / 0
	StrokeWidth(3);
	Stroke(20,80,80,1);
	Roundrect(xx,yy, 120,70,20,20);
	Fill(0, 0, 0, 1);	
	Text(xx+4, yy+45, " EJECTORS ", SansTypeface, 14);
	Text(xx+5, yy+25, "     BWD", SansTypeface, 14);
	Text(xx+7, yy+5, "   ", SansTypeface, 14);
	return;
}

void but_14_ON(void){
	int xx=780; int yy=150;
	Fill(0, 255, 0, 1);					             // ON / TRUE / 1
	StrokeWidth(3);
	Stroke(20,80,80,1);
	Roundrect(xx,yy, 120,70,20,20);
	Fill(0, 0, 0, 1);	
	Text(xx+4, yy+45, " EJECTORS ", SansTypeface, 14);
	Text(xx+5, yy+25, "     BWD", SansTypeface, 14);
	Text(xx+7, yy+5, "   ", SansTypeface, 14);
	return;
}
//__________________________________________________core pull 1 BWD

void but_15_OFF(void){
	int xx=780; int yy=75;
	Fill(255, 0, 0, 1);					            // OFF / FALSE / 0
	StrokeWidth(3);
	Stroke(20,80,80,1);
	Roundrect(xx,yy, 120,70,20,20);
	Fill(0, 0, 0, 1);	
	Text(xx+4, yy+45, "core pullers I", SansTypeface, 12);
	Text(xx+5, yy+25, "     pos 1", SansTypeface, 14);
	Text(xx+7, yy+5, "    ", SansTypeface, 14);
	return;
}

void but_15_ON(void){
	int xx=780; int yy=75;
	Fill(0, 255, 0, 1);					             // ON / TRUE / 1
	StrokeWidth(3);
	Stroke(20,80,80,1);
	Roundrect(xx,yy, 120,70,20,20);
	Fill(0, 0, 0, 1);	
	Text(xx+4, yy+45, "core pullers I", SansTypeface, 12);
	Text(xx+5, yy+25, "     pos 1", SansTypeface, 14);
	Text(xx+7, yy+5, "    ", SansTypeface, 14);
	return;
}

//______________________________________________core pullers 2 BWD

void but_16_OFF(void){
	int xx=780; int yy=0;
	Fill(255, 0, 0, 1);					            // OFF / FALSE / 0
	StrokeWidth(3);
	Stroke(20,80,80,1);
	Roundrect(xx,yy, 120,70,20,20);
	Fill(0, 0, 0, 1);	
	Text(xx+4, yy+45, "core pullers II", SansTypeface, 12);
	Text(xx+5, yy+25, "     pos 1", SansTypeface, 14);
	Text(xx+7, yy+5, "    ", SansTypeface, 14);
	return;
}

void but_16_ON(void){
	int xx=780; int yy=0;
	Fill(0, 255, 0, 1);					             // ON / TRUE / 1
	StrokeWidth(3);
	Stroke(20,80,80,1);
	Roundrect(xx,yy, 120,70,20,20);
	Fill(0, 0, 0, 1);	
	Text(xx+4, yy+45, "core pullers II", SansTypeface, 12);
	Text(xx+5, yy+25, "     pos 1", SansTypeface, 14);
	Text(xx+7, yy+5, "    ", SansTypeface, 14);
	return;
}

//______________________________________________mould open

void but_5_OFF(void){
	int xx=650; int yy=150;
	Fill(255, 0, 0, 1);					            // OFF / FALSE / 0
	StrokeWidth(3);
	Stroke(20,80,80,1);
	Roundrect(xx,yy, 120,70,20,20);
	Fill(0, 0, 0, 1);	
	Text(xx+4, yy+45, "   MOULD", SansTypeface, 14);
	Text(xx+5, yy+25, "    OPEN", SansTypeface, 14);
	Text(xx+7, yy+5, "   ", SansTypeface, 14);
	return;
}

void but_5_ON(void){
	int xx=650; int yy=150;
	Fill(0, 255, 0, 1);					             // ON / TRUE / 1
	
	StrokeWidth(3);
	Stroke(20,80,80,1);
	Roundrect(xx,yy, 120,70,20,20);
	Fill(0, 0, 0, 1);	
	Text(xx+4, yy+45, "   MOULD", SansTypeface, 14);
	Text(xx+5, yy+25, "    OPEN", SansTypeface, 14);
	Text(xx+7, yy+5, "    ", SansTypeface, 14);
	return;
}

//___________________________________________ INJECTION

void but_50_OFF(void){
	int xx=390; int yy=150;
	Fill(20, 30, 40, 1);					            // OFF / FALSE / 0
	StrokeWidth(3);
	Stroke(20,80,80,1);
	Roundrect(xx,yy, 120,70,20,20);
	Fill(0, 0, 0, 1);	
	Text(xx+4, yy+45, "  ", SansTypeface, 14);
	Text(xx+5, yy+25, " INJECTION ", SansTypeface, 14);
	Text(xx+7, yy+5, "     ", SansTypeface, 14);
	return;
}

void but_50_ON(void){
	int xx=390; int yy=150;
	Fill(0xFF, 0xE6, 0x06, 1);					             // ON / TRUE / 1
	
	StrokeWidth(3);
	Stroke(170,100,100,1);
	Roundrect(xx,yy, 120,70,20,20);
	Fill(0, 0, 0, 1);	
	Text(xx+4, yy+45, "   ", SansTypeface, 14);
	Text(xx+5, yy+25, " INJECTION ", SansTypeface, 14);
	Text(xx+7, yy+5, "     ", SansTypeface, 14);
	return;
}




//___________________________________________ AUTOMATIC

void but_51_ON(void){
	int xx=780; int yy=480;
	Fill(1, 255, 1, 1);					            // OFF / FALSE / 0
	StrokeWidth(3);
	Stroke(20,80,80,1);
	Roundrect(xx,yy, 240,120,20,20);
	Fill(0, 0, 0, 1);	
	Text(xx+4, yy+45, "   START /", SansTypeface, 14);
	Text(xx+5, yy+25, " AUTOMATIC ", SansTypeface, 14);
	Text(xx+7, yy+5, "     ", SansTypeface, 14);
	return;
}

void but_51_OFF(void){
	int xx=780; int yy=480;
	Fill(255, 1, 1, 1);				             // ON / TRUE / 1
	
	StrokeWidth(3);
	Stroke(170,100,100,1);
	Roundrect(xx,yy, 240,120,20,20);
	Fill(0, 0, 0, 1);	
	Text(xx+4, yy+45, "   STOP /", SansTypeface, 14);
	Text(xx+5, yy+25, "   MANUAL ", SansTypeface, 14);
	Text(xx+7, yy+5, "     ", SansTypeface, 14);
	return;
}


//___________________________________________ EXIT EXIT EXIT EXIT

void but_52(void){
	int xx=390; int yy=520;
	Fill(66, 50, 63, 1);					            // OFF / FALSE / 0
	StrokeWidth(3);
	Stroke(20,80,80,1);
	Roundrect(xx,yy, 120,50,10,10);
	Fill(0, 0, 0, 1);	
	Text(xx+5, yy+15, "  EXIT ", SansTypeface, 14);
	
	return;
}

//_______61 reject checkbox

void but_61_OFF(void){
	int xx=390; int yy=150;
	Fill(33,33,33, 1);					            // OFF / FALSE / 0
	StrokeWidth(3);
	Stroke(39,100,100,1);
	VGfloat xxx[]={580,600,580,565,580};
	VGfloat yyy[]={30,50,20,36,30};
	xxx1=xxx; yyy1=yyy; 
	Polygon(xxx1,yyy1,5);
	Fill(0, 0, 0, 1);	
	Text(xx+4, yy+45, "  ", SansTypeface, 14);
	Text(xx+5, yy+25, " INJECTION ", SansTypeface, 14);
	Text(xx+7, yy+5, "     ", SansTypeface, 14);
	return;
}

void but_61_ON(void){
	int xx=390; int yy=150;
	Fill(0xB2, 0xFF, 0x00, 1);					             // ON / TRUE / 1
	
	StrokeWidth(3);
	Stroke(170,100,100,1);
	VGfloat xxx[]={580,600,580,565,580};
	VGfloat yyy[]={30,50,20,36,30};
	xxx1=xxx; yyy1=yyy; 
	Polygon(xxx1,yyy1,5);
	Fill(0, 0, 0, 1);	
	Text(xx+4, yy+45, "   ", SansTypeface, 14);
	Text(xx+5, yy+25, " INJECTION ", SansTypeface, 14);
	Text(xx+7, yy+5, "     ", SansTypeface, 14);
	return;
}

//but 62 intermediate pos checkbox
void but_62_OFF(void){
	int xx=390; int yy=150;
	Fill(33,33,33, 1);					            // OFF / FALSE / 0
	StrokeWidth(3);
	Stroke(39,100,100,1);
	VGfloat xxx[]={710,730,710,695,710};
	VGfloat yyy[]={30,50,20,36,30};
	xxx1=xxx; yyy1=yyy; 
	Polygon(xxx1,yyy1,5);
	Fill(0, 0, 0, 1);	
	Text(xx+4, yy+45, "  ", SansTypeface, 14);
	Text(xx+5, yy+25, " INJECTION ", SansTypeface, 14);
	Text(xx+7, yy+5, "     ", SansTypeface, 14);
	return;
}

void but_62_ON(void){
	int xx=390; int yy=150;
	Fill(0xB2, 0xFF, 0x00, 1);					             // ON / TRUE / 1
	
	StrokeWidth(3);
	Stroke(170,100,100,1);
	VGfloat xxx[]={710,730,710,695,710};
	VGfloat yyy[]={30,50,20,36,30};
	xxx1=xxx; yyy1=yyy; 
	Polygon(xxx1,yyy1,5);
	Fill(0, 0, 0, 1);	
	Text(xx+4, yy+45, "   ", SansTypeface, 14);
	Text(xx+5, yy+25, " INJECTION ", SansTypeface, 14);
	Text(xx+7, yy+5, "     ", SansTypeface, 14);
	return;
}
