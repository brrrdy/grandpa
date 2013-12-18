#compiler used
CC=g++

#compiler flags
CFLAGS=-c -Wall

#libraries
LDFLAGS= -LC:\SFML\lib -lsfml-window -lsfml-system -lsfml-graphics

#includes
INCFLAGS= -IC:\SFML\include

#source files
SOURCES= driver.cpp Game.cpp GameState.cpp Uninitialized.cpp

#object files
OBJECTS=$(SOURCES:.cpp=.o)

#executable name
EXECUTABLE= game


all:	$(SOURCES) $(EXECUTABLE)

$(EXECUTABLE) : $(OBJECTS)
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@
	
.cpp.o:
	$(CC) $(CFLAGS) $(INCFLAGS) $< -o $@
	
clean:
	del $(EXECUTABLE).exe $(OBJECTS)