#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "matrix.h"
#include "queue.h"
#include "priorityqueue.h"
#include "breadth.h"
#include "a_star.h"
#include "greedy.h"
#include "depth.h"
#include "idfs.h"

//Receives inicial_matrix and final_matrix,returns 1 if it os solvable, 0 otherwise
int solvability(int m[16], int f[16]){
  int inversions=0, inversions_final=0, blank_m, blank_f;
  for (int i = 0; i<4; i++){
    for (int j = 0; j<4; j++){
      if (m[i*4+j] == 0){
         blank_m = i%2;
      }
      if (f[i*4+j] == 0){
        blank_f = i%2;
      }
    }
  }
  for(int i=0; i<16; i++){
    for (int j=i+1; j<16; j++){
      if (m[i] != 0 && m[j]!= 0){
        if(m[i]>m[j]){inversions++;}
      }
      if (f[i] != 0 && f[j]!=0){
        if(f[i]>f[j]){inversions_final++;}
      }
    }
  }
  if ( (blank_m != inversions%2 && blank_f != inversions_final%2) ||(blank_m == inversions%2 && blank_f == inversions_final%2)){
    return 1;
  }
  return 0; 
}

int main(){
  int initial_matrix[16];
  int final_matrix[16];
  int selection=0;
  
  // Building the matrix arrays.
  printf("Writing initial matrix...\n");
  for (int i=0; i<16; i++) {
    scanf("%d", &initial_matrix[i]);
  }

  printf("Writing final matrix...\n");
  for (int i=0; i<16; i++) {
    scanf("%d", &final_matrix[i]);
  }
  
  // Putting initial_matrix and final_matrix in MATRIX structs.
  // 'n' movement -> null movement.
  MATRIX i_matrix=new_matrix(initial_matrix, NULL, 0, 'n');
  MATRIX f_matrix=new_matrix(final_matrix, NULL, -1, 'n');
  
  if (solvability(initial_matrix, final_matrix)) {
    printf("\n***\n");
    printf("What search algorithm would you like to use?\n");
    printf("1: Depth-first search.\n");
    printf("2: Breadth-first search.\n");
    printf("3: Iterative deepening depth-first search.\n");
    printf("4: A* with number of pieces not in order heuristic.\n");
    printf("5: A* with Manhattan heuristic\n");
    printf("6: Greedy with number of pieces not in order heuristic.\n");
    printf("7: Greedy with Manhattan heuristic.\n");
    printf("***\n\n");
    scanf("%d",&selection);
    
    //in the functions we are gonna pass structs of the inicial and final matrix
    
    //starting time
    clock_t start=clock();
    
    if(selection==1){
      if (DFS(i_matrix, f_matrix, 24)==0)
        printf("Solution not found");
    }
    if(selection==2){
      breadth(i_matrix, f_matrix);
    }
    if(selection==3){
      IDFS(i_matrix, f_matrix);
    }
    if(selection==4){
      a_star_pieces(i_matrix, f_matrix);
    }
    if(selection==5){
      a_star_manhattan(i_matrix,f_matrix);
    }
    if(selection==6){
      greedy_pieces(i_matrix,f_matrix);
    }
    if(selection==7){
      greedy_manhattan(i_matrix,f_matrix);
    }
    
    //ending time
    clock_t end=clock();
    double time=(double)(end-start)/CLOCKS_PER_SEC;
    printf("Execution time: %f\n ", time);
  }
  else {
    printf("There is no solution.\n");
    return 0;
  }
  
  return 0;
}
