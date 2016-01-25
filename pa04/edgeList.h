// Oscar Parra 
// oparra Student Id# 1422939
// cmps101-avg 
// 11/12/15
// header file for edgeList.c 

#ifndef C101EdgeList
#define C101EdgeList
/* Multiple typedefs for the same type are an error in C. */

typedef struct EdgeListNode * EdgeList;

typedef struct EdgeInfoStruct
    {
    int to;
    double wgt;
    }
    EdgeInfo;

/** edgeNil denotes the empty EdgeList */
extern const EdgeList edgeNil;

/* Access functions
 * (what are the preconditions? Replace question with your text)
 */

/** first
*/
// pre: oldL is of type EdgeList, oldL is not null
// post: returns the next int value that the current node is pointing to 
EdgeInfo edgeFirst(EdgeList oldL);

/** rest
*/
// pre: oldL is of type EdgeList, oldL is not null
// post: returns the rest of the EdgeList, if there is no rest then NULL is return
EdgeList edgeRest(EdgeList oldL);

/* Constructors
 * (what are the preconditions and postconditions? Replace question with your text)
 */

/** cons
*/
// pre: Both arguments new and oldL are passed and are of the correct type when constructor is called
// post: returns a new EdgeList
EdgeList edgeCons(EdgeInfo newE, EdgeList oldL);

#endif

