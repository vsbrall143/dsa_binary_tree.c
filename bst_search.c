
#include <stdio.h>
#include <malloc.h>
// creating a structure
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
// constructing function for creating the nodes
struct node *createnode(int data)
{
    struct node *n;                                 // crating a node pointer
    n = (struct node *)malloc(sizeof(struct node)); // allocating memory in the heap
    n->data = data;                                 // setting the data
    n->left = NULL;                                 // setting the values of left and rignt childrens to null
    n->right = NULL;
    return n; // finally returning the created nod
}


struct node *search(struct node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (key == root->data)
    {
        return root;
    }
    else if (key < root->data)
    {
        return search(root->left, key);
    }
    else
    {
        return search(root->right, key);
    }
}

struct node *searchiterative(struct node *root, int key)
{
    while (root != NULL)
    {
        if (key == root->data)
        {
            return root;
        }
        else if (key < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return NULL;
}


int main()
{
    // constructing the root node and child nodes  using function
    struct node *p = createnode(4);
    struct node *p1 = createnode(2);
    struct node *p2 = createnode(6);
    struct node *p3 = createnode(1);
    struct node *p4 = createnode(3);
    struct node *p5 = createnode(5);
    struct node *p6 = createnode(7);
    // linking the root node with left and rignt children
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    p2->left = p5;
    p2->right = p6;

    //              4
    //           /     \ 
    //          2       6
    //        /   \    /  \  
    //       1     3  5    7


// search using reccursions
    struct node *n = search(p, 7);

    if (n != NULL)
    {
        printf("found:  %d", n->data);
    }
    else
    {
        printf("element not found");
    }


// search using iterations
    // struct node* n=searchiterative(p,4);
    // if(n!=NULL)
    // {
    // printf("found:%d",n->data);
    // }
    // else
    // {
    //     printf("element not found");
    // }



    return 0;
}

