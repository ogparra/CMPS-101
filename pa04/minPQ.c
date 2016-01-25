/* Oscar Parra 
 * 12/2/15
 * minPQ.c 
 */


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include "minPQ.h"

// prototype for findMin();
void findMin(MinPQ pq);

// structure for MinPQNode
struct MinPQNode{
     int numVertices; 
     int numPQ; 
     int minVertex; 
     int oo; 	 
	 int* parent;
     char* status;
     double* fringeWgt;
};

int isnumPQ(MinPQ pq){
	return pq->numPQ;
};

/** isEmpty
     checks to see if the queue is empty of not 
*/
int isEmptyPQ(MinPQ pq){
	return (pq->numPQ == 0);
};

/** getMin
     getting the minimum path?
*/
int getMin(MinPQ pq){
	 if(pq->minVertex == -1){
		 findMin(pq);
	 }
	 return pq->minVertex;
};

/** getStatus
     checking the status of a certain edge 
*/
int getStatus(MinPQ pq, int id){
	return pq->status[id];
};

/** getParent
     getting the parent of a certain Vertex 
*/
int getParent(MinPQ pq, int id){
	return pq->parent[id];
};

/** getPriority
     gets the weight of an edge, I believe this chooses the lowest weight
*/
double getPriority(MinPQ pq, int id){
	 return pq->fringeWgt[id];
};

/* Manipulation procedures (what are the preconditions and postconditions? Replace this question.)
*/

/** delMin
     deletes the minimum edge weight from fringing (and the vertex that is being fringed upon) 
*/
void delMin(MinPQ pq){   
	 int oldMin = getMin(pq);
	 
	 pq->status[oldMin] = INTREE;  
	 pq->minVertex = -1; 
	 pq->numPQ--;
	 return;
};

/** insertPQ
     places the vertex with the minimum weight into the tree 
*/
void insertPQ(MinPQ pq, int id, double priority, int par){
	 pq->parent[id] = par; 
	 pq->fringeWgt[id] = priority; 
	 pq->status[id] = FRINGE; 
	 pq->minVertex = -1; 
	 pq->numPQ++; 
	 return; 
};

/** decreaseKey
*/
void decreaseKey(MinPQ pq, int id, double priority, int par){
	 pq->parent[id] = par; 
	 pq->fringeWgt[id] = priority; 
	 pq->minVertex = -1; 
	 return;
};

/** findMin // user of the ADT will not have access to this function in the ADT
     this function does most of the work
*/ 
void findMin(MinPQ pq){
	 int v; 
	 float minWgt; 
	 
	 minWgt = pq->oo; 
	 for(v = 1; v <= pq->numVertices; v++){
		 if(pq->status[v] == 'f'){ // i need to define fringe 
			 if(pq->fringeWgt[v] < minWgt){
				 pq->minVertex = v;
				 minWgt = pq->fringeWgt[v];
			 }
		 }
	 }
	 return;
}

/* Constructors (what are the preconditions and postconditions? Replace this question.)
*/

/** 
     constructs the minimum priority queue
*/
MinPQ createPQ(int n, char status[], double fringeWgt[], int parent[]){
	MinPQ pq = malloc(sizeof(MinPQ)); 
	pq->parent = parent; 
	pq->fringeWgt = fringeWgt;
	pq->status = status;  
	pq->numVertices = n; 
	pq->numPQ = 0; 
	pq->minVertex = -1; 
	pq->oo = HUGE_VAL;  
	return pq; 
};

