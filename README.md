The code goes as follows:
- Create a set sptSet (shortest path tree set) that keeps track of vertices included in the shortest path tree, i.e., whose minimum distance from the source is calculated and finalized. Initially, this set is empty.
- Assign a distance value to all vertices in the input graph. Initialize all distance values as INFINITE . Assign the distance value as 0 for the source vertex so that it is picked first.
- While sptSet doesn’t include all vertices:
  - Pick a vertex u that is not there in sptSet and has a minimum distance value.
  - Include u to sptSet .
  - Then update the distance value of all adjacent vertices of u .
    - To update the distance values, iterate through all adjacent vertices.
    - For every adjacent vertex v, if the sum of the distance value of u (from source) and weight of edge u-v , is less than the distance value of v , then update the distance value of v .
Note: We use a boolean array sptSet[] to represent the set of vertices included in SPT . If a value sptSet[v] is true, then vertex v is included in SPT , otherwise not. Array dist[] is used to store the shortest distance values of all vertices.

Function Descriptions:
1. minDistance(int dist[], bool sptSet[])
- Purpose: 
    Finds the vertex with the smallest distance value that has not been included in the shortest path tree (SPT).
- Parameters:
    dist[]: Array of current shortest distances from the source to all vertices.
    ptSet[]: Boolean array indicating whether a vertex is included in the SPT.
- Returns: 
    Index of the vertex with the minimum distance.

2. printRoute(int parent[], int j)
- Purpose: 
    Recursively prints the path from the source to a specified vertex.
- Parameters:
    parent[]: Array storing the parent of each vertex in the shortest path tree.
    j: Target vertex whose path needs to be printed.
- Output: 
    The path from the source to vertex j in the format 1 -> 2 -> 3.

3. printSolution(int dist[], int parent[], const vector<int>& parkingSpaces)
- Purpose:
    Determines the optimal parking space based on the shortest distance.
    Prints the optimal parking space and the route to reach it.
- Parameters:
    dist[]: Array of shortest distances from the source to all vertices.
    parent[]: Array storing the parent of each vertex in the shortest path tree.
    parkingSpaces: List of indices representing available parking spaces.
- Output:
    Optimal parking space and its distance.
    The shortest route to that parking space.

4. dijkstra(int graph[V][V], int src, int dist[], int parent[], const vector<int>& parkingSpaces)
- Purpose: 
    Implements Dijkstra's algorithm to find the shortest path from a source vertex to all other vertices in the graph.
- Parameters:
    graph[V][V]: Adjacency matrix representing the graph.
    src: Source vertex.
    dist[]: Array to store the shortest distance from the source to each vertex.
    parent[]: Array to store the parent of each vertex in the shortest path tree.
    parkingSpaces: List of indices representing available parking spaces (unused directly in this function but passed for flexibility).
- Process:
    Initializes all distances as Inf and parent array as -1.
    Repeatedly finds the minimum distance vertex and updates distances to its adjacent vertices.
- Output:
    Updates dist[] with the shortest distances.
    Updates parent[] with the shortest path tree.

//-----------------------------------------------------------------------------------------//

Deskripsi Fungsi
1. minDistance(int dist[], bool sptSet[])
- Tujuan:
    Menemukan simpul (vertex) dengan nilai jarak terkecil yang belum dimasukkan ke dalam Shortest Path Tree (SPT).
- Parameter:
   dist[]: Array jarak terpendek saat ini dari sumber ke semua simpul.
   sptSet[]: Array boolean yang menunjukkan apakah simpul sudah dimasukkan ke dalam SPT.
- Mengembalikan:
   Indeks simpul dengan jarak minimum.

2. printRoute(int parent[], int j)
- Tujuan:
  M encetak jalur dari sumber ke simpul tertentu secara rekursif.
- Parameter:
    parent[]: Array yang menyimpan simpul induk dari setiap simpul dalam SPT.
    j: Simpul tujuan yang jalurnya perlu dicetak.
- Output:
    Jalur dari sumber ke simpul j dalam format 1 -> 2 -> 3.

3. printSolution(int dist[], int parent[], const vector<int>& parkingSpaces)
- Tujuan:
    Menentukan tempat parkir optimal berdasarkan jarak terpendek.
    Mencetak tempat parkir optimal dan jalur untuk mencapainya.
- Parameter:
    dist[]: Array jarak terpendek dari sumber ke semua simpul.
    parent[]: Array yang menyimpan simpul induk dari setiap simpul dalam SPT.
    parkingSpaces: Daftar indeks yang mewakili tempat parkir yang tersedia.
- Output:
    Tempat parkir optimal dan jaraknya.
    Jalur terpendek ke tempat parkir tersebut.

4. dijkstra(int graph[V][V], int src, int dist[], int parent[], const vector<int>& parkingSpaces)
- Tujuan:
   Mengimplementasikan algoritma Dijkstra untuk menemukan jalur terpendek dari simpul sumber ke semua simpul lain dalam graf.
- Parameter:
    graph[V][V]: Matriks ketetanggaan (adjacency matrix) yang mewakili graf.
    src: Simpul sumber.
    dist[]: Array untuk menyimpan jarak terpendek dari sumber ke setiap simpul.
    parent[]: Array untuk menyimpan simpul induk dari setiap simpul dalam SPT.
    parkingSpaces: Daftar indeks yang mewakili tempat parkir yang tersedia (tidak digunakan langsung dalam fungsi ini, tetapi diteruskan untuk fleksibilitas).
- Proses:
    Menginisialisasi semua jarak dengan Inf dan array parent dengan -1.
    Berulang kali menemukan simpul dengan jarak minimum dan memperbarui jarak ke simpul-simpul yang berdekatan.
- Output:
    Memperbarui dist[] dengan jarak terpendek.
    Memperbarui parent[] dengan Shortest Path Tree.