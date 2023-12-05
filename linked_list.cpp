#include <iostream>

class listNode {
    public:
    int nodeData; //data in the node 
    listNode *next; //pointer to next node in list
    listNode() {
        nodeData = 0;
        next = NULL;
    }
};

void insertNode(listNode **head, int data) {
    listNode* newNode = new listNode();
    newNode->nodeData = data;
    newNode->next = *head;
    *head = newNode;
}

void deleteNode(listNode **head, int data) {
    
}

int main() {
    //CREATING LIST
    listNode* head;
    listNode* firstNode = new listNode();
    listNode* secondNode = new listNode();
    listNode* thirdNode = new listNode();

    //put in the values 
    firstNode->nodeData = 1;
    secondNode->nodeData = 2;
    thirdNode-> nodeData = 3;

    //connect them 
    firstNode->next = secondNode;
    secondNode->next = thirdNode;

    //print 
    head = firstNode;
    while (head != NULL) {
        std::cout << head->nodeData << " ";
    head = head->next;
    }
    std::cout << std::endl;

    //set back to first node 
    head = firstNode;

    //INSERTION
    //insert new node 
    insertNode(&head, 6);
    insertNode(&head, 8);
    insertNode(&head, 4);

    //print again
    while (head != NULL) {
        std::cout << head->nodeData << " ";
    head = head->next;
    }

    //set back to first node 
    head = firstNode;

    //


}
