#include <iostream>
#include <vector>
#include <list>
using namespace std;
class Graph
{
    int v;
    list<int> *adjL;
    int **adjM;
    vector<bool> visited;

public:
    Graph(int);
    void addEdge(int, int);
    void DFS(int);
    void BFS(int);
};
Graph::Graph(int v)
{
    this->v = v;
    adjL = new list<int>[v];
    adjM = new int *[v];
    visited.assign(v, false);
    for (int row = 0; row < v; row++)
    {
        adjM[row] = new int[v];
        for (int column = 0; column < v; column++)
        {
            adjM[row][column] = 0;
        }
    }
}
void Graph::addEdge(int x, int y)
{
    adjL[x].push_back(y);
    adjL[y].push_back(x);
    adjM[x][y] = 1;
    adjM[y][x] = 1;
}
void Graph::DFS(int start)
{
    cout << start << " ";
    visited[start] = true;
    for (int i = 0; i < v; i++)
    {
        //
        if (adjM[start][i] == 1 && (!visited[i]))
        {
            DFS(i);
        }
    }
}
void Graph::BFS(int start)
{
    visited.assign(v, false);
    list<int> queue;
    visited[start] = true;
    queue.push_back(start);
    while (!queue.empty())
    {
        start = queue.front();
        cout << start << " ";
        queue.pop_front();
        for (int i : adjL[start])
        {
            if (!visited[i])
            {
                visited[i] = true;
                queue.push_back(i);
            }
        }
    }
}
int main()
{
    int v = 8;
    Graph G(v);
    int edges[][2] = {{0, 1}, {0, 6}, {0, 5}, {1, 2}, {1, 6}, {2, 3}, {2, 4}, {2, 6}, {2, 7}, {3, 4}, {3, 7}, {4, 5}, {4, 6}, {4, 7}, {5, 6}};
    for (auto edge : edges)
    {
        G.addEdge(edge[0], edge[1]);
    }
    cout << "\nOperation on following Graph ->\n\n\n";
    "               (1)  @@  @  @  @  @ @  @ @@@  (2)\n"
    "                   @@@               @  @ @   @\n"
    "                 @  @              @     @   @     @\n"
    "              @     @            @       @     @        @\n"
    "           @        @         @          @       @          @\n"
    "  (0)    @          @      @             @          @            @\n"
    "      @             @   @                @             @              @\n"
    "  @@@ @  @  @  @  @ @@  (6)              @          (7) @@               @@ (3)\n"
    "  @@@               @@                   @              @@@  @  @  @  @  @@@\n"
    "      @             @   @                @             @              @\n"
    "         @          @      @             @           @             @\n"
    "           @        @        @           @         @          @\n"
    "             @      @           @        @      @        @\n"
    "                @   @             @      @    @      @\n"
    "                  @@@                @   @  @   @\n"
    "             (5)   @@  @  @  @   @  @  @@@@  (4)\n";
    cout << "\n\n Depth First Traversal (starting from vertex 2) : ";
    G.DFS(2);
    cout << "\n\nBreadth First Traversal (starting from vertex 2) : ";
    G.BFS(2);
    return 0;
}