#include <iostream>
#include <cmath>
using namespace std;

int respuesta(int a){
    int ans, temp;
    temp = ((((((a * 567)/9)+7492)*235)/47)-498);

    ans = abs((temp / 10) % 10);

    return ans;
}

int main(){
int c;
cin >> c;
while(c--){
    int num, ans;
    cin >> num;
    cout << respuesta(num) << endl;
}

    return 0;
}