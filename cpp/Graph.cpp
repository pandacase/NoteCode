#include<iostream>
#include<queue>
#include<vector>
using namespace std;

////////////////////并查集/////////////////////
#define maxn 1001

int p[maxn];

int find(int x){
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}

void sets_union(int x, int y){
    p[find(x)] = find(y);
}
///////////////////////////////////////////////


class undirected_graph{
private:
    int size;
    vector<int>* adj;

    void print_route(vector<int>& prev, int s, int t){ // 打印搜索路径
        if(prev[t] != -1 && s != t)
            print_route(prev, s, prev[t]);
        cout << t << " "; // 尾递归打印数据
    }

    bool found;
    void recurDfs(int s, int t, vector<int>& prev, vector<bool>& visited){
        if(found) return;
        visited[s] = true; // s 已经访问
        if(s == t){ // 找到了 t
            found = true;
            return;
        }
        for(int i = 0; i < adj[s].size(); ++i){ // 与BST的前序遍历类似
            int num = adj[s][i];
            if(!visited[num]){
                prev[num] = s;
                recurDfs(num, t, prev, visited);
            }
        }
    }

public:
    undirected_graph(int size){
        this->size = size;
        adj = new vector<int>[size+1];
    }

    void addEdge(int s, int t){ // 无向图相当于添加2条来回的有向边
        adj[s].push_back(t);
        adj[t].push_back(s);
    }

    void bfs(int s, int t){ // 广度优先搜索从 s 到 t 的路径是最短路径
        if(s == t) return;
        vector<int> prev(size+1, -1);
        vector<bool> visited(size+1, false);
        queue<int> helper; // 使用队列来协助进行广搜
        prev.push_back(s);
        visited[s] = true;
        helper.push(s);

        while(!helper.empty()){
            int visiting = helper.front();
            for(int i = 0; i < adj[visiting].size(); ++i){
                int num = adj[visiting][i];
                if(!visited[num]){
                    visited[num] = true;
                    helper.push(num);
                    prev[num] = visiting;
                }
            }
            helper.pop();
        }
        print_route(prev, s, t);
        cout << endl;
    }

    void dfs(int s, int t){
        found = false;
        if(s == t) return;
        vector<int> prev(size+1, -1);
        vector<bool> visited(size+1, false);
        recurDfs(s, t, prev, visited); // 回溯递归算法进行深搜
        print_route(prev, s, t);
        cout << endl;
    }

};



int main(){
    undirected_graph graph(5);
    graph.bfs(1, 3);
    graph.dfs(1, 3);

    system("pause");
    return 0;
}