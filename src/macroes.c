/*
** macroes.c for my_ls
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Fri Nov 27 09:33:55 2015 marc brout
** Last update Sun Nov 29 01:33:16 2015 marc brout
*/

#include "../include/my_ls.h"

void		free_str(char *str)
{
  if (str)
    free(str);
}

void		free_t_dir(t_dir *tdir)
{
  t_dir		*tmp;
  t_dir		*tmp2;

  free_str(tdir->path);
  tmp = tdir->next;
  while (tmp != tdir && tmp)
    {
      tmp2 = tmp->next;
      if (tmp != NULL)
	free(tmp);
      tmp = tmp2;
    }
  if (tdir != NULL)
    free(tdir);
}

void		print_time(t_dir *file)
{
  char		*ttp;
  int		i;

  i = 4;
  ttp = my_strdup(ctime(&file->stats.st_mtime));
  while (i < 16)
    {
      my_putchar(ttp[i]);
      i += 1;
    }
  if (ttp != NULL)
    free(ttp);
}

void		print_rights(t_dir *file)
{
  my_putchar((file->stats.st_mode & S_IRUSR) ? 'r' : '-');
  my_putchar((file->stats.st_mode & S_IWUSR) ? 'w' : '-');
  my_putchar((file->stats.st_mode & S_IXUSR) ? 'x' : '-');
  my_putchar((file->stats.st_mode & S_IRGRP) ? 'r' : '-');
  my_putchar((file->stats.st_mode & S_IWGRP) ? 'w' : '-');
  my_putchar((file->stats.st_mode & S_IXGRP) ? 'x' : '-');
  my_putchar((file->stats.st_mode & S_IROTH) ? 'r' : '-');
  my_putchar((file->stats.st_mode & S_IWOTH) ? 'w' : '-');
  my_putchar((file->stats.st_mode & S_IXOTH) ? 'x' : '-');
}

char		print_type(t_dir *file)
{
  file->d = '-';
  file->d = S_ISDIR(file->stats.st_mode) ? 'd' : file->d;
  file->d = S_ISCHR(file->stats.st_mode) ? 'c' : file->d;
  file->d = S_ISBLK(file->stats.st_mode) ? 'b' : file->d;
  file->d = S_ISFIFO(file->stats.st_mode) ? 'p' : file->d;
  file->d = ((file->stats.st_mode & S_IFMT) == S_IFLNK) ? 'l' : file->d;
  file->d = ((file->stats.st_mode & S_IFMT) == S_IFSOCK) ? 's' : file->d;
  my_putchar(file->d);
  return (file->d);
}
