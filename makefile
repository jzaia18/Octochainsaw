all:
	gcc -o octochainsaw c.c

run: all
	./octochainsaw

clean:
	rm *~ octochainsaw debugo

debug:
	gcc -o debugo -g c.c
