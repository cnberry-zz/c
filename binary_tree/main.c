#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node *left;
    struct node *right;
} Node;

Node * create_node(int val) {

   Node * n = (Node*) malloc(sizeof(Node));
   n->left = NULL;
   n->right = NULL;
   n->val = val;

   return n;
}

typedef struct elem {
    Node *n;
    struct elem *next;
} QueueElem;

typedef struct queue {
    QueueElem *head; 
    QueueElem *tail;
} Queue;

void push(Queue *q, Node *n) {
   QueueElem *elem = (QueueElem*) malloc(sizeof(QueueElem));
   elem->n = n;
   elem->next = NULL;
   
   if (q->tail == NULL) { /* 1st element */
	q->head = elem;
	q->tail = elem;
   } else { 
	q->tail->next = elem;
	q->tail = elem;
   }

}

Node * pop(Queue *q) {
    
    Node *n = NULL;
    QueueElem *head = NULL;

    /* Empty */
    if (q->head == NULL)
	return NULL;

    /* Get object from head */
    n = q->head->n;

    /* Remove head */
    head = q->head;
    q->head = q->head->next;
    free(head);

    /* Check tail */
    if (q->head == NULL)
	q->tail = NULL;

    return n;
}

int findMinBfs(Node *root) {
    Queue q; //using 1 queue and using node value for depth, could use 2 queues if this was not an option
    Node *n = NULL;
    int depth = 1;

    /* initialize queue */
    q.head = NULL;
    q.tail = NULL;

    if (root == NULL)
	return 0;

    /* set up queues */
    root->val = depth;
    push(&q,root);

    /* loop until processed all nodes */
    while ( 1 ) {
        
	/* process next node */
 	n = pop(&q);
	if ( n == NULL)	// reached last node
	    break;
	
	/* push children onto queues */
	if (n->left) {
	    n->left->val = depth+1;
	    push(&q,n->left);
	}

	if (n->right) {
	    n->right->val = depth+1;
	    push(&q,n->right);
	}

        /* get depth from depth queue */
        depth = n->val;
	
	/* check if node is childless */
	if (!n->left && !n->right)
	   break;
   }

   return depth;  
}

int findMinDfs(Node *n) {
  
    int l,r;

    /* recursive terminal case, end of tree */
    if (n == NULL)
        return 0;

    l = findMinDfs(n->left);
    r = findMinDfs(n->right);

    if ( l < r)
	return ++l;
    else
	return ++r;
    
}

int main (int argc, char **argv) {
   
   Node *root = NULL;
   int depth;
       
   /* create a tree with no nodes */
   depth = findMinDfs(root);
   printf("DFS min depth of NULL tree: %d\n",depth);  
   depth = findMinBfs(root);
   printf("BFS min depth of NULL tree: %d\n",depth);  

   /* create a tree with 1 node */
   root = create_node(0);

   depth = findMinDfs(root);
   printf("DFS min depth of root tree: %d\n",depth);  
   depth = findMinBfs(root);
   printf("BFS min depth of root tree: %d\n",depth);  

   /* Create a tree with 5 nodes, depth 2 */
   root->left = create_node(0);
   root->right = create_node(0);
   root->left->left = create_node(0);
   root->left->left->right = create_node(0);

   depth = findMinDfs(root);
   printf("DFS min depth of 5 node tree: %d\n",depth);  
   depth = findMinBfs(root);
   printf("BFS min depth of 5 node tree: %d\n",depth);  
 
   return 0;
}


