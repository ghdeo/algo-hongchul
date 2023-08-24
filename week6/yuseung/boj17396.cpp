#include <cstdio>
#include <vector>
#include <queue>
#define INF 10000000001
#define ll long long
using namespace std;

int n, m;
vector<int> disable;
vector<vector<pair<int,int>>> g;

int main() {
	scanf("%d%d", &n, &m);
	disable = vector<int>(n);
	g = vector<vector<pair<int,int>>>(n);
	
	for (int i = 0; i < n; i++)scanf("%d",&disable[i]);
	for (int i = 0,a,b,t; i < m; i++) {
		scanf("%d%d%d", &a, &b, &t);
		g[a].push_back(make_pair(t, b));
		g[b].push_back(make_pair(t, a));
	}


	vector<bool> visit(n,false);
	vector<ll> dist(n,INF);
	priority_queue<pair<ll, int>> pq;

	dist[0] = 0;
	pq.push(make_pair(0, 0));

	while (!pq.empty()) {
		auto cur = pq.top(); pq.pop();
		if (visit[cur.second])continue;

		visit[cur.second] = true;
		for (auto x : g[cur.second]) {
			if (!(disable[x.second]&&x.second!=n-1) && (dist[x.second] > dist[cur.second] + x.first)) {
				dist[x.second] = x.first + dist[cur.second];
				pq.push(make_pair(-dist[x.second], x.second));
			}
		}
	}

	printf("%lld", dist[n - 1] == INF ? -1 : dist[n - 1]);

	return 0;
}