#include<bits/stdc++.h>

using namespace std;

#define dbg(x) cout << (#x) << " = " << x << endl;
#define f first
#define sec second
#define pb push_back
#define __ ios_base::sync_with_stdio(false); cin.tie(NULL);

const int MAX = 1e5 + 1;

vector< vector<int> > g(MAX);
vector<bool> vis(MAX, false);
vector<int> dist(MAX, -1);
vector<int> pai(MAX, -1);

void bfs(int source){
    queue<int> q;
    q.push(source);
    vis[source] = true;
    dist[source] = 0;
    pai[source] = source;

    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(auto w : g[v]){
            if(!vis[w]){
                q.push(w);
                vis[w] = true;
                dist[w] = dist[v] + 1;
                pai[w] = v;
            }
        }
    }
    return;
}

vector<int> path(int v){
    vector<int> ret;
    ret.pb(v);
    while(pai[v] != v){ // ate chegar na source
        v = pai[v]; // vai subindo
        ret.pb(v);
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

int main(void){ __
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; ++i){
        int a, b;
        cin >> a >> b;
        --a; --b;

        g[a].pb(b);
        g[b].pb(a);
    }

    bfs(0); // 0 eh a source aqui
    vector<int> ans = path(6); // menor caminho da source ate o 7

    for(int i = 0; i < ans.size(); ++i)
        cout << ans[i] + 1 << " ";
    cout << endl;

    return 0;
}
