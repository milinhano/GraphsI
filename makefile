CC = g++
LD = g++
CPPFLAGS = -Wall -O3
LDFLAGS = 

RM = /bin/rm -f

CPPSOURCES = $(wildcard *.cpp)

#nome do programa executavel
PROG = Iso

all: Iso

Iso: $(CPPSOURCES:.cpp=.o)
	$(LD) $(LDFLAGS) $(CPPSOURCES) -o $(PROG)

%.o: %.cpp
	$(CC) $(CPPFLAGS) -c $< 

clean:
	$(RM) $(PROG) $(CPPSOURCES)