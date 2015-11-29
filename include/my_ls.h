/*
** my_ls.h for my_ls
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Mon Nov 23 11:39:19 2015 marc brout
** Last update Sun Nov 29 03:33:01 2015 marc brout
*/

#ifndef MY_LS_H_
# define MY_LS_H_
# define ARGS "lRdrt"
# define SIZE_ARG 5
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
  char			*rpath;
  char			root;
  char			d;
  struct stat		stats;
  struct s_dir		*next;
  struct s_dir		*prev;
}			t_dir;

typedef struct		s_rec
{
  char			*path;
  t_dir			*fold_cont;
  struct dirent		*file;
  DIR			*fold;
}			t_rec;

typedef struct		s_par
{
  int			nbpath;
  t_arg			targ[SIZE_ARG];
  t_dir			*tdir;
}			t_par;

int swap_chains(t_dir *, t_dir *);
int my_perror(char *, char *);
char *my_strcat_ls(char *, char *);
int lstat(const char *, struct stat *);
ssize_t readlink(const char *, char *, size_t);
int add_dir_to_end_list(t_par *, char *);
int add_file_to_end_list(t_dir *, char *, char *);
int conf_file(t_dir *);
void fill_rec_list(t_par *, t_rec *);
void fill_folder_list(t_par *, DIR *, char *);
int fill_dir_arg(t_par *, char *);
void read_d(t_par *);
void read_d_r(t_par *);
void my_ls_r(t_par *);
void my_ls(t_par *);
int my_strcmp_ls(char *, char *);
int set_present(t_par *, char);
void launch_ls(t_par *);
void free_str(char *);
void conf_dir_to_list(t_par *, char *, t_dir *);
void launch_read_file(t_dir *, t_par *, char *);
void print_that_debf(char, char);
void free_t_dir(t_dir *);
void print_file_color(char *, t_dir *);
void print_folder_list_col(char *, t_dir *);
void print_col_symb(char *, char);
void print_color(char *, char);
void print_spaces(t_dir *, int);
void print_symbolics(t_dir *, char);
void print_rights(t_dir *);
void print_time(t_dir *);
int print_blocks(t_par *, t_dir *);
char print_type(t_dir *);
void print_stats(t_dir *, int);
void show_stats(t_par *, t_dir *);
void show_stats_r(t_par *, t_dir *);
void conf_arg(t_par *, char *);
void replace_maj(char *);
void fill_folder_stats(DIR *, t_par *, char *);
void read_folder_list_n(t_dir *);
void read_folder_list_r(t_dir *);
void read_folder_list(t_dir *, t_par *);
void launch_read(t_par *, DIR *, char *);
void my_ls_tri_time(t_par *, t_dir *);
void my_ls_tri(t_dir *);

#endif
