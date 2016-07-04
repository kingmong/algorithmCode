#include <iostream>//크루스칼 알고리즘
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

#define MAXV 10000
#define MAXE 100000
vector<int>parent(MAXV+1, 0);
void init(){ for (int i = 1; i <= MAXV; i++)parent[i] = i; }
int root(int p)
{
    if (p == parent[p])return p;
    return parent[p] = root(parent[p]);
}
bool SameUnion(int a, int b)
{
    a = root(a), b = root(b);
    if (a == b)return true; return false;
}
void Union(int a, int b)
{
    a = root(a), b = root(b);
    if (a == b)return; parent[a] = b;//IsSame함수 필요없을수도 있음
}
struct Edge{
    int n1, n2, cost;
};
bool cmp(Edge a, Edge b){
    return a.cost < b.cost;
}
Edge edge[MAXE + 1];

int main(){
    int v, e;
    scanf("%d %d", &v, &e);
    for (int a, b, c, i = 1; i <= e; i++)
    {
        scanf("%d %d %d", &a, &b, &c);
        edge[i] = { a, b, c };//선언 순서 지켜야함
    }
    sort(edge + 1, edge + e + 1, cop);
    init();
    int vertex = 1; long long cost = 0;
    for (int i = 1; i <= e; i++)
    {
        if (vertex == v)break;
        int n1 = edge[i].n1, n2 = edge[i].n2;
        if (SameUnion(n1, n2))continue;
        
        vertex++;
        Union(n1, n2);
        cost += edge[i].cost;
    }
    printf("%lld\n", cost);
}