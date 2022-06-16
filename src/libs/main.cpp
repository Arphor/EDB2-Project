#include <iostream>
#include <fstream>
#include <vector>
#include "Translate.h"
#include <string>

using namespace std;

int main( int argc, char ** argv )
{
    Translate tradutor;
    string arquivo;
    string linha;
    
    cin >> arquivo;

    ifstream myfile;
    myfile.open(arquivo);

    std::ofstream myfilepre;
    myfilepre.open ("pre.out", std::ios::out);

    std::ofstream myfilein;
    myfilein.open ("in.out", std::ios::out);

    std::string s = "AB+CD+*";
    Node* no;

    if(myfile.is_open()){
        //cin.get();
        while (getline(myfile, linha))
        {
            std::cout << linha << std::endl;
            no = tradutor.read_pos(linha);
            tradutor.infix(no, myfilein);
            myfilein << endl;
            tradutor.prefix(no, myfilepre);
            myfilepre << endl;
            
        }
        myfilein.close();
        myfilepre.close();
        
    }
    return 0;
}