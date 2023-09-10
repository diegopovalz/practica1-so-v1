# Primera Práctica de Sistemas Operativos

Application which reads a graph from a given file and applies Dijkstra algorithm.

## Usage
First step is to compile the program using the *MakeFile* with the command:
~~~ bash 
make
~~~

Once the program is compiled, execute the binary file placed in `build/` directory and give to it, as arguments,
a file dir and a number [0-1] which means whether you will use priority queue or not.
To execute the program from the main directory just use the next command.
~~~ bash
./build/first_practice <dir> <no_queue>
~~~

To run examples of the project you can use the following command.
~~~ bash
make example1
~~~
Or
~~~ bash
make example2
~~~

