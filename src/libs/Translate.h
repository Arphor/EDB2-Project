#ifndef TRANSLATE_H
#define TRANSLATE_H

#include <stack>
#include <iostream> 
#include <fstream>


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
    Node* read_pos(std::string posfixo);
    void clean();
    void infix(Node* n, std::ofstream& out);
    void prefix(Node* n, std::ofstream& out);

};

#endif