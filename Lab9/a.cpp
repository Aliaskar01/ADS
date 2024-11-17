#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int kmp(string& a, string& b){
    if(b.size() == 0){
        return 0;
    }

    string temp = a;
    int cnt = 1;

    while(a.size() < b.size()){
        a += temp;
        cnt++;
    }
    vector<int> lps(b.size(), 0);

    int prevLPS = 0, i = 1;
    while(i < b.size()){
        if(b[i] == b[prevLPS]){
            lps[i] = prevLPS + 1;
            prevLPS += 1;
            i += 1;
        }
        else if(prevLPS == 0){
            lps[i] = 0;
            i += 1;
        }
        else{
            prevLPS = lps[prevLPS - 1];
        }
    }

    int j = 0;
    while(j < 2){
        int i1 = 0;
        int i2 = 0;
        while(i1 < a.size()){
            if(a[i1] == b[i2]){
                i1++;
                i2++;
            }
            else{
                if(i2 == 0){
                    i1 += 1;
                }
                else{
                    i2 = lps[i2- 1];
                }
            }
            if(i2 == b.size()){
                return cnt;
            }
        }

        a += temp;
        cnt++;
        j++;
    }

    return -1;
}

int main(){
    string a, b;
    cin >> a >> b;
    
    cout << kmp(a, b);
}