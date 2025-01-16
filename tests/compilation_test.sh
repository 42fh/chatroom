#! /bin/bash

echo $1

cc -Wall -Werror -Wextra $1 -o compilation_test.out && \
	rm compilation_test.out && echo OK || echo Error
