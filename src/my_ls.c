/*
** my_ls.c for my_ls
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Mon Nov 23 11:38:08 2015 marc brout
** Last update Thu Nov 26 19:01:06 2015 marc brout
*/ 

#include <stdlib.h>
#include "../include/my_ls.h"

int		add_dir_to_end_list(t_par *tpar, char *str)
{
  t_dir		*elem;
  t_dir		*tmp;

  tmp = tpar->tdir->next;
  while (tmp->root != '1')
    {
      if (my_strcmp(tmp->path, str) == 0)
	return (0);
      tmp = tmp->next;
    }
  if ((elem = malloc(sizeof(t_dir))) == NULL)
    return (1);
  tpar->nbpath += 1;
  elem->path = str;
  elem->root = '0';
  elem->next = tpar->tdir;
  elem->prev = tpar->tdir->prev;
  tpar->tdir->prev->next = elem;
  tpar->tdir->prev = elem;
  return (0);
}

int		set_present(t_par *tpar, char x)
{
  int		i;
  int		pres;

  i = 0;
  while (i < SIZE_ARG)
    {
      if (tpar->targ[i].c == x)
	{
	  tpar->targ[i].ispresent = 1;
	  pres = 1;
	}
      i += 1;
    }
  if (pres == 0)
    return (1);
  return (0);
}

int		fill_dir_arg(t_par *tpar, char *str)
{
  int		i;

  if (str[0] == '-')
    {
      i = 1;
      while (str[i])
	if (set_present(tpar, str[i++]) == 1)
	  return (1);
    }
  else
    if (add_dir_to_end_list(tpar, str) == 1)
      return (2);
  return (0);
}

void		conf_arg(t_par *tpar, char *param)
{
  int		i;

  i = -1;
  tpar->tdir->path = my_strdup("root");
  tpar->tdir->root = '1';
  tpar->tdir->next = tpar->tdir;
  tpar->tdir->prev = tpar->tdir;
  tpar->nbpath = 0;
  while (param[++i])
    {
      tpar->targ[i].c = param[i];
      tpar->targ[i].ispresent = 0;
    }
}

int		main(int ac, char **av)
{
  t_par		tpar;
  int		i;

  if ((tpar.tdir = malloc(sizeof(t_dir))) == NULL)
    return (0);
  conf_arg(&tpar, ARGS);
  if (ac > 1)
    {
      i = 0;
      while (++i < ac)
	fill_dir_arg(&tpar, av[i]);
    }
  if (tpar.nbpath == 0)
    {
      fill_dir_arg(&tpar, ".");
      tpar.nbpath = 1;
    }
  if (tpar.nbpath > 1)
    my_ls_tri(tpar.tdir);
  /* my_printf("\n=======================================================\n"); */
  /* my_printf("=================== ARGUMENTS =========================\n"); */
  /* my_printf("=======================================================\n\n"); */
  /* my_show_args(&tpar); */
  /* my_printf("\n=======================================================\n"); */
  /* my_printf("================== START MY LS ========================\n"); */
  /* my_printf("=======================================================\n\n"); */
  my_ls(&tpar);
  return (0);
}
