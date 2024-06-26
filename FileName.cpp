#include <iostream>
using namespace std;
class Graph {
private:
    int vertices;
    int** adjMatrix;
    int capacity;

public:
    Graph(int n) {
        vertices = n;
        capacity = n + 5;
        adjMatrix = new int* [capacity];
        for (int i = 0; i < capacity; ++i) {
            adjMatrix[i] = new int[capacity];
            for (int j = 0; j < capacity; ++j) {
                adjMatrix[i][j] = 0;
            }
        }
    }

    void addEdge(int from, int to, int weight) {
        if (from >= 0 && from < vertices && to >= 0 && to < vertices) {
            adjMatrix[from][to] = weight;
            // For undirected graph, uncomment the next line
            // adjMatrix[to][from] = weight;
        }
        else {
            cout << "Invalid vertices. Edge cannot be added." << endl;
        }
    }

    void addVertex() {
        if (vertices >= capacity) {
            int newCapacity = capacity * 2;
            int** newMatrix = new int* [newCapacity];
            for (int i = 0; i < newCapacity; ++i) {
                newMatrix[i] = new int[newCapacity];
                for (int j = 0; j < newCapacity; ++j) {
                    newMatrix[i][j] = 0;
                }
            }

            for (int i = 0; i < vertices; ++i) {
                for (int j = 0; j < vertices; ++j) {
                    newMatrix[i][j] = adjMatrix[i][j];
                }
                delete[] adjMatrix[i];
            }
            delete[] adjMatrix;

            adjMatrix = newMatrix;
            capacity = newCapacity;
        }

        for (int i = 0; i <= vertices; ++i) {
            adjMatrix[i][vertices] = 0;
            adjMatrix[vertices][i] = 0;
        }
        vertices++;
    }

    void printGraph() {
        cout << "Adjacency Matrix:" << endl;
        for (int i = 0; i < vertices; ++i) {
            for (int j = 0; j < vertices; ++j) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    ~Graph() {
        for (int i = 0; i < capacity; ++i) {
            delete[] adjMatrix[i];
        }
        delete[] adjMatrix;
    }
};

int main() {
    int vertices, choice, from, to, weight;

    cout << "Enter the number of vertices: " << endl;
    cin >> vertices;

    Graph graph(vertices);

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Add Edge\n";
        cout << "2. Add Vertex\n";
        cout << "3. Display Graph\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter source vertex: ";
            cin >> from;
            cout << "Enter destination vertex: ";
            cin >> to;
            cout << "Enter weight: ";
            cin >> weight;
            graph.addEdge(from, to, weight);
            cout << "Edge added from " << from << " to " << to << " with weight " << weight << endl;
            break;
        case 2:
            graph.addVertex();
            cout << "Vertex added." << endl;
            break;
        case 3:
            graph.printGraph();
            break;
        case 4:
            cout << "Exiting..." << endl;
            return 0;
        default:
            cout << "Invalid choice. Please enter a valid option." << endl;
        }
    }

    return 0;
}
