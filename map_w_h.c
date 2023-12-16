/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_w_h.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taelkhal <taelkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 01:08:33 by taelkhal          #+#    #+#             */
/*   Updated: 2023/12/07 01:08:33 by taelkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int lenth_width_map(char **map)
{
    int i = 0;
    while (map[0][i])
        i++;
    return(i);
}

int lenth_height_map(char **map)
{
    int i = 0;
    while (map[i])
        i++;
    return(i);
}

int get_x_player(t_map *map)
{
    int i = 0;
    int j = 0;
    while (map->map[i])
    {
        j = 0;
        while (map->map[i][j])
        {
            if (map->map[i][j] == 'N' || map->map[i][j] == 'S' || map->map[i][j] == 'W' || map->map[i][j] == 'E')
                return (j * 60);
            j++;
        }
        i++;
    }
    return (0);
}

int get_y_player(t_map *map)
{
    int i = 0;
    int j = 0;
    while (map->map[i])
    {
        j = 0;
        while (map->map[i][j])
        {
            if (map->map[i][j] == 'N' || map->map[i][j] == 'S' || map->map[i][j] == 'W' || map->map[i][j] == 'E')
                return (i * 60);
            j++;
        }
        i++;
    }
    return (0);
}