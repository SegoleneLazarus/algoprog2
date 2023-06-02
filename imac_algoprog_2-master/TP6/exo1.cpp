#include <time.h>
#include "../lib/graph.h"


void Graph::buildFromAdjenciesMatrix(int **adjacencies, int nodeCount)
{
	for(int i=0 ; i<nodeCount ;i++)
    {
        this->appendNewNode(new GraphNode(i));
    }
    for(int i=0 ; i<nodeCount ; i++)
    {
        for(int j=0 ; j<nodeCount ; j++){
            if(adjacencies[j][i]!=0)
            {
                this->nodes[i]->appendNewEdge(this->nodes[j],adjacencies[j][i]);
            }
        }
    }
	/**
	  * Make a graph from a matrix
	  * first create all nodes, add it to the graph then connect them
	  * this->appendNewNode
	  * this->nodes[i]->appendNewEdge
	  */
}

void Graph::deepTravel(GraphNode *first, GraphNode *nodes[], int &nodesSize, bool visited[])
{
	/**
	  * Fill nodes array by travelling graph starting from first and using recursivity
	  */
	visited[first->value] = true; 
									
	Edge* edge = first->edges;
	nodes[nodesSize] = first;
	nodesSize++;

	while (edge != nullptr){
		if (visited[first->edges->destination->value] != true){
			deepTravel(edge -> destination, nodes, nodesSize, visited);
			edge = edge -> next;
		}
	}


}

void Graph::wideTravel(GraphNode *first, GraphNode *nodes[], int &nodesSize, bool visited[])
{
	/**
	 * Fill nodes array by travelling graph starting from first and using queue
	 * nodeQueue.push(a_node)
	 * nodeQueue.front() -> first node of the queue
	 * nodeQueue.pop() -> remove first node of the queue
	 * nodeQueue.size() -> size of the queue
	 */
	std::queue<GraphNode*> nodeQueue;
	nodeQueue.push(first);
	while(nodeQueue.size() != 0){
        visited[nodeQueue.front()->value] = true;
        nodeQueue.pop();
    }

}

bool Graph::detectCycle(GraphNode *first, bool visited[])
{
	/**
	  Detect if there is cycle when starting from first
	  (the first may not be in the cycle)
	  Think about what's happen when you get an already visited node
	**/
    visited[first->value] = true;
    Edge* newEdge;
    for(newEdge = first->edges; newEdge != nullptr; newEdge = newEdge->next){
        if(!visited[newEdge->destination->value]){
            if(detectCycle(newEdge->destination, visited)){
                return true;
            }
        }
        else{
            return true;
        }
    }
    return false;

}

int main(int argc, char *argv[])
{
	int n=7;
    int** matrix = new int*[n];
    for (int i=0; i<n; ++i)
	{
        matrix[i] = new int[n];
        for (int j=0; j<n; ++j)
		{
			matrix[i][j] = (rand() % 300 - 230) / 2;
			if (matrix[i][j] < 0)
				matrix[i][j] = 0;
		}
	}

}