/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 20:42:43 by ncruz-ne          #+#    #+#             */
/*   Updated: 2025/07/24 20:42:43 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
    Both options are based on the Positional Notation method
    for conversion of numbers from binary to decimal base:
    https://www.wikihow.com/Convert-from-Binary-to-Decimal
    Option 2 is also based on the method of
    Short Division by Two with Remainder
    to convert numbers from decimal base to binary base:
    https://www.wikihow.com/Convert-from-Decimal-to-Binary
*/

// OPTION 1: W/ BITWISE OPERATIONS
unsigned char	reverse_bits(unsigned char octet)
{
    unsigned char   rev_octet = 0;
    int i = 0;

    while (i < 8)
    {
        rev_octet = rev_octet * 2 + (octet >> i & 1);
        i++;
    }
    return (rev_octet);
}

// OPTION 2: WITHOUT BITWISE OPERATIONS
unsigned char	reverse_bits(unsigned char octet)
{
	unsigned char	rev_octet = 0;
	int				i = 7;

	while (i >= 0)
	{
		rev_octet = rev_octet * 2 + (octet % 2);
		octet = octet / 2;
        i--;
	}
	return (rev_octet);
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
//     print_bits(reverse_bits(2)); // = 01000000
//     write(1, "\n", 1);
//     print_bits(reverse_bits(3)); // = 11000000
//     write(1, "\n", 1);
//     print_bits(reverse_bits(10)); // = 01010000
//     write(1, "\n", 1);
//     print_bits(reverse_bits(42)); // = 01010100
//     write(1, "\n", 1);
//     print_bits(reverse_bits(0)); // = 00000000
//     write(1, "\n", 1);
//     print_bits(reverse_bits(38)); // = 01100100
//     write(1, "\n", 1);
//     return (0);
// }
