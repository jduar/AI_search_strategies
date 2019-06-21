/*
Implementation of limited depth first search.
*/

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


int DFS(MATRIX initial_m, MATRIX final_m, int level) {
  PSTACK st = st_make_empty(100000);

  int node_counter = 0;
  st_push(st, initial_m);

  while (st_is_empty(st) == FALSE) {
    MATRIX cur = st_pop(st);

    if (compare_matrix(cur, final_m) == 1) {
      // Printing solution depth.
      printf("Solution depth: %d\n", cur->depth);
      // Printing number of used nodes.
      printf("Nodes generated: %d\n", node_counter);
      // Printing path.
      print_path(cur);
      return 1;
    }

    if (cur->depth == level) {
      continue;
    }

    if (verify_parents(cur) == 0) {
      continue;
    }

    MATRIX next;
    if (cur->movement != 'd') {
      next = successors2(cur->matrix, 'u', cur->depth, cur);
      if (next != NULL) {
	st_push(st, next);
	node_counter++;
      }
    }

    if (cur->movement != 'u') {
      next = successors2(cur->matrix, 'd', cur->depth, cur);
      if (next != NULL) {
	st_push(st, next);
	node_counter++;
      }
    }

    if (cur->movement != 'l') {
      next = successors2(cur->matrix, 'r', cur->depth, cur);
      if (next != NULL) {
	st_push(st, next);
	node_counter++;
      }
    }

    if (cur->movement != 'r') {
      next = successors2(cur->matrix, 'l', cur->depth, cur);
      if (next != NULL) {
	st_push(st, next);
	node_counter++;
      }
    }

  }
  return 0;
}
