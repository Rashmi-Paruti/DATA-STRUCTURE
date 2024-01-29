/*
Design, Develop and Implement a menu driven Program in C for the following operations on Binary Search Tree(BST) of Integers
Create a BST of N Integers: 6, 9, 5, 2, 8, 15, 24, 14, 7, 8, 5, 2
Traverse the BST in Inorder, Preorder and Post Order
Search the BST for a given element (KEY) and report the appropriate message
Exit
*/
#include <stdio.h>
#include <stdlib.h>
int flag=0;
typedef struct BST
{
int data;
struct BST *lchild,*rchild;
} node;
/*FUNCTION PROTOTYPE*/
void insert(node *, node *);
void inorder(node *);
void preorder(node *);
void postorder(node *);
node *search(node *, int, node **);
void main()
{
int choice;
int ans =1;
int key;
 node *new_node, *root, *tmp, *parent;
 node *get_node();
 root = NULL;
 printf("\nProgram For Binary Search Tree ");
do
 {
 printf("\n1.Create");
 printf("\n2.Search");
 printf("\n3.Recursive Traversals");
 printf("\n4.Exit");
 printf("\nEnter your choice :");
 scanf("%d", &choice);
 switch (choice)
 {
 case 1:
 do
 {
 new_node = get_node();
 printf("\nEnter The Element ");
 scanf("%d", &new_node->data); 
if (root == NULL) /* Tree is not Created */
 root = new_node;
 else
 insert(root, new_node);
 printf("\nWant To enter More Elements?(1/0)");
 scanf("%d",&ans);
 } while (ans);
 break;
 case 2:
 printf("\nEnter Element to be searched :");
 scanf("%d", &key);
 tmp = search(root, key, &parent);
 if(flag==1)
 {
 printf("\nParent of node %d is %d", tmp->data, parent->data);
 }
 else
 {
 printf("\n The %d Element is not Present",key);
 }
 flag=0;
 break;
 case 3:
 if (root == NULL)
 printf("Tree Is Not Created");
 else
 {
 printf("\nThe Inorder display :");
 inorder(root);
 printf("\nThe Preorder display : ");
 preorder(root);
 printf("\nThe Postorder display : ");
 postorder(root);
 }
 break;
 }
 }
 while (choice != 4);
 }
/*Get new Node */
node *get_node()
{
 node *temp; 
temp = (node *) malloc(sizeof(node));
 temp->lchild = NULL;
 temp->rchild = NULL;
return temp;
}
/*This function is for creating a binary search tree */
void insert(node *root, node *new_node)
{
if (new_node->data < root->data)
 {
 if(root->lchild==NULL)
 root->lchild=new_node;
 else
 insert(root->lchild, new_node);
 }
if (new_node->data > root->data)
 {
 if (root->rchild == NULL)
 root->rchild = new_node;
 else
 insert(root->rchild, new_node);
 }
}
/*This function is for searching the node from binary Search Tree*/
node *search(node *root, int key, node **parent)
{
 node *temp;
 temp = root;
while (temp != NULL)
 {
 if (temp->data == key)
 {
 printf("\nThe %d Element is Present", temp->data);
 flag=1;
 return temp;
 }
 *parent = temp;
 if (temp->data > key)
 temp = temp->lchild;
 else
 temp = temp->rchild;
 } 
return NULL;
}
/*This function displays the tree in inorder fashion */
void inorder(node *temp)
{
if (temp != NULL)
 {
 inorder(temp->lchild);
 printf("%d\t", temp->data);
 inorder(temp->rchild);
 }
}
/*This function displays the tree in preorder fashion */
void preorder(node *temp)
{
if (temp != NULL)
 {
 printf("%d\t", temp->data);
 preorder(temp->lchild);
 preorder(temp->rchild);
 }
}
/*This function displays the tree in postorder fashion */
void postorder(node *temp)
{
if (temp != NULL)
 {
 postorder(temp->lchild);
 postorder(temp->rchild);
 printf("%d\t", temp->data);
 }
}