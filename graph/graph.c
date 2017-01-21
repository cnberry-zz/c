#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "graph.h"

/* create a new graph with n vertices */
Graph * graph_create(int n) {
    int i;

    Graph *g = (Graph*) malloc(sizeof(Graph));
    assert(g);

    /* allocate vertices in main array */
    for (i=0; i<n; i++) {
	g->vlist[i] = (Vertex*) malloc(sizeof(Vertex));
    	assert(g->vlist[i]);
	
	/* initialize vertex */
	g->vlist[i]->topNum = i;
        g->vlist[i]->visited = 0;
        g->vlist[i]->outdegree = 0;
        g->vlist[i]->indegree = 0;
	g->vlist[i]->alist = NULL;	
    }

    /* explicitly null out remainder of main array */
    for (i=n; i<MAX_NUM_VERTICES; i++) {
	g->vlist[i] = NULL;
    }

    /* set the vertices num */
    g->v = n;
    g->e = 0;
    g->isSorted = 0;

    return g;
}

/* free all space used by graph */
void graph_destroy(Graph *g) {
    int i;
    
    /* free all vertices */
    for(i=0; i<g->v; i++) {
        /* free all adjacency list nodes (per vertice) */
	list_destroy(g->vlist[i]->alist);
        free(g->vlist[i]);
    }

    free(g);

}

/* add an edge to an existing graph */
void graph_add_edge(Graph *g, int u, int v, int w) {

    assert(u >= 0);
    assert(u < g->v);
    assert(v >= 0);
    assert(v < g->v);
    assert(w >= 0);

    /* add v to u's adjacency list */
    g->vlist[u]->alist = list_add(g->vlist[u]->alist, g->vlist[v], w);
    
    /* update u's outdegree, v's indegree */
    g->vlist[u]->outdegree++;
    g->vlist[v]->indegree++;
}

/* print out our graph */
void graph_print(Graph *g) {
    int i;
    ListNode *ptr;
    Vertex *v;
   
    printf("node(indegree|outdegree): node(weight)\n");
    for(i=0; i<g->v; i++) {
	printf("%d(%d|%d): ",i,g->vlist[i]->indegree,g->vlist[i]->outdegree);
	ptr = g->vlist[i]->alist;
	while (ptr != NULL) {
	    v = (Vertex*) ptr->obj;
	    printf("%d(%d) ",v->topNum,ptr->weight);
	    ptr = ptr->next;
	}
        printf("\n");
    }
	

}

void graph_swap_vertices(Graph *g, int u, int v) {
    Vertex *tmp = g->vlist[u];
    g->vlist[u] = g->vlist[v];
    g->vlist[v] = tmp;

    /* set the vertices topNum to new topNum */
   g->vlist[u]->topNum = u;
   g->vlist[v]->topNum = v;
}
