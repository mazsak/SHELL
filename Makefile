n = main.o divide.o execute.o



run: $(n)
	gcc $(n) -o myshell

clean:
	rm -f *.o*
	rm myshell
