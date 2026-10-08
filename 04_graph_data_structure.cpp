#include <iostream>
#include <vector>

using namespace std;

struct Edge 
{
    int start;
    int end;
};

class Graph 
{
    public:
        Graph (vector <vector <bool>> myMatrix);
        vector <int> neighbors (int i);
        void addEdge (int start, int end);
        void removeEdge (int start, int end);
        vector <Edge> getGraph() const;
    private:
        vector <Edge> graph;
};

Graph::Graph (vector <vector <bool>> myMatrix) 
{
    for (int i = 0; i < myMatrix.size(); i++) 
    {
        for (int j = i; j < myMatrix.size(); j++) 
        {
            if (myMatrix[i][j] == true) 
            {
                graph.push_back(Edge{i, j});
            }
        }
    }
}

vector <int> Graph::neighbors (int i) 
{
    vector <int> adj;
    for (auto item : graph) 
    {
        if (i == item.start) 
        {
            adj.push_back(item.end);
        }
        if (i == item.end) 
        {
            adj.push_back(item.start);
        }
    }
    return adj;
}

void Graph::addEdge (int start, int end) 
{
    bool edgeExists = false;
        
    for (auto item : graph) 
    {
        if ((item.start == start && item.end == end) || (item.start == end && item.end == start)) {
            edgeExists = true;
            break;
        }
    }
        
    if (edgeExists) 
    {
        cout << "*** Edge already exists ***";
    } 
    else 
    {
        graph.push_back(Edge{start, end});
        cout << "*** Edge is successfully added ***";
    }
}

void Graph::removeEdge(int start, int end) 
{
    int index = -1;

    for (int i = 0; i < graph.size(); i++) 
    {
        if ((graph[i].start == start) && (graph[i].end == end)) 
        {
            index = i;
            break;
        }
    }
    
    if (index != -1) 
    {
        graph.erase(graph.begin() + index);
        cout << "*** Edge is successfully removed ***";
    } 
    else 
    {
        cout << "*** Edge doesn't exist ***";
    }
}

vector <Edge> Graph::getGraph() const
{
    return graph;
}

void print (vector <vector <bool>> adjacencyMatrix) 
{
    for (int i = 0; i < adjacencyMatrix.size(); i++) 
    {
        for (int j = 0; j < adjacencyMatrix.size(); j++) 
        {
            cout << adjacencyMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() 
{
    vector <vector <bool>> adjacencyMatrix;
    
    int n;
    cout << "Enter n: " << endl;
    cin >> n;

    for (int i = 0; i < n; i++) 
    {
        vector <bool> row;
        for (int j = 0; j < n; j++) 
        {
            cout << "Enter value: ";
            int value;
            cin >> value;
            row.push_back(value);
        }
        adjacencyMatrix.push_back(row);
    }

    cout << endl << "Adjacency matrix:" << endl;
    print (adjacencyMatrix);
    Graph anya = Graph(adjacencyMatrix);

    while (true) 
    {
        cout << "---------------------------------------------------------------------------------------------------------------------------" << std::endl
             << "Five commands available:" << endl
             << "\t1. Print adjacency list." << endl
             << "\t2. Get neighbors of vertex." << endl
             << "\t3. Add edge." << endl
             << "\t4. Remove edge." << endl
             << "\t5. Exit." << endl
             << "Choose one of the commands (1-5): ";
        int choice;
        cin >> choice;
        switch (choice)
        {
            case 1:
            {
                cout << "Adjacency list:" << endl;
                for (auto edge : anya.getGraph()) 
                {
                    cout << edge.start << " — " << edge.end << endl;
                }
                break;
            }
            case 2:
            {
                int vertex;
                cout << "Enter vertex: ";
                cin >> vertex;
                if ((vertex < 0) || (vertex >= n))
                {
                    cout << "*** Invalid vertex ***" << endl;
                    break;
                }
                cout << "Neighbors: ";
                for (auto neighbor : anya.neighbors(vertex)) 
                {
                    cout << neighbor << " ";
                }
                cout << endl;
                break;
            }
            case 3:
            {
                int start, end;
                cout << "Enter start vertex: ";
                cin >> start;
                cout << "Enter end vertex: ";
                cin >> end;
                if ((start < 0) || (start >= n) || (end < 0) || (end >= n))
                {
                    cout << "*** Invalid vertex ***" << endl;
                    break;
                }
                anya.addEdge (start, end);
                cout << endl;
                break;
            }
            case 4:
            {
                int start, end;
                cout << "Enter start vertex: ";
                cin >> start;
                cout << "Enter end vertex: ";
                cin >> end;
                if ((start < 0) || (start >= n) || (end < 0) || (end >= n))
                {
                    cout << "*** Invalid vertex ***" << endl;
                    break;
                }
                anya.removeEdge (start, end);
                cout << endl;
                break;
            }
            case 5:
            {
                return false;
            }
            default:
            {
                cout << "*** Invalid command ***" << endl;
                return false;
            }
        }
    }

    return 0;
}