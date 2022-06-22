# RSA-KEY-GENERATOR
El en presente algoritmo hice uso de varios otros algoritmos visto en el curso, un ejemplo seria el modulo, el cual es usado por la funcion expmod, la cual en el texto es visto por todo los otros algoritmo como el de Miller Rabin, el EScompuesto.
Para crear a los primos se uso el RANDOMGEN PRIMOS un algoritmo basado en Miller Rabin, el EScompuesto.
Luego de crear a los 2 primos los mismos se inicializan en la variables p y q.
Para confirmar que son primos se realiza otro test de miller rabin a las 2 variables.
Luego de eso, las variables se multiplican y se le pone el valor a la variable n.
Usamos la funcion φ de Euler en n.
Todo esto para utilizarlo en e.
Primero genere un numero al azar entre 2 y n-1.
Luego confirmo con el bucle si es coprimo con phi(n).
Si no es coprimo, se genera otro número hasta encontrar uno que lo sea.
Para sacar a d se usa el exponente -1 en e.
Ya que e.d=1.
Y 1 es congruente con cualquier base.
