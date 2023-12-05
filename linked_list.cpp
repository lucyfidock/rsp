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

listNode *findPredeccessor(listNode *head, listNode *value) {
    if ((head == NULL) || (head->next == NULL)) {
        return NULL;
    }

    if (head->next == value) {
        return head;
    } else {
        return findPredeccessor(head->next, value);
    }
}

void deleteNode(listNode **head, listNode **value) {
    listNode * node = *head;
    listNode * predeccessor = findPredeccessor(*head, *value); 

    if (predeccessor == NULL) {
        *head = node->next;
    } else {
        predeccessor->next = (*value)->next;
    }
    free(*value);
}

listNode * searchList(listNode *head, int data) {
    if (head == NULL) {
        return NULL;
    }

    if (head->nodeData == data) {
        return head;
    } else {
        return searchList(head->next, data);
    }
}

void printList(listNode *head) {
    listNode* traverse = head;

    while (traverse != NULL) {
        std::cout << traverse->nodeData << " ";
    traverse = traverse->next;
    }
    std::cout << std::endl;
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

    head = firstNode;

    //print 
    printList(head);

    //INSERTION
    //insert new node 
    insertNode(&head, 6);
    insertNode(&head, 8);
    insertNode(&head, 4);

    //print again
    printList(head);

    //DELETION
    deleteNode(&head, &secondNode);

    //print again
    printList(head);

    //search list 
    std::cout << searchList(head, 6) << std::endl;

    listNode * node6 = searchList(head, 6);
    deleteNode(&head, &node6);

    //print again
    printList(head);


}
