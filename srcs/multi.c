/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 20:59:44 by agrosset          #+#    #+#             */
/*   Updated: 2017/11/28 17:43:16 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftls.h"

static int	multi_flagging_lst(char **av, t_flags *toggle, t_list **search)
{
	int i;

	i = 1;
	while (av[i])
	{
		if (av[i][0] == '-' && av[i][1] != 0)
		{
			if (check_flags(av[i], toggle))
				return (0);
		}
		else
			break ;
		i++;
	}
	while (av[i])
	{
		ft_lstaddend(search,
			ft_lstnew(av[i], sizeof((void *)av[i]) * ft_strlen(av[i])));
		i++;
		toggle->exist++;
	}
	return (0);
}

int			parse_multi_lst(char **av)
{
	t_flags	*toggle;
	t_list	*search;

	toggle = ft_memalloc(sizeof(t_flags));
	toggle->exist = 0;
	search = NULL;
	multi_flagging_lst(av, toggle, &search);
	if (toggle->exist == 0)
	{
		ft_lstaddend(&search,
			ft_lstnew(".", sizeof((void *)".") * ft_strlen(".")));
		toggle->exist++;
	}
	if (toggle->exist == 1)
		ls_single_lst(search->content, toggle);
	else
	{
		sort_file_dir_lst(&search, toggle);
		ft_print_multi(&search, toggle, NULL);
	}
	ft_lstdel(&search, &ft_lstdelcontent);
	free(toggle);
	return (0);
}
