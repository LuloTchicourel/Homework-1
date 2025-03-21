Para compilar:
g++ -std=c++14 compare.cpp  -Wall -g -o compare

Para ejecutar:
./compare

NOTAS:
Sin constexpr:
Comparing text1 and text2: 1 (Execution time: 916 ns)
Comparing text1 and text3: 0 (Execution time: 208 ns)

Con constexpr:
Comparing text1 and text2: 1 (Execution time: 83 ns)
Comparing text1 and text3: 0 (Execution time: 42 ns)

Explicacion:
Con constexpr, la comparación se evalúa en tiempo de compilación, eliminando la recursión en la ejecución del programa.
Sin constexpr, la función se ejecuta en tiempo de ejecución, procesando cada carácter de forma recursiva, lo que aumenta el tiempo de ejecución.

Basicamente el tiempo de ejecucion baja porque uno opera fuera de este mientras el otro no.