#include<stdio.h>
#include<stdlib.h>

// A* with heuristc pieces not in place
int a_star_pieces(MATRIX i_matrix, MATRIX f_matrix){
  int node_counter=0;
  Node* pq = newNode(i_matrix, misplaced_pieces(i_matrix, f_matrix));
  
  while(!isEmpty(&pq)){
    MATRIX aux=peek(&pq);
    pop(&pq);
    if(compare_matrix(aux,f_matrix)==1){

      // Printing solution depth.
      printf("Solution depth: %d\n", aux->depth);
      // Printing number of used nodes.
      printf("Nodes generated: %d\n", node_counter);
      //Printing path.
      print_path(aux);
     
      return aux->depth;
    }
    //Create successores, test one at a time
    //At most creates 4 successors of the i_matrix and 3 of the others
    MATRIX son;
    
    //move zero up
    son=successors2(aux->matrix,'u',aux->depth,aux);
    
    if(son!=NULL && verify_parents(son)!=0 /*&& is_visited(m, son, j)==0*/){
      if (!isEmpty(&pq)){
        push(&pq, son, son->depth + misplaced_pieces(son, f_matrix));
        node_counter++;
      }
      else{
        pq = newNode(son, son->depth + misplaced_pieces(son, f_matrix));
      }
    }
    
    //move zero down
    son=successors2(aux->matrix,'d',aux->depth,aux);
    if(son!=NULL && verify_parents(son)!=0){
      if (!isEmpty(&pq)){
        push(&pq, son, son->depth + misplaced_pieces(son, f_matrix));
        node_counter++;
      }
      else{
        pq = newNode(son, son->depth + misplaced_pieces(son, f_matrix));
      }
    }
    
    //move zero left
    son=successors2(aux->matrix,'l',aux->depth,aux);
    if(son!=NULL && verify_parents(son)!=0){
      if (!isEmpty(&pq)){
        push(&pq, son, son->depth + misplaced_pieces(son, f_matrix));
      }
      else{
        pq = newNode(son, son->depth + misplaced_pieces(son, f_matrix));
        node_counter++;
      }
    }
    
    //move zero rigth
    son=successors2(aux->matrix,'r',aux->depth,aux);
    if(son!=NULL && verify_parents(son)!=0){
      if (!isEmpty(&pq)){
        push(&pq, son, son->depth + misplaced_pieces(son, f_matrix));
      }
      else{
        pq = newNode(son, son->depth + misplaced_pieces(son, f_matrix));
        node_counter++;
      }
    }
  }
  return 0;
}


//A* with heuristc manhattan
int a_star_manhattan(MATRIX i_matrix, MATRIX f_matrix){
  int node_counter=0;
  Node* pq = newNode(i_matrix, manhattan(i_matrix, f_matrix));
  
  while(!isEmpty(&pq)){
    
    MATRIX aux=peek(&pq);
    pop(&pq);
    if(compare_matrix(aux,f_matrix)==1){

      // Printing solution depth.
      printf("Solution depth: %d\n", aux->depth);
      // Printing number of used nodes.
      printf("Nodes generated: %d\n", node_counter);
      // Printing path.
      print_path(aux);
      
      return aux->depth;
    }
    
    //Create successores, test one at a time
    //At most creates 4 successors of the i_matrix and 3 of the others
    MATRIX son;
    
    //move zero up
    son=successors2(aux->matrix,'u',aux->depth,aux);
    
    if(son!=NULL && verify_parents(son)!=0){
      if (!isEmpty(&pq)){
        push(&pq, son, son->depth + manhattan(son, f_matrix));
        node_counter++;
      }
      else{
        pq = newNode(son, son->depth + manhattan(son, f_matrix));
      }

    }
    //move zero down
    son=successors2(aux->matrix,'d',aux->depth,aux);
    if(son!=NULL && verify_parents(son)!=0){
      if (!isEmpty(&pq)){
        push(&pq, son, son->depth + manhattan(son, f_matrix));
        node_counter++;
      }
      else{
        pq = newNode(son, son->depth + manhattan(son, f_matrix));
      }
    }
    //move zero left
    son=successors2(aux->matrix,'l',aux->depth,aux);
    if(son!=NULL && verify_parents(son)!=0){
      //m[j++]=son;
      if (!isEmpty(&pq)){
        push(&pq, son, son->depth + manhattan(son, f_matrix));
        node_counter++;
      }
      else{
        pq = newNode(son, son->depth + manhattan(son, f_matrix));
      }
    }
    
    //move zero rigth
    son=successors2(aux->matrix,'r',aux->depth,aux);
    if(son!=NULL && verify_parents(son)!=0){
      if (!isEmpty(&pq)){
        push(&pq, son, son->depth + manhattan(son, f_matrix));
        node_counter++;
      }
      else{
        pq = newNode(son, son->depth + manhattan(son, f_matrix));
      }
    }
  }
  return 0;
}
