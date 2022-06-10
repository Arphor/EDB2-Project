#ifndef TRANSLATE_H
#define TRANSLATE_H

#include <stack>
#include <iostream> 


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

class Translate{

    private:

    std::stack<Node*> pilha;
    Node* top;

    public:
    Translate(){
        top = nullptr;

    };

    bool isSymbol(char c);
    void read_pos(std::string posfixo);
    void clean();

};

#endif