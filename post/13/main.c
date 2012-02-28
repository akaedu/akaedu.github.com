#include <stdio.h>
const int A = 10;
int a = 20;
static int b = 30;
int c;

int main(int argc, const char *argv[])
{
        static int a = 40;
        char b[] = "Hello world";
        register int c = 50;

        a = 10;
        printf("Hello world %d\n", c);

        return 0;
}
