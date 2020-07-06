# 
#  Name: Marcus Robertson-Jones
#  Matric No: 150010807
#  Module No: AC21008
#
CFLAGS = -Wall -Wextra -pedantic

fm:
	cc -Wall -g frame_manager.c -o frame_manager

compileFrame:
	 gcc -Wall frame_manager.c -o frame_manager.o -c
	 gcc -Wall frame_tester.c -o frame_tester.o -c
	 gcc -o test frame_tester.o frame_manager.o

compileStack:
	gcc -Wall frame_manager.c -o frame_manager.o -c
	gcc -Wall stack.c -o stack.o -c
	gcc -Wall stack_tester.c -o stack_tester.o -c
	gcc -o stack stack.o stack_tester.o frame_manager.o


