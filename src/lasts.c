/*
** lasts.c for my_ls
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Sun Nov 29 04:05:03 2015 marc brout
** Last update Sun Nov 29 17:53:01 2015 marc brout
*/

#include "../include/my_ls.h"

void		free_t_dir_main(t_dir *tdir)
{
  t_dir		*tmp;
  t_dir		*tmp2;

  free_str(tdir->path);
  tmp = tdir->next;
  while (tmp != tdir && tmp)
    {
      tmp2 = tmp->next;
      if (tmp != NULL)
	free(tmp);
      tmp = tmp2;
    }
  if (tdir != NULL)
    free(tdir);
}

void		conf_dir_to_list(t_par *tpar, char *str, t_dir *elem)
{
  elem->path = str;
  elem->rpath = str;
  elem->root = '0';
  elem->next = tpar->tdir;
  elem->prev = tpar->tdir->prev;
  tpar->tdir->prev->next = elem;
  tpar->tdir->prev = elem;
}
