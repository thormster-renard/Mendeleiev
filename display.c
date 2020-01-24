/*
** display.c for Mendeleïev Periodic Table in /home/thormster/Dev/mendeleiev
** 
** Made by thormster
** Login   <thormster@localhost>
** 
** Started on  Fri Jan 24 16:00:29 2020 thormster
** Last update Fri Jan 24 16:01:05 2020 thormster
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
    while (wit != 4)
    {
      display_table_function(table, pos);
      pos += 1;
      wit += 1;
    }
  }
  else if (table[pos - 1][0] >= '0' && table[pos - 1][0] <= '9')
  {
    while (wit != 4)
    {
      display_table_function(table, pos - 1);
      pos += 1;
      wit += 1;
    }
  }
  else if (table[pos - 2][0] >= '0' && table[pos - 2][0] <= '9')
  {
    while (wit != 4)
    {
      display_table_function(table, pos - 2);
      pos += 1;
      wit += 1;
    }
  }
  else if (table[pos - 3][0] >= '0' && table[pos - 3][0] <= '9')
  {
    while (wit != 4)
    {
      display_table_function(table, pos - 3);
      pos += 1;
      wit += 1;
    }
  }
  return (wit);
}

void		display_table_function(char **table, int i)
{
  if (((table[i][0] >= '1' && table[i][0] <= '9') && xstrlen(table[i]) == 1) && table[i][0] != '[')
    xputstr("00");
  if (((table[i][0] >= '0' && table[i][0] <= '9') && xstrlen(table[i]) == 2) && table[i][0] != '[')
    xputchar('0');
  xputstr(table[i]);
  if ((table[i][0] > '9') && (xstrlen(table[i]) < 8) && table[i][0] != '[')
    xputstr("\t\t");
  else
    xputchar('\t');
}

int		display_full_table(char **table)
{
  int		i;

  i = 0;
  while (table[i] != NULL)
  {
    set_color_element(table, i);
    display_table_function(table, i);
    if (((i + 1) % 4 == 0) && (i != 0))
      xputchar('\n');
    reset_color_table();
    i += 1;
  }
  return (0);
}
