#include<bits/stdc++.h>
#define FOR(i,b) for(int i =0 ; i< b;i++)
#define loop(i,a,b) for(int i =a ; i< b;i++)
#define fi first
#define se second
#define len(a) ((int)a.size())
#define pb push_back
#define NEXT(a,b) ((a)%b)

using namespace std;


typedef pair<int,int> ii;
typedef pair<ii,int> iii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef long long i64;

const int MAXN = 100+5, INF = 1e9;
int V, m;

vector< vector<int> > AdjList;

/*
short int vis[26][26][7][5];
const int dx[] = {-1,0,1,0} , dy[] = {0,1,0,-1};

struct node{
  int i,j,color,direccion, time;
		node(int i_ , int j_ , int color_, int direccion_ , int t): i(i_) , j(j_) , color(color_) ,
		direccion(direccion_) , time(t) {}
};

short int let(int i, int j){return 0<=i && i<N && 0<=j && j<M;}
*/

vi color;
int colCount[] = {0,0};
int bfs(const int s){
		queue<int> q; q.push(s);
		color[s] = 0;
		colCount[0]++;
		bool isBipartite = true; // addition of one boolean flag, initially true
		while (!q.empty() & isBipartite) { // similar to the original BFS routine
				int u = q.front(); q.pop();
				for (int j = 0; j < (int)AdjList[u].size(); j++) {
				int v = AdjList[u][j];
				if (color[v] == INF) { // but, instead of recording distance,
						color[v] = 1 - color[u]; // we just record two colors {0, 1}
						colCount[color[v]]++;
						q.push(v);
				}
				else if (color[v] == color[u]) { // u & v.first has same color
						isBipartite = false;
						break;
				}
			}
	}
	return isBipartite;
}

/*
	Casos de escape
	2
	1 0
	r = 1
	2 0
	r = 2

*/

int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int ntc;
	int u ,  v ;
	cin >> ntc;
	AdjList.clear();
	loop(ctn,1,ntc+1){
			cin >> V >> m;
			AdjList.assign(V+1,vi());
			FOR(i,m){
					cin >> u >> v;
					AdjList[u].pb(v);
					AdjList[v].pb(u);
			}

			int esFloor = 1,tmp = 0;
			color.assign(V+1,INF);
			memset(colCount,0,sizeof colCount);
			FOR(u,V){
						if (color[u]==INF){
                    esFloor = bfs(u);
                    if (!esFloor)break;
						}
						cerr << u << endl;
						//cout << colCount[0] << " " << colCount[1] << endl;
						if(colCount[0]==0 && colCount[1]!=0)tmp++;
						else if(colCount[1]==0 && colCount[0]!=0)tmp++;
						else tmp += min(colCount[0],colCount[1]);
						memset(colCount,0,sizeof colCount);
			}
			if (!esFloor)cout <<  -1  << endl;
			else cout << tmp << endl;

	}

  return 0;
}
