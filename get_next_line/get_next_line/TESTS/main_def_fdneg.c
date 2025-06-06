/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_def_fdneg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 16:24:56 by ncruz-ne          #+#    #+#             */
/*   Updated: 2025/06/06 18:52:57 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
# include <fcntl.h>

int	main(void)
{
	char	*line;

	printf("%s\n", line = get_next_line(-1));
	if (line != NULL)
		free(line);
	printf("\n***** Next line: *****\n");
	printf("%s\n", line = get_next_line(-1));
	if (line != NULL)
		free(line);
	return (0);
}
