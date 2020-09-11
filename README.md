### LRUCache

## Explicación

Para implementar el LRUCache se usaron dos estructuras de datos: un hashmap (de STL) y un Circular Linked List (Implementado propiamente).
Esto ayuda para poder usar la facilidad de movimiento de datos y también para tener la rapidez de acceso del Linked List.

## Algoritmos

# getValueFromKey()

Esta función es O(1) en tiempo de ejecución y O(1) en memoria, esto es debido a que solo se hace un acceso al hash (que es O(1)), y después se usa este valor poder conseguir mover los values para poder conseguir que el elemento que fue usado más anteriormente esté al inicio. Y solo se crea un nodo temporal en un caso particular, entonces en el peor de los casos en términos de memoria esta función es O(1).

# insertKeyValuePair()

Esta función es O(1) en tiempo de ejecución y O(1) en memoria, esto es debido a que para insertar antes de que el cache este completamente lleno se inserta usando el Linked List, es decir insert O(1). Después, tenemos que se usa el hash table para poder obtener el puntero del elemento y se usa este con el linked list para cambiar elementos de lugar.

# getMostRecentKey()

Al tener la Linked List ordenada, eso quiere decir que para poder conseguir el "Most Recent Key" solo se llama al elemento en la parte de atras del Linked List y eso hace que esta función sea O(1).
