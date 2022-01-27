#include <stdio.h>
#include <malloc.h>
                                                                 //creating a structure
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
                                                                  //constructing function for creating the nodes 
struct node* createnode(int data)
{
    struct node *n;                                               //crating a node pointer
    n = (struct node*)malloc(sizeof(struct node));                //allocating memory in the heap
    n->data  = data;                                               //setting the data
    n->left  = NULL;                                               //setting the values of left and rignt childrens to null 
    n->right = NULL;
    return n;                                                     //finally returning the created nod
}

void preorder(struct node*root)
{
    if(root!=NULL){
        printf("%d",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}


void postorder(struct node*root)
{
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d",root->data);
    }
}


void inorder(struct node*root)
{
    if(root!=NULL){
        inorder(root->left);
        printf("%d",root->data);
        inorder(root->right);
    }
}

//              2 
//           /     \ 
//          1       4  
//        /   \    /  \  
//       7     9  4    3 


int main()
{
                                                                   //constructing the root node and child nodes  using function
    struct node *p  = createnode(2);
    struct node *p1 = createnode(1);
    struct node *p2 = createnode(4);
    struct node *p3 = createnode(7);
    struct node *p4 = createnode(9);
    struct node *p5 = createnode(4);
    struct node *p6 = createnode(3);  
                                                                    //linking the root node with left and rignt children
    p->left   = p1;
    p->right  = p2;
    p1->left  = p3;
    p1->right = p4;
    p2->left  = p5;
    p2->right = p6;

printf("preorder  ");
    preorder(p);


printf("\npostorder  ");
    postorder(p);


printf("\ninorder ");
    inorder(p);

    return 0;
}

