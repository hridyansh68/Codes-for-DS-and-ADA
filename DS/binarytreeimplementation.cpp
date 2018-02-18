#include <iostream>
#include <math.h>
using namespace std;

struct node {
  int data;
  node *left;
  node *right;
};

node *newNode(int data){
    node *newNode = new(node);
    newNode->data = data ;
    newNode->left = NULL;
    newNode->right = NULL;
    return(newNode);
}

void inorderTraversal(node *head){
    if(head!=NULL){
        inorderTraversal(head->left);
        cout<<head->data<<" ";
        inorderTraversal(head->right);
    }
}

void preorderTraversal(node *head){
    if(head!=NULL){
        cout<<head->data<<" ";
        preorderTraversal(head->left);
        preorderTraversal(head->right);
    }
}

void postorderTraversal(node *head){
    if(head!=NULL){
        postorderTraversal(head->left);
        postorderTraversal(head->right);
        cout<<head->data<<" ";
    }
}

int height(node *root){
    if(root==NULL){
        return 0;
    }
    else{
        int lheight=height(root->left);
        int rheight=height(root->right);
        return ((lheight>rheight)?(lheight+1):(rheight+1));
    }
}

node **createque(int *front,int *rear,int size){
    node **que = new node*[size];
    *rear=0;
    *front=0;
    return(que);
}

void enque(node **que,int *front,int *rear,node *newNode){
    que[*rear]= newNode;
    *rear+=1;
}

node *deque(node **que,int *front){
    (*front)+=1;
    return(que[(*front)-1]);
}

void levelorderTraversal(node *root){
    int front,rear,h=height(root);
    node **que = createque(&front,&rear,(pow(2,h)-1));
    node *temp_node = root;
    while(temp_node!=NULL){
         cout<<temp_node->data<<" ";
        if (temp_node->left!=NULL)
            enque(que,&front, &rear, temp_node->left);
 
        if (temp_node->right!=NULL)
            enque(que,&front, &rear, temp_node->right);
 
        temp_node = deque(que, &front);
        
        
    }
}
int main() {
	 struct node *root = newNode(1);  
	 root->left        = newNode(2);
     root->right       = newNode(3);
     root->left->left  = newNode(4);
     root->left->right = newNode(5);
     inorderTraversal(root);
     cout<<endl;
     preorderTraversal(root);
     cout<<endl;
     postorderTraversal(root);
     cout<<endl;
     cout<<height(root);
     cout<<endl;
     levelorderTraversal(root);
     
	return 0;
}