/*
** my_ls_tri.c for my_ls
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Tue Nov 24 14:21:46 2015 marc brout
** Last update Tue Nov 24 23:04:44 2015 marc brout
*/

#include "../include/my_ls.h"

void		my_ls_tri(t_par *tpar)
{
  t_dir		*tmp;
  char		*stock;
  int		tri;

  tri = 0;
  tmp = tpar->tdir->next;
  while (tri == 0 || my_strcmp(tmp->next->path, "root") != 0)
    {
      tri = 1;
      if (my_strcmp(tmp->path, tmp->next->path) > 0)
	{
	  tri = 0;
	  stock = tmp->path;
	  tmp->path = tmp->next->path;
	  tmp->next->path = stock;
	  tmp = tpar->tdir->next;
	}
      tmp = tmp->next;
    }
}
