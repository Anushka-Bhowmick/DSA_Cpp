#include <iostream>
#include <stack>

using namespace std;

class Graph {
public:
    int vertices;
    int **adjMatrix;

    Graph(int v) : vertices(v) {
        adjMatrix = new int*[vertices];
        for (int i = 0; i < vertices; ++i) {
            adjMatrix[i] = new int[vertices];
            for (int j = 0; j < vertices; ++j) {
                adjMatrix[i][j] = 0;  
            }
        }
    }

    void addEdge(int u, int v) {
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
    }

    void dfs(int start) {
        bool *visited = new bool[vertices];
        for (int i = 0; i < vertices; ++i) {
            visited[i] = false;
        }

        stack<int> s;
        s.push(start);

        cout << "DFS Traversal starting from node " << start << ": ";

        while (!s.empty()) {
            int current = s.top();
            s.pop();

            if (!visited[current]) {
                cout << current << " ";
                visited[current] = true;
            }

            for (int neighbor = vertices - 1; neighbor >= 0; --neighbor) {
                if (adjMatrix[current][neighbor] && !visited[neighbor]) {
                    s.push(neighbor);
                }
            }
        }

        cout << endl;

        delete[] visited;
    }

    ~Graph() {
        for (int i = 0; i < vertices; ++i) {
            delete[] adjMatrix[i];
        }
        delete[] adjMatrix;
    }
};

int main() {
    int numVertices, numEdges;

    cout << "Enter the number of vertices: ";
    cin >> numVertices;

    Graph g(numVertices);

    cout << "Enter the number of edges: ";
    cin >> numEdges;

    cout << "Enter the edges (vertex1 vertex2):" << endl;
    for (int i = 0; i < numEdges; ++i) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    int startNode;
    cout << "Enter the starting node for DFS: ";
    cin >> startNode;

    g.dfs(startNode);

    return 0;
}
