//bfs
#include <stdio.h>
#include <stdlib.h>

#define MAX 100   // Maximum number of vertices

// Queue implementation for BFS(Queue setup)
int queue[MAX];   //queue stores the nodes waiting to be processed.// Array to store queue elements
int front = -1;   // Front pointer//front points to the first element in the queue.
int rear = -1;    // Rear pointer//rear points to the last element.//Initially both are -1, meaning the queue is empty.

//  enqueue Function:
     //Adds a node to the queue.
     //If the queue is full, it does nothing.
     //When the queue is empty, it sets front = 0.
void enqueue(int v)
 {
    if (rear == MAX - 1) return;        // Prevent overflow
    if (front == -1) front = 0;         // Initialize front for first element
    queue[++rear] = v;                  // Place element at rear
}

// dequeue function:
   //Removes the front node from the queue.
    //Returns the node that was removed.
    //front++ moves the front pointer forward.
int dequeue() 
{
    if (front == -1 || front > rear) return -1; // Queue empty check
    return queue[front++];              // Return element at front and move front
}

// Function to check if queue is empty
int isEmpty() {
    return (front == -1 || front > rear); // True if no elements left
}

// BFS traversal function
void bfs(int graph[MAX][MAX], int n, int start) 
{
    int visited[MAX] = {0};             // visited keeps track of nodes already seen.(0 = not visited)
    enqueue(start);                     // Start node added to queue
    visited[start] = 1;                 // Mark start node as visited
    //the start node is not the only visited node. It is just the first one that starts the BFS process. The queue loop continues visiting all connected nodes.
    printf("BFS Traversal: ");
    //actual bfs logic:
       // Take the first node from the queue.
       //Print it.
       //Look at all possible neighbors i.
        //If there is an edge graph[node][i] == 1 and the neighbor has not been visited, add it to the queue and mark it visited.
         //This ensures every node is visited once and traversal follows breadth-first order.
        while (!isEmpty())
       {                // Continue until queue is empty
        int node = dequeue();           // Remove first element
        printf("%d ", node);            // Print current node

        // Explore all neighbors of current node
        for (int i = 0; i < n; i++) {
            if (graph[node][i] == 1 && !visited[i]) { // If edge exists and not visited
                enqueue(i);             // Add neighbor to queue
                visited[i] = 1;         // Mark neighbor as visited
            }
        }
    }
    printf("\n");
}

int main() {
    int n = 6; // Number of vertices
    // Graph represented as adjacency matrix
    int graph[MAX][MAX] = {
        {0,1,1,0,0,0},  // Node 0 connected to 1,2
        {1,0,1,1,0,0},  // Node 1 connected to 0,2,3
        {1,1,0,0,1,0},  // Node 2 connected to 0,1,4
        {0,1,0,0,1,1},  // Node 3 connected to 1,4,5
        {0,0,1,1,0,1},  // Node 4 connected to 2,3,5
        {0,0,0,1,1,0}   // Node 5 connected to 3,4
    };

    bfs(graph, n, 0); // Start BFS from node 0
    return 0;
}
