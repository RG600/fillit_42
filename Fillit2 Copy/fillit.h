/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosgill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 12:02:25 by rosgill           #+#    #+#             */
/*   Updated: 2019/08/05 12:04:16 by rosgill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
#define FILLIT_H
#include "libft/libft.h"
#include <fcntl.h>
#include <stdio.h>

#define BUFF_SIZE 4

typedef	struct	s_array
{
	char	letter;
	int		x[4];
	int		y[4];
}	t_array;

int main(int argc, char **argv);
int parse(char *files);
int validate_tetri(char *buff, int bytes_amount);
int	miscellaneous_counter(char *buff);
int miscellaneous_hashtag_period_newline_check(char *buff, int i, int hashtag_counter, int period_counter, int new_line_counter);
int	miscellaneous_final_checker(int hashtag_counter, int period_counter, int new_line_counter);
int	touches(char *buff);
int check_touches(char *buff, int i, int touch);
int	find_tetris_pieces(char *files);
int	findmapsize(int numoftets);
int	before_get_coordinates(char *files, t_array *sp, int numoftets);
char **read_files_save_to_char(int fd);
int	get_next_line(const int fd, char **line);
int	b_check(int bytes, char *str[4864], const int fd, char **line);
int	find_newline_savetoline(char **stack, char **line);
t_array get_coordinates(char **buff, t_array *sp, int structcounter);
int move_coordinates_top_left(t_array *sp, int structcounter);
int move_to_top_left(t_array *sp, int structcounter, int counter, int x1, int y1);
char **finding_map_making_map(int numoftets);
char **make_map(int mapsize);
char  **fill_it(char **map, t_array sp[26], int mapsize, int numoftets, int i);
int fill_map(char **map, t_array sp[26], int mapsize, int numoftets, int i);
int find_open_space(char **map, t_array sp[26], int temp_x, int temp_y, int mapsize, int counter, int i);
char **place_pieces(char **map, t_array sp[26], int temp_x, int temp_y, int counter, int i);
char **remove_pieces(char **map, t_array sp[26], int temp_x, int temp_y, int counter, int i);
void	print_map(char **map);

#endif