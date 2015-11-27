/*
** my_ls_show.c for my_ls
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Mon Nov 23 21:13:58 2015 marc brout
** Last update Fri Nov 27 23:30:16 2015 marc brout
*/

#include "../include/my_ls.h"

void		read_folder_list(t_dir *tdir, t_par *tpar)
{
  t_dir		*tmp;

  tmp = (tpar->targ[3].ispresent == 0) ? tdir->next : tdir->prev;
  if (tpar->targ[3].ispresent == 0)
      while (tmp->root != '1')
	{
	  my_printf("%s", tmp->path);
	  if (tmp->next->root != 1)
	    my_printf("\n");
	  tmp = tmp->next;
	}
  else
      while (tmp->root != '1')
	{
	  my_printf("%s", tmp->path);
	  if (tmp->prev->root != 1)
	    my_printf("\n");
	  tmp = tmp->prev;
	}
}

int		conf_file(t_dir *tdir)
{
  tdir->path = my_strdup("root");
  tdir->root = '1';
  tdir->next = tdir;
  tdir->prev = tdir;
  return (0);
}

int		add_file_to_end_list(t_dir *tdir, char *str)
{
  t_dir		*elem;

  if ((elem = malloc(sizeof(t_dir))) == NULL)
    return (1);
  elem->path = str;
  elem->root = '0';
  elem->next = tdir;
  elem->prev = tdir->prev;
  tdir->prev->next = elem;
  tdir->prev = elem;
  return (0);
}

int		fill_folder_list(t_par *tpar, DIR *fold)
{
  struct dirent *file;
  t_dir		*fold_cont;

  if ((file = readdir(fold)) == NULL)
	{
	  perror("\nmy_ls");
	  return (1);
	}
  if ((fold_cont = malloc(sizeof(t_dir))) == NULL)
    return (1);
  conf_file(fold_cont);
  while (file != NULL)
    {
      if (file->d_name[0] != '.')
	add_file_to_end_list(fold_cont, file->d_name);
      file = readdir(fold);
    }
  my_ls_tri(fold_cont);
  read_folder_list(fold_cont, tpar);
  closedir(fold);
  free_t_dir(fold_cont);
  return (0);
}

void		print_that_debf(char c, char b)
{
  if ((c == '0' && b != '1'))
    my_putchar('\n');
  else if ((c != '1' && b == '1'))
    my_putchar('\n');
}
