En este trabajo, se utiliza los pasos de la metodología PCAM principalmente en la solución del problema con MPI. Este metodología fue propuesta por Foster en el libro Design and building parallel programs. Se tienen las cuatro etapas señaladas por la metodología, adaptadas al problema en cuestión:

**Particionamiento:**

En este caso, se particiona la tarea por datos, sobre los cuales se ejecuta la misma función y se hace la final una acumulación de los resultados parciales. Se divide en N, donde N son la cantidad de nodos. En cada nodo se ejecuta  también en multithreading, dependiendo de los hilos disponibles o definidos por el usuario. Dejaremos la solución final con los hilos disponibles, pues si se solicitan hilos y no hay disponibles los suficientes, el proceso tendrá que esperar y tardará más. Sin embargo se harán pruebas para mirar cómo afecta distintos hilos a la solución OpenMP. Cada nodo realiza n/4 iteraciones para resolver la integral.

**Comunicación:**

Los nodos se comunican usando la red de alta velocidad del cluster, lo que permite tener tiempos de comunicación pequeños. Se utiliza el protocolo MPIAllReduce para obtener el resultado final, que toma todos los resultados parciales y utiliza el operador suma para proveer el total de la integral en el intervalo dado. Los hilos se comunican a través de memoria compartida, que lo define simd en la función a integrar en este caso.

Dentro de cada nodo, se tienen hilos de procesamiento de acuerdo a los hilos disponibles en el sistema en un momento dado. Cada hilo operará en un subconjunto del conjunto recibido por el nodo.

**Aglomeración:**

Cada nodo de ejecución tendrá un subconjunto de los n pasos a realizar, y evaluará la función utilizando la regla del trapecio compuesto para obtener un acumulado parcial, en un subintervalo del intervalo inicial [a,b]. Este resultado parcial se sumará con los demás para obtener la integral total.

Cada nodo retorna un resultado parcial (ri, con i = 1-4), de la integral. Para resolverla totalmente, se suman estos resultados y se aplica otro cálculo definido por el método del trapecio.

**Mapeo:**

Se tendrán N = 4 nodos, para evaluar la integral definida de la función exp(x) en el intervalo [a=0, b=10], con n = 4*10^9 pasos. El resultado que se obtuvo para el algoritmo MPI es de 22025.465795, como integral definida.
