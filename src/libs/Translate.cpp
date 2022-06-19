#include "Translate.h"
#include <stack>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <sstream>


Node* Translate::read_pos(std::string posfixo){
    
    this->clean();
    if (posfixo.length() == 0){
        return nullptr;
    }



    //string line = "test one two three.";
    std::vector<std::string> v;
    std::stringstream ss(posfixo);
    std::string s;

    while (std::getline(ss, s, ' ')) {
        v.push_back(s);
    }


    std::string d;

    while(!v.empty()){
        d = v.front();
        v.erase(v.begin());

        if (!Translate::isSymbol(d)){
            Node* n = new Node(d);
            Translate::pilha.push(n);
        }else{
            Node* x = pilha.top();
            pilha.pop();

            Node* y = pilha.top();
            pilha.pop();

            Node* n = new Node(d, y, x);

            pilha.push(n);
        }
    }

    return pilha.top();

    
}

bool Translate::isSymbol(std::string c){
    if (!c.compare("+") || !c.compare("*") || !c.compare("/") || !c.compare("-")){
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

    out << n->val << " ";

    prefix(n->left, out);
    prefix(n->right, out);


}

int Translate::val(Node *n){

    if(isSymbol(n->val)) {
        if(!n->val.compare("+")){
            return val(n->left) + val(n->right);
        }
        if(!n->val.compare("-")){
            return val(n->left) - val(n->right);
        }
        if(!n->val.compare("/")){
            return val(n->left) / val(n->right);
        }
        if(!n->val.compare("*")){
            return val(n->left) * val(n->right);
        }   
    }else{
        int number = 0;
        number = std::stoi(n->val);
        return number;
    }

}