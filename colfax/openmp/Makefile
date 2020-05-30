CXX=icpc
CXXFLAGS=-c -qopenmp -qopt-report=5 -xMIC-AVX512
LDFLAGS=-qopenmp

OBJECTS=main.o ../common/definition.o

app: $(OBJECTS)
	$(CXX) $(LDFLAGS) -o app $(OBJECTS)

all:	app

queue:	all
	echo 'cd $$PBS_O_WORKDIR ; ./app' | qsub -N process_openmp

clean:
	rm *~ process_openmp.*
