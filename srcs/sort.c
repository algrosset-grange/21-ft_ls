/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printsort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 20:59:44 by agrosset          #+#    #+#             */
/*   Updated: 2017/11/28 17:43:16 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftls.h"

void	sort_lst(t_list **list, t_flags *toggle, char *dir,
	int (*cmp)(char *content1, char *content2, t_flags *toggle, char *dir))
{
	t_list *maillon;

	toggle->count = 1;
	while (toggle->count && (maillon = *list))
	{
		toggle->count = 0;
		while (maillon && maillon->next)
		{
			if (cmp((char *)((maillon)->content),
				(char *)((maillon->next)->content), toggle, dir))
			{
				toggle->count = 1;
				ft_lstswap(&maillon);
			}
			maillon = maillon->next;
		}
	}
}
