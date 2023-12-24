#include <iostream>

class Tree {
    public:
    int data;
    // is optional : Tree* parent;
    Tree* leftChild;
    Tree* rightChild;
    Tree(int _data) {
        data = _data;
        leftChild = NULL;
        rightChild = NULL;
    }
};

Tree* insert(Tree* root, int _data) {
    if (root == NULL) {
        return new Tree(_data);
    }

    if (_data > root->data) {
        root->rightChild = insert(root->rightChild, _data);
    } else if (_data < root->data) {
        root->leftChild = insert(root->leftChild, _data);
    }
    return root; 
    }

void traverseTree(Tree *root) {
    if (root != NULL) {
        traverseTree(root->leftChild);
        std::cout << root->data << std::endl;
        traverseTree(root->rightChild);
    }
}

Tree* deleteNode(Tree* root, int _data) {
    if (root == NULL) {
        return root;
    }

    //recursive calls (navigate through ancestors of node to delete)
    if (root->data > _data) {
        root->leftChild = deleteNode(root->leftChild, _data);
        return root;
    } else if (root->data < _data) {
        root->rightChild = deleteNode(root->rightChild, _data);
        return root;
    }

    //reach here when root is node to delete

    //if one (or both) child is empty
    if (root->leftChild == NULL) {
        //not sure what point of this is 
        Tree* temporaryNode = root->rightChild;
        delete root;
        return temporaryNode;
    } else if (root->rightChild == NULL) {
        Tree* temporaryNode = root->leftChild;
        delete root;
        return temporaryNode;
    }

    //if both children exist
    else {
        Tree* parentNode = root;

        //assign successor to be deleted
        Tree* successor = root->rightChild;
        while (successor->leftChild != NULL) {
            parentNode = successor;
            successor = successor->leftChild;
        }

        //successor is always left child of parent, can make successor's right child left of its parent
        //if no such successor, assign parent's right child to successor's right child 
        if (parentNode != root) {
            parentNode->leftChild = successor->rightChild;
        } else {
            parentNode->rightChild = successor->rightChild;
        }

        //transfer data 
        root->data = successor->data;

        //delete it
        delete successor;
        return root;

    }


}

int main() {
    Tree* root = new Tree(10);

    root->leftChild = new Tree(3);
    root->rightChild = new Tree(14);

    traverseTree(root);

    insert(root, 30);
    insert(root, 12);
    insert(root, 1);

    std::cout << "After insertion" << std::endl;

    traverseTree(root);

    deleteNode(root, 1);
    deleteNode(root, 14);
    deleteNode(root, 10);
    
    std::cout << "After deletion" << std::endl;

    traverseTree(root);
}