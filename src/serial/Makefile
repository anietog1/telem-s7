CXX=icpc
CXXFLAGS=-c -qopenmp -qopt-report=5 -xMIC-AVX512
LDFLAGS=-qopenmp

OBJECTS=main.o ../common/definition.o

all: app

app: $(OBJECTS)
	$(CXX) $(LDFLAGS) -o app $(OBJECTS)

queue: all
	echo 'cd $$PBS_O_WORKDIR ; ./app' | qsub -N process_serial

clean:
	rm *.o app process_serial.*
