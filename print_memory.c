#include <unistd.h>

void    print_byte_hex(const unsigned char c)
{
    char hex[] = "0123456789abcdef";

    write(1, hex + (c / 16), 1);
    write(1, hex + (c % 16), 1);
}

void    print_row_hex(size_t remain, const unsigned char *c)
{
    size_t     i;

    i = 0;
    while (i < 16)
    {
        if (i < remain)
            print_byte_hex(*(c + i));
        else
            write(1, "  ", 2);
        i++;
        if (i % 2 == 0)
            write(1, " ", 1);
    }
}

void    print_row_ascii(size_t remain, const unsigned char *c)
{
    size_t  i;

    i = 0;
    while (i < 16 && i < remain)
    {
        if (*(c + i) < 32 || *(c + i) > 126)
            write(1, ".", 1);
        else
            write(1, c + i, 1);
        i++;
    }
}

void    print_memory(const void *addr, size_t size)
{
    size_t  i;

    i = 0;
    while (i < size)
    {
        print_row_hex(size - i, addr + i);
        print_row_ascii(size - i, addr + i);
        write(1, "\n", 1);
        i += 16;
    }
}
// int     main()
// {
//     int tab[10] = {0, 23, 150, 255, 12, 16, 42, 103};
//     char str[] = "STRONG STRINGIN' STRING!";

//     print_memory(str, sizeof(str));
//     return (0);
// }