#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

void bfs(queue<pair<int, int>> q, int marios, int mushrooms, vector<vector<int>> a, int n, int m){
    vector<vector<int>> visited(n, vector<int> (m, 0));

    visited[q.front().first][q.front().second] = 1;
    int cnt = 0;
    while(!q.empty()){
        int tempMarios = 0;
        bool isChanged = false;

        while(marios != 0){
            int x = q.front().first;
            int y = q.front().second;

            q.pop();

            if(x - 1 >= 0 && a[x-1][y] == 1 && visited[x-1][y] == 0){
                isChanged = true;
                tempMarios++;
                mushrooms--;
                visited[x-1][y] = 1;
                q.push(make_pair(x-1, y));
            }
            if(x + 1 < a.size() && a[x+1][y] == 1 && visited[x+1][y] == 0){
                isChanged = true;
                tempMarios++;
                mushrooms--;
                visited[x+1][y] = 1;
                q.push(make_pair(x+1, y));
            }
            if(y - 1 >= 0 && a[x][y-1] == 1 && visited[x][y-1] == 0){
                isChanged = true;
                tempMarios++;
                mushrooms--;
                visited[x][y-1] = 1;
                q.push(make_pair(x, y-1));
            }
            if(y + 1 < m && a[x][y+1] == 1 && visited[x][y+1] == 0){
                isChanged = true;
                tempMarios++;
                mushrooms--;
                visited[x][y+1] = 1;
                q.push(make_pair(x, y+1));
            }
            marios--;

        }
        if(isChanged == true){
            cnt++;
        }
        marios = tempMarios;
    }
    if(mushrooms == 0) cout << cnt;
    else cout << -1;
}


int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> a; 
    map<pair<int, int>, int> visited;
    queue<pair<int, int>> q;
    
    int mushrooms = 0, marios = 0;

    for (int i = 0; i < n; i++) {
        vector<int> tempRow;
        for (int j = 0; j < m; j++) {
            int temp;
            cin >> temp;
            tempRow.push_back(temp);
            if(temp == 1){
                mushrooms++;
            }
            if(temp == 2){
                marios++;
                q.push(make_pair(i, j));
            }
        }
        a.push_back(tempRow);
    }

    if(mushrooms == 0){
        cout << 0;
        return 0;
    } 

    bfs(q, marios, mushrooms, a, n, m);

    return 0;
}