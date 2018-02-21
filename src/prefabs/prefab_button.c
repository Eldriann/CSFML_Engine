/*
** EPITECH PROJECT, 2017
** my_sfml
** File description:
** prefab for a button that can be clicked
*/

#include "my_sfml_engine.h"
#include "my_sfml_gameobject.h"
#include "my_sfml_prefab.h"

void setup_button_comp(sf_engine_t *engine, sf_button_t *button, \
char *tex_path, sfIntRect position)
{
	button->position = position;
	button->sprites[0] = engine->get_sprite(engine, tex_path);
	if (button->sprites[0] == NULL) {
		my_putdebug("[INFO]Sprite not found\n");
	} else {
		sfSprite_setPosition(button->sprites[0], \
(sfVector2f){position.left, position.top});
		sfSprite_setScale(button->sprites[0], (sfVector2f)\
{(position.width / sfSprite_getLocalBounds(button->sprites[0]).width), \
(position.height / sfSprite_getLocalBounds(button->sprites[0]).height)});
	}
	button->curr_sprite = button->sprites[0];
	button->engine = engine;
	engine->add_to_layer(engine, UI_IMAGE, (void **)&button->curr_sprite);
	engine->add_update(engine, button, (int (*)(void *, int))button_update);
}

gameobject_t *create_prefab_button(sf_engine_t *engine, char *name, \
char *textures_path, sfIntRect position)
{
	gameobject_t *new_button = NULL;
	sf_button_t *button_component = NULL;

	if (engine == NULL || textures_path == NULL) {
		my_putdebug("[ERROR]Prefab button: NULL receved!\n");
		return (NULL);
	}
	new_button = create_gameobject((name) ? name : "new button");
	if (new_button == NULL)
		return (NULL);
	button_component = new_button->add_component(new_button, BUTTON);
	if (button_component == NULL) {
		new_button->destroy(new_button);
		return (NULL);
	}
	setup_button_comp(engine, button_component, textures_path, position);
	engine->add_gameobject(engine, new_button);
	return (new_button);
}

int is_over_button(sf_button_t *button)
{
	sfVector2i mouse_pos;

	mouse_pos = sfMouse_getPositionRenderWindow(button->engine->window);
	if (mouse_pos.x >= button->position.left \
&& mouse_pos.x <= button->position.left + button->position.width \
&& mouse_pos.y >= button->position.top \
&& mouse_pos.y <= button->position.top + button->position.height)
		return (1);
	return (0);
}

int button_update(sf_button_t *button, int delta_time)
{
	(void)delta_time;
	if (button == NULL)
		return (84);
	if (is_over_button(button) && button->state == 0) {
		button->state = 1;
		button->on_mouse_enter(button);
	} else if (!is_over_button(button) && button->state >= 1) {
		button->state = 0;
		button->on_mouse_exit(button);
	} else if (is_over_button(button) && \
sfMouse_isButtonPressed(sfMouseLeft) && button->state == 1) {
		button->state = 2;
		button->on_clicked(button);
	}
	return (0);
}