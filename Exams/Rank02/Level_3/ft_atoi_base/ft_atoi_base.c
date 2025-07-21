#include <stdio.h>

int	ft_atoi_base(const char *str, int str_base)
{
    char    *base_max16 = "0123456789abcdef";
    int base_10 = 0;
    int sign = 1;
    int i_bmax16 = 0;
    int i_str = 0;

    // Recognize uppercase letters in str:
    while (str[i_str] && str[i_str] != '\0')
    {
        if (str[i_str] >= 'A' && str[i_str] <= 'Z')
            base_max16 = "0123456789ABCDEF";
        // Check for negative number:
        if (str[i_str] == '-')
        {
            sign = -1;
            i_str++;
        }
        // Return 0 for unrecognized char:
        if ((str_base < 1 || str_base > 16)
        || !((str[i_str] >= '0' && str[i_str] <= '9')
        || (str[i_str] >= 'A' && str[i_str] <= 'F')
        || (str[i_str] >= 'a' && str[i_str] <= 'f')))
            return (0);
        i_str++;
    }
    if (sign == -1)
        i_str = 1;
    else
        i_str = 0;
    while (str[i_str] && str[i_str] != '\0')
    {
        i_bmax16 = 0;
        while (base_max16[i_bmax16] && base_max16[i_bmax16] != '\0'
                && i_bmax16 < str_base)
        {
            if (str[i_str] == base_max16[i_bmax16])
            {
                base_10 += i_bmax16;
                i_bmax16 = 0;
                break;
            }
            i_bmax16++;
        }
        if (str[i_str + 1] != '\0')
        base_10 += str_base - 1;
        i_str++;
    }
    return (base_10 * sign);
}
// // FOR TESTING ONLY:
// int main()
// {
//     printf("%d", ft_atoi_base("11", 4));
//     if (ft_atoi_base("11", 4) == 5)
//         printf(" ---> OK\n");
//     else
//         printf(" ---> NOK\n");
//     printf("%d", ft_atoi_base("B", 16));
//     if (ft_atoi_base("B", 16) == 11)
//         printf(" ---> OK\n");
//     else
//         printf(" ---> NOK\n");
//     printf("%d", ft_atoi_base("b", 16));
//     if (ft_atoi_base("b", 16) == 11)
//         printf(" ---> OK\n");
//     else
//         printf(" ---> NOK\n");
//     printf("%d", ft_atoi_base("10", 16));
//     if (ft_atoi_base("10", 16) == 16)
//         printf(" ---> OK\n");
//     else
//         printf(" ---> NOK\n");
//     printf("%d", ft_atoi_base("0", 7));
//     if (ft_atoi_base("0", 7) == 0)
//         printf(" ---> OK\n");
//     else
//         printf(" ---> NOK\n");
//     printf("%d", ft_atoi_base("-11", 4));
//     if (ft_atoi_base("-11", 4) == -5)
//         printf(" ---> OK\n");
//     else
//         printf(" ---> NOK\n");
//     printf("%d", ft_atoi_base("5", 0));
//     if (ft_atoi_base("5", 0) == 0)
//         printf(" ---> OK\n");
//     else
//         printf(" ---> NOK\n");
//     printf("%d", ft_atoi_base("-7", -1));
//     if (ft_atoi_base("-7", -1) == 0)
//         printf(" ---> OK\n");
//     else
//         printf(" ---> NOK\n");
//     printf("%d", ft_atoi_base(" A", 13));
//     if (ft_atoi_base(" A", 13) == 0)
//         printf(" ---> OK\n");
//     else
//         printf(" ---> NOK\n");
//     return(0);
// }