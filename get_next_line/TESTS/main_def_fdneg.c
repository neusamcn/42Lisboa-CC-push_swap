/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_def_fdneg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 16:24:56 by ncruz-ne          #+#    #+#             */
/*   Updated: 2025/07/01 17:41:27 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	char	*line;

	line = get_next_line(-1);
	if (line)
	{
		printf("\n***** Next line: *****\n%s\n", line);
		free(line);
	}
	else
		printf("\n***** Next line: *****\n(null)\n");
	line = get_next_line(-1);
	if (line)
	{
		printf("\n***** Next line: *****\n%s\n", line);
		free(line);
	}
	else
		printf("\n***** Next line: *****\n(null)\n");
	return (0);
}
