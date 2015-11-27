/*
** my_ls_options.c for my_ls in /home/brout_m/rendu/projet/System_unix/PSU_2015_my_ls/src
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Fri Nov 27 23:16:39 2015 marc brout
** Last update Fri Nov 27 23:30:57 2015 marc brout
*/

#include "../include/my_ls.h"

int		my_ls(t_par *tpar)
{
  DIR		*fold;
  t_dir		*tmp;
  struct stat	stats;

  tmp = tpar->tdir->next;
  while (tmp->root != '1')
    {
      print_that_debf(tmp->prev->root, tmp->next->root);
      if ((fold = opendir((const char *)tmp->path)) != NULL)
  	{
  	  if (tpar->nbpath > 1)
  	    my_printf("%s:\n", tmp->path);
  	  launch_read(tpar, fold, tmp->path);
  	}
      else if (lstat(tmp->path, &stats) != -1)
  	launch_read_file(tpar, tmp->path);
      else
  	perror("my_ls");
      tmp = tmp->next;
    }
  return (0);
}

int		my_ls_r(t_par *tpar)
{
  DIR		*fold;
  t_dir		*tmp;
  struct stat	stats;

  tmp = tpar->tdir->prev;
  while (tmp->root != '1')
    {
      print_that_debf(tmp->next->root, tmp->prev->root);
      if ((fold = opendir((const char *)tmp->path)) != NULL)
	{
	  if (tpar->nbpath > 1)
	    my_printf("%s:\n", tmp->path);
	  launch_read(tpar, fold, tmp->path);
	}
      else if (lstat(tmp->path, &stats) != -1)
	launch_read_file(tpar, tmp->path);
      else
	perror("my_ls");
      tmp = tmp->prev;
    }
  return (0);
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
