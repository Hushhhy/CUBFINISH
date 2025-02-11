/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:14:51 by acarpent          #+#    #+#             */
/*   Updated: 2025/02/05 19:01:43 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/*---------------------------INCLUDES-------------------------------*/

# include "../libft/libft.h"
# include "struct.h"
# include "../mlx/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include <stdbool.h>

# ifndef O_DIRECTORY
#  define O_DIRECTORY 0
# endif

/*-----------------------------KEYS---------------------------------*/

enum	e_touches
{
	W = 119,
	UP = 65362,
	A = 97,
	LEFT= 65361,
	S = 115,
	DOWN = 65364,
	D = 100,
	RIGHT = 65363,
	ESC = 65307,
};

/*-------------------------WINDOW DETAILS---------------------------*/

# define WIN_HEIGHT 1080
# define WIN_WIDTH 1920

/*--------------------------GAME DETAILS----------------------------*/

# define FOV 66
# define WIN_HEIGHT 1080
# define WIN_WIDTH 1920
# define MOVE_SPEED 0.10f
# define ROT_SPEED 0.09f
# define TEXTURE_WIDTH 64
# define TEXTURE_HEIGHT 64
# define SIZE_PLAYER 3

/*----------------------------COLORS--------------------------------*/

# define RESET		"\e[0m"
# define SALMON		"\e[38;2;255;160;122m"
# define RED		"\e[38;2;255;0;0m"
# define BLACK		"\e[38;2;0;0;0m"
# define WHITE		"\e[38;2;255;255;255m"
# define GREEN		"\e[38;2;0;255;0m"
# define BLUE		"\e[38;2;0;0;255m"
# define YELLOW		"\e[38;2;255;255;0m"
# define CYAN		"\e[38;2;0;255;255m"
# define MAGENTA	"\e[38;2;255;0;255m"
# define ORANGE		"\e[38;2;255;165;0m"
# define PURPLE		"\e[38;2;138;43;226m"
# define PINK		"\e[38;2;255;192;203m"
# define BROWN		"\e[38;2;165;42;42m"
# define GREY		"\e[38;2;128;128;128m"

/*--------------------------ERROR DEF-------------------------------*/

# define ERR_ARG "./cub3d <path/to/map.cub>"
# define ERR_NAME "Has to be a .cub file"
# define ERR_IS_DIR "Is a directory"
# define ERR_ENV "Environment not found"
# define ERR_GET_FILE "File doesn't exist"
# define ERR_EMPTY "Empty file"
# define ERR_CHAR "Invalid character in map"
# define ERR_NORTH "Too many north textures"
# define ERR_SOUTH "Too many south textures"
# define ERR_EAST "Too many east textures"
# define ERR_WEST "Too many west textures"
# define ERR_FLOOR "Too many floor colors"
# define ERR_CEILING "Too many ceiling colors"
# define ERR_FORMAT "Invalid map format"
# define ERR_AFTER "Invalid characters after map"
# define ERR_NO_MAP "No map found"
# define ERR_SMALL_MAP "Map too small"
# define ERR_PLAYER "Invalid number of players"
# define ERR_CLOSED "Map not closed"
# define ERR_COLOR_FORMAT "Invalid color format"
# define ERR_COLOR_RANGE "Color out of range"
# define ERR_COMA "Invalid color format"
# define ERR_DOT "Invalid texture path"
# define ERR_MLX_INIT "Could not init mlx"
# define ERR_MLX_WIN "Could not create window"
# define ERR_XPM "Not a .xpm texture"
# define ERR_PIXEL "Pixel out of range"
# define ERR_TEXTURES "Could not load textures"

/*------------------------MAIN FUNCTIONS----------------------------*/

int		main(int ac, char **av);

/*-----------------------------INIT---------------------------------*/

void	_data_init(t_game *game);
void	_player_init(t_game *game);
void	_ray_init(t_ray *ray);
void	_mlx_struct_init(t_game *game);
void	_init_mlx(t_game *game);
void	t_img_init(t_img *img);

/*----------------------------PARSING-------------------------------*/

/*---------------------------------*/
/*--ERROR--*/

int		_error_msg_free(char *det, char *str, int code, t_game *game);
int		_err_msg_val(int detail, char *str, int code, t_game *game);
void	_free_texture(char *no, char *so, char *ea, char *we);
int		_error_msg(char *det, char *str, int code);
void	_free_colors(char *ceiling, char *floor);

/*---------------------------------*/
/*--NAME OR DIR--*/

void	_checkname(char *name);
bool	_is_directory(char *name);

/*---------------------------------*/
/*--GET FILE--*/

int		_getfile(t_game *game, char *file);
char	**_gnl_in_file(t_game *game, int lc);
char	*_new_alloc(int start, char *line);

/*---------------------------------*/
/*--FILE PARSING--*/

void	_parse_file(t_game *game);
int		_get_size(t_game *game);
void	_char_check(char *line, t_game *game);
void	_emptyfile(t_game *game);

/*---------------------------------*/
/*--TEXTURES && COLORS--*/

void	_north_check(t_game *game, char *line);
void	_south_check(t_game *game, char *line);
void	_east_check(t_game *game, char *line);
void	_west_check(t_game *game, char *line);
void	_check_texname(char *name, t_game *game);
void	_ceiling_check(t_game *game, char *line);
void	_floor_check(t_game *game, char *line);
void	_get_ceiling(char *color, t_game *game);
void	_get_floor(char *color, t_game *game);
void	_coma_check(char *color, t_game *game);
void	_point_check(t_game *game, char *s);

/*---------------------------------*/
/*--GET MAP--*/

void	_getmap(t_game *game, int i);
void	_map_realloc(t_game *game);
void	_smaller_line(t_game *game, int len, int i);
void	_verify(t_game *game, int start);
int		_is_invalid(char *line, t_game *game);
void	_after_map(t_game *game, int last);
int		_emptylines(t_game *game, int start);
int		_line_empty(char *line);
int		_get_map_size(t_game *game, int i);

/*---------------------------------*/
/*--MAP PARSING--*/

int		_get_map_width(char **map);
int		_get_map_height(char **map);
void	_check_the_map(t_game *game);
bool	_check_nb_player(char **map, t_game *game);
void	_player_pos(t_game *game, int i, int j, char c);
void	_player_cd(t_game *game, int i, int j);
bool	_there_is_walls(char **map, int row, int col);
bool	_check_closed_map(t_game *game);
bool	_check_top_bot(char *line);
bool	_check_rows(char **map, int y, int x);
bool	_check_cols(char **map, int y, int x);
bool	_check_left(char **map, int y, int i);
bool	_check_right(char **map, int y, int i);
bool	_check_up(char **map, int i, int x);
bool	_check_down(char **map, int i, int x);
bool	_check_spaces(char **map, int y, int x);
bool	_check_space_row(char **map, int y, int x);
bool	_check_space_col(char **map, int y, int x);
bool	_check_space_left(char **map, int y, int i);
bool	_check_space_up(char **map, int i, int x);
int		**_convert_map(t_game *game);

/*-----------------------------GAME---------------------------------*/

/*---------------------------------*/
/*--RENDERING--*/

int		my_mlx_pixel_put(t_game *game, int x, int y, int color);
void	dda(t_game *game, t_ray *ray);
void	calculate_wall_x(t_ray *ray, t_game *game);
void	_render(t_game *game);
void	draw_floor_ceiling(t_game *game);
int		get_texture_color(t_img *text, int x, int y);
void	calcul_ray(t_game *game, t_ray *ray, int x);
double	_calculate_perp_wall_dist(t_game *game, t_ray ray);
void	_calculate_step(t_game *game, t_ray *ray);
t_img	*select_texture(t_ray ray, t_game *game);
void	draw_walls(int x, t_ray ray, t_game *game);
void	get_textures(t_game *game);

/*---------------------------------*/
/*--MOVEMENT MANAGEMENT--*/

int		_key_press(int key, t_game *game);
int		_key_release(int key, t_game *game);
void	_handle_move(t_game *game);
void	move_forward(t_game *game, double move_speed);
void	move_backward(t_game *game, double move_speed);
void	move_left(t_game *game, double move_speed);
void	move_right(t_game *game, double move_speed);
void	rotate_left(t_game *game);
void	rotate_right(t_game *game);

/*---------------------------------*/
/*--GAME CLEARING--*/

int		_close_game(t_game *game);
void	free_textures(t_game *game);
int		_game(t_game *game);

#endif