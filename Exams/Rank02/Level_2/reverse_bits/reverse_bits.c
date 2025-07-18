#include <unistd.h>

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

// W/ BITWISE OPERATIONS
unsigned char	reverse_bits(unsigned char octet)
{
    unsigned char   rev_octet = 0;
    int i = 0;

    while (i <= 8)
    {
        rev_octet = rev_octet << i;
        rev_octet = (octet >> i & 1) + '0';
        i++;
    }
    return (rev_octet);
}

// WITHOUT BITWISE OPERATIONS
unsigned char	reverse_bits(unsigned char octet)
{

}

int main()
{
    print_bits(reverse_bits(2)); // = 01000000
    write(1, "\n", 1);
    print_bits(reverse_bits(3)); // = 11000000
    write(1, "\n", 1);
    print_bits(reverse_bits(10)); // = 01010000
    write(1, "\n", 1);
    print_bits(reverse_bits(42)); // = 01010100
    write(1, "\n", 1);
    print_bits(reverse_bits(0)); // = 00000000
    write(1, "\n", 1);
    print_bits(reverse_bits(38)); // = 01100100
    write(1, "\n", 1);
    return (0);
}