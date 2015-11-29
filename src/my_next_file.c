/*
** my_next_file.c for my_ls
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Sun Nov 29 03:54:42 2015 marc brout
** Last update Sun Nov 29 03:55:35 2015 marc brout
*/

#include "../include/my_ls.h"

int		my_perror(char *str, char *str2)
{
  my_putstr(str);
  perror(str2);
  return (1);
}

void		print_file_color(char *str, t_dir *tdir)
{
  if (S_ISDIR(tdir->stats.st_mode))
    my_printf("\x1b[34%s\x1b[0m\n", str);
  else if ((tdir->stats.st_mode & S_IFMT) == S_IFLNK)
    my_printf("\x1b[36%s\x1b[0m\n", str);
  else
    my_printf("%s\n", str);
}

void		read_d(t_par *tpar)
{
  t_dir		*tmp;

  tmp = tpar->tdir;
  if (tpar->targ[0].ispresent == 1)
    {
      while ((tmp = tmp->next) && tmp->root != '1')
	show_stats(tpar, tmp);
    }
  else
    while ((tmp = tmp->next) && tmp->root != '1')
      print_file_color(tmp->path, tmp);
}

void		read_d_r(t_par *tpar)
{
  t_dir		*tmp;

  tmp = tpar->tdir;
  if (tpar->targ[0].ispresent == 1)
    {
      while ((tmp = tmp->prev) && tmp->root != '1')
	show_stats(tpar, tmp);
    }
  else
    while ((tmp = tmp->prev) && tmp->root != '1')
      print_file_color(tmp->path, tmp);
}

void		launch_ls(t_par *tpar)
{
  if (tpar->targ[2].ispresent == 0)
    if (tpar->targ[3].ispresent == 0)
      my_ls(tpar);
    else
      my_ls_r(tpar);
  else
    if (tpar->targ[3].ispresent == 0)
      read_d(tpar);
    else
      read_d_r(tpar);
}

