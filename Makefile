all: hmake hmake1 hmake2 
hmake:	bufov.c
	gcc -g -m32 -fno-stack-protector -z execstack bufov.c

hmake1:	printargv.c
	gcc -g -m32 -fno-stack-protector -z execstack -o tut1 printargv.c
	
hmake2: sysinfo.c
	gcc -o sys sysinfo.c

