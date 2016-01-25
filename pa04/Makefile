CFLAGS  = -g -Wall -std=c99 -D_SVID_SOURCE

greedy04:	 greedy04.o loadWgtGraph.o edgeList.o minPQ.o
	gcc   -o greedy04 greedy04.o loadWgtGraph.o edgeList.o minPQ.o

greedy04.o:	 greedy04.c loadWgtGraph.h edgeList.h minPQ.h	        
	gcc   -c -g -Wall -std=c99 -D_SVID_SOURCE greedy04.c  

loadWgtGraph.o:  loadWgtGraph.c loadWgtGraph.h edgeList.h
	gcc   -c -g -Wall -std=c99 -D_SVID_SOURCE loadWgtGraph.c

edgeList.o: 	 edgeList.c edgeList.h
	gcc   -c -g -Wall -std=c99 -D_SVID_SOURCE edgeList.c

minPQ.o:	 minPQ.c minPQ.h
	gcc   -c -g -Wall -std=c99 -D_SVID_SOURCE  minPQ.c 

submit:		greedy04.c loadWgtGraph.c MinPQ.c edgeList.c
	submit cmps101-avg.f15 pa04 greedy04.c loadWgtGraph.c MinPQ.c edgeList.c README greedy_test1.in greedy_test2.in  

clean: 
	rm -f *.o greedy04   
