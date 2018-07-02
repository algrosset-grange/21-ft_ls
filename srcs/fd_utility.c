/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_utility.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 20:59:44 by agrosset          #+#    #+#             */
/*   Updated: 2017/11/28 17:43:16 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftls.h"

static void	ft_print_info_mode_p2(t_flags *toggle)
{
	char	*ll_char;
	char	*temp;

	if (toggle->there_is_total)
	{
		ll_char = ft_lltoa(toggle->blocks);
		temp = ft_strjoin("total ", ll_char);
		ft_putendl(temp);
		ft_memdel((void **)&temp);
	}
	ft_memdel((void **)&ll_char);
}

void		print_info_mode(char *str, char *dir, t_flags *toggle)
{
	struct stat		items;
	char			*file;
	char			*temp;

	if (dir == NULL)
		file = str;
	else
		file = dir;
	stat(file, &items);
	if (S_ISDIR(items.st_mode) && toggle->exist > 1)
	{
		if (toggle->file == 0)
			toggle->file = 1;
		else
			ft_putstr("\n");
		temp = ft_strjoin(dir, ":\n");
		ft_putstr(temp);
		ft_memdel((void **)&temp);
		if (toggle->l == 1 && toggle->blocks > 0)
			ft_print_info_mode_p2(toggle);
	}
	if (S_ISDIR(items.st_mode) && toggle->exist <= 1)
		ft_print_info_mode_p2(toggle);
}

void		grab_format_file(char *str, t_flags *toggle)
{
	struct stat		items;
	struct passwd	user;
	struct group	group;

	if (!stat(str, &items) && !S_ISDIR(items.st_mode))
	{
		user = *getpwuid(items.st_uid);
		if (ft_strlen(user.pw_name) > (size_t)toggle->fuid)
			toggle->fuid = ft_strlen(user.pw_name);
		group = *getgrgid(items.st_gid);
		if (ft_strlen(group.gr_name) > (size_t)toggle->fgid)
			toggle->fgid = ft_strlen(group.gr_name);
		if (ft_numullen(items.st_size) > toggle->fsize)
			toggle->fsize = ft_numullen(items.st_size);
		if ((long long)ft_numlen(items.st_nlink) > (long long)toggle->fnlinks)
			toggle->fnlinks = ft_numlen(items.st_nlink);
	}
}

int			mode_compare(int one, int two, t_flags *toggle)
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
