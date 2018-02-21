# CSFML_Engine
A game engine inspired by Unity
Developped by Julian Fräbel for the Epitech Graphical module

You can generate documentation if you have Doxygen installed.
Simply do "make gendoc"

All frees are handeled by the engine if you register gameobjects (engine->add_gameobject(engine, go)).
If you want to destroy gameobject prefer using engine->destroy_gameobject or you will have to clear all updaters and renderer manually.

If you have any question fill free to ask me at julian.frabel@epitech.eu.

To remove the engine debug messages and warning in the console go to include/my_sfml_core.h and change the macro from 1 to 0

Examples:
- your main loop should look like this:
```
	while (sfRenderWindow_isOpen(engine->window)) {
		engine->update(engine);
		if (engine->current_scene)
			engine->current_scene->loop(engine, NULL);
		engine->render(engine);
	}
```
 with all your scene related code in the loop function of the scene

- your scene files should look like this:
```
	int load_XXX_scene(sf_engine_t *engine, void *data)
	{
		if (engine == NULL)
			return (84);
		engine->initialize_physic_state(engine);
		/* Setup here your initialisation code (obj creation...) */
		return (0);
	}

	int loop_XXX_scene(sf_engine_t *engine, void *data)
	{
		sfEvent event;

		if (engine == NULL)
			return (84);
		while (sfRenderWindow_pollEvent(engine->window, &event)) {
			if (event.type == sfEvtClosed)
				sfRenderWindow_close(engine->window);
		}
		/* Other stuff to be called each frame */
		return (0);
	}

	int unload_XXX_scene(sf_engine_t *engine, void *data)
	{
		(void)data;
		/* Cleaning: reset scene will auto clear all of the scene settting it back to the unloaded state */
		reset_scene(engine->current_scene);
		return (0);
	}

	sf_scene_t *create_menu_scene(sf_engine_t *engine)
	{
		sf_scene_t *new_scene = create_scene("XXX");

		if (new_scene == NULL || engine == NULL)
			return (NULL);
		new_scene->load = &load_menu_scene;
		new_scene->loop = &loop_menu_scene;
		new_scene->unload = &unload_menu_scene;
		engine->add_scene(engine, new_scene);
		return (new_scene);
	}
```

- Updaters will be run each frame with as parameter the elapsed time since last call in microseconds
