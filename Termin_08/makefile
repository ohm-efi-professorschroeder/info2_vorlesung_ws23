namesarchive: main.o libnamesarchive.so
		gcc -Wall -o namesarchive main.o libnamesarchive.so
		
main.o: main.c
		gcc -c -Wall main.c
		
namesarchive.o: namesarchive.c namesarchive.h
		gcc -c -Wall namesarchive.c
		
libnamesarchive.so: namesarchive.o
		gcc -shared -o libnamesarchive.so namesarchive.o
		
clean:
		del /f namesarchive.exe *.o *.so
#       Comment line above and uncomment line below for UNIX systems
#       rm -f namesarchive *.o *.so