Para compilar:
g++ -std=c++11 list.cpp -Wall -g -o list

Para correr:
./list

Perdida de memoria
Para asegurarme que no pierda memoria, corri el ejecutable con:
leaks -atExit -- ./list
Esta funcion de Mac permite ver si hay leaks en un ejecutable. 
El output de este comando fue el siguiente:

leaks Report Version: 4.0, multi-line stacks
Process 7835: 186 nodes malloced for 14 KB
Process 7835: 0 leaks for 0 total leaked bytes.

Lo que significa que no hubieron leaks en el programa.
No use Valgrind debido a la incompatibilidad con Mac OS