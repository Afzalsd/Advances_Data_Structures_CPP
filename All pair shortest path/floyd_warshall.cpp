#include<iostream>
#define INFINITY INT_MAX
using namespace std;

int main()
{
    int numberOfNodes;
    cout<<"Enter the number of nodes: ";
    cin >> numberOfNodes;
    int costMatrix[numberOfNodes][numberOfNodes];
    cout<<"Enter the cost matrix: ";
    for(int i=0; i<numberOfNodes; i++)
    {
        for(int j=0; j<numberOfNodes; j++)
        {
            cin >> costMatrix[i][j];
        }
    }
    int shortestPathMatrix[numberOfNodes][numberOfNodes];
    for(int i=0; i<numberOfNodes; i++)
    {
        for(int j=0; j<numberOfNodes; j++)
        {
            shortestPathMatrix[i][j]=costMatrix[i][j];
        }
    }
    for(int k=0; k<numberOfNodes; k++)
    {
        for(int i=0; i<numberOfNodes; i++)
        {
            for(int j=0; j<numberOfNodes; j++)
            {
                if(shortestPathMatrix[i][j] > shortestPathMatrix[i][k] + shortestPathMatrix[k][j])
                {
                    shortestPathMatrix[i][j] = shortestPathMatrix[i][k] + shortestPathMatrix[k][j];
                }
            }
        }
    }
    cout<<"The required shortest path matrix is: ";
    for(int i=0; i<numberOfNodes; i++)
    {
        for(int j=0; j<numberOfNodes; j++)
        {
            cout<<shortestPathMatrix[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
