#include <stdio.h>
#include <stdlib.h>


typedef struct node 
{
    int value;
    int balance;
    struct node* left;
    struct node* right;
}Node;

void updateBal(Node* node);

Node* getParent(Node* root, Node* child);
void printNodeInfo(Node* node);
Node* createNode(int value)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->balance = 0;
    node->value = value;
    node->left = node->right = NULL;
    return node;
}

Node* addNode(Node* node, int value)
{
    if(node == NULL)
    {
        return createNode(value);
    }   
    
    Node* curr = node;
    while(curr != NULL)
    {
        if(curr->value> value)
        {
            if(curr->left == NULL)
            {
                curr->left = createNode(value);
                break;
            }
            curr = curr->left;
        }
        else 
        {
            if(curr->right == NULL)
            {
                curr->right = createNode(value);
                break;
            }
            curr = curr->right;
        }
    }

    return node;
}

Node* parentTraversal(Node* root, Node* child)
{
    Node* curr = child;

    while(curr != NULL)
    {
        updateBal(curr);
        curr = getParent(root, curr);
    }
    return NULL;
}

Node* getParent(Node* root, Node* child)
{
    if(root->value == child->value) 
        return NULL;
    
    Node* curr = root;
    while(curr != NULL)
    {
        if(curr->left != NULL)
        {
            if(curr->left->value == child->value)
            {
                return curr;
            }
        }

        if(curr->right != NULL)
        {
            if(curr->right->value == child->value)
            {
                return curr;
            }
        }

        if(curr->value > child->value)
        {
            curr = curr->left;
        }
        else
        {
            curr = curr->right;
        }
    }
    return NULL;
}

void updateBal(Node* node)
{
    int left,right;
    left = right = 0;
    if(node == NULL)
    {
        return;
    }
    if(node->left != NULL)
    {
        if(node->left->balance < 0)
        {
            left = 1-(node->left->balance);
        }
        else
        {
        left = 1+node->left->balance;
        }
    }
    node->balance = left + right;

    if(node->right != NULL)
    {
        if(node->right->balance >0)
        {
            right = -1-(node->right->balance);
        }
        else
        {
            right = -1+node->right->balance;
        }
    }
    node->balance = left + right;
}

// Node* searchPivot(Node* root)
// {
//     Node* curr = root;
    
//     while(curr->balance>-2 && curr->balance <2)
//     {
//         curr = (curr->balance >0)? curr->left : curr->right;
//     }
//     return curr;
// }

Node* rightRotate(Node* node)
{
    Node* pivot = node->left;
    Node* empty = pivot->right;

    pivot->right = node;
    node->left = empty;

    updateBal(pivot);
    updateBal(node);
    updateBal(pivot->left);

    return pivot;
}

Node* leftRotate(Node* node)
{
    Node* pivot = node->right;
    Node* empty = pivot->left;

    pivot->left = node;
    node->right = empty;

    updateBal(pivot);
    updateBal(node);
    updateBal(pivot->right);

    return pivot;
}

Node* rotate(Node* pivot)
{
    //left left case
    if(pivot->balance == 2 && pivot->left->balance == 1)
    {
        return rightRotate(pivot);
    }
    //left right case
    if(pivot->balance == 2 && pivot->left->balance == -1)
    {
        pivot->left = leftRotate(pivot->left);
        return rightRotate(pivot);
    }
    //right right case
    if(pivot->balance == -2 && pivot->right->balance == -1)
    {
        return leftRotate(pivot);
    }
    //right left case
    if(pivot->balance == -2 && pivot->right->balance == 1)
    {
        pivot->right = rightRotate(pivot->right);
        return leftRotate(pivot);
    }
    return NULL;
}
void preOrder(Node* root)
{
    if(root!= NULL)
    {
        printf("%d ", root->value);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void printNodeInfo(Node* node)
{
    if(node == NULL)
    {
        printf("This node is NULL!\n");
    }
    printf("===============\n");
    printf("Node's value : %d\n", node->value);
    printf("Node's BF : %d\n", node->balance);
    printf("Node's left: %d\n", node->left == NULL? 0:1);
    printf("Node's right: %d\n", node->right == NULL? 0:1);
}

int main()
{
    Node* root = NULL;

    root = addNode(root, 10);
    parentTraversal(root, root);
    root = addNode(root, 15);
    parentTraversal(root, root->right);
    root = addNode(root, 16);
    parentTraversal(root, root->right->right);

    printNodeInfo(root);
    printNodeInfo(root->right);
    printNodeInfo(root->right->right);
    
    preOrder(root);
    printf("\n");

    root = rotate(root);
    parentTraversal(root,root);
    preOrder(root);
    printf("\n");
   
    printNodeInfo(root);
    printNodeInfo(root->left);
    printNodeInfo(root->right);
    // Node* root = NULL;

    // root = addNode(root, 10);
    // parentTraversal(root, root);
    // if(NULL==getParent(root,root))
    // {
    //     printf("Root NULL\n");
    // }
    
    // root = addNode(root, 5);
    // if(root == getParent(root, root->left))
    // {
    //     printf("root'left\n");
    // }

    // parentTraversal(root, root->left);
    // printf("root bal : %d\n", root->balance);
    // printf("root's left bal : %d\n", root->left->balance);

    // root = addNode(root, 3);
    // parentTraversal(root, root->left->left);

    // if(root->left->left == NULL)
    // {
    //     printf("left left is NULL\n");
    // }
    //  Node* temp = getParent(root, root->left->left);
    //  printNodeInfo(temp);
    //  printNodeInfo(getParent(root, temp));

    // Node* pivot = searchPivot(root);
    // printNodeInfo(pivot);
    // preOrder(root);
    // printf("\n");
    // root = rotate(pivot);
    // preOrder(root);
    // printf("\n");
    // printNodeInfo(root);
    // printNodeInfo(root->left);
    // printNodeInfo(root->right);
}