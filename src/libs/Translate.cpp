#include "Translate.h"
#include <stack>
#include <iostream>
#include <fstream>


Node* Translate::read_pos(std::string posfixo){
    
    this->clean();
    if (posfixo.length() == 0){
        return nullptr;
    }

    for (char i : posfixo){
        if (!Translate::isSymbol(i)){
            Node* n = new Node(i);
            Translate::pilha.push(n);
        }else{
            Node* x = pilha.top();
            pilha.pop();

            Node* y = pilha.top();
            pilha.pop();

            Node* n = new Node(i, y, x);

            pilha.push(n);
        }
    }

    return pilha.top();

    
}

bool Translate::isSymbol(char c){
    if (c == '+' || c == '*' || c == '/' || c == '-'){
        return true;
    }
    return false;

}

void Translate::clean(){
    while(!pilha.empty()){
        pilha.pop();
    }

    top = nullptr;
}

void Translate::infix(Node* n, std::ofstream& out){


    if (n == nullptr){
        return;
    }

    if (isSymbol(n->val)){
        out << "(";
    }

    infix(n->left, out);
    out << n->val;

    infix(n->right, out);

    if (isSymbol(n->val)){
        out << ")";
    }


}


void Translate::prefix(Node* n, std::ofstream& out){

    if (n == nullptr){
        return;
    }

    out << n->val;

    prefix(n->left, out);
    prefix(n->right, out);


}
