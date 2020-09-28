project1: tokenizer.o history.o simpleUI.o
	gcc -o project1 tokenize.o history.o simpleUI.o

tokenizer.o: tokenizer.c tokenizer.h

history.o: history.c history.h

simpleUI.o: simpleUI.c tokenizer.h history.h

clean:
	rm -f *.o project1
