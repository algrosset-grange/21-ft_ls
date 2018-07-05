/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 20:59:44 by agrosset          #+#    #+#             */
/*   Updated: 2017/11/28 17:43:16 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftls.h"

static int	mode_compare(int one, int two, t_flags *toggle)
{
	int a;
	int b;

	a = 0;
	b = 0;
	if (S_ISREG(one))
	{
		toggle->file = 1;
		a = 1;
	}
	if (S_ISREG(two))
	{
		toggle->file = 1;
		b = 1;
	}
	return (a - b);
}

static int	file_dir_alpha_sort_lst(char *content1, char *content2,
	t_flags *toggle, char *dir)
{
	struct stat	item1;
	struct stat	item2;

	if (stat(content2, &item2) == -1 && errno == ENOENT)
	{
		if (stat(content1, &item1) == -1 && errno == ENOENT)
		{
			if (cmp_str(content1, content2,
				toggle, dir))
				return (1);
		}
		else
			return (0);
	}
	if (mode_compare(item1.st_mode, item2.st_mode, toggle) == 0)
		if (ft_strcmp(content1, content1) < 0)
			return (1);
	return (0);
}

static int	file_dir_sort_lst(char *content1, char *content2,
	t_flags *toggle, char *dir)
{
	struct stat	item1;
	struct stat	item2;

	(void)dir;
	if (stat(content2, &item2) != 0 && errno == ENOENT)
	{
		if (stat(content1, &item1) != 0 && errno == ENOENT)
			return (0);
		return (1);
	}
	if (mode_compare(item1.st_mode, item2.st_mode, toggle) > 0)
		return (1);
	return (0);
}

static void	sort_hub_lst(t_list **search, t_flags *toggle)
{
	sort_lst(search, toggle, NULL, &file_dir_sort_lst);
	sort_lst(search, toggle, NULL, &file_dir_alpha_sort_lst);
	if (toggle->t == 1)
		sort_lst(search, toggle, NULL, &cmp_file_dir_time);
}

void		sort_file_dir_lst(t_list **search, t_flags *toggle)
{
	int		i;
	t_list	*maillon;
	char	*str;

	i = -1;
	maillon = *search;
	while (maillon)
	{
		str = (char *)maillon->content;
		if (str[0] != '.' || toggle->a == 1)
			grab_format_file(str, toggle);
		maillon = maillon->next;
	}
	sort_hub_lst(search, toggle);
}
