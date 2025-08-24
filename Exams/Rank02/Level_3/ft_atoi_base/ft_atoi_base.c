/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 20:37:11 by ncruz-ne          #+#    #+#             */
/*   Updated: 2025/07/24 20:37:32 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi_base(const char *str, int str_base)
{
	int	result_base10;
	int	sign;
	int	char2int;
	int	i_str;

	result_base10 = 0;
	sign = 1;
	char2int = 0;
	i_str = 0;
	// Recognize '-' at index 0 and recognize valid letters in rest of str:
	while (str[i_str] && str[i_str] != '\0')
	{
		// Check for negative number:
		if (str[i_str] == '-')
		{
			sign = -1;
			i_str++;
		}
		// Return 0 for unrecognized char:
		if ((str_base < 1 || str_base > 16) || !((str[i_str] >= '0'
					&& str[i_str] <= '9') || (str[i_str] >= 'A'
					&& str[i_str] <= 'F') || (str[i_str] >= 'a'
					&& str[i_str] <= 'f')))
			return (0);
		i_str++;
	}
	// Start on the correct index:
	if (sign == -1)
		i_str = 1;
	else
		i_str = 0;
	// Convert nb from str_base to decimal base:
	while (str[i_str] && str[i_str] != '\0')
	{
		// Convert chars 'A'/'a' to 'F'/'f' and numeric chars to int:
		if (str[i_str] == 'A' || str[i_str] == 'a')
			char2int = 10;
		else if (str[i_str] == 'B' || str[i_str] == 'b')
			char2int = 11;
		else if (str[i_str] == 'C' || str[i_str] == 'c')
			char2int = 12;
		else if (str[i_str] == 'D' || str[i_str] == 'd')
			char2int = 13;
		else if (str[i_str] == 'E' || str[i_str] == 'e')
			char2int = 14;
		else if (str[i_str] == 'F' || str[i_str] == 'f')
			char2int = 15;
		else
			char2int = str[i_str] - '0';
		// Convert to decimal base:
		if (char2int < str_base)
		{
			result_base10 = result_base10 * str_base + char2int;
			i_str++;
		}
		else
			return (0);
	}
	return (result_base10 * sign);
}
// // FOR TESTING ONLY:
// #include <stdio.h>
// #include <limits.h>

// int main()
// {
//     printf("%d", ft_atoi_base("11", 4));
//     if (ft_atoi_base("11", 4) == 5)
//         printf(" ---> Test 1 OK\n");
//     else
//         printf(" ---> Test 1 NOK\n");
//     printf("%d", ft_atoi_base("B", 16));
//     if (ft_atoi_base("B", 16) == 11)
//         printf(" ---> Test 2 OK\n");
//     else
//         printf(" ---> Test 2 NOK\n");
//     printf("%d", ft_atoi_base("b", 16));
//     if (ft_atoi_base("b", 16) == 11)
//         printf(" ---> Test 3 OK\n");
//     else
//         printf(" ---> Test 3 NOK\n");
//     printf("%d", ft_atoi_base("10", 16));
//     if (ft_atoi_base("10", 16) == 16)
//         printf(" ---> Test 4 OK\n");
//     else
//         printf(" ---> Test 4 NOK\n");
//     printf("%d", ft_atoi_base("0", 7));
//     if (ft_atoi_base("0", 7) == 0)
//         printf(" ---> Test 5 OK\n");
//     else
//         printf(" ---> Test 5 NOK\n");
//     printf("%d", ft_atoi_base("-11", 4));
//     if (ft_atoi_base("-11", 4) == -5)
//         printf(" ---> Test 6 OK\n");
//     else
//         printf(" ---> Test 6 NOK\n");
//     printf("%d", ft_atoi_base("5", 0));
//     if (ft_atoi_base("5", 0) == 0)
//         printf(" ---> Test 7 OK\n");
//     else
//         printf(" ---> Test 7 NOK\n");
//     printf("%d", ft_atoi_base("-7", -1));
//     if (ft_atoi_base("-7", -1) == 0)
//         printf(" ---> Test 8 OK\n");
//     else
//         printf(" ---> Test 8 NOK\n");
//     printf("%d", ft_atoi_base(" A", 13));
//     if (ft_atoi_base(" A", 13) == 0)
//         printf(" ---> Test 9 OK\n");
//     else
//         printf(" ---> Test 9 NOK\n");
//     printf("%d", ft_atoi_base("101010", 2));
//     if (ft_atoi_base("101010", 2) == 42)
//         printf(" ---> Test 10 OK\n");
//     else
//         printf(" ---> Test 10 NOK\n");
//     printf("%d", ft_atoi_base("-101010", 2));
//     if (ft_atoi_base("-101010", 2) == -42)
//         printf(" ---> Test 11 OK\n");
//     else
//         printf(" ---> Test 11 NOK\n");
//     printf("%d", ft_atoi_base("2147483647", 10));
//     if (ft_atoi_base("2147483647", 10) == INT_MAX)
//         printf(" ---> Test 12 OK\n");
//     else
//         printf(" ---> Test 12 NOK\n");
//     printf("%d", ft_atoi_base("-2147483648", 10));
//     if (ft_atoi_base("-2147483648", 10) == INT_MIN)
//         printf(" ---> Test 13 OK\n");
//     else
//         printf(" ---> Test 13 NOK\n");
//     printf("%d", ft_atoi_base("5", 3));
//     if (ft_atoi_base("5", 3) == 0)
//         printf(" ---> Test 13 OK\n");
//     else
//         printf(" ---> Test 13 NOK\n");
//     return(0);
// }
