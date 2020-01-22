/*
** my_str_to_wordtab.c for Mendeleïev Periodic Table in /home/thormster/Dev/my_str_to_wordtab
** 
** Made by thormster
** Login   <thormster@localhost>
** 
** Started on  Tue Dec 31 00:07:21 2019 thormster
** Last update Tue Jan 21 13:32:44 2020 thormster
*/

#include	"header.h"

int		word_len(char *str, int i, char delim)
{
  int		l;

  l = 0;
  while (str[i] && str[i] != delim)
    {
      l += 1;
      i += 1;
    }
  return (l);
}

int		word_count(char *str, char delim)
{
  int		wd;
  int		i;

  i = 0;
  wd = 1;
  while (str[i])
    {
      if (str[i] == delim)
	wd += 1;
      i += 1;
    }
  return (wd);
}

char		**my_str_to_wordtab(char *s, char delim)
{
  char          **tab;
  int		i;
  int           j;
  int           k;

  i = 0;
  j = 0;
  if ((tab = malloc((word_count(s, delim) + 1) * sizeof(char *))) == NULL)
    return (NULL);
  while (s[i])
    {
      k = 0;
      if ((tab[j] = malloc((word_len(s, i, delim) + 1) *
			   sizeof(char))) == NULL)
	return (NULL);
      while (s[i] && s[i] != delim)
	tab[j][k++] = s[i++];
      while (s[i] == delim)
	i += 1;
      tab[j][k] = '\0';
      j += 1;
    }
  tab[j] = '\0';
  return (tab);
}
