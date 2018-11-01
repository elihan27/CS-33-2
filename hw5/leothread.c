

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>



int leo(int order)
{
    if (order==0 || order==1)
        return 1;
    return leo(order-1) +leo(order-2) +1;
}

struct Node
{
    int label, n;
    struct Node *left, *right;
    
};




void *thread(void *first)
{
    struct Node* curr=(struct Node*)first;
    if (curr->n==0 || curr->n ==1) //the leafnode
    {
        printf("[%d]\n", curr->label);
        return NULL;
    }
    
    printf("(%d\n", curr->label);
    
    pthread_t lid;
    struct Node left;
    left.label = curr->label + 1; //calculating label
    left.n = curr-> n-1; //calculating order
    pthread_t rid;
    struct Node right;
    right.label = curr->label + 1 + leo((curr->n)-1); //calculating label
    right.n = curr->n-2;//calculating order
    //curr->left = &left;
    pthread_create(&lid, NULL, thread,&left);
  
    
        //curr->right = &right;
    pthread_create(&rid, NULL, thread, &right);
    
    pthread_join(lid, NULL);
    pthread_join(rid, NULL);
    
    printf("%d)\n", curr->label);
    
    
    
    return NULL;
    
}

 
int main(int argc, char** argv)
 {
     if (argc < 1)
         return -1;
    pthread_t tid;
    struct Node curr;
    curr.label = 0;
     curr.n = atoi(argv[1]);

  
     
    if (curr.n<=1 )
    {
        printf("[%d]\n", curr.label);
        return 0;
    }
     
    pthread_create(&tid, NULL, thread, &curr);
    pthread_join(tid, NULL);
     
 }





