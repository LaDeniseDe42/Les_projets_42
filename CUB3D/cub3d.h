/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 08:55:43 by akastler          #+#    #+#             */
/*   Updated: 2023/08/17 14:39:47 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "./core/utils/get_next_line/get_next_line.h"
# include "./core/utils/libft/libft.h"
# include "./.MLX42/include/MLX42/MLX42.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

# define PLAYER_SPEED 8
# define SCREEN_SIZE_X 1920
# define SCREEN_SIZE_Y 1080
# define MINIMAP_SIZE 11

# ifndef PI
#  define PI 3.14159265
# endif

typedef struct s_god
{
	int		hauteur;
	int		ciel;
	int		wall;
	int		i_pixel_y;
	int		sol;
	int		value;
	float	fish_eyes;
	int32_t	color;
	float	step;
	float	current_step;
}			t_god;

typedef struct s_position
{
	int		y;
	int		x;
}			t_pos;

typedef struct s_draaw
{
	int		dx;
	int		dy;
	int		sx;
	int		sy;
	int		err;
	int		next_x;
	int		next_y;
	int		e2;
}			t_draw;

typedef struct s_ray
{
	float	a_y;
	float	a_x;
	int		pos_a_y;
	int		pos_a_x;
	float	y_a;
	float	x_a;
	int		hit_v;
	int		hit_h;
	int		ray_nbr;
	float	angle;
	int		direction;
	char	hit;
}	t_rayx;

typedef struct s_rayt
{
	t_rayx	ray;
	t_rayx	ray_v;
	float	angle;
	int		ray_nbr;
	float	vert_dist;
	float	hori_dist;
}			t_ray;

typedef struct s_player
{
	float		fov;
	float		speed;
	float		pa;
	float		delta_x;
	float		delta_y;
	float		px;
	float		py;
}			t_player;

typedef struct s_cub
{
	int				fd_file;
	char			**complete_read;
	char			*no_texture_path;
	char			*so_texture_path;
	char			*we_texture_path;
	char			*ea_texture_path;
	char			*floor_color;
	int				floor[3];
	char			*ceilling_color;
	int				ceilling[3];
	char			**map;
	int				hauteur;
	int				largeur;
	mlx_t			*id;
	mlx_texture_t	*n_tex;
	mlx_texture_t	*s_tex;
	mlx_texture_t	*w_tex;
	mlx_texture_t	*e_tex;
	mlx_texture_t	*d_c;
	mlx_texture_t	*d_oc;
	mlx_texture_t	*d_co;
	mlx_texture_t	*d_o;
	mlx_image_t		*d_3;
	mlx_texture_t	*pf[9];
	mlx_image_t		*minimap;
	t_player		player;
	t_pos			pos;
	double			time;
	double			time_pf;
	int				what_pf;
	int				modified_y;
	int				modified_x;
	double			origin_curseur_x;
	double			origin_curseur_y;
	bool			cursor_stuck;
	int				nb_try;
}			t_cub;

typedef struct s_index
{
	int		i;
	int		j;
	int		k;
	int		l;
	int		n;
	int		w;
	int		e;
	int		s;
	int		flag;
	int		flag2;
}			t_index;

typedef struct s_read_f
{
	char	*str;
	char	*temp;
	char	*final;
}			t_read_f;

//INIT
void		init_index(t_index *index);
void		init_position(t_pos *pos);
void		init_player(t_cub *cub);
void		init_the_loop_ray(t_ray *r, t_cub *cub);

//INIT2
void		init_cub(t_cub *cub);
void		put_colors_in_tab_error(t_cub *cub);
void		exit_flood_fill_error(char *str, t_cub *cub);

//UTILS => STRING
int			line_sp(char *str);
int			str_start_with_str(char *str, char *starting);
char		*add_char(char add_this, char *to_this);

//UTILS => TAB
int			count_tab(char **tab);
void		free_tab(char **paths);
char		**ft_copy_tb(char **tb);

//UTILS_GRAPH
int			ft_pixel(int r, int g, int b, int a);
void		calcul_len_max(t_cub *cub);
void		set_lines(t_cub *cub);

//UTILS => OTHER
int			free_struct(t_cub *cub);
int			is_space(char c);
int			check_ints(char **tab);

//VERIF => CHECK FILE
int			check_file(char *file, t_cub *cub);
void		read_file(t_cub *cub);
void		parse_read(t_cub *cub);

//VERIF => CHECK FILE 2
int			fill_struct(char *str, t_cub *cub);
int			fill_struct2(char *str, t_cub *cub);
char		*subjoin(char *str);
int			find_first_chara(char *line);
char		**fill_map(t_cub *cub, int j);

//VERIF =>FLOOD
int			flood_fill(char **tab, t_cub *cub);
t_pos		find_pos(char **tab, char c);
t_pos		find_pos_player(char **tab);

//VERIF =>FLOOD
int			count_char_verif(char **tab);
int			verif_fill2(char **tab);
int			verif_fill(char **origin, char **filled);

//CORE => GRAPHIC
void		graphic(t_cub *cub);
void		set_lines(t_cub *cub);

//CORE => MOVE
void		move_handler(void *param);
void		press_right(t_cub *cub);
void		press_left(t_cub *cub);

//CORE => MOVE2
void		press_w(t_cub *cub);
void		press_a(t_cub *cub);
void		press_d(t_cub *cub);
void		press_s(t_cub *cub);

//CORE => MOVE3
int			dont_cross_wall_or_door_w(t_cub *cub);
int			dont_cross_wall_or_door_a(t_cub *cub);
int			dont_cross_wall_or_door_s(t_cub *cub);
int			dont_cross_wall_or_door_d(t_cub *cub);
int			try_again(t_cub *cub);

//CORE => LOOP
void		loop_handler(void *param);
void		set_ray_value(t_ray *r, t_cub *cub);

//CORE => DRAW

//CORE =>RAYCASTING
int			set_horizontal_ray_value(t_ray *r, t_cub *cub, float tang);
void		init_ray(t_ray *r, t_cub *cub, float tang);
int			set_vertical_ray_value(t_ray *r, t_cub *cub, float tang);
void		init_ray2(t_ray *r, t_cub *cub, float tang);

//CORE => BUILD_THE_WORD
void		set_value_of_god_building(t_god *god, t_cub *cub,
				t_rayx *ray, float dist);
void		build_south_and_west(t_god *god, t_cub *cub,
				t_rayx *ray, int id);
void		draw_my_wall_like_a_french_girl(t_god *god, t_cub *cub,
				t_rayx *ray, int id);
void		draw_nathan_face(float dist, t_cub *cub, t_rayx *ray, int id);

//CORE => N_S_W_E
void		god_color(mlx_texture_t *img, t_god *god);
void		build_south(t_god *god, t_cub *cub, t_rayx *ray);
void		build_west(t_god *god, t_cub *cub, t_rayx *ray);
void		build_est(t_god *god, t_cub *cub, t_rayx *ray);
void		build_north(t_god *god, t_cub *cub, t_rayx *ray);

//CORE => MINIMAP
void		draw_minimap_cube(t_cub *cub, t_index *k, int color);
void		draw_player(t_cub *cub);
void		minimap_handler(void *param);
void		draw_this_if(t_cub *cub, t_index i, t_pos pos);

//CORE => TEXTURE
void		image_manager(t_cub *cub);
void		load_pf(t_cub *cub);

//CORE => door_and_cursor
void		door_handler(void *param);
void		press_e(t_cub *cub);
void		cursor_hook(double x, double y, void *param);
void		action_handler(struct mlx_key_data keydata, void *param);

#endif