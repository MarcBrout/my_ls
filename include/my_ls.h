/*
** my_ls.h for my_ls
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Mon Nov 23 11:39:19 2015 marc brout
** Last update Fri Nov 27 23:54:20 2015 marc brout
*/

#ifndef MY_LS_H_
# define MY_LS_H_
# define ARGS "lRdrt"
# define SIZE_ARG (int)sizeof(ARGS)
# define S_IFMT 0170000
# define S_IFSOCK 0140000
# define S_IFLNK 0120000

# include <stdio.h>
# include <fcntl.h>
# include <time.h>
# include <pwd.h>
# include <grp.h>
# include <unistd.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <dirent.h>
# include "my.h"

typedef struct		s_arg
{
  char			c;
  int			ispresent;
}			t_arg;

typedef struct		s_dir
{
  char			*path;
  char			root;
  struct s_dir		*next;
  struct s_dir		*prev;
}			t_dir;

typedef struct		s_par
{
  int			nbpath;
  t_arg			targ[SIZE_ARG];
  t_dir			*tdir;
}			t_par;

char *my_strcat_ls(char *, char *);
int lstat(const char *, struct stat *);
ssize_t readlink(const char *, char *, size_t);
int add_dir_to_end_list(t_par *, char *);
int add_file_to_end_list(t_dir *, char *);
int conf_file(t_dir *);
int fill_folder_list(t_par *, DIR *);
int fill_dir_arg(t_par *, char *);
int my_ls_r(t_par *);
int my_ls(t_par *);
int my_strcmp_ls(char *, char *);
int set_present(t_par *, char);
void launch_read_file(t_par *, char *);
void print_that_debf(char, char);
void free_t_dir(t_dir *);
void print_spaces(struct stat *, int);
void print_symbolics(struct stat *, char, char *);
void print_rights(struct stat *);
void print_time(struct stat *);
int print_blocks(t_dir *, char *);
char print_type(struct stat *);
void print_stats(struct stat *, char *, int);
void show_stats(t_dir *, char *);
void show_stats_r(t_dir *, char *);
void conf_arg(t_par *, char *);
void replace_maj(char *);
int fill_folder_stats(DIR *, t_par *, char *);
void read_folder_list(t_dir *, t_par *);
void launch_read(t_par *, DIR *, char *);
void my_ls_tri(t_dir *);

#endif
