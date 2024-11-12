#include <bits/stdc++.h>
#include <limits.h>
#include <fstream>
#include <sstream>

using namespace std;
#define V 51
#define Inf INT_MAX

// Function to read the CSV file into the graph matrix
void readCSV(string filename, int graph[V][V]) {
    ifstream file(filename);
    string line;
    int row = 0;

    // Reading each line from the file
    while (getline(file, line)) {
        stringstream ss(line);
        string value;
        int col = 0;
        
        // Splitting each value in the row by commas and filling the graph matrix
        while (getline(ss, value, ',')) {
            graph[row][col] = stoi(value);
            col++;
        }
        row++;
    }
    file.close();
}

// Function to find the vertex with the minimum distance value
int minDistance(int dist[], bool sptSet[]) {
    int min = INT_MAX, min_index;

    // Searching for the vertex with the minimum distance
    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

// Function to print the final shortest distances
void printSolution(int dist[]) {
    cout << "Vertex \t Distance from Source" << endl;
    for (int i = 0; i < V; i++)
        if (dist[i] < INT_MAX) cout << i << " \t\t\t\t" << dist[i] << endl;
}

// Function to implement Dijkstra's algorithm
void dijkstra(int graph[V][V], int src) {
    int dist[V];        // The output array dist[i] will hold the shortest distance from src to i
    bool sptSet[V];     // sptSet[i] will be true if vertex i is included in the shortest path tree

    // Initializing all distances to INFINITY and sptSet[] as false
    for (int i = 0; i < V; i++) dist[i] = INT_MAX, sptSet[i] = false;

    // Distance from the source to itself is always 0
    dist[src] = 0;

    // Dijkstra's algorithm
    for (int count = 0; count < V - 1; count++) {
        // Choose the vertex with the minimum distance
        int u = minDistance(dist, sptSet);

        // Mark the chosen vertex as processed
        sptSet[u] = true;

        // Update the distance value of the adjacent vertices of the chosen vertex
        for (int v = 0; v < V; v++)
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    // Print the final shortest distances
    printSolution(dist);
}

int main() {
    int graph[V][V];

    // Update the file path here
    readCSV("C:/Users/Asus/Documents/GitHub/DAA-Project/Dummy_Dataset.csv", graph);
    
    // Function call to run Dijkstra algorithm starting from vertex 0
    dijkstra(graph, 0);

    return 0;
}
