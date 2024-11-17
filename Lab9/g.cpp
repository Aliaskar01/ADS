#include <iostream>
#include <string>
#include <vector>

using namespace std;

int kmp(string& patt){

    vector<int> lps(patt.size(), 0);

    int prevLPS = 0, i = 1;
    while(i < patt.size()){
        if(patt[i] == patt[prevLPS]){
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

    int i1 = 0;
    int i2 = 0;
    return lps[patt.size() - 1];
}

int main(){
    string patt;
    cin >> patt;
    cout << patt.size() - kmp(patt);
}