/*
** header.h for Mendeleïev Periodic Table in /home/thormster/Dev/mendeleiev
** 
** Made by thormster
** Login   <thormster@localhost>
** 
** Started on  Tue Jan 21 11:29:59 2020 thormster
** Last update Fri Jan 24 16:01:19 2020 thormster
*/

#ifndef		__HEADER_H__
# define	__HEADER_H__

#include	<ncurses.h>
#include	<stdlib.h>
#include	<string.h>
#include	<unistd.h>

#define		BLOCKSIZE	2825
#define		XERROR		-1

void		set_color_element(char**, int);
void		reset_color_table();

void		xputchar(char);
void		xputstr(char*);
int		xstrlen(char*);

int		display_line(char**, int);
void		display_table_function(char**, int);
int		display_full_table(char**);
char		*init_file();
int		strlen_s(char*, int);
void		free_table(char**);

int		word_len(char*, int, char);
int		word_count(char*, char);
  char		**my_str_to_wordtab(char*, char);

#endif /* __HEADER_H__ */
