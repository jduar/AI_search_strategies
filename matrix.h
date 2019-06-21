#include<stdlib.h>
#include<string.h>

/* Header guard: previne includes repetidos. */
#ifndef MATRIX_H
#define MATRIX_H

// definição de BOOL 
typedef enum {FALSE,TRUE} BOOL;

typedef struct matrix {
  char* id; // matrix ID
  int depth; 
  int lin0, col0; // line and column of blank space
  int* matrix;
  char movement;
  struct matrix *pai;
} *MATRIX;


/* --- Function prototype. --- */


// Creates a new matrix structure.
MATRIX new_matrix(int*, MATRIX, int, char);
// Compares the matrix arrays within two MATRIX structures.
int compare_matrix(MATRIX, MATRIX);
// Compares two array matrixes.
int compare_matrix_array(int m1[16], int m2[16]);
// Prints the matrix array within a MATRIX.
void print_matrix(MATRIX);
// Generates MATRIX structures with the next movements.
MATRIX successors(MATRIX, char);
// Returns 0 if it's equal to any parent, 1 otherwise.
MATRIX successors2(int m[16], char, int , MATRIX );
// Like successors() but expects a matrix array.
int verify_parents(MATRIX);
// Returns the number of pieces that are not in the final state.
int misplaced_pieces(MATRIX, MATRIX);
// Returns the sum of Manhattan distance of all pieces.
int manhattan(MATRIX, MATRIX);
//Return the path from inicial_matrix to solution
void print_path(MATRIX);

// TODO: Free memory.
// TODO: falta contadores de nos gerados 

MATRIX new_matrix(int* mat, MATRIX pai, int depth, char movement) {
  MATRIX m = malloc(sizeof(struct matrix));
  m->matrix = (int*) malloc(16 * sizeof(int));
  m->matrix = mat;
  m->pai = pai;
  m->id = (char*) malloc(16 * sizeof(char));
  m->depth = depth;
  m->movement = movement;

  // Finding the blank position.
  for(int i=0;i<4;i++){
    for(int j=0;j<4;j++){
      if(m->matrix[i*4 +j]==0){
        m->lin0=i;
        m->col0=j;
      }
    }
  }

  // Generating ID.
  for(int i=0;i<16;i++){
    m->id[i]=m->matrix[i];
  }
  return m;
}


int compare_matrix(MATRIX m1, MATRIX m2) {
  /*Returns 0 for false and 1 for true.*/
  for (int i=0; i<4; i++) {
    for (int j=0; j<4; j++) {
      if (m1->matrix[i*4 + j] != m2->matrix[i*4 + j]) {
	      return 0;
      }
    }
  }
  return 1;
}


void print_matrix(MATRIX m) {
  for (int i=0; i<4; i++) {
    for (int j=0; j<4; j++) {
      printf("%d ", m->matrix[i*4 + j]);
    }
    printf("\n");
  }
}

// TODO: FREE
// Return 0 if it's equal to any parent, 1 otherwise.
int verify_parents(MATRIX m){
  MATRIX aux = m;
  while (m->pai != NULL){
    if (compare_matrix(aux, m->pai) == 1){
      return 0;
    }
    m = m->pai;
  }
  return 1;
}

// Returns the number of pieces that are not in the final order.
int misplaced_pieces(MATRIX m, MATRIX f){
  int count=0;
  for(int i = 0; i<16; i++){
    if(m->matrix[i] != 0 && m->matrix[i]!=f->matrix[i]){
      count++;
    }
  }
  return count;
}

int manhattan(MATRIX m, MATRIX f){
  int res=0;
  for (int i=0; i<4; i++){
    for (int j=0; j<4;j++){
      if(m->matrix[i*4+j] != 0 && m->matrix[i*4+j]!=f->matrix[i*4+j]){
        for (int k=0; k<4; k++){
          for (int l=0; l<4;l++){
            if(m->matrix[i*4+j] == f->matrix[k*4+l]){
              if(i<k){
                res=res+k-i;
              }
              else{
                res=res+i-k;
              }
              if(j<l){
                res=res+l-j;
              }
              else{
                res=res+j-l;
              }
            }
          }
        }
      }
    }
  }
  return res;
}

//Compare the matrixes still in arrays, doesn't do the struct
//return 1 if differents, otherwise 0
int compare_matrix_array(int m1[16],int m2[16]){
  for(int i=0;i<4;i++){
    for(int j=0;j<4;j++){
      if(m1[i*4+j]!=m2[i*4+j])
        return 1;
    }
  }
  return 0;
}
//Generates the sucessores still in array
MATRIX successors(MATRIX pai, char c){
  int value;
  
  // Movement up.
  if(c=='u'){
    if(pai->lin0 - 1 >= 0){
      int *successor = malloc(16*sizeof(int));
      for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){ 
          successor[i*4+j]=pai->matrix[i*4+j];
        }
      }
      value = pai->matrix[(pai->lin0 - 1)*4 + pai->col0];
      successor[(pai->lin0)*4 + pai->col0] = value;
      successor[(pai->lin0 - 1)*4 + pai->col0] = 0;
      return new_matrix(successor, pai, pai->depth + 1,'u');
    }
    else{
      return NULL;
    }
  }
  // Movement down.
  if (c=='d'){
    if ((pai->lin0 + 1) < 4){
      int *successor = malloc(16*sizeof(int));
      for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
          successor[i*4+j] = pai->matrix[i*4+j];
        }
      }
      value = pai->matrix[(pai->lin0 + 1)*4 + pai->col0];
      successor[(pai->lin0)*4 + pai->col0] = value;
      successor[(pai->lin0 + 1)*4 + pai->col0] = 0;
      return new_matrix(successor, pai, pai->depth + 1,'d');
    }
    else{
      return NULL;
    }
  }
  // Movement left.
  if(c=='l'){
    if((pai->col0 - 1) >= 0){
      int *successor = malloc(16*sizeof(int));
      for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
          successor[i*4+j] = pai->matrix[i*4+j];
        }
      }
      value = pai->matrix[(pai->lin0)*4 + (pai->col0 - 1)];
      successor[(pai->lin0)*4 + pai->col0] = value;
      successor[(pai->lin0)*4 + (pai->col0 - 1)] = 0;
      return new_matrix(successor, pai, pai->depth+1,'l');
    }
    else{
      return NULL;
    }
  }
  // Movement rigth.
  if(c=='r'){
    if((pai->col0 + 1) < 4){
      int *successor = malloc(16*sizeof(int));
      for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
          successor[i*4+j] = pai->matrix[i*4+j];
        }
      }
      value = pai->matrix[(pai->lin0)*4 + (pai->col0 + 1)];
      successor[(pai->lin0)*4 + pai->col0] = value;
      successor[(pai->lin0)*4+(pai->col0 + 1)] = 0;
      return new_matrix(successor, pai, pai->depth+1,'r');
    }
    else{
      return NULL;
    }
  }
  abort();
}

MATRIX successors2(int m[16],char c, int depth, MATRIX pai){
  //int* successor = malloc(16*sizeof(int));
  int value;
  int lin0;
  int col0;
  for(int i=0; i<4; i++){
    for(int j=0; j<4; j++){
      //successor[i*4 + j] = m[i*4 +j];
      if(m[i*4+j]==0){
        lin0=i;
        col0=j;
      }
    }
  }
  
  // Movement up.
  if(c=='u'){
    if(lin0-1>=0){
      int *successor=malloc(16*sizeof(int));
      for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){ 
          successor[i*4+j]=m[i*4+j];
        }
      }
      value = m[(lin0-1)*4+col0];
      successor[(lin0)*4+col0]=value;
      successor[(lin0-1)*4+col0]=0;
      return new_matrix(successor, pai, depth+1,'u');
    }
    else{
      return NULL;
    }
  }
  // Movement down.
  if (c=='d'){
    if ((lin0+1)<4){
      int *successor=malloc(16*sizeof(int));
      for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
          successor[i*4+j]=m[i*4+j];
        }
      }
      value = m[(lin0+1)*4+col0];
      successor[(lin0)*4+col0]=value;
      successor[(lin0+1)*4+col0]=0;
      return new_matrix(successor, pai, depth+1,'d');
    }
    else{
      return NULL;
    }
  }
  // Movement left.
  if(c=='l'){
    if((col0-1)>=0){
      int *successor=malloc(16*sizeof(int));
      for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
          successor[i*4+j]=m[i*4+j];
        }
      }
      value = m[(lin0)*4+(col0-1)];
      successor[(lin0)*4+col0]=value;
      successor[(lin0)*4+(col0-1)]=0;
      return new_matrix(successor, pai, depth+1,'l');
    }
    else{
      return NULL;
    }
  }
  // Movement rigth.
  if(c=='r'){
    if((col0+1)<4){
      int *successor=malloc(16*sizeof(int));
      for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
          successor[i*4+j]=m[i*4+j];
        }
      }
      value = m[(lin0)*4+(col0+1)];
      successor[(lin0)*4+col0]=value;
      successor[(lin0)*4+(col0+1)]=0;
      return new_matrix(successor, pai, depth+1,'r');
    }
    else{
      return NULL;
    }
  }
  abort();
}

int is_visited(MATRIX* m, MATRIX son, int j){
  for(int i=0; i<j;i++){
    if (compare_matrix(m[i],son)==1)
      return 1;
  }
  return 0;
}

void print_path(MATRIX m){
  char path[m->depth];
  int size=m->depth;
  int i=size-1;
  while(m->pai != NULL){
    path[i] = m->movement;
    m = m->pai;
    i--;
  }
  printf("u-up; d-down; l-left; r-right\n");
  printf("Path: ");
  for(int i=0; i<size-1; i++){
    printf("%c -> ",path[i]);
  }
  printf("%c\n", path[size-1]);
}


#endif
