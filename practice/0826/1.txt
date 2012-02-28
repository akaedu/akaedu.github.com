#include <stdio.h>

char *find_max(char *str)
{
        char *max = str;
        while(*str)
        {
                if(*max < *str)
                        max = str;
                str++;
        }
        return max;
}

char *parse(char *str)
{
        char *max_p = find_max(str);
        char max = *max_p;
        char *tmp;
        for(tmp = max_p; tmp >= str; tmp--)
                *tmp = *(tmp - 1);
        *str = max;
        return str;
}

int main(int argc, const char *argv[])
{
        char buf[100] = "chyab";
        printf("%s\n", parse(buf));
        return 0;
}
