#! /bin/bash

cc -Wall -Werror -Wextra ../srcs/main.c -o compilation_test.out && \
	rm compilation_test.out && echo OK || echo Error
