/*
** functions.c for my_ls
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Thu Nov 26 14:18:49 2015 marc brout
** Last update Fri Nov 27 23:41:40 2015 marc brout
*/

#include "../include/my_ls.h"

char	*my_strcat_ls(char *str, char *str2)
{
  char	*tmp;
  int	i;
  int	j;

  if ((tmp = malloc(my_strlen(str) + my_strlen(str2) + 2)) == NULL)
    return (NULL);
  i = 0;
  while (str[i])
    {
      tmp[i] = str[i];
      i += 1;
    }
  if (tmp[i - 1] != '/')
    tmp[i++] = '/';
  j = 0;
  while (str2[j])
    tmp[i++] = str2[j++];
  tmp[i] = 0;
  return (tmp);
}

void		show_stats(t_dir *fold_cont, char *root_path)
{
  int		max;
  t_dir		*tmp;
  char		*full_p;
  struct stat	stats;

  tmp = fold_cont->next;
  max = print_blocks(fold_cont, root_path);
  while (tmp->root != '1')
    {
      if ((full_p = my_strcat_ls(root_path, tmp->path)) == NULL)
	return ;
      if (lstat((const char *)full_p, &stats) == -1)
	{
	  perror("\nmy_ls");
	  return ;
	}
      print_stats(&stats, tmp->path, max);
      tmp = tmp->next;
      if (full_p != NULL)
	free(full_p);
    }
}

void		show_stats_r(t_dir *fold_cont, char *root_path)
{
  int		max;
  t_dir		*tmp;
  char		*full_p;
  struct stat	stats;

  tmp = fold_cont->prev;
  max = print_blocks(fold_cont, root_path);
  while (tmp->root != '1')
    {
      if ((full_p = my_strcat_ls(root_path, tmp->path)) == NULL)
	return ;
      if (lstat((const char *)full_p, &stats) == -1)
	{
	  perror("\nmy_ls");
	  return ;
	}
      print_stats(&stats, tmp->path, max);
      tmp = tmp->prev;
      if (full_p != NULL)
	free(full_p);
    }
}

int		fill_folder_stats(DIR *fold, t_par *tpar, char *path)
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
  if (tpar->targ[3].ispresent == 0)
    show_stats(fold_cont, path);
  else
    show_stats_r(fold_cont, path);
  closedir(fold);
  free_t_dir(fold_cont);
  return (0);
}

void		launch_read(t_par *tpar, DIR *fold, char *path)
{
  if (tpar->targ[0].ispresent == 0)
    fill_folder_list(tpar, fold);
  else
    fill_folder_stats(fold, tpar, path);
}
