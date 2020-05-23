CXX=icpc
CXXFLAGS=-xMIC-AVX512 -qopenmp
OPTRPT=-qopt-report=5

default: app

app: main.cc
	${CXX} ${OPTRPT} ${CXXFLAGS} -o "$@" "$<"

clean:
	rm app *.optrpt
