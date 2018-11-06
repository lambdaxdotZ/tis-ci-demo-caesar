SHELL := /bin/bash

.PHONY: all
all:
	@echo -e "\\x1b[00;36mgcc -I. src/caesar.c src/gen_test.c test_01.c && ./a.out\\x1b[00m"
	@gcc -Isrc src/caesar.c src/gen_test.c test_01.c && ./a.out

.PHONY: clean
clean:
	rm -rf a.out a.out.dSYM *.gcov *.gcda *.gcno
