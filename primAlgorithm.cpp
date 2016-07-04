#include <iostream>//프림 알고리즘
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
#define MAXV 10000
#define MAXE 100000
struct Adj{
    int v, w;
    Adj(int a, int b){ v = a, w = b; }//변수 다르게 해야함
    bool operator < (const Adj&i)const{
        return w > i.w;
    }
};
vector<vector<Adj> >A;
vector<int> visited;
int main()
{
    A.resize(MAXV + 1);
    visited.resize(MAXV + 1, 0);
    int v, e, start;
    scanf("%d%d", &v, &e);
    for (int u, v, w, i = 1; i <= e; i++)
    {
        scanf("%d %d %d", &u, &v, &w);
        A[u].push_back(Adj(v, w));
        A[v].push_back(Adj(u, w));
    }
    priority_queue<Adj> pq;
    long long cost = 0;
    start = 1;
    pq.push(Adj(start, 0));
    int vertex = 0;
    while (!pq.empty())
    {
        Adj now = pq.top(); pq.pop();
        if (visited[now.v])continue;
        visited[now.v] = 1; ++vertex;
        cost += now.w;
        if (vertex == v)break;
        for (int i = 0; i < A[now.v].size(); i++)
        {
            Adj next = A[now.v][i];
            if (!visited[next.v])
            pq.push(next);
        }
    }
    printf("%lld\n", cost);
}