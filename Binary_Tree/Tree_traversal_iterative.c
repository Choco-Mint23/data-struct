#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
    int data;
    struct node* LC;
    struct node* RC;
}Node,*BST;


void insert(BST* B, int value);
void inorder(BST B);
void preorder(BST B);
void preorder(BST B);
void Delete (BST *B, int value);
int main() {
    
    BST B = NULL;    
    
    insert(&B,5);
    insert(&B,20);
    insert(&B,1);
    insert(&B,8);
   
    
    preorder(B);
    
}
void insert(BST* B, int value) {
    
    BST *trav = B;
    
    while(*trav!=NULL && (*trav)->data != value)  {
        trav = value > (*trav)->data ? & (*trav)->RC : & (*trav)->LC;
    }
    if(*trav == NULL) {
        *trav = (BST) calloc(1,sizeof(Node));
        (*trav)->data = value;
    }
    
}

void inorder(BST B) {
    BST stack[100];
    int top = -1;
    BST curr = B;

    while (curr != NULL || top != -1) {
        while (curr != NULL) {
            stack[++top] = curr;
            curr = curr->LC;
        }
        curr = stack[top--];
        printf("%d,", curr->data);
        curr = curr->RC;
    }
}
void preorder(BST B) {
    
    if(B==NULL) {
    	return;
	}
	BST stack[100];
	int top = -1;
	stack[++top] = B;
	while(top!=-1) {
		BST curr = stack[top--];
		printf("%d,",curr->data);
	if(curr->RC) {
		stack[++top] = curr->RC;
		
	   } 
	if(curr->LC) {
		stack[++top] = curr->LC;
       	}
	
	}
  
  
  
}
void postorder(BST B) {
    if (B == NULL) {
		return;
	}
    BST stack1[100], stack2[100];
    int top1 = -1, top2 = -1;

    stack1[++top1] = B;

    while (top1 != -1) {
        BST curr = stack1[top1--];
        stack2[++top2] = curr;

        if (curr->LC) stack1[++top1] = curr->LC;
        if (curr->RC) stack1[++top1] = curr->RC;
    }

    while (top2 != -1) {
        printf("%d,", stack2[top2--]->data);
    }
}
void Delete (BST *B, int value) {
 	
	BST *trav = B;
	
	while(*trav!=NULL && (*trav)->data !=value) {
	   if(value > (*trav)->data ) {
	   	trav = &(*trav)->RC;
	   } else {
	   	trav = &(*trav)->LC;
	   }
	   if(*trav == NULL) return;
	}
	 	
	    if((*trav)->LC != NULL && (*trav)->RC != NULL) {
	    		
	    		
	    		BST *successor = &(*trav)->RC;
	    		while((*successor)->LC !=NULL) {
	    			successor = &(*successor)->LC;
				}
				(*trav)->data = (*successor)-> data;
				Node *sNode = *successor;
				Node *child = sNode->RC;
				*successor = child;
				free(sNode);
			}
	    	
	     else if((*trav)->LC == NULL && (*trav)->RC == NULL) {
	    		Node* temp = *trav;
	    		*trav = NULL;
	    		free(temp);
			} else {
				
				Node *child = ((*trav)->LC!= NULL) ? (*trav)->LC : (*trav)->RC;
					Node *temp = *trav;
					*trav = child;
					free(temp);
		                      	}
				
			}
		
	

