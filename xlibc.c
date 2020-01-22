/*
** xlibc.c for Medev in /home/thormster/Dev/Melev/lib
** 
** Made by thormster
** Login   <thormster@localhost>
** 
** Started on  Sat Dec 28 23:30:00 2019 thormster
** Last update Tue Jan 21 13:33:52 2020 thormster
*/

#include	"header.h"

void		xputchar(char c)
{
  write(1, &c, 1);
}

void		xputstr(char *s)
{
  int		i;

  i = 0;
  while (s[i] != '\0')
    {
      xputchar(s[i]);
      i += 1;
    }
}

int		xstrlen(char *s)
{
  int		i;

  i = 0;
  while (s[i] != '\0')
    i += 1;
  return (i);
}

int		strlen_s(char *buf, int pos)
{
  int		len;

  len = pos;
  while (buf[len] != '\n' && buf[len] != '\0')
    len += 1;
  return (len);
}
