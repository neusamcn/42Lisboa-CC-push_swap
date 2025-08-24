/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 22:11:04 by ncruz-ne          #+#    #+#             */
/*   Updated: 2025/08/11 15:54:24 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_printf_ptr(void *ptr)
{
	if (ptr == NULL)
		return (ft_putstr_fd_len("(nil)", 1));
	return (ft_putstr_fd_len("0x", 1) + ft_printf_hex((size_t)ptr, 0, 'x'));
}
