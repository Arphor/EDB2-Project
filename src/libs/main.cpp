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

    Node* no;

    if(myfile.is_open()){
        cin.get();
        while (getline(myfile, linha))
        {
            cout << linha << endl;
            //no = tradutor.read_pos(linha);
            //tradutor.infix(no, myfilein);
            //tradutor.prefix(no, myfilepre);
        }
        
    }
    return 0;
}