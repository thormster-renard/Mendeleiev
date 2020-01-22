/*
** main.c for Mendeleïev Periodic Table in /home/thormster/Dev/mendeleiev
** 
** Made by thormster
** Login   <thormster@localhost>
** 
** Started on  Tue Jan 21 11:30:18 2020 thormster
** Last update Tue Jan 21 22:00:03 2020 thormster
*/

#include	"header.h"

int		display_line(char **table, int i)
{
  int		wit;
  int		pos;

  pos = i;
  wit = 0;
  if (table[pos][0] >= '0' && table[pos][0] <= '9')
  {
    while (wit != 3)
    {
      display_table_function(table, pos);
      pos += 1;
      wit += 1;
    }
  }
  else if (table[pos - 1][0] >= '0' && table[pos - 1][0] <= '9')
  {
    while (wit != 3)
    {
      display_table_function(table, pos - 1);
      pos += 1;
      wit += 1;
    }
  }
  else if (table[pos - 2][0] >= '0' && table[pos - 2][0] <= '9')
  {
    while (wit != 3)
    {
      display_table_function(table, pos - 2);
      pos += 1;
      wit += 1;
    }
  }
  return (wit);
}

void		display_table_function(char **table, int i)
{
  if ((table[i][0] >= '1' && table[i][0] <= '9') && xstrlen(table[i]) == 1)
    xputstr("00");
  if ((table[i][0] >= '0' && table[i][0] <= '9') && xstrlen(table[i]) == 2)
    xputchar('0');
  xputstr(table[i]);
  if ((table[i][0] > '9') && (xstrlen(table[i]) < 8))
    xputstr("\t\t");
  else
    xputchar('\t');
}

int		full_table(char **table)
{
  int		i;

  i = 0;
  while (table[i] != NULL)
  {
    display_table_function(table, i);
    if (((i + 1) % 3 == 0) && (i != 0))
      xputchar('\n');
    i += 1;
  }
  return (0);
}

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
    i += 1;
  }
  xputchar('\n');
  if (y == 0)
    return (ERR);
  return (0);
}

int		main(int ac, char **av)
{
  char		**table;
  char		*tmp;

  if ((tmp = init_file()) == NULL)
    return (ERR);
  if ((table = my_str_to_wordtab(tmp, ',')) == NULL)
    return (ERR);
  if (ac == 1)
  {
    if ((full_table(table)) == ERR)
      return (ERR);
  }
  else if (ac == 2)
  {
    if ((search_element(table, av[1])) == ERR)
      xputstr("L'élement n'existe pas ou a été mal orthographié\n");
  }
  free(tmp);
  free_table(table);
  return (0);
}
