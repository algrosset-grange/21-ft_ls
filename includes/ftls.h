/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftls.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/25 09:00:00 by agrosset          #+#    #+#             */
/*   Updated: 2017/08/25 09:00:00 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTLS_H
# define FTLS_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include <sys/ioctl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <sys/stat.h>
# include <sys/xattr.h>
# include <sys/acl.h>
# include <dirent.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <errno.h>
# include <string.h>

# include "libft.h"

typedef struct			s_flags
{
	int					r;
	int					a;
	int					l;
	int					t;
	int					re;
	long long			blocks;
	int					nlinks;
	int					uid;
	int					gid;
	unsigned long long	size;
	unsigned long long	minor;
	unsigned long long	major;
	long long			i;
	int					exist;
	int					file;
	int					fnlinks;
	int					fuid;
	int					fgid;
	unsigned long long	fsize;
	unsigned long long	total;
	int					there_is_total;
	unsigned long long	count;
}						t_flags;

/*
** fd_sort.c
*/
void					sort_file_dir(char **search, int exist,
							t_flags *toggle);
void					sort_file_dir_lst(t_list **search, t_flags *toggle);

/*
** fd_utility.c
*/
void					grab_format_file(char *str, t_flags *toggle);
int						mode_compare(int one, int two, t_flags *toggle);
void					print_info_mode(char *str, char *dir,
	t_flags *toggle);

/*
** ft_print_multi.c
*/
void					ft_print_multi(t_list **search, t_flags *toggle,
	char *dir);
int						ft_print_recurse(t_list **search, t_flags *toggle,
	char *dir);

/*
** multi.c
*/

int						parse_multi_lst(char **av);

/*
** permissions.c
*/
char					*perms(int mode);

/*
** print_process.c
*/
void					print_l_hub(char *str, char *dir, t_flags *toggle);
int						cmp_time(char *one, char *two, t_flags *toggle,
	char *dir);
void					suffix(char *path);
void					print_spacing(t_flags *toggle, char *dir);

/*
** printlong_2.c
*/
void					print_l_f(char *str, char *file, t_flags *toggle);

/*
** printlong.c
*/
void					print_date_name(t_flags *toggle, char *str,
	struct stat timer, char *file);
void					print_size_device(struct stat items, t_flags *toggle,
	char *dir);

/*
** printlong.c
*/
void					print_l(char *str, char *dir, t_flags *toggle);

/*
** printsort.c
*/
void					print_simple_lst(t_list **list, t_flags *toggle,
	char *dir);
void					print_long_lst(t_list **list, t_flags *toggle,
	char *dir);

/*
** single.c
*/
int						ls_single_lst(char *str, t_flags *toggle);
int						parse_single_lst(char *flag, char *search);
void					ft_print(t_list **list, t_flags *toggle, char *dir);
int						parse_single(char *flag, char *search);

/*
** sort.c
*/
void					sort_lst(t_list **list, t_flags *toggle, char *dir,
	int (*cmp)(char *content1, char *content2, t_flags *toggle, char *dir));
int						cmp_str(char *one, char *two, t_flags *toggle,
	char *dir);
int						cmp_file_dir_time(char *one, char *two, t_flags *toggle,
	char *dir);

/*
** utility_2.c
*/
int						item_amount_lst(char *str, char *way, t_flags *toggle);

/*
** utility.c
*/
int						check_flags(char *str, t_flags *toggle);
void					grab_format_long(char *str, char *dir, t_flags *toggle);

#endif
