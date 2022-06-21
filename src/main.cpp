#include <iostream>
#include <string>

#include "Translate.h"

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

    std::ofstream myfileval;
    myfileval.open ("val.out", std::ios::out);

    Node* no;

    if(myfile.is_open()){
        cin.get();
        while (getline(myfile, linha))
        {
            //std::cout << "oi" << std::endl;
            //cout << linha << endl;
            no = tradutor.read_pos(linha);

            tradutor.infix(no, myfilein);
            myfilein << std::endl;

            tradutor.prefix(no, myfilepre);
            myfilepre << std::endl;

            myfileval << tradutor.val(no) << std::endl;

        }
        
    }
    return 0;
}