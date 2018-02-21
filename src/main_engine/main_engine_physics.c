/*
** EPITECH PROJECT, 2017
** mysfml
** File description:
** main engine physics engine links
*/

#include "my_sfml_engine.h"

int add_physic_object_main_engine(sf_engine_t *engine, gameobject_t *object)
{
	if (engine == NULL || object == NULL || engine->current_scene == NULL)
		return (84);
	return (engine->current_scene->physic_engine->add_object(\
engine->current_scene->physic_engine, object));
}

gameobject_t **get_collisions_rect_main_engine(sf_engine_t *engine, \
sfIntRect rect, int *size_buff, void *ignore)
{
	if (engine == NULL || size_buff == NULL || \
engine->current_scene == NULL)
		return (NULL);
	return (engine->current_scene->physic_engine->get_collisions_rect(\
engine->current_scene->physic_engine, rect, size_buff, ignore));
}

gameobject_t **get_collisions_point_main_engine(sf_engine_t *engine, \
vector_t point, int *size_buff)
{
	if (engine == NULL || size_buff == NULL || \
engine->current_scene == NULL)
		return (NULL);
	return (engine->current_scene->physic_engine->get_collisions_point(\
engine->current_scene->physic_engine, point, size_buff));
}

gameobject_t **get_collisions_go_main_engine(sf_engine_t *engine, \
gameobject_t *obj, int *size_buff)
{
	if (engine == NULL || size_buff == NULL || \
engine->current_scene == NULL)
		return (NULL);
	return (engine->current_scene->physic_engine->get_collisions_go(\
engine->current_scene->physic_engine, obj, size_buff));
}

void initialize_physic_state(sf_engine_t *engine)
{
	if (engine == NULL || engine->current_scene == NULL || \
engine->current_scene->physic_engine == NULL || \
engine->current_scene->physic_engine->update == NULL) {
		my_putdebug("Could not initialize physic state!\n");
		return;
	}
	engine->add_update(engine, engine->current_scene->physic_engine, \
(int (*)(void *, int))engine->current_scene->physic_engine->update);
}