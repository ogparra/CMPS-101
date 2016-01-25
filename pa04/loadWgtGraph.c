/* Oscar Parra 
   cmps101-avg 
   12/2/15 
   Loads the graph from the input file, returns either a list of type IntList or of type EdgeList
 */ 
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "edgeList.h"
#include "loadWgtGraph.h"

Edge parseEdge(char* line){
     Edge newE;
     int numFields;
     numFields = sscanf(line, " %d %d %lf", &newE.from, &newE.to, &newE.weight);
     if (numFields < 2 || numFields > 3){
         printf("Bad edge: %s", line);
         exit(1);
     }
     if (numFields == 2) newE.weight = 0.0;
	     sscanf(line,"%d %d", &newE.from, &newE.to);
	 if (numFields == 3)
		 sscanf(line,"%d %d %lf", &newE.from, &newE.to, &newE.weight );
     return newE;
}

EdgeList* intEdges(int m, char* instream, char line[1024], FILE* inbuff){
	int n = 0;
	EdgeList adjVertices[m];
	EdgeList* pointAdj = malloc(sizeof(EdgeList));
	for(int i = 1; i <=m; i++) adjVertices[i] = edgeNil; 
     while(instream != NULL){  
		 Edge e = parseEdge(line);
		 EdgeInfo P; 
		 P.to = e.to; 
		 P.wgt = e.weight;
		 adjVertices[e.from] = edgeCons(P, adjVertices[e.from]);
		 instream = fgets(line, 1024, inbuff);
		 n++;
	 }

	 pointAdj = adjVertices;
	 return pointAdj;
}