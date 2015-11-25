/*
** my_ls_show.c for my_ls
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Mon Nov 23 21:13:58 2015 marc brout
** Last update Wed Nov 25 12:10:34 2015 marc brout
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

void		read_folder_list(t_dir *tdir, t_par *tpar)
{
  t_dir		*tmp;

  tmp = (tpar->targ[3].ispresent == 0) ? tdir->next : tdir->prev;
  if (tpar->targ[3].ispresent == 0)
      while (my_strcmp(tmp->path, "root") != 0)
	{
	  my_printf("%s  ", tmp->path);
	  tmp = tmp->next;
	}
  else
      while (my_strcmp(tmp->path, "root") != 0)
	{
	  my_printf("%s  ", tmp->path);
	  tmp = tmp->prev;
	}
}

void		conf_file(t_dir *tdir)
{
  tdir->path = my_strdup("root");
  tdir->next = tdir;
  tdir->prev = tdir;
}

int		add_file_to_end_list(t_dir *tdir, char *str)
{
  t_dir		*elem;

  if ((elem = malloc(sizeof(t_dir))) == NULL)
    return (1);
  elem->path = str;
  elem->next = tdir;
  elem->prev = tdir->prev;
  tdir->prev->next = elem;
  tdir->prev = elem;
  return (0);
}

int		fill_folder_list(t_par *tpar, DIR *fold)
{
  struct dirent *file;
  t_dir		fold_cont;
  
  if ((file = readdir(fold)) == NULL)
    return (1);
  conf_file(&fold_cont);
  while (file != NULL)
    {
      if (my_strcmp(file->d_name, ".") != 0 &&
	  my_strcmp(file->d_name, "..") != 0)
	add_file_to_end_list(&fold_cont, file->d_name);
      file = readdir(fold);
    }
  my_ls_tri(&fold_cont);
  read_folder_list(&fold_cont, tpar);
  return (0);
}

int		my_ls(t_par *tpar)
{
  DIR		*fold;
  t_dir		*tmp;

  tmp = tpar->tdir->next;
  while (my_strcmp(tmp->path, "root") != 0)
    {
      my_printf("%s\n", tmp->path);
      fold = opendir((const char *)tmp->path);
      fill_folder_list(tpar, fold);
      my_printf("\n");
      closedir(fold);
      tmp = tmp->next;
    }
  return (0);
}
