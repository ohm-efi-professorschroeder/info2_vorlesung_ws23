bmp: main.o libbmp.so
		gcc -Wall -o bmp main.o libbmp.so
		
main.o: main.c
		gcc -c -Wall main.c
		
bmp.o: bmp.c bmp.h
		gcc -c -Wall bmp.c
		
libbmp.so: bmp.o
		gcc -shared -o libbmp.so bmp.o
		
clean:
#		del /f bmp.exe *.o *.so
#       Comment line above and uncomment line below for UNIX systems
		rm -f bmp *.o *.so