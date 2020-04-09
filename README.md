# Bigdata

## Problema

Decidí resolver el siguiente problema:

Se tiene un conjunto de acciones de la bolsa, en la cual se reporta a diario el valor promedio por acción, la estructura de los datos es (archivo: dataempresas.csv):

    company,price,date
    exito,77.5,2015-01-01
    EPM,23,2015-01-01
    exito,80,2015-01-02
    EPM,22,2015-01-02
    ...

Realizar un programa en Map/Reduce, con hadoop en Python, que permita calcular:

1. Por acción, dia-menor-valor, día-mayor-valor.
2. Listado de acciones que siempre han subido o se mantienen estables.
3. DIA NEGRO: Saque el día en el que la mayor cantidad de acciones tienen el menor valor de acción (DESPLOME), suponga una inflación independiente del tiempo.

## Programas

### Localmente

Para correr los programas es simplemente:

    $ ./accion-min-max.py dataempresas.csv
    $ ./siempre-subiendo.py dataempresas.csv
    $ ./dia-negro.py dataempresas.csv

También está la siguiente alternativa:

    $ ./run_locally dia-negro.py # reemplazar dia-negro.py con el programa deseado

### EMR

Para ejecutarlos en EMR:

1. Actualizar las credenciales y la región del bucket S3 en el archivo `mrjob.conf`.
1. Ejecutar el siguiente comando:

````
$ ./run_in_emr siempre-subiendo.py # reemplazar siempre-subiendo.py con el programa deseado
````

## Outputs

Los programas generan los siguientes outputs:

### Día min-max

Genera un output que indica:

    [(compañía, (día min, día max))]

Donde `compañía` es el nombre de la compañía, `día min` es el día de mínimo precio en el mercado y `día max` es el día de mayor precio en el mercado.

### Siempre subiendo

Genera un output que indica:

    [(compañía, siempre subiendo)]

Donde `compañía` es el nombre de la compañía, `siempre subiendo` es un `boolean` que indica si siempre está subiendo o no la compañía específica.

### Día negro

Genera un output que indica:

    [(fecha, conteo)]

Donde `fecha` es una fecha en particular y `conteo` indica cuántas empresas tienen su mínimo en la fecha `fecha`.
