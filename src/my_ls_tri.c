/*
** my_ls_tri.c for my_ls
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Tue Nov 24 14:21:46 2015 marc brout
** Last update Thu Nov 26 23:49:23 2015 marc brout
*/

#include "../include/my_ls.h"

void		print_time(struct stat *stats)
{
  char		*ttp;
  int		i;

  i = 4;
  ttp = my_strdup(ctime(&stats->st_mtime));
  while (i < 16)
    {
      my_putchar(ttp[i]);
      i += 1;
    }
}

void		print_blocks(t_dir *fold_cont, char *root_path)
{
  t_dir		*tmp;
  char		*full_p;
  int		block;
  struct stat	stats;

  block = 0;
  tmp = fold_cont->next;
  while (tmp->root != '1')
    {
      if ((full_p = my_strcat_ls(root_path, tmp->path)) == NULL ||
	  stat((const char *)full_p, &stats) == -1)
	return;
      block += stats.st_blocks;
      tmp = tmp->next;
      if (full_p != NULL)
	free(full_p);
    }
  my_printf("total %d\n", block / 2);
}

void		print_stats(struct stat *stats, char *full_p, char *path)
{
  struct passwd *pass;
  struct group	*grp;

  pass = getpwuid(stats->st_uid);
  grp = getgrgid(stats->st_gid);
  my_printf("%d ", stats->st_nlink);
  my_printf("%s %s %d ", pass->pw_name, grp->gr_name, stats->st_size);
  print_time(stats);
  my_printf(" %s\n", path);
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
    return (1);
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

void		my_ls_tri(t_dir *tdir)
{
  t_dir		*tmp;
  char		*stock;
  int		tri;

  tri = 0;
  tmp = tdir->next;
  while (tri == 0 || tmp->next->root != '1')
    {
      tri = 1;
      if (my_strcmp_ls(tmp->path, tmp->next->path) > 0)
	{
	  tri = 0;
	  stock = tmp->path;
	  tmp->path = tmp->next->path;
	  tmp->next->path = stock;
	  tmp = tdir;
	}
      tmp = tmp->next;
    }
}
