/*
** main.c for Mendeleïev Periodic Table in /home/thormster/Dev/mendeleiev
** 
** Made by thormster
** Login   <thormster@localhost>
** 
** Started on  Tue Jan 21 11:30:18 2020 thormster
** Last update Fri Jan 24 16:01:13 2020 thormster
*/

#include	"header.h"

int		search_element(char **table, char *element)
{
  int		len;
  int		i;
  int		y;

  i = 0;
  y = 0;
  len = xstrlen(element);
  while (table[i] != NULL)
  {
    if ((strncmp(table[i], element, len)) == 0)
      y = display_line(table, i);
    if (y != 0)
      break;
    i += 1;
  }
  xputchar('\n');
  if (y == 0)
    return (XERROR);
  return (0);
}

int		main(int ac, char **av)
{
  char		**table;
  char		*tmp;

  if ((tmp = init_file()) == NULL)
    return (XERROR);
  if ((table = my_str_to_wordtab(tmp, ',')) == NULL)
    return (XERROR);
  if (ac == 1)
  {
    if ((display_full_table(table)) == XERROR)
      return (XERROR);
  }
  else if (ac == 2)
  {
    if ((search_element(table, av[1])) == XERROR)
      xputstr("L'élement n'existe pas ou a été mal orthographié\n");
  }
  free(tmp);
  free_table(table);
  return (0);
}
