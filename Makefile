##
## EPITECH PROJECT, 2017
## mysfml
## File description:
## Makefile that build the mysfml lib
##

SRC_DIR_AUDIO	=	$(realpath src/audio)

SRC_FILES_AUDIO	=	audio_engine_add_sound.c			\
			audio_engine_core.c				\
			audio_engine_play.c				\
			audio_engine_set_volume.c			\
			audio_engine_stop.c

SRC_DIR_COMP	=	$(realpath src/components)

SRC_FILES_COMP	=	animation_2d.c					\
			button.c					\
			collider_2d_collisions.c			\
			collider_2d.c					\
			rigidbody_2d.c					\
			text.c						\
			transform.c

SRC_DIR_CORE	=	$(realpath src/core)

SRC_FILES_CORE	=	sf_linked_list_get_data.c			\
			sf_linked_list_remove.c				\
			sf_linked_list_size.c				\
			sf_linked_list_sort.c				\
			sf_linked_list.c				\
			my_putdebug.c					\
			my_int_to_str.c


SRC_DIR_GO	=	$(realpath src/gameobject)

SRC_FILES_GO	=	gameobject_add_component.c			\
			gameobject_core.c

SRC_DIR_GRAPH	=	$(realpath src/graphics)

SRC_FILES_GRAPH	=	graphical_engine_add_to_layer.c			\
			graphical_engine_core.c				\
			graphical_engine_render_frame.c			\
			graphical_engine_texture_core.c			\
			layer_set_type.c				\
			layers_compare.c				\
			layers_core.c					\
			layers_render.c					\
			layers_sort.c

SRC_DIR_ENGINE	=	$(realpath src/main_engine)

SRC_FILES_ENGINE=	get_sprite.c					\
			main_engine_core.c				\
			main_engine_gameobject.c			\
			main_engine_graph.c				\
			main_engine_graph_2.c				\
			main_engine_physics.c				\
			main_engine_physics_2.c				\
			main_engine_scene.c				\
			main_engine_sound.c				\
			main_engine_updates.c

SRC_DIR_PHYSIC	=	$(realpath src/physics)

SRC_FILES_PHYSIC=	physics_engine_add_object.c			\
			physics_engine_core.c				\
			physics_engine_display_hitbox.c			\
			physics_engine_get_collisions.c			\
			physics_engine_update.c

SRC_DIR_PREFAB	=	$(realpath src/prefabs)

SRC_FILES_PREFAB=	prefab_button.c					\
			prefab_image.c

SRC_DIR_SCENES	=	$(realpath src/scenes)

SRC_FILES_SCENES=	scenes_core.c

SRC		=	$(addprefix $(SRC_DIR_AUDIO)/, $(SRC_FILES_AUDIO)) \
			$(addprefix $(SRC_DIR_COMP)/, $(SRC_FILES_COMP)) \
			$(addprefix $(SRC_DIR_CORE)/, $(SRC_FILES_CORE)) \
			$(addprefix $(SRC_DIR_GO)/, $(SRC_FILES_GO)) \
			$(addprefix $(SRC_DIR_GRAPH)/, $(SRC_FILES_GRAPH)) \
			$(addprefix $(SRC_DIR_ENGINE)/, $(SRC_FILES_ENGINE)) \
			$(addprefix $(SRC_DIR_PHYSIC)/, $(SRC_FILES_PHYSIC)) \
			$(addprefix $(SRC_DIR_PREFAB)/, $(SRC_FILES_PREFAB)) \
			$(addprefix $(SRC_DIR_SCENES)/, $(SRC_FILES_SCENES))

OBJ		=	$(SRC:%.c=%.o)

NAME		=	mysfml

INCLUDE		=	-I include -I ../my/include

CFLAGS		=	-W -Wall -Wextra -Werror
CFLAGS		+=	$(INCLUDE)

CC		=	gcc

DOXYGEN		:=	$(shell command -v doxygen 2> /dev/null)

FIREFOX		:=	$(shell command -v firefox 2> /dev/null)

all:		$(NAME)

$(NAME):	$(OBJ)
		$(AR) -rc lib$(NAME).a $(OBJ) $(SHARED_COMPILE)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) lib$(NAME).so lib$(NAME).a

re:		fclean all

debug:		CFLAGS += -g
debug:		re

shared:		CFLAGS += -fPIC
shared:		$(OBJ)
		$(CC) -shared $(OBJ) -o lib$(NAME).so

reshared:	fclean shared

gen_doc:	clean_doc
ifndef DOXYGEN
		$(error "Doxygen wasn't found on your computer!")
endif
		doxygen config

clean_doc:
		$(RM) -r html
		$(RM) -r latex

open_doc:
ifndef FIREFOX
		$(error "Firefox wasn't found! Launch html/index.html manually")
endif
		firefox html/index.html

install:
		$(error "Can't install a non shared library")

install_shared:
		cp lib$(NAME).so /usr/local/lib/lib$(NAME).so
		cp -r include/* /usr/local/include/

uninstall:
		rm /usr/local/lib/$(NAME).so
		rm /usr/local/include/$(NAME)*
