/*
** EPITECH PROJECT, 2017
** my_sfml
** File description:
** Core function used in all my_sfml lib
*/

/**
** \file my_sfml_core.h
** \brief Header file that contains core structs and funtions
**
** Contains structs and functions used by two or more engines/go.
*/

#ifndef __MY_SFML_CORE_H_
#define __MY_SFML_CORE_H_

/* --------------------------------DEFINE-------------------------------- */

#define DEBUG_MSG_ACTIVE 1

#define MSG_MY_SFML_MALLOC "[ERROR] Malloc failed!\n"
#define MSG_MY_SFML_ERR_NULL "[ERROR] Pointer given was NULL!\n"

#define MSG_MY_SFML_FILE_NOT_FOUND "[ERROR] File requested not found!\n"

#define MSG_MY_SFML_DATA_NOT_FOUND "[INFO] Data wasn't found!\n"

/* ------------------------------END-DEFINE------------------------------ */

/* ------------------------------LINKEDLIST------------------------------ */

/**
** \struct my_sfml_linked_list
** \brief A custom linked list
**
** A custom linked list that have an id to be easely found.
*/
struct my_sfml_linked_list {
	void *data; /**< the data of the list */
	char *id; /**< the unique id of the index and it's data */
	struct my_sfml_linked_list *next; /**< the next element of the list */
};

typedef struct my_sfml_linked_list sf_linked_list_t;

/**
** \brief Push an element in a linked list
** @param data the data to be pushed in the list
** @param id the unique id for this index (mainly the data adress)
** @param list the list to push to
**
** Push the given object into the givent list,
** the unique id can be used to identify the data without a compare function.
** Return the new element added.
*/
sf_linked_list_t *sf_push(void *data, char *id, sf_linked_list_t *list);
/**
** \brief Remove an element from a list
** @param id the unique id of the element to be removed
** @param list the list to remove from
**
** Remove an element of the givent list given it's unique id.
*/
void sf_remove(char *id, sf_linked_list_t **list);
/**
** \brief Remove an element from a list
** @param node the node of the element to be removed
** @param list the list to remove from
**
** Remove an element of the givent list given the node.
*/
void sf_remove_node(sf_linked_list_t *node, sf_linked_list_t **list);
/**
** \brief Return the data of an element of the list given it's id
** @param id the unique id of the element to get
** @param list the list to get from
**
** Get the data of a list given it's unique id.
** Return the data if found, NULL otherwise.
*/
void *get_data(char const *id, sf_linked_list_t *list);
/**
** \brief Return the data of an element of the list given a compare function
** @param list the list to get from
** @param comp the compared element used by the compare function
** @param cmp the compare function to be used to found data
**
** Get the data of a list given a compare function and compare data.
** Return the data if found, NULL otherwise.
*/
void *get_data_from_node(sf_linked_list_t *list, void *comp, int (*cmp)());
/**
** \brief Return a null terminated array of data linked with the id
** @param id the compared id
** @param list the list to get from
**
** Get the data of a list given an id.
** Return an array of data if found, NULL otherwise.
*/
void **get_data_array(char const *id, sf_linked_list_t *list);
/**
** \brief Return the size of a list
** @param begin the start of the list
**
** Get the size of a list.
** Return the size of the list.
*/
int my_sf_list_size(sf_linked_list_t const *begin);
/**
** \brief Sort a list given a compare function
** @param list the list to be sorted
** @param cmp the compare function
**
** Sort a list based of a compare function.
*/
void my_sort_sf_list(sf_linked_list_t **list, int (*cmp)());

/* ----------------------------END-LINKEDLIST---------------------------- */

/**
** \brief strdup function
*/
char *my_strdup(const char *str);
/**
** \brief strlen function
*/
int my_strlen(const char *str);
/**
** \brief put an str on the error output
*/
int my_putdebug(const char *debug);
/**
** \brief turn an int in an str
*/
char *my_int_to_str(int nb);
/**
** \brief compare two str
*/
int my_strcmp(char const *s1, char const *s2);
/**
** \brief return a number from a character string
*/
int my_getnbr(const char *str);

/* --------------------------------VECTOR-------------------------------- */

/**
** \struct my_sfml_vector
** \brief a 3D vector struct
*/
struct my_sfml_vector {
	float x;
	float y;
	float z;
};

typedef struct my_sfml_vector vector_t;

/* ------------------------------END-VECTOR------------------------------ */

#endif /* __MY_SFML_CORE_H_ */