# Código de Honor

En este trabajo resolvemos integrales haciendo uso del [método numérico del trapecio](https://www.geogebra.org/m/qfsWGKKp) y declaramos que la solución propuesta se basa en los conocimientos adquiridos durante el curso [Fundamentals of Parallelism on Intel Architecture](https://www.coursera.org/learn/parallelism-ia/), en código fuente presentado allí para la solución de otros problemas y el método del trapecio desarrollado está basado en el curso que una vez vimos de análisis numérico en la universidad, más concretamente en el libro [Métodos Numéricos](http://www.eafit.edu.co/cultura-eafit/fondo-editorial/colecciones/Paginas/metodos-numericos.aspx) del docente Francisco José Correa Zabala.

Yo, Agustín Nieto García, mejoré el desempeño de la aplicación garantizando el máximo aprovechamiento de la vectorización en la máquina, con SIMD en OpenMP, lo cual también mejoró los tiempos de cómputo en MPI.

Yo, Kevin Arley Parra Henao, diseñé e implementé los algoritmos para la ejecución serial, OpenMP y MPI. En estos algoritmos se tiene la implementación básica del método del trapecio compuesto utilizado para calcular la integral definida de una función en un intervalo dado, con un número de pasos especificados. Este método fue enriquecido con las características que ofrece OpenMP para el manejo de hilos de ejecución y con el procesamiento distribuido en cluster de MPI.

Yo, Santiago Castrillón Galvis, aporté al proyecto analizando los programas de OpenMP y MPI de manera que fueran eficientes y acordes al desempeño esperado en computación de alto rendimiento, realizando mediciones, SpeedUp y Eficiencia en cada una de las etapas hasta conseguir resultados adecuados.

# Estructura del repositorio

.
├── LICENSE
├── PCAM.md
├── README.md
├── reports
│   ├── process_mpi_N_2.o115907
│   ├── process_mpi_N_3.o115908
│   ├── process_mpi.o115906
│   ├── process_openmp.o115905
│   └── process_serial.o115770
└── src
    ├── common
    │   ├── definition.cc
    │   └── definition.h
    ├── mpi
    │   ├── main.cc
    │   └── Makefile
    ├── openmp
    │   ├── main.cc
    │   └── Makefile
    └── serial
        ├── main.cc
        └── Makefile
**src** Tiene los códigos para la implementación serial, openmp, y mpi (cada uno en una carpeta llamada respectivamente). Cada carpeta contiene el código y el Makefile para la compilación y ejecución. La subcarpeta **common** contiene las definiciones comunes como el número de pasos y el intervalo a usar para todos los programas.

**reports** Tiene las salidas de la ejecución de los programas, donde cada archivo process_* indica la salida de su respectivo programa. En este caso, por ejemplo process_serial.o*, contiene la salida del procesamiento del programa serial.A su vez, process_mpi_N_2.o*, por ejemplo, contiene la salida del procesamiento en MPI con 2 nodos. Por otro lado, process_mpi.o* es la salida con 4 nodos (número máximo de nodos permitidos) y es la que se implementó por defecto. Por último, el archivo final_report.pdf contiene un informe que incluye información  más detallada del proceso de desarrollo del proyecto.

**PCAM.md** Tiene detalles generales de la implementación en PCAM. Información más detallada, que incluye diagramas, en el archivo reports/final_report.pdf

# Cómo ejecutar

Se requiere estar dentro del cluster de colfax o un cluster equivalente, con máquinas con procesadores Xeon Phi.

En la carpeta de cualquiera de los métodos, ejecutar:

    $ make       # para compilar el programa y generar el reporte de compilador
    $ make queue # para correr el programa en el cluster

# Análisis de Resultados

Primeramente se tomaron los tiempos de procesamiento en el algoritmo serial:

## TcomputoSerial = 115.530155 s.

Este es el tiempo obtenido del algoritmo base sin ningun tipo de paralelización, como se ve, el tiempo de computo es elevado dado la gran cantidad de operaciones que tiene que realizar en el cálculo de cada trapecio y en la sumatoria de cada uno de ellos, y al ser operaciones secuenciales todo el proceso se torna aún más extenso.

