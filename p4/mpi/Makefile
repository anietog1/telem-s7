CXX=mpiicpc
CXXFLAGS=-c -qopenmp -qopt-report=5 -xMIC-AVX512
LDFLAGS=-qopenmp

OBJECTS=main.o ../common/definition.o

all: app

app: $(OBJECTS)
	$(CXX) $(LDFLAGS) -o app $(OBJECTS)

queue: all
	echo 'cd $$PBS_O_WORKDIR ; mpirun -machinefile $$PBS_NODEFILE ./app' | qsub -l nodes=4:flat -N process_mpi

queueN:	all
	echo 'cd $$PBS_O_WORKDIR ; mpirun -machinefile $$PBS_NODEFILE ./app' | qsub -l nodes=$(N):flat -N process_mpi_N_$(N)

clean:
	rm *.o app process_mpi.*
