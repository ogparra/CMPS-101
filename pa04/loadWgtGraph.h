/* Oscar Parra 
 * cmps101-avg
 * 12/2/15
 * header file for loadGraph.c
 */ 


#include "edgeList.h"
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>

#ifndef C101loadGraph
#define C101loadGraph

typedef struct Edge{
	     int from; 
	     int to; 
	     double weight; 
    }Edge;

//parseEdge
// pre: the line being passed in is the second line from the infile
// post: returns a new edge and stores that edge in adjVertices 
Edge parseEdge(char* line);

// pre: takes in 4 different arguments, make sure they are of the same type before calling function
// post: returns a pointer to the adjVertices EdgeList
EdgeList* intEdges(int m, char* instream, char line[], FILE* inbuff);

#endif