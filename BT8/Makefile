CC = g++
CFLAGS = -Wall -g

# -Wall: This flag enables a variety of warning messages during compilation, helping you catch potential issues in your code.
# -g: This flag includes debugging information in the compiled binary, which is useful for debugging your code with tools like gdb.

OUTPUT = main
OBJECT = main.o Student.o LibraryCard.o LibraryMS.o
MAIN = main.cpp Student.h LibraryCard.h LibraryMS.h
STUDENT = Student.cpp Student.h
LIBRARYCARD = LibraryCard.cpp LibraryCard.h
LIBRARYMS = LibraryMS.cpp LibraryMS.h
 
main: $(OBJECT)
	$(CC) $(CFLAGS) -o $(OUTPUT) $(OBJECT)
 
main.o: $(MAIN)
	$(CC) $(CFLAGS) -c $(MAIN)
 
Student.o: $(STUDENT)
	$(CC) $(CFLAGS) -c $(STUDENT)
 
LibraryCard.o: $(LIBRARYCARD)
	$(CC) $(CFLAGS) -c $(LIBRARYCARD)	

LibraryMS.o: $(LIBRARYMS)
	$(CC) $(CFLAGS) -c $(LIBRARYMS)
clean:
	rm $(OBJECT)