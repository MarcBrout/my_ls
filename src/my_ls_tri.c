/*
** my_ls_tri.c for my_ls
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Tue Nov 24 14:21:46 2015 marc brout
** Last update Fri Nov 27 23:54:54 2015 marc brout
*/

#include "../include/my_ls.h"

int		print_blocks(t_dir *fold_cont, char *root_path)
{
  t_dir		*tmp;
  char		*full_p;
  int		block;
  int		max;
  struct stat	stats;

  block = 0;
  max = 0;
  tmp = fold_cont->next;
  while (tmp->root != '1')
    {
      if ((full_p = my_strcat_ls(root_path, tmp->path)) == NULL)
	return (-1);
      if (lstat((const char *)full_p, &stats) == -1)
	{
	  perror("\nmy_ls");
	  return (-1);
	}
      max = ((stats.st_size > max) ? stats.st_size : max);
      block += stats.st_blocks;
      tmp = tmp->next;
      free(full_p);
    }
  my_printf("total %d\n", block / 2);
  return (max);
}

void		print_symbolics(struct stat *stats, char c, char *path)
{
  ssize_t	r;
  char		*link;

  if (c != 'l')
    my_printf(" %s\n", path);
  else
    {
      if ((link = malloc(stats->st_size + 1)) == NULL)
	return ;
      if ((r = readlink(path, link, stats->st_size + 1)) == -1)
	{
	  perror("\nmy_ls");
	  my_putchar('\n');
	  return ;
	}
      link[r] = 0;
      my_printf(" %s -> %s\n", path, link);
      if (link != NULL)
	free(link);
    }
}

void		print_spaces(struct stat *stats, int max)
{
  long		power;

  power = 10;
  while (power < max)
    power *= 10;
  power /= 10;
  while (power > stats->st_size && power > 10)
    {
      my_putchar(' ');
      power /= 10;
    }
}

void		print_stats(struct stat *stats, char *path, int max)
{
  struct passwd *pass;
  struct group	*grp;
  char		c;

  if ((pass = getpwuid(stats->st_uid)) == NULL)
    {
      perror("\nmy_ls");
      return ;
    }
  if ((grp = getgrgid(stats->st_gid)) == NULL)
    {
      perror("\nmy_ls");
      return ;
    }
  c = print_type(stats);
  print_rights(stats);
  my_printf(" %d ", stats->st_nlink);
  my_printf("%s %s ", pass->pw_name, grp->gr_name);
  print_spaces(stats, max);
  my_printf("%d ", stats->st_size);
  print_time(stats);
  print_symbolics(stats, c, path);
}

void		my_ls_tri(t_dir *tdir)
{
  t_dir		*tmp;
  char		*stock;
  int		tri;

  tri = 0;
  tmp = tdir->next;
  if (tmp->root == '1')
    return ;
  while (tri == 0 || tmp->next->root != '1')
    {
      tri = 1;
      if (my_strcmp_ls(tmp->path, tmp->next->path) > 0 &&
	  tmp->next->root != '1')
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
