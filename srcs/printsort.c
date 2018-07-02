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

static void	reset_data(t_flags *toggle)
{
	toggle->there_is_total = 0;
	toggle->blocks = 0;
	toggle->nlinks = 0;
	toggle->uid = 0;
	toggle->gid = 0;
	toggle->size = 0;
	toggle->i = -1;
}

static void	ft_adddir(t_list **lst_dir, char *name, char *rep)
{
	DIR			*dir;
	char		*tmp;
	char		*file;
	struct stat	items;

	if (!ft_strcmp(name, ".") || !ft_strcmp(name, ".."))
		return ;
	tmp = ft_strjoin(rep, "/");
	file = ft_strjoin(tmp, name);
	dir = NULL;
	lstat(file, &items);
	if ((dir = opendir(file)) != NULL || S_ISDIR(items.st_mode))
	{
		ft_lstaddend(lst_dir, ft_lstnew(name,
			sizeof((void *)name) * ft_strlen(name)));
		if (dir != NULL)
			closedir(dir);
	}
	ft_memdel((void **)&tmp);
	ft_memdel((void **)&file);
}

static void	set_stuff_lst(t_list **maillon, char *dir, t_flags *toggle)
{
	char	*str;

	str = (*maillon)->content;
	if (str[0] != '.' || toggle->a == 1)
	{
		toggle->there_is_total = 1;
		grab_format_long(str, dir, toggle);
	}
	*maillon = (*maillon)->next;
}

void		print_long_lst(t_list **list, t_flags *toggle, char *dir)
{
	char	*name_file;
	t_list	*maillon;
	t_list	*lst_dir;

	printf("passe1\n");
	reset_data(toggle);
	maillon = *list;
	lst_dir = NULL;
	while (maillon != NULL)
		set_stuff_lst(&maillon, dir, toggle);
	printf("passe2\n");
	maillon = *list;
	name_file = maillon->content;
	print_info_mode(name_file, dir, toggle);
	printf("passe3\n");
	while (maillon != NULL)
	{
		name_file = maillon->content;
		if (name_file[0] != '.' || toggle->a == 1)
			print_l_hub(name_file, dir, NULL, toggle);
		if (toggle->re == 1)
			ft_adddir(&lst_dir, name_file, dir);
		maillon = maillon->next;
	}
	printf("passe4\n");
	ft_print_recurse(&lst_dir, toggle, dir);
	printf("passe5\n");
	ft_lstdel(&lst_dir, &ft_del_lst);
	printf("passe6\n");
	sleep(5);
}

void		print_simple_lst(t_list **list, t_flags *toggle, char *dir)
{
	t_list	*maillon;
	t_list	*lst_dir;
	char	*name;

	printf("passe\n");
	sleep(5);

	maillon = *list;
	lst_dir = NULL;
	while (maillon != NULL)
	{
		name = (char *)(maillon->content);
		if ((name[0] != '.' && toggle->a == 0) || toggle->a == 1)
		{
			ft_putendl(name);
			if (toggle->re == 1)
				ft_adddir(&lst_dir, name, dir);
		}
		maillon = maillon->next;
	}
	ft_print_recurse(&lst_dir, toggle, dir);
	ft_lstdel(&lst_dir, &ft_del_lst);
}
