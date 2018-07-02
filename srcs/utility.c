/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 20:59:44 by agrosset          #+#    #+#             */
/*   Updated: 2017/11/28 17:43:16 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftls.h"

void		ft_del_lst(void *content, size_t content_size)
{
	(void)content_size;
	ft_memdel(&content);
}

static void	ft_grab_format_p2(char *str, char *dir, char **file)
{
	char	*tmp;

	tmp = NULL;
	if (dir != NULL)
	{
		tmp = ft_strjoin(dir, "/");
		*file = ft_strjoin(tmp, str);
	}
	else
		*file = ft_strdup(str);
	ft_memdel((void **)&tmp);
}

void		grab_format_long(char *str, char *dir, t_flags *toggle)
{
	struct stat		items;
	struct passwd	user;
	struct group	group;
	char			*file;

	ft_grab_format_p2(str, dir, &file);
	stat(file, &items);
	if (!S_ISCHR(items.st_mode) && !S_ISBLK(items.st_mode))
		toggle->blocks = toggle->blocks + items.st_blocks;
	user = *getpwuid(items.st_uid);
	if ((long long)ft_strlen(user.pw_name) > (long long)toggle->uid)
		toggle->uid = ft_strlen(user.pw_name);
	group = *getgrgid(items.st_gid);
	if ((long long)ft_strlen(group.gr_name) > (long long)toggle->gid)
		toggle->gid = ft_strlen(group.gr_name);
	if (ft_numullen(items.st_size) > toggle->size)
		toggle->size = ft_numullen(items.st_size);
	if ((long long)ft_numlen(items.st_nlink) > (long long)toggle->nlinks)
		toggle->nlinks = ft_numlen(items.st_nlink);
	ft_memdel((void **)&file);
}

int			check_flags(char *str, t_flags *toggle)
{
	int i;

	i = 1;
	while (str[i] != '\0')
	{
		str[i] == 'r' ? toggle->r = 1 : 0;
		str[i] == 'a' ? toggle->a = 1 : 0;
		str[i] == 'l' ? toggle->l = 1 : 0;
		str[i] == 't' ? toggle->t = 1 : 0;
		str[i] == 'R' ? toggle->re = 1 : 0;
		if (str[i] != 'r' && str[i] != 'a' && str[i] != '1'
			&& str[i] != 'l' && str[i] != 't' && str[i] != 'R')
		{
			ft_putstr("ft_ls: illegal option -- '");
			ft_putchar(str[i]);
			ft_putstr("'\n");
			ft_putstr("Try 'ft_ls --help' for more information.\n");
			return (1);
		}
		i++;
	}
	return (0);
}