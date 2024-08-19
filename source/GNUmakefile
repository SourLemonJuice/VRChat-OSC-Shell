CC := /usr/bin/clang
Clang_Flag += -I./
Clang_Flag += -g

source += main.c
source += tinyosc/tinyosc.c

.PHONY += default

default: main.out

main.out: ${source}
	${CC} ${source} \
		--output main.out \
		${Clang_Flag}
