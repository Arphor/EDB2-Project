#include "translate.h"

#include <stack>
#include <iostream>


Translate::Node* construct(std::string posfixo){
    
    if (posfixo.length() == 0){
        return nullptr;
    }

    for (char i : postfix){
        if (!isSymbol(i)){
            Node* n = new Node(i);
            pilha.push(n);
        }else{
            Node* x = pilha.top();
            pilha.pop();

            Node* y = pilha.top();
            pilha.pop();

            Node* n = new Node(i, y, x);

            s.push(n);
        }
    }

    top = pilha.top();

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