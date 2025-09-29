#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int MOD = 1000000007;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    if(!(cin >> s)){
        return 0;
    }

    int n = (int)s.size();
    int k = 0;
    for (char c : s){
        if (c == '?'){
            k++;
        }
    }
    // Precompute powers of 2 up to k
    vector<long long> pow2(k+1);
    pow2[0] = 1;
    for(int i = 1; i <= k; i++){
        pow2[i] = (pow2[i-1] * 2) % MOD;
    }

    auto powSafe = [&](int exp) -> long long {
        if (exp < 0){
            return 0;
        }
        if (exp > k ){
            return pow2[k];
        }
        return pow2[exp];
    };

    int ans = 0;
    int onesCount = 0; // count of '1's encountered so far
    int questionsCount = 0; // count of '?' encountered so far

    for(int i = 0; i < n; i++){
        char c = s[i];
        if (c == '0'){
            //pair (1,0), left is fixed 1, 2^k each
            if(onesCount){
                ans = (ans + onesCount % MOD * powSafe(k)) % MOD;
            }
            //pair (?, 0), left is fixed ?, 2^(k-1) each
            if(questionsCount){
                ans = (ans + questionsCount % MOD * powSafe(k - 1)) % MOD;
            }
        }
        else if (c == '?'){
            //treat position as 0 
            if(onesCount){ //pair (1,?), 2^(k-1) each
                ans = (ans + onesCount % MOD * powSafe(k - 1)) % MOD;
            }
            if(questionsCount){ //pair (?,?), 2^(k-2) each
                ans = (ans + questionsCount % MOD * powSafe(k - 2)) % MOD;
            }
            questionsCount++;
        }
        else{ // c == '1'
            onesCount++;
        }
    }

    cout << ans % MOD << "\n";
    return 0;
}
