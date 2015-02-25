CC = gcc
CCMAC = gcc
CFLAGS= -c -ansi -pedantic -std=c++0x -Weffc++ -g -I./include
MOVE = /bin/mv -f
RM = /bin/rm -f
BIN = ./bin

# CPLUS_INCLUDE_PATH=.\include
# export  CPLUS_INCLUDE_PATH
# LIBRARY_PATH=.\lib
# export LIBRARY_PATH

EXE=bin/exec
LIBS=-L./libMac -lEngine -framework OpenGL -framework GLUT 
LIBSLINUX=  -L./libLinux -lEngine -lGL -lglut -lm -lGLU
LIBSWINDOWS= -L./libWin -lEngine -lglu32 -lopengl32  -lglut32 
LDFLAGS= -lm -g -lstdc++

SOURCES = $(wildcard src/*.cpp src/*/*.cpp src/*/*/*.cpp)
ENTETES = $(wildcard src/*.h src/*/*.h src/*/*/*.h)

#SOURCES = ${shell ls *.cpp}
#ENTETES = ${shell ls *.h}
#OBJS =${subst .cpp,.o, ${SOURCES}}
OBJS = ${SOURCES:.cpp=.o}


ifdef DEBUG
	CFLAGS += -g
endif

mac: ${OBJS}
	${CCMAC} ${OBJS} -o ${EXE} ${LDFLAGS} ${LIBS}

linux: ${OBJS}
	${CC} ${OBJS} -o ${EXE} ${LDFLAGS} ${LIBSLINUX}

windows: ${OBJS}
	${CC} ${OBJS} -o ${EXE} ${LDFLAGS} ${LIBSWINDOWS}
   
.cpp.o:
	${CC} ${CFLAGS} $^ -o ${^:.cpp=.o}

run:
	cd bin;./exec

.PHONY: clean veryclean

clean : #pas de dependance
	/bin/rm -f *.o *.gch *.bak *~ src/*.o src/*/*.o src/*/*/*.o

veryclean : clean
	/bin/rm -f ${EXE}
