/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   castrays.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taelkhal <taelkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:54:00 by taelkhal          #+#    #+#             */
/*   Updated: 2023/12/11 15:54:00 by taelkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

float fixang(float ang)
{
    if (ang < 0)
        ang += 360.0;
    if (ang > 360.0)
        ang -= 360.0;
    return (ang);
}

void castoneray(t_game *game)
{
    int i = 0;float x, y;
    game->castrays->ra = fixang(game->player->angle - 30.0);
    while (i < WIN_W)
    {
        game->castrays->rx = game->player->x;
        game->castrays->ry = game->player->y;
        x = cos(degtorad(game->castrays->ra));
        y = sin(degtorad(game->castrays->ra));
        while (1)
        {
            if (game->map->map[(int)(game->castrays->ry + y) / 64][(int)(game->castrays->rx + x) / 64] == '1')
                break;
            game->castrays->rx += x;
            game->castrays->ry += y;
            my_mlx_pixel_put(game, game->castrays->rx, game->castrays->ry, 0x00FF00);
        }
        // draw_line(game, game->player->x, game->player->y, game->castrays->rx, game->castrays->ry, 0x0000FF);
        // draw_thick_line(game, game->player->x, game->player->y, game->castrays->rx  + game->castrays->r , game->castrays->ry - game->castrays->r , 0xFF0000);
        // draw_thick_line(game, game->player->x, game->player->y, game->castrays->rx, game->castrays->ry, 0xFF0000);
        game->castrays->ra += 60.0 / (WIN_W);
        game->castrays->ra = fixang(game->castrays->ra);
        i++;
    }
}