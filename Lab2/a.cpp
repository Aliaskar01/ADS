#include <iostream> 
#include <vector> 
#include <cmath> 
using namespace std; 
int offset (vector<int>& vector_v, int h) { 
    int index; 
    if (vector_v.empty()) { 
        return -1; 
    } else { 
        int min_offset = abs((vector_v[0]-h)); 
        index=0; 
        for (int i=0; i<vector_v.size(); ++i) { 
            if (abs((vector_v[i]-h))<min_offset) { 
                min_offset=abs((vector_v[i]-h)); 
                index=i; 
            }  
        } 
    } 
    return index; 
} 
int main() { 
    int n; 
    cin >> n; 
    vector<int> list(n); 
    for (int i=0; i<n; ++i) { 
        cin >> list[i]; 
    } 
    int k; 
    cin >> k; 
    int answer = offset(list, k); 
    cout << answer; 
     
    return 0; 
}

