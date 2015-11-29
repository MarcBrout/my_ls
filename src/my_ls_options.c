/*
** my_ls_options.c for my_ls in /home/brout_m/rendu/projet/System_unix/PSU_2015_my_ls/src
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Fri Nov 27 23:16:39 2015 marc brout
** Last update Sun Nov 29 03:57:34 2015 marc brout
*/

#include "../include/my_ls.h"

void		my_ls(t_par *tpar)
{
  DIR		*fold;
  t_dir		*tmp;

  tmp = tpar->tdir;
  while ((tmp = tmp->next) && tmp->root != '1')
    {
      print_that_debf(tmp->prev->root, tmp->next->root);
      if ((fold = opendir((const char *)tmp->path)) != NULL)
  	{
  	  if (tpar->nbpath > 1)
  	    my_printf("%s:\n", tmp->path);
  	  launch_read(tpar, fold, tmp->path);
  	}
      else
  	launch_read_file(tmp, tpar, tmp->path);
    }
}

void		my_ls_r(t_par *tpar)
{
  DIR		*fold;
  t_dir		*tmp;

  tmp = tpar->tdir;
  while ((tmp = tmp->prev) && tmp->root != '1')
    {
      print_that_debf(tmp->next->root, tmp->prev->root);
      if ((fold = opendir((const char *)tmp->path)) != NULL)
	{
	  if (tpar->nbpath > 1)
	    my_printf("%s:\n", tmp->path);
	  launch_read(tpar, fold, tmp->path);
	}
      else
	launch_read_file(tmp, tpar, tmp->path);
    }
}

void		replace_maj(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    {
      str[i] -= (str[i] >= 'A' && str[i] <= 'Z') ? 'A' - 'a' : 0;
      i += 1;
    }
}

int		my_strcmp_ls(char *str, char *str2)
{
  int		i;
  int		val;
  char		*cmp;
  char		*cmp2;

  if ((cmp = my_strdup(str)) == NULL || (cmp2 = my_strdup(str2)) == NULL)
    return (0);
  replace_maj(cmp);
  replace_maj(cmp2);
  i = 0;
  while (cmp[i] && cmp2[i] && cmp[i] == cmp2[i])
    i += 1;
  val = cmp[i] - cmp2[i];
  free(cmp);
  free(cmp2);
  return (val);
}

int		add_dir_to_end_list(t_par *tpar, char *path)
{
  t_dir		*elem;
  t_dir		*tmp;

  tmp = tpar->tdir->next;
  while (tmp->root != '1')
    {
      if (my_strcmp(tmp->path, path) == 0)
	return (0);
      tmp = tmp->next;
    }
  if ((elem = malloc(sizeof(t_dir))) == NULL)
    return (1);
  tpar->nbpath += 1;
  if (lstat((const char *)path, &elem->stats) == -1)
    {
      free(elem);
      return (my_perror("my_ls: cannot access ", path));
    }
  else
    conf_dir_to_list(tpar, path, elem);
  return (0);
}
