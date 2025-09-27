#include <iostream>
using namespace std;

//Find the number of operations needed to make a string contain "lv" as a subsequence
int main(){
    int N;
    string s;
    cin >> N >> s;

    //Case 1: If the string already contains "lv" as a subsequence
    if(s.find("lv") != string::npos){
        cout << 0 << endl;
        return 0;
    }
    //Case 2: If the string contains 'l' but not 'v'
    else if(s.find('l') != string::npos){
        cout << 1 << endl;
        return 0;
    }
    //Case 3: If the string contains 'v' but not 'l'
    else if(s.find('v') != string::npos){
        cout << 1 << endl;
        return 0;
    }
    //Case 4: If the string contains neither 'l' nor 'v'
    else{
        cout << 2 << endl;
        return 0;
    }
    return 0;
}