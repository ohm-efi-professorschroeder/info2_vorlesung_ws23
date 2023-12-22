santa: main.o libbst.so
		gcc -Wall -o santa.exe main.o libbst.so
		
main.o: main.c
		gcc -c -Wall main.c
		
bst.o: bst.c bst.h
		gcc -c -Wall bst.c
		
libbst.so: bst.o
		gcc -shared -o libbst.so bst.o
		
clean:
#		del /f santa.exe *.o *.so
#       Comment line above and uncomment line below for UNIX systems
		rm -f santa.exe *.o *.so