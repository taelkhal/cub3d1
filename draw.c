/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taelkhal <taelkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 02:58:37 by taelkhal          #+#    #+#             */
/*   Updated: 2023/11/27 02:58:37 by taelkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	my_mlx_pixel_put(t_game *data, int x, int y, int color)
{
	char	*dst;

	// if (x <= 0 || x >= 720 || y <= 0 || y >= 720)
	// 	return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void draw_h_v_lines(t_game *game)
{
    int j;
    int i;

    i = 0;
    while (i < game->map->height)
    {
        j = 0;
        while (j < game->map->width * game->size_px_map)
        {
            mlx_pixel_put(game->mlx, game->win, j, i * game->size_px_map, 0x000000);
            j++;
        }
        i++;
    }
    i = 0;
    while (i < game->map->width)
    {
        j = 0;
        while (j < game->map->height * game->size_px_map)
        {
            mlx_pixel_put(game->mlx, game->win, i * game->size_px_map, j, 0x000000);
            j++;
        }
        i++;
    }
}

void draw_map(t_game *game)
{
    int x;
    int y;

    y = 0;
    while (y < game->map->width)
    {
        x = 0;
        while (x < game->map->height)
        {
            int i = x * game->size_px_map;
            while (i < x * game->size_px_map + game->size_px_map/*&& i < 18*/)
            {
                int j = y * game->size_px_map;
                while (j < y * game->size_px_map + game->size_px_map /*&& j < 6*/)
                {
                    if (game->map->map[x][y] == '1')
                        my_mlx_pixel_put(game, j, i, 0xFFFFFF);
                    if (game->map->map[x][y] != '1' && game->map->map[x][y] != ' ' && game->map->map[x][y] != '\n')
                        my_mlx_pixel_put(game, j, i, 0x808080);
                    j++;
                }
                i++;
            }
            x++;
        }
        y++;
    }
    // draw_player(game, game->player->x, game->player->y);
}

void draw_player(t_game *game, int x, int y)
{
    int i, j;

    for (i = 0; i < game->player_size; i++) {
        for (j = 0; j < game->player_size; j++) {
            my_mlx_pixel_put(game, x + i, y + j, 0x0000FF);
        }
    }
}

void draw_thick_line(t_game *game, int x1, int y1, int x2, int y2, int color)
{
    int dx = x2 - x1;
    int dy = y2 - y1;

    int sx, sy;
    if (dx < 0) {
        sx = -1;
        dx = -dx;
    } else {
        sx = 1;
    }

    if (dy < 0)
    {
        sy = -1;
        dy = -dy;
    }
    else
        sy = 1;

    int err = dx - dy;
    while (x1 != x2 || y1 != y2)
    {
        my_mlx_pixel_put(game, x1, y1, color);
        int err2 = 2 * err;

        if (err2 > -dy)
        {
            err -= dy;
            x1 += sx;
        }

        if (err2 < dx) {
            err += dx;
            y1 += sy;
        }
    }
    my_mlx_pixel_put(game, x2, y2, color);
}