#include <iostream>
#include <string.h>
#include "node.h"

using std::cout;
using std::cin;
 
Node C(int a){
    Node n;
    n.semigroup.reserve(a+1);
    for(int r = 0; r < a+1; r++){
        n.semigroup[r]=false;
    }
    if(a%2==0){
        for(int k = (a/2)+1; k < a+1; k++){
            n.semigroup[k]=true;
        }
        n.semigroup[a]=false;
    }
    else{
        for(int k = (a+1)/2; k < a+1; k++){
            n.semigroup[k]=true;
        }
        n.semigroup[a]=false;
    }
    n.level = 0;
    n.f = a;
    return n;
}

int main(int argc, char *argv[]){

    int frobenius;
    bool tex = false, 
         csv = false;


    for(int i = 1; i < argc; ++i){
        if(strcmp(argv[i],"-f") == 0)
        {
            if(++i >= argc)
            {
                cout << "Usage: -f [frobenius number]\n";
                return 1;
            }
            frobenius = atoi(argv[i]);    
        }
        else if(strcmp(argv[i],"-d") == 0)
        {
            if(++i >= argc)
            {
                cout << "Usage: -d [format (tex/csv)]\n";
                return 1;
            }
            else if(strcmp(argv[i], "tex") == 0)
            {
                tex = true;
            }
            else if(strcmp(argv[i], "csv") == 0)
            {
                csv = true;
            }
            else
            {
                cout << "Usage: -d [format (tex/csv)]\n";
                return 1;
            }
        }
		else{
			cout <<"Unknown option " << argv[i] << "\n";
            return 1;
		}
    }

	Node top;

    top = C(frobenius);
    top.buildTree();

    if(csv)
    {
        cout << top.csvLine();
    }
    else if(tex)
    {
        cout << top.texLine();
    }

    return 0;
}
