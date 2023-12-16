#ifndef CUB3D_H
# define CUB3D_H



# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include "minilibx-linux/mlx.h"
# include "get_next_line/get_next_line.h"
#define pi 3.1415926535


# define TAIL 150
# define SCALE 0.005
# define WIN_W  1400
# define WIN_H  800

typedef struct s_map
{
    int width;
    int height;
    char **map;
}           t_map;

typedef struct s_player
{
    float x;
    float y;
    float pdx;
    float pdy;
    float angle;
}t_player;

typedef struct s_castrays
{
    int r;
    int mx;
    int my;
    int mp;
    int dof;
    float rx;
    float ry;
    float ra;
    float xo;
    float yo;
}t_castrays;

typedef struct s_game
{
    void *mlx;
    void *win;
    void *img;
    char *addr;
    int    bits_per_pixel;
    int   line_length;
	int		endian;
    int player_size;
    int size_px_map;
    t_map *map;
    t_player *player;
    t_castrays *castrays;
}t_game;

//init_structs
t_map *init_map(char *path);
t_player *init_player(t_map *map);
// void init_game(t_game *game,t_map *map);
void init_game(t_game *game,t_map *map, t_castrays *castrays);

//libft

void    ft_putstr(char *str, int fd);
char    **ft_split(char const *s, char c);
// char *ft_strdup(const char *s1);
int ft_strcmp(const char *s1, const char *s2);
// size_t	ft_strlen(const char *str);
// char	*ft_strjoin(char *s1, char *s2);

char **read_map(char *path);
int lenth_width_map(char **map);
int lenth_height_map(char **map);
void draw_map(t_game *game);
void draw_player(t_game *game, int x, int y);
int get_x_player(t_map *map);
int get_y_player(t_map *map);
void draw_thick_line(t_game *game, int x1, int y1, int x2, int y2, int color);
void	my_mlx_pixel_put(t_game *data, int x, int y, int color);
//raycasting
void castoneray(t_game *game);
float degtorad(float angle);
#endif