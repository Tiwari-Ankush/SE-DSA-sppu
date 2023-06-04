/*
Represent a given graph using adjacency matrix/list to perform DFS and using adjacency 
list to perform BFS. Use the map of the area around the college as the graph. Identify
the prominent land marks as nodes and perform DFS and BFS on that.
*/

#include <iostream>
#include <list>
#include <queue>

using namespace std;

// Graph class representing the map of the area around the college
class Graph {
private:
    int numVertices;
    list<int>* adjList;

public:
    Graph(int numVertices) : numVertices(numVertices) {
        adjList = new list<int>[numVertices];
    }

    void addEdge(int source, int destination) {
        adjList[source].push_back(destination);
    }

    void DFS(int startVertex) {
        bool* visited = new bool[numVertices];
        for (int i = 0; i < numVertices; i++) {
            visited[i] = false;
        }

        DFSUtil(startVertex, visited);
        delete[] visited;
    }

    void BFS(int startVertex) {
        bool* visited = new bool[numVertices];
        for (int i = 0; i < numVertices; i++) {
            visited[i] = false;
        }

        queue<int> queue;

        visited[startVertex] = true;
        queue.push(startVertex);

        while (!queue.empty()) {
            int currentVertex = queue.front();
            cout << currentVertex << " ";
            queue.pop();

            for (int neighbor : adjList[currentVertex]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    queue.push(neighbor);
                }
            }
        }

        delete[] visited;
    }

private:
    void DFSUtil(int vertex, bool* visited) {
        visited[vertex] = true;
        cout << vertex << " ";

        for (int neighbor : adjList[vertex]) {
            if (!visited[neighbor]) {
                DFSUtil(neighbor, visited);
            }
        }
    }
};

int main() {
    // Get the number of landmarks (nodes) from the user
    int numVertices;
    cout << "Enter the number of landmarks: ";
    cin >> numVertices;

    // Create a graph representing the map of the area around the college
    Graph graph(numVertices);

    // Get the edges between landmarks from the user
    int numEdges;
    cout << "Enter the number of edges: ";
    cin >> numEdges;

    cout << "Enter the edges between landmarks (e.g., 0 1):" << endl;
    for (int i = 0; i < numEdges; i++) {
        int source, destination;
        cin >> source >> destination;
        graph.addEdge(source, destination);
    }

    // Perform DFS and BFS on the graph
    int startVertex;
    cout << "Enter the starting landmark for DFS and BFS: ";
    cin >> startVertex;

    cout << "DFS traversal starting from Landmark " << startVertex << ": ";
    graph.DFS(startVertex);
    cout << endl;

    cout << "BFS traversal starting from Landmark " << startVertex << ": ";
    graph.BFS(startVertex);
    cout << endl;

    return 0;
}
