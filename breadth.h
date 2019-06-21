#include<stdio.h>
#include<stdlib.h>

#include"matrix.h"
#include"queue.h"

//Returns the depth of the solution, prints the path until the solution and prints the number os nodes created
int breadth(MATRIX i_matrix, MATRIX f_matrix){
  int node_counter=0;
  QUEUE *q=mk_empty_queue(100000000);
  enqueue(i_matrix,q);
  
  while(queue_is_empty(q)==FALSE){
    MATRIX aux=dequeue(q);
    if(compare_matrix(aux,f_matrix)==1){

      // Printing solution depth.
      printf("Solution depth: %d\n", aux->depth);
      // Printing number of used nodes.
      printf("Nodes generated: %d\n", node_counter);
      // Printing path.
      print_path(aux);
      
      return aux->depth;
    }
    //Create successores, test one at a time, adds to the queue after verify if it's different from the parents
    MATRIX son;
    
    //move zero up
    son=successors2(aux->matrix,'u',aux->depth,aux);
    if(son!=NULL && verify_parents(son)!=0){
      enqueue(son,q);
      node_counter++;
    }
    
    //move zero down
    son=successors2(aux->matrix,'d',aux->depth,aux);
    if(son!=NULL && verify_parents(son)!=0){
      enqueue(son,q);
      node_counter++;
    }
    
    //move zero left
    son=successors2(aux->matrix,'l',aux->depth,aux);
    if(son!=NULL && verify_parents(son)!=0){
      enqueue(son,q);
      node_counter++;
    }
    
    //move zero rigth
    son=successors2(aux->matrix,'r',aux->depth,aux);
    if(son!=NULL && verify_parents(son)!=0){
      enqueue(son,q);
      node_counter++;
    }
  }
  return 0;
}
