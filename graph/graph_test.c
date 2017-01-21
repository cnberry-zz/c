#include <stdio.h>
#include <assert.h>

#include "graph.h"

#define TEST_SIZE (14)

int
main(int argc, char **argv)
{
    Graph *g = NULL;

    g = graph_create(TEST_SIZE);
    assert(g->v == TEST_SIZE);

    /* Build up edges */
    graph_add_edge(g,0,1,3); 
    graph_add_edge(g,0,2,2); 
    graph_add_edge(g,1,3,0); 
    graph_add_edge(g,1,4,3); 
    graph_add_edge(g,2,3,0); 
    graph_add_edge(g,2,5,1); 
    graph_add_edge(g,3,6,2); 
    graph_add_edge(g,4,7,0); 
    graph_add_edge(g,5,8,0); 
    graph_add_edge(g,6,7,0); 
    graph_add_edge(g,6,8,0); 
    graph_add_edge(g,7,9,3); 
    graph_add_edge(g,8,10,2); 
    graph_add_edge(g,9,12,0); 
    graph_add_edge(g,10,12,0); 
    graph_add_edge(g,11,12,0); 
    graph_add_edge(g,12,13,1); 

    /* print out the graph */
    printf("Graph after creation:\n");
    graph_print(g);
    printf("\n");

    graph_swap_vertices(g,0,1);
    printf("Graph after swap:\n");
    graph_print(g);
    printf("\n");

    /* free it */
    graph_destroy(g);

    return 0;
}
