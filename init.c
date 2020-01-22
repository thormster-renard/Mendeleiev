/*
** init.c for Mendeleïev Periodic Table in /home/thormster/Dev/mendeleiev
** 
** Made by thormster
** Login   <thormster@localhost>
** 
** Started on  Tue Jan 21 13:32:59 2020 thormster
** Last update Tue Jan 21 21:11:19 2020 thormster
*/

#include	"header.h"

char		*init_file()
{
  FILE		*file;
  char		*buffer;
  int		nb;

  file = NULL;
  if ((file = fopen("./Mendeleïev_Periodic_Table.txt", "r")) == NULL)
    return (NULL);
  if ((buffer = malloc((BLOCKSIZE + 1) * sizeof(char))) == NULL)
    return (NULL);
  if ((nb = fread(buffer, 1, BLOCKSIZE + 1, file)) == ERR)
    return (NULL);
  buffer[nb - 1] = '\0';
  fclose(file);
  return (buffer);
}
