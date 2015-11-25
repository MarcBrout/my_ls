/*
** my_ls.h for my_ls
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Mon Nov 23 11:39:19 2015 marc brout
** Last update Wed Nov 25 10:47:30 2015 marc brout
*/

#ifndef MY_LS_H_
# define MY_LS_H_
# define SIZE_ARG 5
# define ARGS "lRdrt"

# include <unistd.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <dirent.h>
# include "my.h"

typedef struct		s_arg
{
  char			c;
  int			ispresent;
  int			val;
}			t_arg;

typedef struct		s_dir
{
  char			*path;
  struct s_dir		*next;
  struct s_dir		*prev;
}			t_dir;

typedef struct		s_par
{
  int			nbpath;
  int			argval;
  t_arg			targ[SIZE_ARG];
  t_dir			*tdir;
}			t_par;

int add_dir_to_end_list(t_par *, char *);
int add_file_to_end_list(t_dir *, char *);
int set_present(t_par *, char);
int fill_folder_list(t_par *, DIR *);
int fill_dir_arg(t_par *, char *);
void conf_arg(t_par *, char *);
void conf_file(t_dir *);
void read_folder_list(t_dir *, t_par *);
void my_show_args(t_par *);
void my_ls_tri(t_dir *);
int my_ls(t_par *);

#endif
