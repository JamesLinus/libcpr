/* This is free and unencumbered software released into the public domain. */

#ifndef _CPRIME_LIST_H
#define _CPRIME_LIST_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h> /* for size_t */

/**
 * The canonical end-of-list sentinel value.
 */
#define LIST_SENTINEL NULL

/**
 * Represents a singly-linked list.
 */
typedef struct list_t {
  pair_t* first;
  size_t length;
  free_func_t free_func;
} list_t;

/**
 * Allocates heap memory for a new list.
 */
extern list_t* list_alloc();

/**
 * Initializes a stack-allocated list.
 */
#define LIST_INIT {.first = LIST_SENTINEL, .length = 0, .free_func = free}

/**
 * Initializes a heap-allocated list.
 */
extern int list_init(list_t* list);

/**
 * Returns `TRUE` if a list is empty.
 */
extern bool list_is_empty(const list_t* list);

/**
 * Returns the length of a list.
 */
extern long list_length(const list_t* list);

/**
 * ...
 */
extern long list_count(const list_t* restrict list,
  const void* restrict ptr);

/**
 * Removes all elements from a list.
 */
extern int list_clear(list_t* list);

/**
 * Prepends an element to a list.
 */
#define list_prepend(list, ptr) list_prepend_ptr(list, ptr)

extern int list_prepend_bool(list_t* list, bool_t value);
extern int list_prepend_byte(list_t* list, byte_t value);
extern int list_prepend_char(list_t* list, char_t value);
extern int list_prepend_ptr(list_t* list, const void* ptr);
extern int list_prepend_pair(list_t* list, const pair_t* pair);

/**
 * Reverses a list.
 */
extern int list_reverse(list_t* list);

/**
 * Represents a list iterator.
 */
typedef struct list_iter_t {
  iter_t iter;
  pair_t* element;
  void* current;
} list_iter_t;

extern const iter_interface_t list_iter_interface;

/**
 * Initializes a stack-allocated list iterator.
 */
#define LIST_ITER_INIT(list) {                        \
  .iter    = ITER_INIT(&list_iter_interface, (list)), \
  .element = (list)->first,                           \
  .current = NULL,                                    \
}

/**
 * Advances the iterator to the next list element.
 */
extern int list_iter_next(list_iter_t* iter);

#ifdef __cplusplus
}
#endif

#endif /* _CPRIME_LIST_H */
