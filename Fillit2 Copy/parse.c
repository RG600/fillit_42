/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosgill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 12:37:44 by rosgill           #+#    #+#             */
/*   Updated: 2019/09/23 13:51:53 by rosgill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

//Validate if all tetriminoes are correctly inputed
//Save the coordinates of the tetriminoes into structs
//Fill map using recursion
//Print final map
int parse(char *files)
{
	int i;
	int fd;
	int bytes;
	int numoftets;
	int mapsize;
	char buff[545];
	char **map;
	char **filledmap;
	t_array sp[26];

	i = 0;
	fd = open(files, O_RDONLY);
	bytes = read(fd, buff, 545);
	close(fd);
	buff[bytes] = '\0';
	numoftets = find_tetris_pieces(files);
	mapsize = findmapsize(numoftets);
	if (numoftets > 26 || numoftets <= 0)
		return (-1);
	if (validate_tetri(buff, bytes) == -1)
		return (-1);
	before_get_coordinates(files, sp, numoftets);
	map = finding_map_making_map(numoftets);
	filledmap = fill_it(map, sp, mapsize, numoftets, i);
	print_map(filledmap);
	return (0);
}

//Validates all inputed tetriminoes have specific variables 
//Validates if all inputed tetriminoes are the correct piece 
//(A piece is valid if it has 6 or 8 touches) 
int validate_tetri(char *buff, int bytes_amount)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i <= bytes_amount)
	{
		if (miscellaneous_counter(buff + i) == 0 && (bytes_amount <= (i + 21)))
			break;
		if (miscellaneous_counter(buff + i) == -1)
			return (-1);
		i += 21;
	}
	while (j <= bytes_amount)
	{   
		if (touches(buff + j) != 6 && touches(buff + j) != 8)
			return (-1);
		j += 21;
	}
	return (0);
}

//Inititalizes all the variables
//Calls the main checker function
//Will return either -1 for error, 1 to continue checking, 0 if all are correct and validated 
int miscellaneous_counter(char *buff)
{
	int i;
	int return_value;
	int hashtag_counter;
	int period_counter;
	int new_line_counter;

	i = 0;
	hashtag_counter = 0;
	period_counter = 0;
	new_line_counter = 0;
	return_value = miscellaneous_hashtag_period_newline_check(buff, i, hashtag_counter, period_counter, new_line_counter);
	return (return_value);
}

//Checks for the correct amount of hashtags, periods, newlines in a tetrimino
int miscellaneous_hashtag_period_newline_check(char *buff, int i, int hashtag_counter, int period_counter, int new_line_counter)
{
	while (i <= 19)
	{
		if (buff[i] == '#')
			hashtag_counter++;
		if (buff[i] == '.')
			period_counter++;
		if (buff[i] == '\n')
			new_line_counter++;
		if (buff[i] != '#' && buff[i] != '.' && buff[i] != '\n' && buff[i] != '\0')
			return (-1);
		if (buff[i] != '#' && buff[i] != '.' && buff[i] == '\0' && i == 19)
		{
			if (miscellaneous_final_checker(hashtag_counter, period_counter, new_line_counter) == 0)
				return (0);
		}
	i++;
	}
	if (miscellaneous_final_checker(hashtag_counter, period_counter, new_line_counter) == 1)
		return (1);
	return (-1);
}

//Checks if the amount of hashtags, periods, and newlines are correct
//Also checks if the tetrimino is the last one or there are more remaining
int	miscellaneous_final_checker(int hashtag_counter, int period_counter, int new_line_counter)
{
	if (hashtag_counter == 4)
	{
		if (period_counter == 12)
		{
			if (new_line_counter == 3)
				return (0);
			else if (new_line_counter == 4)
				return (1);
		}
	}
	return (-1);
}

//Will call the check_touches and will return touch
int touches(char *buff)
{
	int i;
	int touch;

	i = 0;
	touch = 0;
	while (i < 19)
	{
		touch = check_touches(buff, i, touch);
		i++;
	}
return (touch);
}

//Will check the top, bottom, left, and right of the hashtag's position
//If there is another hashtag at those positions we will increment touch
//Return touch
int check_touches(char *buff, int i, int touch)
{
	if (buff[i] == '#')
	{
		if (buff[i + 1] == '#')
			touch++;
		if (buff[i - 1] == '#')
			touch++;
		if (buff[i + 5] == '#')
			touch++;
		if (buff[i - 5] == '#')
			touch++;              
	}
return (touch);
}

//This function will use the open and read functions to find the exact amount of bytes used in the file
//We will divide by 21 because that's the amount of bytes each tetrimino should hold
//Check if it's a valid amount of tetriminoes and return them
int	find_tetris_pieces(char *files)
{
	int	numoftets;
	int bytes;
	int	tempfiles;
	char *buff;

	numoftets = 0;
	buff = malloc(sizeof(char) * 545);
	bytes = 0;
	tempfiles = open(files, O_RDONLY);
	bytes = read(tempfiles, buff, 545);
	close(tempfiles);
	if (bytes >= 19 && bytes <= 545)
	{
		numoftets = (bytes / 21) + 1;
		if (numoftets > 26 || numoftets <= 0)
		{
			return (-1);
		}
		else
		{
			return (numoftets);
		}
	}
	else
		return (-1);
}

//A simple equation that finds the minimum map size we need to begin with
int	findmapsize(int numoftets)
{
	int i;
	int count;

	count = 0;
	i = 1;	
	numoftets = (numoftets * 4);
	while (count < 26)
	{
		if (i * i >= numoftets)
			return (i);
		else
		{
			i++;
			count++;
		}
	}
	return (-1);
}

//Function that will save per 21 bytes into **char variable buff
//Get the coordintates of each hashtag and save into the struct
//Move the coordinates to the top left
int	before_get_coordinates(char *files, t_array *sp, int numoftets)
{
	int letter;
	int struct_counter;
	int fd;
	char **buff;

	letter = 'A';
	struct_counter = 0;
	fd = open(files, O_RDONLY);
	while (struct_counter < numoftets)
	{
		buff = (read_files_save_to_char(fd));
		get_coordinates(buff, sp, struct_counter);
		move_coordinates_top_left(sp, struct_counter);
		free(buff);
		sp[struct_counter].letter = letter;
		letter++;
		struct_counter++;
	}
	close(fd);
	return (0);
}

//Malloc enough space for char **buff
//Use our get_next_line function to read and save per line
//Read only 4 lines and return buff
char **read_files_save_to_char(int fd)
{
	int i;
	char **buff;
	char *line;

	i = 0;
	buff = (char**)malloc(sizeof(char*) * 20);
	while (i < 4)
	{
		if (get_next_line(fd, &line) == 1)
		{
			buff[i] = ft_strdup(line);
			i++;
			free(line);
		}
		else
			exit(0);	
	}
	if (get_next_line(fd, &line) == 1)
		free(line);
	else
	{
		return (buff);
	}
	return (buff);
}

//This function returns a line read from a file descriptor
int	get_next_line(const int fd, char **line)
{
	static char	*str[4864];
	char		buff[BUFF_SIZE + 1];
	int			bytes;
	char		*temp;

	if (fd < 0 || !line)
		return (-1);
	while ((bytes = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[bytes] = '\0';
		if (!str[fd])
			str[fd] = ft_strdup(buff);
		else
		{
			temp = ft_strjoin(str[fd], buff);
			free(str[fd]);
			str[fd] = temp;
		}
		if (ft_strchr(str[fd], '\n'))
			break ;
	}
	return (b_check(bytes, str, fd, line));
}

//Part of get_next_line
int	b_check(int bytes, char *str[4864], const int fd, char **line)
{
	if (bytes < 0)
		return (-1);
	else if (bytes == 0 && !str[fd])
		return (0);
	else
		return (find_newline_savetoline(&str[fd], line));
}

//Part of get_next_line
int	find_newline_savetoline(char **stack, char **line)
{
	char	*i;
	char	*temp;

	if ((*stack)[0] == '\0')
		return (0);
	temp = ft_strdup(*stack);
	ft_memdel((void**)stack);
	if ((i = ft_strchr(temp, '\n')))
	{
		*i = '\0';
		*line = ft_strdup(temp);
		*stack = ft_strdup(i + 1);
		ft_memdel((void**)&temp);
	}
	else
	{
		*line = ft_strdup(temp);
		ft_memdel((void**)stack);
	}
	return (1);
}

//This function will find the coordinates position and save it into the struct
t_array get_coordinates(char **buff, t_array *sp, int structcounter)
{
	int x;
	int y;
	int counter;

	x = 0;
	y = 0;
	counter = 0;
	while (counter < 4)
	{
		while (x < 4)
		{
			while (y < 4)
			{
				if (buff[x][y] == '#')
				{
					sp[structcounter].x[counter] = x;
					sp[structcounter].y[counter] = y;
					counter++;
				}
				y++;
			}
		y = 0;
		x++;	
		}
	}
	return (*sp);
}

//This function will move every tetriminoes position to the top left
int move_coordinates_top_left(t_array *sp, int structcounter)
{
	int counter;
	int x1;
	int y1;
	int temp_x;
	int temp_y;

	counter = 0;
	temp_x = sp[structcounter].x[counter];
	temp_y = sp[structcounter].y[counter];
	x1 = temp_x;
	y1 = temp_y;
	while (counter < 4)
	{
		if (counter == 0)
		{
			sp[structcounter].x[counter] = temp_x - x1;
			sp[structcounter].y[counter] = temp_y - y1;
			counter++;
		}
		if (!(move_to_top_left(sp, structcounter, counter, x1, y1) == 1))
			return (-1);
		counter++;
	}
	return (0);
}

//Part of move_coordinates_top_left
int move_to_top_left(t_array *sp, int structcounter, int counter, int x1, int y1)
{
	int temp_x;
	int temp_y;

	temp_x = sp[structcounter].x[counter];
	temp_y = sp[structcounter].y[counter];
	if (counter < 4)
	{
		sp[structcounter].x[counter] = temp_x - x1;
		sp[structcounter].y[counter] = temp_y - y1;
		return (1);
	}
	return (-1);
}

//Uses findmapsize to find map
//Initializes make map into map and return it
char **finding_map_making_map(int numoftets)
{
	int mapsize;
	char **map;
	
	mapsize = findmapsize(numoftets);
	map = make_map(mapsize);
	return (map);
}

//Uses the mapsize value to make a valid map full of periods
char **make_map(int mapsize)
{
	int x;
	int y;
	int i;
	char **map;

	x = 0;
	y = 0;
	i = 0;
	map = (char**)malloc(sizeof(char*) * mapsize);
	while (i < mapsize)
	{	
		map[i] = (char*)malloc(mapsize + 1);
		i++;
	}
	while (x < mapsize)
	{
		while (y < mapsize)
		{
			map[x][y] = '.';
			y++;    
		}
	x++;
	y = 0;
	}
	return (map);
}

//Calls the fill_map function
//If the fill_map function does not successfully place all pieces within the map, we will make the map bigger by 1 and try again
//Once fill_map is done we will return the valid map
char  **fill_it(char **map, t_array sp[26], int mapsize, int numoftets, int i)
{
	while (fill_map(map, sp, mapsize, numoftets, i) == 0)
	{
		free(map);
		mapsize++;
		map = make_map(mapsize);
		i = 0;
	}
	return (map);
}

//Find open space, if all pieces fit, place them, call the find_open_space function again until all tetriminoes are filled
//If a piece does not fit, remove the previous piece and place it in a new spot, try again
//If there is no solution then return 0
int fill_map(char **map, t_array sp[26], int mapsize, int numoftets, int i)
{
	int x;
	int y;
	int temp_x;
	int temp_y;
	int counter;

	x = 0;
	y = 0;
	temp_x = 0;
	temp_y = 0;
	counter = 0;

	if (i == numoftets)
		return (1);
	while (x < mapsize)
	{
		while (y < mapsize)
		{
			if (map[x][y] == '.')
			{
				temp_x = x;
				temp_y = y;
				counter = find_open_space(map, sp, temp_x, temp_y, mapsize, 0, i);
				if (counter == 4)
    			{
					map = place_pieces(map, sp, temp_x, temp_y, 0, i);
					if (!(fill_map(map, sp, mapsize, numoftets, i + 1) == 1))
					{
						map = remove_pieces(map, sp, temp_x, temp_y, counter, i);
						temp_x = 0;
						temp_y = 0;
						counter = 0;
					}
					else	
						return (1);
				}
			}
			y++;
		}
		x++;
		y = 0;
	}
return (0);
}

//First checks if all the pieces that may be placed are within the map's parameters
//Then check if all the pieces that may be placed have open spots aka periods 
int find_open_space(char **map, t_array sp[26], int temp_x, int temp_y, int mapsize, int counter, int i)
{	
	int outofboundscounter;
	int replacement_map;

	replacement_map = mapsize;
	replacement_map--;
	outofboundscounter = 1;
	while (outofboundscounter != 4)
	{
		if ((sp[i].x[outofboundscounter] + temp_x >= 0) && (sp[i].y[outofboundscounter] + temp_y >= 0)
		&& (sp[i].x[outofboundscounter] + temp_x <= replacement_map) && (sp[i].y[outofboundscounter] + temp_y <= replacement_map))
			outofboundscounter++;
		else
			return (counter);
	}
	while (counter != 4)
	{
		if (map[sp[i].x[counter] + temp_x][sp[i].y[counter] + temp_y] == '.')
			counter++;
		else
			return (counter);
	}
	return (counter);
}

//Set all the coordinates to the specific letter
char **place_pieces(char **map, t_array sp[26], int temp_x, int temp_y, int counter, int i)
{
	while (counter != 4)
	{
		map[sp[i].x[counter] + temp_x][sp[i].y[counter] + temp_y] = sp[i].letter;
		counter++; 
	}
	return (map);
}

//Place periods to the specific coordinates making them open spots once again 
char **remove_pieces(char **map, t_array sp[26], int temp_x, int temp_y, int counter, int i)
{
	counter--;
	while (counter != -1)
	{
		(map[sp[i].x[counter] + temp_x][sp[i].y[counter] + temp_y] = '.');
		counter--;
	}
	return (map);
}

//Prints out the final map
void	print_map(char **map)
{
	int i;
	int j;
	int size;

	i = 0;
	j = 0;
	size = ft_strlen(map[0]);
	while (i < size)
	{
		while (j < size)
		{
			ft_putchar(map[i][j]);
			j++;
		}
		j = 0;
		i++;
		ft_putchar('\n');
	}
}