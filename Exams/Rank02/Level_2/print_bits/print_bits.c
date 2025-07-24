/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 20:42:07 by ncruz-ne          #+#    #+#             */
/*   Updated: 2025/07/24 20:42:07 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

// W/ BITWISE OPERATIONS
void	print_bits(unsigned char octet)
{
	unsigned char bit_mask;
	int i = 7;

	while (i >= 0)
	{
		bit_mask = (octet >> i & 1) + '0';
		write(1, &bit_mask, 1);
		i--;
	}
}

// WITHOUT BITWISE OPERATORS
void	print_bits(unsigned char octet)
{
	char bin_bits[] = "00000000";
	int max_index;

	max_index = 7;
	while (max_index >= 0 && octet > 0)
	{
		bin_bits[max_index] = (octet % 2) + '0';
		octet = octet / 2;
		max_index--;
	}
	write(1, &bin_bits, 8);
}
/*
	octet >> i
Allows to shift all bits of this octet/byte to the right,
shifting all bits 'i' positions at a time,
starting by making a right shift
that places the provided octet's 1st bit in the last bit's position
and ending with the last bit in the provided octet's original position.

	octet & 1 + '0'
To be able to use write() to return this unsigned CHAR octet in binary
(only chars '0' and '1'), it's necessary to
transform the representation of the octet
from a SINGLE UNSIGNED CHAR to EIGHT CHAR THAT CAN ONLY BE '0' OR '1'.
How to solve this:
By using the bitwise 'AND' operator,
the 2 bytes provided on each side of the '&'
will have each of their bits compared at equivalent place values.
If both bits from the 2 bytes/octets
at equivalent place values
are equal to 1,
then the result of the AND operation will be 1,
otherwise it will be 0.
Thus, by comparing the provided octet to (decimal) '1' (binary => 00000001),
the provided octet's LSB (Least Significant Bit = rightmost bit)
will be revealed, since the resulting octet of this operation can be either
00000001 => 1 (decimal) or 00000000 => 0 (decimal).
This means it's possible to
write() each bit of the octet
by iterating on the LSB position,
where they're revealed.
*/

// WITHOUT BITWISE OPERATIONS

/*
int	main(void)
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
