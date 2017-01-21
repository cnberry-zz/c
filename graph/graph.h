/* basic directed graph type */

#define MAX_NUM_VERTICES (500)

typedef struct listnode {
    void *obj;
    int weight; 
    struct listnode *next; 
} ListNode;

typedef struct vertex {
    int topNum;
    int visited;
    int indegree;
    int outdegree;
    ListNode *alist;
} Vertex;

typedef struct graph {
    int v;              /* number of vertices */
    int e;              /* number of edges */
    int isSorted;	/* set to 1 if graph is in topological order */
    Vertex *vlist[MAX_NUM_VERTICES]; /* array of vertices */
} Graph;

/*----- Graph methods ----*/
Graph * graph_create(int n);	/* create a new graph with n vertices labeled 0..n-1 and no edges */
void graph_destroy(Graph *g);	/* free all space used by graph */
void graph_add_edge(Graph *g, int source, int sink, int weight);	/* add an edge to an existing graph */
void graph_print(Graph *g);	/* print out adjacency list */
void graph_swap_vertices(Graph *g, int u, int v);	/* swap two vertices in array */

/*----- List methods ----*/
void list_destroy(ListNode *l); /* destroy all nodes in linked list */
ListNode * list_add(ListNode *l, void *obj, int weight); /* create a new list node and add it in front of l, return new node */

