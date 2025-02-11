/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrellie <pgrellie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 10:35:31 by codespace         #+#    #+#             */
/*   Updated: 2025/01/31 14:51:35 by pgrellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <stdbool.h>

/*----------------------Structs and lists---------------------------*/

typedef struct s_vector2_d
{
	double		x;
	double		y;
}				t_vector2_d;

typedef struct s_data
{
	char	**file;
	int		fd;
	char	*no_texture;
	char	*so_texture;
	char	*we_texture;
	char	*ea_texture;
	char	*floor_color;
	char	*ceiling_color;
	int		ceiling_rgb;
	int		floor_rgb;
	char	**map;
	int		**map_int;
	int		map_width;
	int		map_height;
	int		y;
}				t_data;

typedef struct s_player
{
	int			p_count;
	t_vector2_d	pos;
	t_vector2_d	dir;
	t_vector2_d	plane;
}	t_player;

typedef struct s_img
{
	char		*neso_texures;
	int			player;
	int			height;
	int			width;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			color;
	int			tex_x;
	int			tex_y;
	double		wall_x;
	double		step;
	double		tex_pos;
}				t_img;

typedef struct s_draw_line
{
	int		x;
	int		start;
	int		end;
	int		tex_x;
	t_img	*texture;
}				t_draw_line;

typedef struct s_ray
{
	t_vector2_d	raydir;
	t_vector2_d	sidedist;
	t_vector2_d	deltadist;
	double		perp_walldist;
	double		wall_x;
	int			lineheight;
	int			start;
	int			end;
	int			color;
	int			mapx;
	int			mapy;
	int			stepx;
	int			stepy;
	int			side;
}	t_ray;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*img_data;
	int		bpp;
	int		size_line;
	int		endian;
	char	*addr;
}	t_mlx;

typedef struct s_key
{
	bool	left_pressed;
	bool	right_pressed;
	bool	key[256];
}	t_key;

typedef struct s_game
{
	t_mlx		mlx;
	t_ray		ray;
	t_player	player;
	t_data		data;
	t_key		key;
	t_img		img;
	t_img		text[4];
}	t_game;

#endif