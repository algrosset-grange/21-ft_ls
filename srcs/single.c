/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 20:59:44 by agrosset          #+#    #+#             */
/*   Updated: 2017/11/28 17:43:16 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftls.h"

void	ft_print(t_list **list, t_flags *toggle, char *dir)
{
	if (toggle->t == 1)
		sort_lst(list, toggle, dir, &cmp_time);
	if (toggle->l == 1)
		print_long_lst(list, toggle, dir);
	else
		print_simple_lst(list, toggle, dir);
}

int		ls_single_lst(char *search, t_flags *toggle)
{
	struct dirent	*d;
	DIR				*dir;
	int				item;
	t_list			*lst_char;

	if ((item = item_amount_lst(search, NULL, toggle)))
		return (0);
	dir = opendir(search);
	lst_char = NULL;
	while ((d = readdir(dir)))
		ft_lstaddend(&lst_char, ft_lstnew(d->d_name,
			sizeof((void *)d->d_name) * ft_strlen(d->d_name)));
	ft_print(&lst_char, toggle, search);
	closedir(dir);
	ft_lstdel(&lst_char, &ft_lstdelcontent);
	return (0);
}

int		parse_single_lst(char *flag, char *search)
{
	t_flags *toggle;

	toggle = ft_memalloc(sizeof(t_flags));
	if (flag[0] == '-')
		if (check_flags(flag, toggle))
			return (0);
	ls_single_lst(search, toggle);
	free(toggle);
	return (0);
}
