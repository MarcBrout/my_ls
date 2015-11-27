/*
** macroes.c for my_ls
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Fri Nov 27 09:33:55 2015 marc brout
** Last update Fri Nov 27 22:57:46 2015 marc brout
*/

#include "../include/my_ls.h"

void		free_t_dir(t_dir *tdir)
{
  t_dir		*tmp;
  t_dir		*tmp2;

  free(tdir->path);
  tmp = tdir->next;
  while (tmp != tdir && tmp)
    {
      tmp2 = tmp->next;
      free(tmp);
      tmp = tmp2;
    }
  if (tdir != NULL)
    free(tdir);
}

void		launch_read_file(t_par *tpar, char *path)
{
  struct stat	stats;

  lstat((const char *)path, &stats);
  if (tpar->targ[0].ispresent == 1)
    print_stats(&stats, path, stats.st_size);
  else
    my_printf("%s\n", path);
}

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
  if (ttp != NULL)
    free(ttp);
}

void		print_rights(struct stat *stats)
{
  my_putchar((stats->st_mode & S_IRUSR) ? 'r' : '-');
  my_putchar((stats->st_mode & S_IWUSR) ? 'w' : '-');
  my_putchar((stats->st_mode & S_IXUSR) ? 'x' : '-');
  my_putchar((stats->st_mode & S_IRGRP) ? 'r' : '-');
  my_putchar((stats->st_mode & S_IWGRP) ? 'w' : '-');
  my_putchar((stats->st_mode & S_IXGRP) ? 'x' : '-');
  my_putchar((stats->st_mode & S_IROTH) ? 'r' : '-');
  my_putchar((stats->st_mode & S_IWOTH) ? 'w' : '-');
  my_putchar((stats->st_mode & S_IXOTH) ? 'x' : '-');
}

char		print_type(struct stat *stats)
{
  char		c;

  c = '-';
  c = S_ISDIR(stats->st_mode) ? 'd' : c;
  c = S_ISCHR(stats->st_mode) ? 'c' : c;
  c = S_ISBLK(stats->st_mode) ? 'b' : c;
  c = S_ISFIFO(stats->st_mode) ? 'p' : c;
  c = ((stats->st_mode & S_IFMT) == S_IFLNK) ? 'l' : c;
  c = ((stats->st_mode & S_IFMT) == S_IFSOCK) ? 's' : c;
  my_putchar(c);
  return (c);
}
