#include <stdio.h>
#include <stdlib.h>

int factorial(int x);

int numOfBST(int key);

typedef struct Node {
    int data;
    int totalBST;
    struct Node* leftNode;
    struct Node* rightNode;
} Node;

Node *createNode(int num,int key) {
    Node* result = malloc(sizeof(Node));
    if(result!=NULL){
        result->data = num;
        result->totalBST = numOfBST(key);
        result->leftNode = NULL;
        result->rightNode = NULL;
    }
    return result;
}

int main() {
    Node *myNode = createNode(5,1);
    Node *myLeftNode = createNode(6,2);
    Node *myRightNode = createNode(7,3);
    Node *myRightLeftNode = createNode(8,5);

    myNode->leftNode = myLeftNode;
    myNode->rightNode = myRightNode;
    myRightNode->leftNode = myRightLeftNode;

    printf("%d", myNode->rightNode->leftNode->totalBST);

    return 0;
    
}

int factorial(int x){
    int factNum=1;
    if(x==0)
        return 1;
    else{
        while(x>1){
            factNum *= x;
            x--;
        }
    }
    return factNum;
}

int numOfBST(int key){
    int catalanNum = factorial(2*key)/(factorial(key+1)*factorial(key));
    return catalanNum;
}
