/*
** free.c for Mendeleïev Periodic Table in /home/thormster/Dev/mendeleiev
** 
** Made by thormster
** Login   <thormster@localhost>
** 
** Started on  Fri Jan 24 15:59:57 2020 thormster
** Last update Fri Jan 24 16:00:12 2020 thormster
*/

#include	"header.h"

void		free_table(char **tb)
{
  int		i;

  i = 0;
  while (tb[i] != NULL)
  {
    free(tb[i]);
    i += 1;
  }
  free(tb);
}
