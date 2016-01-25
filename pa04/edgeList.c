/* Oscar Parra 
 * Student ID# 1422939 
 * 11/12/15 
 * edgeList.c uses edgeList.h 
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "edgeList.h"

// Structure that holds the element, numItems in the EdgeList, and points to the next node in the list (null if not found)
 struct EdgeListNode{
	 EdgeList next;
	 EdgeInfo edgeInfo; 
};

const EdgeList edgeNil = NULL;

// Pre: oldL is of type EdgeList and it is not null
// Post: returns the first element in edgeFirst
EdgeInfo edgeFirst(EdgeList oldL){
	 EdgeInfo P;
     P = oldL->edgeInfo;
	return P;
};

// Pre: oldL is of type EdgeList and 
// Post: return the rest of the edgeList
EdgeList edgeRest(EdgeList oldL){
	return oldL->next; 
};

// Pre: EdgeInfo is a new element, oldL is of type edgeList
// Post: returns a newly constructed EdgeList called N 
EdgeList edgeCons(EdgeInfo newE, EdgeList oldL){
	EdgeList N = malloc(sizeof(EdgeList));
	N->edgeInfo.to = newE.to; 
	N->edgeInfo.wgt = newE.wgt;
	N->next = oldL;
	return N;
};