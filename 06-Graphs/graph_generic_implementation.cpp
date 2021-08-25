//Generic implementation of grpah
//it could be directed or undirected, weighted or non-wieghted
#include <bits/stdc++.h>
using namespace std;


template <typename T>
class super_graph{
public:
	map<T,bool> visited;		//for dfs
	map<T,list<pair<T,int>>> adj; //adjacency list representation of graph


	//-------------------------------------------------------------------
	void addEdge(T u,T v,int w,bool bidirec =1)  //two vectice,wieght of edge,bidirec by default is 1 
	{
		adj[u].push_back(make_pair(v,w));
		if(bidirec)
			adj[v].push_back(make_pair(u,w));
	}

	void dfsHelper(T u){
		cout<<u<<" ";
		visited[u] = true;
		for(auto x : adj[u]){
			if(!visited[x.first])
				dfsHelper(x.first);
		}
	}

	void dfs(){
		
		for(auto i:adj){
			if(!visited[i.first])
				dfsHelper(i.first);
		}
	}
/*
	//If dfs need to run for disconnected graph 
	//call for all vectices and keep as visited map public member in class
*/

	void bfs(){
		map<T,bool> visited;
		queue<T> q;
		for(auto i : adj){ 			//this loop is for disconnected
			if(!visited[i.first]){  //this line is part of disc. loop for multi-component graphs also
				q.push(i.first);
				while(!q.empty()){
					T frontElement = q.front();
					q.pop();
					if(!visited[frontElement]){
						cout<<frontElement<<" ";
						visited[frontElement] = true;
					}
					for(auto x : adj[frontElement]){
						if(!visited[x.first]){
							q.push(x.first);
						}
					}
				}
			}
		}
	}

	void printGraph(){
		for(auto vertex : adj){
			cout<<vertex.first<<":";
			for(auto neibours : vertex.second){
				cout<<neibours.first<<"-"<<neibours.second<<" ";
			}
			cout<<endl;
		}
	}


	bool helper_cycleDetect_Undirected_dfs(T node,T parent,vector<int>&vis){
		vis[node] = 1;
		for(auto x : adj[node]){
			if(!vis[x.first]){
				if(helper_cycleDetect_Undirected_dfs(x.first,node,vis))
					return true;
			}
			else if(x.first!=parent){	
				return true;
			}
		}

		return false;

	}

	bool cycleDetect_Undirected_dfs(){
		int v = adj.size();

		vector<int> vis(v);
		for(auto i : adj){
			if(!vis[i.first])
				if(helper_cycleDetect_Undirected_dfs(i.first,-1,vis))
					return true;
		}

		return false;
	}
//detecting cycle main bfs working function
    bool detectCycle(int s,vector<bool> visited){
        
        queue<pair<int,int>> q;
        visited[s] = true;
        q.push(make_pair(s,-1));
        
        while(!q.empty()){
            int cur = q.front().first;
            int prev = q.front().second;
            
            q.pop();
            
            for(auto i: adj[cur]){
                if(!visited[i.first]){
                    visited[i.first] = true;
                    q.push(make_pair(i.first,cur));
                }
                else if(prev !=i.first){
                    return true;
                }
            }
        }
        
        return false;
    }
//
//-------detect cycle in undirected graph using BFS-------
	bool isCycle()
	{	
		int V = adj.size();
	    vector<bool> visited(V+1,0);
	    for(int i=0;i<V;i++){
	        if(!visited[i]){
	            if(detectCycle(i,visited))
	                return true;
	        }
	    }
	    
	    return false;
	}

	//----------------------------------------------


};

int main(){

	super_graph<int> g;
	g.addEdge(0,1,1,1);
	g.addEdge(1,2,1,1);
	g.addEdge(1,6,1,1);
	g.addEdge(2,3,1,1);
	g.addEdge(6,7,1,1);
	g.addEdge(7,4,1,1);
	g.addEdge(3,4,1,1);
	g.addEdge(4,5,1,1);
	


	g.printGraph();
	g.dfs();
	cout<<endl;
	g.bfs();
	cout<<endl;
	cout<<g.cycleDetect_Undirected_dfs();
	cout<<g.isCycle();

}

