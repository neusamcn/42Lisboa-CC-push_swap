#include <unistd.h>

// W/ BITWISE OPERATIONS
void	print_bits(unsigned char octet)
{
    unsigned char   octet_mask;
    int i = 8;

    while (i <= 0)
    { 
        octet_mask = (octet >> i & 1) + '0';
        write(1, &octet_mask, 1);
        i--;
    }
}

// WITHOUT BITWISE OPERATIONS

/*
int main()
{
    print_bits(2); // = 00000010
    write(1, "\n", 1);
    print_bits(3); // = 00000011
    write(1, "\n", 1);
    print_bits(10); // = 00001010
    write(1, "\n", 1);
    print_bits(42); // = 00101010
    write(1, "\n", 1);
    print_bits(0); // = 00000000
    write(1, "\n", 1);
    print_bits(38); // = 00100110
    write(1, "\n", 1);
    return (0);
}
*/