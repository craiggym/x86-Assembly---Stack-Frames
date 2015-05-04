nasm -f elf64 findframe.asm -o Output_Files/ff.o
g++ -m64 -Wall c1.cpp -c -o Output_Files/c1.o
g++ -m64 -Wall c2.cpp -c -o Output_Files/c2.o
g++ -m64 -Wall c3.cpp -c -o Output_Files/c3.o
g++ -m64 -Wall c4.cpp -c -o Output_Files/c4.o
g++ -m64 -Wall c5.cpp -c -o Output_Files/c5.o
g++ -m64 -Wall debug.o Output_Files/ff.o Output_Files/c1.o Output_Files/c2.o Output_Files/c3.o Output_Files/c4.o Output_Files/c5.o -o Output_Files/exec.out
./Output_Files/exec.out
