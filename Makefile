# Add PANDA_LIB and PANDA_CPATH environment variables

all: text.o
	g++ $^ -o a.out -fPIC -L$(PANDA_LIB) -lp3framework -lpanda -lpandafx -lpandaexpress -lp3dtoolconfig -lp3dtool -lp3pystub -lp3direct -lpthread

%.o: %.cpp
	g++ -c $< -o $@ -fPIC -O0 -ggdb3 --std=gnu++11 -I$(PANDA_CPATH) -I/usr/include/eigen3

clean:
	rm *.o *.out
