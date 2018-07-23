/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaporoz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 17:36:29 by azaporoz          #+#    #+#             */
/*   Updated: 2018/07/23 17:37:35 by azaporoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H

# define WOLF_H
# include <GLFW/glfw3.h>

typedef struct  t_data
{
    int         **map_coord;
    int         chars;
    int         lines;
}               s_data;
#endif
