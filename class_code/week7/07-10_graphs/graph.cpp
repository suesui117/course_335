#include <list>
#include<iostream>
#include<vector>
#include <cstdlib>    
#include <ctime>   

using namespace std;

class graph
{
    private:
        int vertices;
        vector<list<int>> adj_list;
        vector<vector<int>> adj_matrix;
        vector<bool> visited;
        bool bi_directed; 

    public:
    // set total number of vertices to the input which is 7
    // and let this graph be a bi-directed true graph
    // visited_ is set to size 7 with each element being a boolean false
    // adj_list is set to size 7 with each element being an empty int list
    // adj_matrix is set to size 7 with with 7 vectors, each is size 7 of 0.
        graph(int v, bool b): vertices(v), bi_directed(b), 
                              visited(vector<bool>(v,false)), 
                              adj_list(vector<list<int>>(v,list<int>())),
                              adj_matrix(vector<vector<int>>(v,vector<int>(v,0)))  
        {
            for(int i = 0; i < v; i++)    
                adj_matrix[i][i] = 1; // setting the diagonal elements to 1 [1,1], [2,2], [3,3]
        }

        std::vector<bool> getVisited() { return visited;}
        std::vector<list<int>> getList() { return adj_list;}
        std::vector<vector<int>> getVector() { return adj_matrix;}

        int GetNumVertices()
        {
            return vertices;
        }

        void AddEdge(int vertex, int destination)
        {
            // user inputs a vertix, has to be between 0>= vertix > 7, same goes for destination
            if( vertex >= vertices || destination >= vertices)
            {
                cout<<"invalid vertex"<<endl;
                return;
            }
            // else if its valid
            adj_list[vertex].push_back(destination); // 0th list, first element will be the other vertex
            adj_matrix[vertex][destination] = 1;

            if(bi_directed)
            {
                adj_list[destination].push_back(vertex); // if both ways, then also link destination to vertex
                adj_matrix[destination][vertex] = 1;
            }
        }

        void PrintEdgesAtVertex(int vertex)
        {
            cout << "list edges at vertex "<< vertex << endl;
            for(auto& b : adj_list[vertex])
                cout << b << endl;
        }

        void BFS(int start_vertex)
        {
            if( start_vertex >= vertices)
            {
                cout<<"invalid vertex"<<endl;
                return;
            }

            ResetVisited();
            list<int> queue;

            // mark starting_vertex as visited
            cout<<start_vertex;
            visited[start_vertex] = true;
            queue.push_back(start_vertex);

            while(!queue.empty())
            {
                start_vertex = queue.front();
                queue.pop_front();

                for (auto& i : adj_list[start_vertex])
                {
                    if(!visited[i])
                    {
                        cout <<" -> "<< i;
                        visited[i] = true;
                        queue.push_back(i);
                    }
                }
                if (queue.empty())
                {
                    int count = 0;
                    for (auto i : visited)
                    {
                        if (!i)
                        {
                            cout<< " -> " << count;
                            i = true;
                            queue.push_back(count);
                            break;
                        }
                        count++;
                    }
                }
                
            }
        }

        void ResetVisited()
        {
            for (auto f  : visited)
                f = false;
        }

        void DFS(int vertex)
        {
            if( vertex >= vertices)
            {
                cout<<"invalid vertex"<<endl;
                return;
            }

            if(visited[vertex])
                return;
            
            else 
            {
                visited[vertex] = true;
                cout<<vertex<<" -> ";
            }

            for (auto& neighbor : adj_list[vertex])
                DFS(neighbor);
            
        }

        void DisconnectedDFS(int vertex)
        {
            DFS(vertex);
            for(int i = 0; i < visited.size(); i++)
                if(!visited[i])
                    DFS(i);
        }
};

int main()
{
    graph test(7, true);
    test.AddEdge(0,1);
    test.AddEdge(0,2);
    test.AddEdge(1,3);
    test.AddEdge(1,4);
    test.AddEdge(2,5);
    test.AddEdge(2,6);

    std::vector<std::list<int>> adj_list = test.getList();

    for (int i = 0; i < adj_list.size(); ++i) {
        std::cout << "Vertex " << i << " -> ";
        for (auto it = adj_list[i].begin(); it != adj_list[i].end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << "\n";
    }


    // Breadth-First-Search
    for (int i = 0; i < test.GetNumVertices(); i++)
        {
            cout<<"Breadth First Search: ";

            test.BFS(i);
            
            cout<<endl;
        }

    // Depth-First-Search
    for(int i = 0; i < test.GetNumVertices(); i++)
    {
        test.ResetVisited();
        cout<<"Depth First Search: ";
        test.DFS(i);
        cout<<endl;
    }

    // Disconnected Depth First Search
    srand (time(NULL));

    int iSecret = rand() % 10 + 1;
    for(int i = 0; i < test.GetNumVertices(); i++)
    {
        test.ResetVisited();
        cout<<"Disconnected Depth First Search: ";
    
        test.DisconnectedDFS(i);
        cout<<endl;
    }


    return 0;
}