all: compile

compile: compile_header
	@-cc *.o -w test.c && ./a.out
	@-rm *.o

compile_header:
	@-cc ft_print/*.c -w -c

+: compile_header+
	cc *.o test.c && ./a.out
	rm *.o

compile_header+:
	cc ft_print/*.c -c

clean:
	rm a.out
