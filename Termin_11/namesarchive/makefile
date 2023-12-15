namesarchive: main.o libstringbst.so namesarchive.o
		gcc -Wall -o namesarchive main.o namesarchive.o libstringbst.so

main.o: main.c
		gcc -c -Wall main.c

namesarchive.o: namesarchive.c namesarchive.h
		gcc -c -Wall namesarchive.c

stringbst.o: ../../Termin_10/stringbst.c ../../Termin_10/stringbst.h
		gcc -c -Wall ../../Termin_10/stringbst.c

libstringbst.so: stringbst.o
		gcc -shared -o libstringbst.so stringbst.o
		
clean:
#		del /f namesarchive.exe *.o *.so
#       Comment line above and uncomment line below for UNIX systems
		rm -f namesarchive *.o *.so