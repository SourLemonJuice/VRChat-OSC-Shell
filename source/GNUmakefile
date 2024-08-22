CC := /usr/bin/clang
Clang_Flag += -I./
Clang_Flag += -I./library/
Clang_Flag += -g

exec_name := vrchat-osc

source += main.c
source += library/tinyosc/tinyosc.c

.PHONY += default

default: ${exec_name}

${exec_name}: ${source}
	${CC} ${source} \
		--output ${exec_name} \
		${Clang_Flag}
