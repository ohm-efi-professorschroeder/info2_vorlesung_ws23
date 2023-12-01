namesarchive: main.o libstringlist.so namesarchive.o
		gcc -Wall -o namesarchive main.o namesarchive.o libstringlist.so
		
main.o: main.c
		gcc -c -Wall main.c

namesarchive.o: namesarchive.c namesarchive.h
		gcc -c -Wall namesarchive.c
		
stringlist.o: stringlist.c stringlist.h
		gcc -c -Wall stringlist.c
		
libstringlist.so: stringlist.o
		gcc -shared -o libstringlist.so stringlist.o
		
clean:
#		del /f namesarchive.exe *.o *.so
#       Comment line above and uncomment line below for UNIX systems
		rm -f namesarchive *.o *.so