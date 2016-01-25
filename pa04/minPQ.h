/* The purpose of minPQ.h is to serve as a header file for minPQ.c  
	minPQ.h serves as the file for clients of the MinPQ.c ADT
*/

#ifndef C101MinPQ
#define C101MinPQ
/* Multiple typedefs for the same type are an error in C. */

typedef struct MinPQNode * MinPQ;

#define UNSEEN ('u')
#define FRINGE ('f')
#define INTREE ('t')

/* Access functions (what are the preconditions? Replace this question.)
*/

int isnumPQ(MinPQ pq);

/** isEmpty
     Pre: pq is of type MinPQ and has been created
	 Post: returns an int to indicate whether the queue is empty or not
*/
int isEmptyPQ(MinPQ pq);

/** getMin
     Pre: 
	 Post:
*/
int getMin(MinPQ pq);

/** getStatus
     Pre: pq is of type MinPQ and pq has been created, id is the vertex to be checked in the queue
	 Post: Returns an int to indicate the status of a vertex in the queue
*/
int getStatus(MinPQ pq, int id);

/** getParent
     Pre: pq is of type MinPQ and pq has been created, id is the vertex to be checked in the queue
	 Post: Returns an int to indicate the paretn of a vertex in the queue
*/
int getParent(MinPQ pq, int id);

/** getPriority
     Pre: pq is of type MinPQ and pq has been created, id is the vertex to be checked in the queue
	 Post: Returns an double to indicate the weight of an edge in the queue
*/
double getPriority(MinPQ pq, int id);

/* Manipulation procedures (what are the preconditions and postconditions? Replace this question.)
*/

/** delMin
     deletes the minimum edge from fringe edge possibilities
*/
void delMin(MinPQ pq);

/** insertPQ
     Pre: pq is of type MinPQ and pq has been created, id is the vertex in the queue, priority is the weight between the edge id
	      and parent vertex, par is the parent vertex to id 
	 Post: inserts id in into the queue   		  
*/
void insertPQ(MinPQ pq, int id, double priority, int par);

/** decreaseKey
     Pre: pq is of type MinPQ and pq has been created, id is the vertex in the queue, priority is the weight between the edge id
	      and parent vertex, par is the parent vertex to id 
	 Post: deletes id from the queue 
*/
void decreaseKey(MinPQ pq, int id, double priority, int par);

/* Constructors (what are the preconditions and postconditions? Replace this question.)
*/

/**
     Pre: int n is the number of vertices from graph, status a char array, priority is the weight between two vertices, parent is an int array 
	 Post: creates a queue to store the vertices and status, priority, parent 
*/
MinPQ createPQ(int n, char status[], double priority[], int parent[]);


#endif

