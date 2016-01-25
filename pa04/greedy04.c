// Oscar Parra 
// oparra Student Id# 1422939
// cmps101-avg 
// 12/2/15
#include <unistd.h>
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#include "minPQ.h"
#include "edgeList.h"
#include "loadWgtGraph.h"

int getopt(int argc, char* args[], const char* optstring);
void updateFringe(MinPQ pq, EdgeList adjInfofV, int v, char task);
void DJP(EdgeList adjInfo[], int n, int s, int parent[], double fringeWgt[], char status[], char task);
void printDJP(EdgeList adjVertices[], int m, int parent[], double fringeWgt[], char status[], char task);

int main(int argc, char* argv[]){
	 int m;
	 int startV; 
	 int true = 0;
	 int opt = -1;
	FILE* inbuff;
	char* instream;
	char line [1024];
	char task; 
	
	while((opt = getopt(argc, argv, "DP")) != -1){
		switch(opt){
			case 'D':
				 if (argc == 4) {
					 inbuff = fopen(argv[3], "r");
				     true = true + 1;
					 task = 'D';
				 }
				 break;
			case 'P':
				 if (argc == 4){
					 inbuff = fopen(argv[3], "r");
				     true = true + 1;
					 task = 'P';
				 }
				 break;
		}
	}
	
	if( true == 0){
		printf("Usage: greedy04 P startVertex input.data \n");
		printf("Usage: greedy04 D startVertex input.data \n");
		// printf("Usage: greedy P or D startVertex -)
		// still have to specify how to input from stdin 
		exit(EXIT_FAILURE); 
	}
	
	 instream = fgets(line, 1024, inbuff);
	 m = atoi(instream); 
     sscanf(argv[2], "%d", &startV);
	 int parent[m+1]; 
     double fringeWgt[m+1];
	 char status[m+1];
	 
	 for(int x = 1; x <= m; x++){ 
	 	 parent[x] = 0;
		 fringeWgt[x] = 0;
	     status[x] = UNSEEN;
	 }

	 if(true == 1) {
		 EdgeList adjVertices[m];
		 EdgeList* pointerAdj = malloc(sizeof(EdgeList));
		 instream = fgets(line, 1024, inbuff);
		 pointerAdj = intEdges(m, instream, line, inbuff);
		 for(int i = 1; i <=m; i++) adjVertices[i] = *(pointerAdj + i);
		 DJP(adjVertices, m, startV, parent, fringeWgt, status, task); 
         printDJP(adjVertices, m, parent, fringeWgt, status, task);		
	 }
}

	 
     void DJP(EdgeList adjInfo[], int n, int s, int parent[], double fringeWgt[], char status[], char task){
		 //int status = new int[n+1];
	     MinPQ pq = createPQ(n, status, fringeWgt, parent);

	     insertPQ(pq, s, -1, -1); 
	     while(isEmptyPQ(pq) != 1 ){
	         int v = getMin(pq);
	         delMin(pq); 
	         updateFringe(pq, adjInfo[v], v, task);
	     }
	     return;
     }

     /** See if a better connection is found to any vertex in the list adjInfo of V, and decreaseKEy if so. 
     For a new connection, insert the vertex. 
     */     

     void updateFringe(MinPQ pq, EdgeList adjInfoOfV, int v, char task){
		 double myDist = getPriority(pq, v);
		 double newDist;
		 float newWgt;
         EdgeList remAdj; 
	     remAdj = adjInfoOfV; 
	     while(remAdj != NULL){
	         EdgeInfo wInfo = edgeFirst(remAdj);
			 int w = wInfo.to;
             if(task == 'D'){ newDist = myDist + wInfo.wgt; } 			 
		     if (task == 'P'){ newWgt = wInfo.wgt; }
	         if(getStatus(pq, w) == UNSEEN){
				 if(task == 'D') insertPQ(pq, w, newDist, v);
		         if(task == 'P') insertPQ(pq, w, newWgt, v);
		     }else if(getStatus(pq, w) == FRINGE){
				 if(task == 'D'){
					 if(newDist < getPriority(pq, w)) decreaseKey(pq, w, newDist, v);
				 }
				 if(task =='P'){
		             if(newWgt < getPriority(pq, w)) decreaseKey(pq, w, newWgt, v);
				 }
			 }
	         remAdj = edgeRest(remAdj); 
		 }
	     return;
	 }
	 
	 void printDJP(EdgeList adjVertices[], int m, int parent[], double fringeWgt[], char status[], char task){
		 if (task == 'D'){printf("Dijkstra's Alorithm \n");}
		 if (task == 'P'){printf("Prim's Algorithm \n");}
		 printf("V     ");
	     printf("parent ");
	     printf("fringeWgt ");
	     printf("status \n");
	     for(int i = 1; i <= m; i++){
		     EdgeList temp = adjVertices[i];
		     printf("%d \t ", i);
		     if (temp == edgeNil){ printf("[]");}
		     else{
				 if(parent[i] < 0){
					 printf("%d      ", parent[i]);
				 }else{
			         printf(" %d     ", parent[i]);
				 }
				 if(fringeWgt[i] < 0){
					 printf("%.2f ", fringeWgt[i]);
				 }else{
				     printf("  %.2f ", fringeWgt[i]);
				 }
				 printf("     %c", status[i]);
                 temp = edgeRest(temp);
		     }
		 printf("\n");
	    }
	 }

