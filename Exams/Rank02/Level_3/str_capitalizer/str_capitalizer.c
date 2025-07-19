#include <unistd.h>

int main(int ac, char **av)
{
    int row = 1;
    int col;
    if (ac > 1)
    {
        while (row <= ac)
        {
            col = 0;
            while (av[row][col] && av[row][col] != '\0')
            {
                // Capitalizing words:   
                if (av[row][col] >= 'a' && av[row][col] <= 'z')
                {
                    if (col == 0 || av[row][col - 1] == ' ' ||
                    (av[row][col - 1] >= '\t' && av[row][col - 1] <= 'r'))
                    {
                        av[row][col] = av[row][col] - 32;
                        write(1, &av[row][col], 1);
                        col++;
                    }
                }
                // Everything other char
                else if (av[row][col] >= 'A' && av[row][col] <= 'Z')
                {
                    if (!(col == 0 || av[row][col - 1] == ' ' ||
                    (av[row][col - 1] >= '\t' && av[row][col - 1] <= 'r')))
                    {
                        av[row][col] = av[row][col] + 32;
                        write(1, &av[row][col], 1);
                        col++;
                    }
                }
                col++;
            }
            row++;
        }
        write(1, "\n", 1);
    }
    write(1, "\n", 1);
    return (0);
}
/*
tasks for each row:
capitalizes the first letter of each word
puts the rest in lowercase

word:
isspace
start and end of string
only 1 letter
*/