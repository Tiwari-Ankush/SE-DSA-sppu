/*
You have a business with several offices; you want to lease phone lines to connect them
up with each other; and the phone company charges different amounts of money to
connect different pairs of cities. You want a set of lines that connects all your offices
with a minimum total cost. Solve the problem by suggesting appropriate data structures.
*/

#include <iostream>
using namespace std;

#define ROW 10
#define COL 10
#define infi 9999

class prims
{
    int graph[ROW][COL], nodes;

public:
    void createGraph();
    void primsAlgo();
};

void prims::createGraph()
{
    int i, j;
    cout << "Enter Total Offices: ";
    cin >> nodes;
    cout << "\nEnter Adjacency Matrix: \n";
    for (i = 0; i < nodes; i++)
    {
        for (j = i; j < nodes; j++)
        {
            cout << "Enter distance between " << i << " and " << j << endl;
            cin >> graph[i][j];
            graph[j][i] = graph[i][j];
        }
    }

    for (i = 0; i < nodes; i++)
    {
        for (j = 0; j < nodes; j++)
        {
            if (graph[i][j] == 0)
                graph[i][j] = infi; // fill infinity where path is not present
        }
    }
}

void prims::primsAlgo()
{
    int selected[ROW], i, j, ne = 0;
    int zero = 0, one = 1, min = 0, x, y;
    int cost = 0;
    for (i = 0; i < nodes; i++)
        selected[i] = zero;

    selected[0] = one; // starting vertex is always node-0

    while (ne < nodes - 1)
    {
        min = infi;

        for (i = 0; i < nodes; i++)
        {
            if (selected[i] == one)
            {
                for (j = 0; j < nodes; j++)
                {
                    if (selected[j] == zero)
                    {
                        if (min > graph[i][j])
                        {
                            min = graph[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }
        selected[y] = one;
        cout << "\n"
             << x << " --> " << y;
        cost += graph[x][y];
        ne++;
    }
    cout << "\nTotal cost is: " << cost << endl;
}

int main()
{
    prims MST;
    cout << "\nPrims Algorithm to connect several offices\n";
    MST.createGraph();
    MST.primsAlgo();
}

/*
The prims class is defined with private member variables graph and nodes.

The createGraph function is used to create the adjacency matrix representation of the graph. It takes user input for the number of offices (nodes) and the distances between each pair of offices. The input distances are stored in the graph matrix. If the distance is 0, it is considered as infinity (infi) to indicate that there is no direct path between the offices.

The primsAlgo function implements Prim's algorithm to find the minimum spanning tree of the graph. It uses an array selected to keep track of the vertices that have been selected or added to the MST. It starts with selecting the first vertex (node-0) and continues until all vertices are selected.

Inside the primsAlgo function, there is a nested loop to find the minimum edge from the selected vertices to the unselected vertices. The minimum edge is determined by comparing the distances in the graph matrix. The indices of the minimum edge are stored in variables x and y.

Once the minimum edge is found, the vertex y is marked as selected (selected[y] = 1), and the edge (x, y) is printed as part of the MST. The cost of the edge is added to the cost variable, and the number of edges ne is incremented.

Finally, the total cost of the MST is printed.

In the main function, an object of the prims class named MST is created. The createGraph and primsAlgo functions are called on this object to create the graph and find the MST.

Overall, this code finds the minimum spanning tree of the given graph using Prim's algorithm and prints the edges and total cost of the MST.
*/
