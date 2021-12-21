INCLUDEFLAGS=-I/opt/vc/include -I/opt/vc/include/interface/vmcs_host/linux -I/opt/vc/include/interface/vcos/pthreads -I..
LIBFLAGS=-L/opt/vc/lib -lEGL -lGLESv2 -lbcm_host -lpthread  -ljpeg -lwiringPi

all: em67_c_17dec2016





em67_c_17dec2016:	em67_c_17dec2016.c ../libshapes.o ../oglinit.o
	gcc -Wall $(INCLUDEFLAGS) -o  em67_c_17dec2016 em67_c_17dec2016.c ../libshapes.o ../oglinit.o $(LIBFLAGS)

