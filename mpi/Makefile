CXX=icpc
CXXFLAGS=-xMIC-AVX512 -qopenmp
OPTRPT=-qopt-report=5

default: app

app: main.cc
	${CXX} ${OPTRPT} ${CXXFLAGS} -o "$@" "$<"

queue:	app
	echo 'cd $$PBS_O_WORKDIR ; ./app' | qsub -N mpi -walltime=00:30:00

clean:
	rm mpi.*
