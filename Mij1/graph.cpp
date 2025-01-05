#include <iostream>
using namespace std;

class Graph {
private:
    int V;                     // Number of vertices
    int** adjMatrix;           // Adjacency matrix (2D array)

public:
    // Constructor to initialize graph with a given number of vertices
    Graph(int vertices) {
        V = vertices;
        adjMatrix = new int*[V];  // Create an array of pointers (for rows)
        
        for (int i = 0; i < V; i++) {
            adjMatrix[i] = new int[V];  // Create an array for each row (columns)
            for (int j = 0; j < V; j++) {
                adjMatrix[i][j] = 0;  // Initialize matrix with 0 (no edges)
            }
        }
    }

    // Destructor to free dynamically allocated memory
    ~Graph() {
        for (int i = 0; i < V; i++) {
            delete[] adjMatrix[i];  // Delete each row
        }
        delete[] adjMatrix;  // Delete the array of pointers
    }

    // Add an edge to the graph (undirected graph, so add two edges)
    void addEdge(int u, int v) {
        adjMatrix[u][v] = 1;  // Add edge u -> v
        adjMatrix[v][u] = 1;  // Add edge v -> u (undirected)
    }

    // Print the graph (adjacency matrix representation)
    void display() {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Perform Depth First Search (DFS) starting from a given vertex
    void dfs(int start) {
        bool* visited = new bool[V];  // Boolean array to track visited vertices
        for (int i = 0; i < V; i++) visited[i] = false;  // Initialize all as unvisited

        dfsUtil(start, visited);  // Call DFS utility function
        delete[] visited;  // Free the visited array
    }

private:
    // Recursive DFS utility function
    void dfsUtil(int vertex, bool* visited) {
        visited[vertex] = true;
        cout << vertex << " ";  // Print the visited vertex
        
        for (int i = 0; i < V; i++) {
            if (adjMatrix[vertex][i] == 1 && !visited[i]) {  // If there's an edge and vertex is not visited
                dfsUtil(i, visited);  // Recursively visit the neighboring vertex
            }
        }
    }
};

int main() {
    // Create a graph with 5 vertices (0, 1, 2, 3, 4)
    Graph g(5);

    // Add edges
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(3, 4);

    // Display the graph
    cout << "Graph representation (Adjacency Matrix):" << endl;
    g.display();

    // Perform DFS starting from vertex 0
    cout << "\nDepth First Search (DFS) starting from vertex 0: ";
    g.dfs(0);
    cout << endl;

    return 0;
}
