#include <iostream> 
#include <algorithm> 
#include <set> 
 
using namespace std; 
int main(){ 
    int size; 
    cin >> size; 
    multiset<int>kuku; 
    for(int i=0; i<size; ++i){ 
        int kuku_insert; 
        cin >> kuku_insert; 
        kuku.insert(kuku_insert); 
    } 
    int max=*kuku.rbegin(); 
    int min=*kuku.begin(); 
    int max_count=0; 
    for (int i=min; i<max+1; ++i){ 
        int couu=kuku.count(i); 
        if (couu>max_count){ 
            max_count=couu; 
        } 
    } 
    set<int>kuku_demo; 
    set<int>kuku_demo_from_max; 
    for (auto it=kuku.begin(); it!=kuku.end(); ++it){ 
        kuku_demo.insert(*it); 
    } 
    for (auto it=kuku_demo.begin(); it!=kuku_demo.end(); ++it){ 
        if(kuku.count(*it)==max_count){ 
            kuku_demo_from_max.insert(*it); 
        } 
    } 
    for (auto it=kuku_demo_from_max.rbegin(); it!=kuku_demo_from_max.rend(); ++it){ 
        cout << *it << " "; 
    } 
 
 
    return 0; 
}