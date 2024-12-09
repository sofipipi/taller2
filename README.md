# taller2 


integrantes:

Sofia Catalina Contreras Godoy Rut: 21.702.328-9 Correo institucional: sofia.contreras02@alumnos.ucn.cl
Luis Felipe Juárez Torres Rut: 19.950.071-6 Correo institucional: luis.juarez@alumnos.ucn.cl
Ambos PARALELO C1

Para compilar: g++ -I./include source/Tablero.cpp source/IA.cpp source/main.cpp -o TableroGato
Para Ejecutar: ./TableroGato

Instrucciones para jugar al gato en este programa:
- Debemos considerar una matriz de 3x3 y con columnas y filas que van del 0 al 2. Además 
  al poner los numeros por consola debemos hacerlo con un espacio entre estos.
  Lo cual se ve como:
       0     1     2
   0 (0 0) (0 1) (0 2)
   1 (1 0) (1 1) (1 2)
   2 (2 0) (2 1) (2 2)
- En el caso de que en la consola se escriba algo distinto arrojará movimiento inválido 
  hasta que haya uno válido.
Diagrama del árbol de juego para un caso simple:

Estado del tablero
X | O |  
---------
  | X |  
---------
  |   |  
Diagrama:
Nivel 0 (Turno de la IA - O)
                           Nodo inicial
                          (Estado actual)
                       /        |        |        \
                  (0,2)      (1,0)    (2,1)    (2,2)
                    |          |         |          |
Nivel 1 (Turno del humano - X)
              Evalúa:      Evalúa:   Podado     Podado
              (1,0)        (0,2)  
             /   \         /   \
Nivel 2 (Turno de la IA - O)
          Sigue evaluando si es relevante para el puntaje...






Explicación sobre el algoritmo utilizado:
-En este caso comenzamos con la construcción del árbol de juego, donde se genera un árbol en el cual cada nodo representa un estado del tablero, y cada rama es un posible movimiento. Al llegar a un estado terminal (victoria, empate o derrota), se asigna un puntaje, en mi caso la victoria para la IA son +10 puntos y la victoria para el humano son -10, un empate es igualado a 0. Y por último para que la ia elija su siguiente movimiento los valores de los nodos terminales se propagan hacia arriba para decidir la mejor jugada en cada nivel.

Explicación teórica del algoritmo Minimax y la poda alfa-beta:
- Minimax es un algoritmo de búsqueda en árboles que se utiliza para tomar decisiones óptimas en juegos de dos jugadores, su objetivo es maximizar la ganancia del jugador actual mientras minimiza las ganancias del oponente.
- La poda alfa-beta es una optimización del algoritmo minimax que reduce el número de nodos que se evalúan. El mejor valor encontrado para el jugador "máximo" (IA) en el camino explorado es el alpha y el mejor valor encontrado para el jugador "mínimo", que suele ser el humano, el cual en el camino explorado es el beta.
Si durante la exploración se encuentra que un nodo no puede mejorar la decisión en curso (ya sea para el jugador "máximo" o "mínimo"), se detiene la exploración de ese subárbol.

Análisis de complejidad temporal del algoritmo, antes y después de aplicar la poda:
- Antes de aplicar la poda, debido a que MINIMAX explora todos los nodos posibles, es n elevado (n)
- Luego de aplicar la poda la complejidad se reduce a n elevado (n/2). Esto a causa de que como se explico antes compara los puntajes de alfa y beta, dandose cuenta que no se puede mejorar el resultado actual y por lo tanto no vuelve a pasar por esa rama.
