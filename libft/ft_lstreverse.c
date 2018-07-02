/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstreverse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 11:58:27 by agrosset          #+#    #+#             */
/*   Updated: 2015/12/03 13:13:41 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstreverse(t_list **alst)
{
	t_list	*tmp;
	t_list	*next;
	t_list	*reverse;

	if (alst == NULL)
		return ;
	reverse = NULL;
	tmp = *alst;
	while (tmp != NULL)
	{
		next = tmp->next;
		ft_lstadd(&reverse, tmp);
		tmp = next;
	}
	*alst = reverse;
}
