// decode the tape

#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <cmath>


using namespace std;



int main(){
    vector<char> final;
    string finalizar= "___________";
    string c;
    getline(cin, c);
    int contar = 1;

    while(contar != 2){
        vector<int> bin(8, 0);
        int result = 0;
        getline(cin, c);

        if(c == finalizar)contar++;
        else{

        for(int i = 1; i < 11 ; i++){
            if( c[i]=='o'){
                if(i>6){
                    bin[i - 2]=1;
                }
                else{
                    bin[i-1]=1;
                }
            } 
        }
        vector<int> bin2(8);
        for(int i = 0; i < 8; i++){
            bin2[7-i] = bin[i];
        }
        for(int i = 0;  i < 8; i++){
            if (bin2[i]==1){
                result += (pow(2,i)) ;
            }

           
        }
        
        final.push_back(static_cast<char>(result));
        }

    }

    for(int i = 0; i < final.size() ; i++){
        cout << final[i];
    }


    return 0;
}

/*
___________
| o   .  o|
|  o  .   |
| ooo .  o|
| ooo .o o|
| oo o.  o|
| oo  . oo|
| oo o. oo|
|  o  .   |
| oo  . o |
| ooo . o |
| oo o.ooo|
| ooo .ooo|
| oo o.oo |
|  o  .   |
| oo  .oo |
| oo o.ooo|
| oooo.   |
|  o  .   |
| oo o. o |
| ooo .o o|
| oo o.o o|
| ooo .   |
| ooo . oo|
|  o  .   |
| oo o.ooo|
| ooo .oo |
| oo  .o o|
| ooo . o |
|  o  .   |
| ooo .o  |
| oo o.   |
| oo  .o o|
|  o  .   |
| oo o.o  |
| oo  .  o|
| oooo. o |
| oooo.  o|
|  o  .   |
| oo  .o  |
| oo o.ooo|
| oo  .ooo|
|  o o.oo |
|    o. o |
___________
*/