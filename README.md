## Código de Honor

En este trabajo resolvemos el problema [Counting DNA Nucleotides](http://rosalind.info/problems/dna/) y declaramos que la solución propuesta es totalmente original, aunque se basa en los conocimientos adquiridos durante el curso [Fundamentals of Parallelism on Intel Architecture](https://www.coursera.org/learn/parallelism-ia/) y en código fuente presentado allí para la solución de otros problemas.

Yo, Agustín Nieto García, mejoré el desempeño de la aplicación garantizando el máximo aprovechamiento de la vectorización en la máquina, con SIMD en OpenMP, lo cual también mejoró los tiempos de cómputo en MPI.

Yo, Kevin Arley Parra Henao, aporté al proyecto implementando un método para la generación aleatoria de nucleobases para los nucleótidos, esto en la fase de prueba. El método genera aleatoriamente (en realidad, pseudo aleatoriamente) una de las siguientes moléculas: adenina (A), citosina (C), guanina (G) y timina (T). Estas se van uniendo a un polímero de DNA (Ácido desoxirribonucleico), el cual se usa como método input para testear los diferentes algoritmos que se tienen. Es importante recalcar que este método es pseudoaleatorio, genera una secuencia no uniformemente distribuida y tampoco constituye una hebra de DNA precisamente, se usa sólo para fines de pruebas y académicos.

Yo, Santiago Castrillón Galvis, aporté al proyecto analizando los programas de OpenMP y MPI de manera que fueran eficientes y acordes al desempeño esperado en computación de alto rendimiento, realizando mediciones, SpeedUp y Eficiencia en cada una de las etapas hasta conseguir resultados adecuados.

## Cómo ejecutar

Se requiere estar dentro del cluster de colfax o un cluster equivalente, con máquinas con procesadores Xeon Phi.

En la carpeta de cualquiera de los métodos, ejecutar:

    $ make       # para compilar el programa y generar el reporte de compilador
    $ make queue # para correr el programa en el cluster

## Análisis de Resultados

Primeramente se tomaron los tiempos de procesamiento en el algoritmo serial, el resultado fue Time(sec): 115.530155, asi que ya tenemos el tiempo de computo serial: TcomputoSerial = 115.530155 s.



