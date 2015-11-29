/*
** lasts.c for my_ls
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Sun Nov 29 04:05:03 2015 marc brout
** Last update Sun Nov 29 04:05:27 2015 marc brout
*/

#include "../include/my_ls.h"

void		conf_dir_to_list(t_par *tpar, char *str, t_dir *elem)
{
  elem->path = str;
  if (my_strcmp(str, ".") == 0)
    elem->rpath = my_strdup("..");
  else
    elem->rpath = str;
  elem->root = '0';
  elem->next = tpar->tdir;
  elem->prev = tpar->tdir->prev;
  tpar->tdir->prev->next = elem;
  tpar->tdir->prev = elem;
}
