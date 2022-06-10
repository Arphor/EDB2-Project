#ifndef TRANSLATE_H
#define TRANSLATE_H

#include <stack>
#include <iostream> 

class Translate{

    public:

    struct Node{
        char val;
        Node *left, *right;

        Node(char val){
            this->val = val;
            this->left = nullptr;
            this->right = nullptr;
        };

        Node(char val, Node *left, Node *right){
            this->val = val;
            this->left = left;
            this->right = right;
        };

    };

    std::stack<Node*> pilha;
    Node* top = nullptr;

    public:

    bool isSymbol(char c);
    Node* construct(std::string posfixo);
    void clean();

};

#endif