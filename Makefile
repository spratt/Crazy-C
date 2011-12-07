CFLAGS = -g

APP1 = 	test_crazy
APP2 =	test_crazy2

APPS = ${APP1} ${APP2}

all: ${APPS}

${APP1}: ${APP1}.c

${APP2}: ${APP2}.c

run:
	@./${APP1}
	@./${APP2}

clean:
	rm -f ${APPS}
