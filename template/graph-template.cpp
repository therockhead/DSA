template <typename T> // to make it usable for any datatype
// for example: Graph<int>g, Graph<char>g etc..

// Defining Graph Class
class Graph{
// unordered map of an int value and a list
  public:
    unordered_map<T, list<int>> adj; // replaced int with T 
    void addEdge(T u, T v, bool direction) { // replaced int with T
        // create an edge from u to v
        adj[u].push_back(v);
        // direction = true -> directed graph
        // direction = false -> undirected graph
        if (direction == false) {
            adj[v].push_back(u);
        }
    }
    void printAdjList() {
        for (auto i:adj) {
            cout << i.first << "->";
            for (auto j: i.second) {
                cout << j << " ";
            }
            cout << "\n";
        }
    }
};