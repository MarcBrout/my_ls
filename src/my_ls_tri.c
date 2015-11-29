/*
** my_ls_tri.c for my_ls
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Tue Nov 24 14:21:46 2015 marc brout
** Last update Sat Nov 28 22:37:45 2015 marc brout
*/

#include "../include/my_ls.h"

void		print_spaces(t_dir *file, int max)
{
  long		power;

  power = 10;
  while (power < max)
    power *= 10;
  power /= 10;
  while (power > file->stats.st_size && power > 10)
    {
      my_putchar(' ');
      power /= 10;
    }
}

void		print_stats(t_dir *file, int max)
{
  struct passwd *ps;
  struct group	*gr;
  char		c;

  if ((ps = getpwuid(file->stats.st_uid)) == NULL)
    {
      perror("\nmy_ls");
      return ;
    }
  if ((gr = getgrgid(file->stats.st_gid)) == NULL)
    {
      perror("\nmy_ls");
      return ;
    }
  c = print_type(file);
  print_rights(file);
  my_printf(" %d %s %s ", file->stats.st_nlink, ps->pw_name, gr->gr_name);
  print_spaces(file, max);
  my_printf("%d ", file->stats.st_size);
  print_time(file);
  print_symbolics(file, c);
}

int		my_swap_chains(t_dir *tmp, t_dir *tmp2)
{
  tmp->prev->next = tmp2;
  tmp2->next->prev = tmp;
  tmp2->prev = tmp->prev;
  tmp->next = tmp2->next;
  tmp2->next = tmp;
  tmp->prev = tmp2;
  return (0);
}

void		my_ls_tri(t_dir *tdir)
{
  t_dir		*tmp;
  t_dir		*tmp2;
  int		tri;

  tri = 0;
  tmp = tdir;
  if (tmp->next->root == '1')
    return ;
  while (tri == 0 || ((tmp = tmp->next) && tmp->next->root != '1'))
    {
      tri = 1;
      if (my_strcmp_ls(tmp->path, tmp->next->path) > 0 &&
	  tmp->next->root != '1' && tmp->root != '1')
	{
	  tmp2 = tmp->next;
	  tri = my_swap_chains(tmp, tmp2);
	  tmp = tdir;
	}
    }
}

void		my_ls_tri_time(t_par *tpar, t_dir *tdir)
{
  t_dir		*tmp;
  t_dir		*tmp2;
  int		tri;

  if (tpar->targ[4].ispresent == 1)
    {
      tri = 0;
      tmp = tdir;
      if (tmp->next->root == '1')
	return ;
      while (tri == 0 || ((tmp = tmp->next) && tmp->next->root != '1'))
	{
	  tri = 1;
	  if (tmp->next->root != '1' && tmp->root != '1' &&
	      tmp->stats.st_mtime < tmp->next->stats.st_mtime)
	    {
	      tmp2 = tmp->next;
	      tri = my_swap_chains(tmp, tmp2);
	      tmp = tdir;
	    }
	}
    }
}
