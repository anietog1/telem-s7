## 1. ¿CUAL ES LA PROBLEMÁTICA QUE QUIERE RESOLVER?
Se solicitó la creación de un API REST que recibiera los datos de temperatura, humedad y localización al que se pudiera acceder con un API key o JWT

## 2. ¿CUALES SON LOS REQUISITOS FUNCIONALES DE LA APP?
El sistema debe permitir al usuario registrarse y obtener una api key que le permite acceder a los servicios
El sistema debe permitir al usuario enviar datos vía POST que se almacenarán en la base de datos
El sistema debe permitir al usuario visualizar los datos por medio de un navegador ingresando con usuario y contraseña

## 3. ¿CUALES SON LOS REQUISITOS NO FUNCIONALES DE LA APP?
Ya que el sistema está planeado para IoT, se debe permitir alrededor de 20 POST por segundo sin sacrificar rendimiento
El sistema debe soportar 3 GET por segundo
Permitir que solo los usuarios autenticados o autorizados hagan POST o lean los datos de la aplicación

## 4. ¿QUÉ TECNOLOGÍA DE DESARROLLO UTILIZÓ?
### 4.1 EN EL BACKEND?
Express para el servidor y el enrutamiento; con Nodejs y algunos middleware como morgan para debuggear los mensajes del servidor. También se usó mongodb para almacenar los datos con mongoose

### 4.2 EN EL FRONTEND?
React para el frontend y Babel como “compilador” de javascript. No hago uso de ninguna hoja de estilo

## 5. ¿CUALES SON Y CUAL ES LA ESPECIFICACIÓN DE LOS SERVICIOS API REST DEL BACKEND?

POST /samples/new con un json permite la creación de un registro
GET /samples retorna todos los registros

## 6. ¿CÓMO REALIZÓ LA AUTENTICACIÓN DE LOS SERVICIOS API REST?

No la he hecho

## 7. ¿CUALES SON LAS PRINCIPALES DIFICULTADES QUE TUVO AL DESARROLLAR EL PROYECTO?

Me inscribí a la pycon y me quedé sin tiempo alrededor de la deadline

### 7.1 POR DESCONOCIMIENTO DE LA TECNOLOGÍA?

Sabía cómo funcionaban las API Rest pero no cómo se integraba eso con un sistema de frontend como React que lo separa totalmente del backend. Desconocía el funcionamiento de las API Key, JWT y sistemas de autenticación y autorización en general.

### 7.2 ¿QUÉ CONCEPTOS O FUNDAMENTOS NO SABE PARA PODER DESARROLLAR ESTE PROYECTO?
Cómo funcionan los sistemas de autenticación. También requiero más conocimientos en arquitectura y diseño de aplicaciones web y uso de las tecnologías como react para tomar decisiones más fácilmente al desarrollar

### 7.3 ¿QUÉ HABILIDADES DE DESARROLLO LE FALTAN PARA PODER TERMINAR EL PROYECTO?
Capacidad de documentarme rápido y generar avances en el desarrollo de una aplicación o proyecto durante intervalos de tiempo cortos. Me pasaba que me sentaba 30min frente a la computadora pero no hacía nada porque necesitaba realmente 3h como para empezar a ser efectivo. En cuanto a telemática me falta conocimiento de las tecnologías que se utilizan y los mecanismos de comunicación, sincronización y cosas como hacer páginas dinámicas

### 7.4 ¿QUÉ OTRAS COSAS LE FALTÓ PARA PODER DESARROLLAR EL PROYECTO 1?
No tengo aún el sistema de autenticación que quisiera que sea tipo API Key debido a que la idea es que sea una aplicación IOT y creo que sería lo más apropiado

## 8. ¿CUALES FUERON LOS PRINCIPALES APRENDIZAJES DEL PROYECTO 1?
Fue un descubrimiento brutal la separación que hacen entre frontend y backend; yo conocía solamente los sistemas en los que se embebía código en el html como ejs. También
