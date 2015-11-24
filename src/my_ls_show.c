/*
** my_ls_show.c for my_ls
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Mon Nov 23 21:13:58 2015 marc brout
** Last update Tue Nov 24 23:51:09 2015 marc brout
*/

#include "../include/my_ls.h"

void		my_show_args(t_par *tpar)
{
  t_dir		*tmp;
  int		i;

  tpar->argval = 0;
  if (tpar->targ[3].ispresent == 1)
    {
      tmp = tpar->tdir->prev;
      while (my_strcmp(tmp->path, "root") != 0)
	{
	  my_printf("%s ", tmp->path);
	  tmp = tmp->prev;
	}
    }
  else
    {
      tmp = tpar->tdir->next;
      while (my_strcmp(tmp->path, "root") != 0)
	{
	  my_printf("%s ", tmp->path);
	  tmp = tmp->next;
	}
    }
  my_printf("\nnbpath =  %d\n", tpar->nbpath);
  i = 0;
  while (i < SIZE_ARG)
    {
      if (tpar->targ[i].ispresent == 1)
	{
	  tpar->argval += tpar->targ[i].val;
	  my_printf("%c ", tpar->targ[i].c);
	}
      i += 1;
    }
  my_printf("\nargval = %d\n", tpar->argval);
}

int		fill_folder_list(DIR *fold, t_dir *fold_cont)
{
  struct dirent *file;
  
  if ((file = readdir(fold)) == NULL)
    return (1);
  while (file != NULL)
    {
      file = readdir(fold);
    }
  return (0);
}

int		my_ls(t_par *tpar)
{
  DIR		*fold;
  t_dir		*fold_cont;
  t_dir		*tmp;

  tmp = tpar->tdir->next;
  while (my_strcmp(tmp->path, "root") != 0)
    {
      fold = opendir((const char *)tmp->path);
      fold_cont = fill_folder_list(fold, fold_cont);
      
    }

  return (0);
}
