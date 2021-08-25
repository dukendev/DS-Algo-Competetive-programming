//We will use STL vectors for ease
#include <bits/stdc++.h>
using namespace std;
//BFS also included and DFS

class mygraph{
public:
	int v; 	//nummber of vertices in graph
	vector<int> *adj;

	bool *visited = new bool[v];



	mygraph(int l){
		v = l;
		adj = new vector<int>[v];

		for(int i = 0;i<v;i++)
		visited[i] = false;
	
	}

	void addEdge(int u,int v){
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	void printgraph(mygraph g){
	int size = g.v;
	for(int i=0;i<size;i++){
		cout<<"list of vectex "<<i<<"->";
		for (auto x : g.adj[i])
			{
				cout<<x;
			}
			cout<<endl;
		}

	}

	void bfs(int s){
		bool *visited = new bool[v];
		for(int i=0;i<v;i++){
			visited[i] = false;
		}

		list<int> queue;
		visited[s] = true;
		queue.push_back(s);

		vector<int>::iterator i;

		while(!queue.empty()){
			s = queue.front();
			cout<<s<<" ";
			queue.pop_front();

			for(i = adj[s].begin();i!=adj[s].end();++i){
				if(!visited[*i]){
					visited[*i] = true;
					queue.push_back(*i);
				}
			}
		}


	}

	void dfs(int s){
		visited[s] = true;
		cout<<s<<" ";

		vector<int>::iterator i;

		for(i=adj[s].begin();i!=adj[s].end();++i){
			if(!visited[*i])
				dfs(*i);
		}
	}

};



int main(){

	mygraph g(6);
	g.addEdge(1,0);
	g.addEdge(1,5);
	g.addEdge(1,3);
	g.addEdge(1,4);
	g.addEdge(1,2);
	g.addEdge(4,2);
	g.addEdge(4,0);
	g.addEdge(4,5);
	g.addEdge(4,3);
	g.addEdge(2,3);
	g.addEdge(0,5);


	g.printgraph(g);

	cout<<"bfs is "<<endl;

	g.bfs(2);

	cout<<endl<<"dfs is "<<endl;
	g.dfs(1);

}