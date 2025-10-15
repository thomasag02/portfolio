#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;

int main(){
    int n, s, m;
    cin >> n >> s >> m; //number of stones, starting stone, magic stone
    vector<int> stones(n + 1); //1-indexed
    for(int i = 1; i <= n; i++){
        cin >> stones[i];
    }

    int h = 0; //number of hops
    vector<bool> visited(n + 1, false);
    int pos = s;

    while(true){
        if(stones[pos] == m){
            cout << "magic" << endl;
            break;
        }
        if(visited[pos]){
            cout << "cycle" << endl;
            break;
        }
        
        visited[pos] = true;
        h++;
        int next = pos + stones[pos];
        
        if(next < 1){
            cout << "left" << endl;
            break;
        }
        if(next > n){
            cout << "right" << endl;
            break;
        }
        pos = next;
    }
    cout << h << endl;
    return 0;
}