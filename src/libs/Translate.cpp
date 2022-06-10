#include "Translate.h"
#include <stack>
#include <iostream>


Node* Translate::construct(std::string posfixo){
    
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

int main(){

    return 0;
}