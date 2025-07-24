/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 20:42:54 by ncruz-ne          #+#    #+#             */
/*   Updated: 2025/07/24 20:42:58 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// FOLLOW THE RED THREAD:
/* 
    Based on the Positional Notation method
    for conversion of numbers from binary to decimal base:
    https://www.wikihow.com/Convert-from-Binary-to-Decimal
    and on the method of Short Division by Two with Remainder
    to convert numbers from decimal base to binary base:
    https://www.wikihow.com/Convert-from-Decimal-to-Binary
*/
unsigned char	swap_bits(unsigned char octet)
{
    unsigned char   swap_octet = 0;
    int left_shift;
    int octet_lsb;
    
    left_shift = 3;
    while (left_shift >= 0)
    {
        octet_lsb = octet >> left_shift & 1;
        swap_octet = swap_octet * 2 + octet_lsb;
        left_shift--;
    }
    left_shift = 7;
    while (left_shift >= 4)
    {
        octet_lsb = octet >> left_shift & 1;
        swap_octet = swap_octet * 2 + octet_lsb;
        left_shift--;
    }
    return (swap_octet);
}

// OR DO THIS INSTEAD:
unsigned char	swap_bits(unsigned char octet)
{
    return (octet >> 4 | octet << 4);
}

// // FOR TESTING ONLY:
// #include <unistd.h>

// void	print_bits(unsigned char octet)
// {
//     unsigned char   bit_mask;
//     int i = 7;

//     while (i >= 0)
//     { 
//         bit_mask = (octet >> i & 1) + '0';
//         write(1, &bit_mask, 1);
//         i--;
//     }
// }

// int main()
// {
//     print_bits(swap_bits(2)); // = 00100000
//     write(1, "\n", 1);
//     if (swap_bits(2) == 32)
//         write(1, "OK\n\n", 4);
//     else
//         write(1, "NOK\n\n", 5);
//     print_bits(swap_bits(3)); // = 00110000
//     write(1, "\n", 1);
//     if (swap_bits(3) == 48)
//         write(1, "OK\n\n", 4);
//     else
//         write(1, "NOK\n\n", 5);
//     print_bits(swap_bits(10)); // = 10100000
//     write(1, "\n", 1);
//     if (swap_bits(10) == 160)
//         write(1, "OK\n\n", 4);
//     else
//         write(1, "NOK\n\n", 5);
//     print_bits(swap_bits(42)); // = 10100010
//     write(1, "\n", 1);
//     if (swap_bits(42) == 162)
//         write(1, "OK\n\n", 4);
//     else
//         write(1, "NOK\n\n", 5);
//     print_bits(swap_bits(0)); // = 00000000
//     write(1, "\n", 1);
//     if (swap_bits(0) == 0)
//         write(1, "OK\n\n", 4);
//     else
//         write(1, "NOK\n\n", 5);
//     print_bits(swap_bits(38)); // = 01100010
//     write(1, "\n", 1);
//     if (swap_bits(38) == 98)
//         write(1, "OK\n\n", 4);
//     else
//         write(1, "NOK\n\n", 5);
//     return (0);
// }