# TC1031.602 - Programación de estructuras de datos y algoritmos fundamentales - Evidencia
Autor: Juan Pablo Chávez
Matrícula: A01705408

## Video de funcionamiento en Windows
- https://youtu.be/BoC6RJUqMUQ
## CONSIDERACIONES
- Al terminar de calificar, puede irse a "Ajustes" y notará la opción de borrar todos los datos. NO borrar datos antes de terminar su uso.
- Al compilar, el programa muestra un warning en Ubuntu, no afecta en el programa y es algo exclusivo de Ubuntu/Linux.
- El programa es sensible al input del usuario, favor de intentar insertar datos de forma correcta.

## Funcionalidad
Este programa se asemeja al inventario de un videojuego, como Pokemon Legends Arceus, entre otros títulos, en donde puedes evidentemente guardar más objetos, ordenarlo según un criterio y puedes mostrarlo de manera ascendente y descendente, además de buscar, filtrar y eliminar todos los datos.
## Correcciones
Existieron miles de correcciones, desde cambios en la estructura de datos (de vector a lista doblemente ligada), hasta cambios en el sort que se usaría, pero mayormente las correcciones surgieron por problemas al eliminar alguna parte del programa. Al cambiar de estructura de datos, mi código quedó obsoleto, como consecuencia tuve que volver a implementarlo todo.
## Competencias
### SICT0301 - Evaluación del problema
### Hace un análisis de complejidad correcto y completo para los algoritmos de ordenamiento usados en el programa.
Se utilizaron 3 algoritmos, los tres utilizan la misma estructura:
- sortQuant() : O(n^2) = Los bucles anidados comparan y cambian los elementos adyascentes hasta que se ordene la lista
- sortAlfabetic() : O(n^2) = Los bucles anidados comparan y cambian los elementos adyascentes hasta que se ordene la lista
- sortPriority() : O(n^2) = Los bucles anidados comparan y cambian los elementos adyascentes hasta que se ordene la lista 
#### Hace un análisis de complejidad correcto y completo todas las estructuras de datos y cada uno de sus usos en el programa
Existen 6 métodos que utiliza la lista doblemente ligada:
- add() : O(1) = la actualización de apuntadores y enlace de la lista se ejecuta en un tiempo constante.
- searchName() : O(n) = Debe recorrer toda la lista para asegurarnos de que exista o no el elemento.
- print() y printContrario() : O(n) = Al igual que el search, debe recorrer toda la lista, así imprimiendola.
- filterType() : O(n) = Debe recorrer toda la lista para mostrar los elementos que cumplan con el tipo de objeto.
#### Hace un análisis de complejidad correcto y completo para todos los demás componentes del programa y determina la complejidad final del programa.
- ifstream y ofstream : O(n) = n sería el número de elementos en el archivo, y ya que debe de extraerlos a todos, debe de recorrer de forma lineal.
- Menú : O(1) = La cantidad de opciones que se pueden tener son constantes
- Complejidad Total : O(n^2) = A raíz de nuestros sorts

### SICT0302 - Toma de decisiones
### Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente.
- Utilicé el bubblesort debido a que primero, es el más fácil de implementar, segundo porque al tener que intercambiar apuntadores, considero que intentar ir por algo más ambisioso podría generar una mayor cantidad de problemas.
### Selecciona una estructura de datos adecuada al problema y lo usa correctamente.
- Utilicé la lista doblemente ligada para que pudiera imprimir en ambos sentidos, es decir no tendría que ejecutar más de una vez el algoritmo de ordenamiento para poder mostrar la información de valores ascendentes a descendentes y de la forma contraria, de descendentes a ascendentes. Además de que se me hizo una estructura de datos muy útil.

### SICT0303 - Implementación de acciones
### Implementa mecanismos para consultar información de las estructras correctos
- Existen 2 funciones en el programa, searchName(string) y filterType(int) que en realidad pude haber llamado igual pero al asemejarse a un filtro, no moví los nombres. searchName(string) al ser llamada recorre el arreglo comparando el valor asignado como parámetro y los atributos de los diferentes objetos. Por otro lado, filterType(int) recorre la lista buscando todos los objetos con el tipo especificado por el parámetro y las variables miembro del objeto.
### Implementa mecanismos de lectura de archivos para cargar datos a las estructuras de manera correcta
- Se utiliza la libreria <fstream> o "File stream", cuyo propósito es permitirnos utilizar archivos, tanto de input como output, dependiendo de lo que busquemos. Importe el archivo "Archivo.txt" para extraer los objetos.
### Implementa mecanismos de escritura de archivos para guardar los datos  de las estructuras de manera correcta
- Se utiliza ofstream o Output File stream para poder generar o editar un archivo, y al agregar el siguiente parámetro "std::ios::app" nos aseguramos que no se borre accidentalmente el archivo.

