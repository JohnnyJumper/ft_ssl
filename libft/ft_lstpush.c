/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtahirov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 15:11:11 by jtahirov          #+#    #+#             */
/*   Updated: 2017/10/07 15:20:53 by jtahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpush(t_list **list, t_list *new)
{
	t_list *current;

	current = *list;
	if (!*list)
		*list = new;
	else
	{
		while (current->next)
			current = current->next;
		current->next = new;
	}
}
