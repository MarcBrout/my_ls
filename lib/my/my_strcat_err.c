/*
** my_strcat_err.c for my_strcat_err in /home/brout_m/dev/lib
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Tue Oct  6 13:37:20 2015 marc brout
** Last update Sat Nov 28 20:23:07 2015 marc brout
*/

#include <stdlib.h>

char	*my_strcat_err(char *str1, char *str2)
{
  int	i;
  int	j;
  char	*res;

  if ((res = malloc(my_strlen(str1) + my_strlen(str2) + 1)) == NULL)
    return (NULL);
  i = 0;
  j = 0;
  while (str1[i])
    res[i] = str1[i++];
  while (str2[j])
    res[i++] = str2[j++];
  res[i] = 0;
  return (res);
}
