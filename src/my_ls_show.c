/*
** my_ls_show.c for my_ls
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Mon Nov 23 21:13:58 2015 marc brout
** Last update Sun Nov 29 03:51:57 2015 marc brout
*/

#include "../include/my_ls.h"

int		conf_file(t_dir *tdir)
{
  tdir->path = my_strdup("root");
  tdir->root = '1';
  tdir->next = tdir;
  tdir->prev = tdir;
  return (0);
}

int		add_file_to_end_list(t_dir *tdir, char *str, char *rpath)
{
  t_dir		*elem;
  char		*str2;

  if ((elem = malloc(sizeof(t_dir))) == NULL)
    return (1);
  str2 = my_strcat_ls(rpath, str);
  if (lstat((const char *)str2, &elem->stats) == -1)
    {
      free_str(str2);
      free(elem);
      return (my_perror("my_ls: cannot access ", str));
    }
  else
    {
      elem->path = str;
      elem->rpath = str2;
      elem->root = '0';
      elem->next = tdir;
      elem->prev = tdir->prev;
      tdir->prev->next = elem;
      tdir->prev = elem;
      free_str(str2);
    }
  return (0);
}

void		fill_rec_list(t_par *tpar, t_rec *trec)
{
  if ((trec->file = readdir(trec->fold)) == NULL)
	{
	  perror("\nmy_ls");
	  return ;
	}
  if ((trec->fold_cont = malloc(sizeof(t_dir))) == NULL)
    return ;
  conf_file(trec->fold_cont);
  while (trec->file != NULL)
    {
      if (trec->file->d_name[0] != '.')
	add_file_to_end_list(trec->fold_cont, trec->file->d_name,
			     trec->path);
      trec->file = readdir(trec->fold);
    }
  my_ls_tri(trec->fold_cont);
  my_ls_tri_time(tpar, trec->fold_cont);
  read_folder_list(trec->fold_cont, tpar);
}

void		fill_folder_list(t_par *tpar, DIR *fold, char *rpath)
{
  t_rec		trec;
  char		*nextpath;

  trec.path = rpath;
  trec.fold = fold;
  fill_rec_list(tpar, &trec);
  if (tpar->targ[1].ispresent == 1)
    while ((trec.fold_cont = trec.fold_cont->next) &&
	   trec.fold_cont->root != '1')
      {
	if (S_ISDIR(trec.fold_cont->stats.st_mode))
	  {
	    my_putchar('\n');
	    nextpath = my_strcat_ls(rpath, trec.fold_cont->path);
	    my_printf("%s:\n", nextpath);
	    fill_folder_list(tpar, opendir(nextpath), nextpath);
	    free_str(nextpath);
	  }
      }
  closedir(trec.fold);
  free_t_dir(trec.fold_cont);
}

void		print_that_debf(char c, char b)
{
  if ((c == '0' && b != '1'))
    my_putchar('\n');
  else if ((c != '1' && b == '1'))
    my_putchar('\n');
}
