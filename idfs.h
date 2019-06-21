/*
Implementation of iterative deepening depth-first search.
*/


int IDFS(MATRIX initial_m, MATRIX initial_f) {
  int level = 0;
  while (DFS(initial_m, initial_f, level) != 1) {
    level++;
  }
  return 1;
}
