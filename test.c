void			textures(t_env *e, t_ray *ray, t_texture *t)
{
	t->type = set_wallpaper(ray->dir);
	t->x_offset = (ray->dir == EAST || ray->dir == WEST) ? \
		ray->y - (((int)ray->y / TILE_SIZE) * TILE_SIZE) : \
		ray->x - (((int)ray->x / TILE_SIZE) * TILE_SIZE);
	t->x = ((double) t->x_offset / TILE_SIZE) * e->textures[t->type]->w;
}

/*
** temp is the wall height, but remaining static because it needs to be a counter
** the wall_h in wall->ytexture (the fifrst statement inside the while loop) needs
** to change to be a percentage of what it should be
*/
void			draw_wallpiece(t_env *e, t_ray *ray, int x)
{
	int			wall_h;
	int			topmost_pixel;
	int			i;
	t_texture	*t;
	int			temp;
	double		y_increment;
	double		percentage;

	i = 0;
	if (ray->s == INT_MAX)
		return ;
	if (!(t = ft_memalloc(sizeof(t_texture))))
		return ;
	textures(e, ray, t);
	wall_h = (int)(e->p->c / ray->s) + 1;
	topmost_pixel = (wall_h > WINDOW_W) ? 0 : (WINDOW_W / 2) - (wall_h / 2);
	temp = (wall_h > WINDOW_W) ? WINDOW_W : wall_h;
	t->y_offset = (wall_h > WINDOW_W) ? grab_y_offset(e, ray) : 0;
	percentage = (wall_h > WINDOW_W) ? 1 - (t->y_offset * 2) : 1;
	y_increment = (1 - (t->y_offset * 2)) / WINDOW_H;
	while (i <= temp)
	{
		if (wall_h > WINDOW_W)
			t->y = (double) ((i * y_increment) + t->y_offset) * e->textures[t->type]->h;
		else
			t->y = (double) ((i / (percentage * wall_h)) + t->y_offset) * e->textures[t->type]->h;
		insert_bitmap(e->img, x, topmost_pixel + i, grab_color(e, \
			t->x, t->y, t->type));
		i++;
	}
}


void			setup_texture(t_ray *ray)
{
	t->type = set_wallpaper(ray->dir);
}


/*
** temp is the wall height, but remaining static because it needs to be a counter
** the wall_h in wall->ytexture (the fifrst statement inside the while loop) needs
** to change to be a percentage of what it should be
*/
void			draw_wallpiece(t_env *e, t_ray *ray, int x)
{
	int			wall_h;
	int			topmost_pixel;
	int			i;
	t_texture	*t;
	double		x_offset;
	int			temp;
	double		y_offset;
	double		y_increment;
	double		percentage;

	i = 0;
	if (ray->s == INT_MAX)
		return ;
	if (!(t = ft_memalloc(sizeof(t_texture))))
		return ;
	setup_texture(ray);
	wall_h = (int)(e->p->c / ray->s) + 1;
	topmost_pixel = (wall_h > WINDOW_W) ? 0 : (WINDOW_W / 2) - (wall_h / 2);
	x_offset = (ray->dir == EAST || ray->dir == WEST) ? \
		ray->y - (((int)ray->y / TILE_SIZE) * TILE_SIZE) : \
		ray->x - (((int)ray->x / TILE_SIZE) * TILE_SIZE);
	wall->x_texture = ((double) x_offset / TILE_SIZE) * e->textures[t->type]->w;
	temp = (wall_h > WINDOW_W) ? WINDOW_W : wall_h;
	y_offset = (wall_h > WINDOW_W) ? grab_y_offset(e, ray) : 0;
	percentage = (wall_h > WINDOW_W) ? 1 - (y_offset * 2) : 1;
	y_increment = (1 - (y_offset * 2)) / WINDOW_H;
	while (i <= temp)
	{
		if (wall_h > WINDOW_W)
			wall->y_texture = (double) ((i * y_increment) + y_offset) * e->textures[t->type]->h;
		else
			wall->y_texture = (double) ((i / (percentage * wall_h)) + y_offset) * e->textures[t->type]->h;
		insert_bitmap(e->img, x, topmost_pixel + i, grab_color(e, \
			wall->x_texture, wall->y_texture, t->type));
		i++;
	}
}

typedef struct	s_texture
{
	int			x;
	int			y;
	int			x_offset;
	int			y_offset;
	t_type		type;
}				t_texture;
