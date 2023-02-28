#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdlib.h>

int g_maxRow, g_maxCol;

typedef struct {
	int row, col;
	bool isPoint, isVisited;
} GridPoint;

typedef struct {
	int x, y;
} Coord;

typedef struct Node{
	Coord point;
	struct Node* next;
} Node;

typedef struct {
	Node* front;
	Node* rear;
} Queue;

Queue* queueInit() {
	Queue* queue = (Queue*) malloc(sizeof(Queue));
	queue->front = NULL;
	queue->rear = NULL;
	return queue;
}

GridPoint** initGrid(int maxRow, int maxCol) {
	GridPoint** grid;
	grid = malloc(maxRow * sizeof *grid);
	for (int i = 0; i < maxRow; i++){
  	  grid[i] = malloc(maxCol * sizeof *grid[i]);
	}
	return grid;
}

void enqueue(Queue* queue, int x, int y) {
	Coord coordinate;
	coordinate.x = x;
	coordinate.y = y;

	Node* node = (Node *) malloc(sizeof(Node));
	node->point = coordinate;
	node->next = NULL;
	
	if (queue->front == NULL) {
	    queue->front = node;
		queue->rear = node;
		return;
	}

	queue->rear->next = node;
	queue->rear = node;
}

Coord dequeue(Queue* queue) {
	if (queue->front == NULL) {
        return (Coord){-1, -1};
    }

    Node* node = queue->front;
    queue->front = queue->front->next;
	if (queue->front == NULL) queue->rear = NULL;
    return node->point;
}

void printQueue(Queue* queue) {
	Node* node = queue->front;
    while (node!= NULL) {
        printf("%d,%d \n", node->point.x, node->point.y);
        node = node->next;
    }
}

void traverse(GridPoint** grid, int x, int y) {
	Queue* queue = queueInit();
	int xMin, xMax, yMin, yMax;
	do {
		// This feels cleaner and more understandable than to write it all in shorter lines
		xMin = x - 1;
		xMax = x + 1;
		yMin = y - 1;
		yMax = y + 1;
		xMin = (xMin < 0) ? 0 : xMin;
		yMin = (yMin < 0) ? 0 : yMin;
		xMax = (xMax >= g_maxCol) ? g_maxCol - 1 : xMax;
		yMax = (yMax >= g_maxRow) ? g_maxRow - 1 : yMax;

		for (int i = yMin; i <= yMax; i++) {
			for (int j = xMin; j <= xMax; j++) {
				// Enqueue if 
				// 1) it's a point
				// 2) it hasn't been visited
				if (grid[i][j].isPoint && !grid[i][j].isVisited) {
					enqueue(queue, j, i);
					// Mark a point as visited even tho technically it's only queued so as not to enqueue it in the next loops
					grid[i][j].isVisited = true;
				}
			}
		}
		Coord newCoord = dequeue(queue);
		x = newCoord.x;
		y = newCoord.y;
	} while (x != -1 && y != -1);
}

void printGrid(GridPoint** grid, int maxRow, int maxCol) {
	printf("\n");
	for (int i = 0; i < maxRow; i++) {
		for (int j = 0; j < maxCol; j++) {
			printf("%d, %d \t", grid[i][j].col, grid[i][j].row);
		}
		printf("\n");
	}
}


// j -> x -> col; maxCol
// i -> y -> row; maxRow
int main() {
	int maxRow, maxCol, objCount = 0;
	scanf("%d %d", &maxRow, &maxCol);
	g_maxRow = maxRow;
	g_maxCol = maxCol;

	GridPoint** grid = initGrid(maxRow, maxCol);

	for (int i = 0, buffer; i < maxRow; i++) {
        for (int j = 0; j < maxCol; j++) {
            scanf("%d", &buffer);
			grid[i][j].row = i;
			grid[i][j].col = j;
			grid[i][j].isPoint = buffer == 1;
        }
    }

	// printGrid(grid, maxRow, maxCol);

	for (int i = 0; i < maxRow; i++) {
		for (int j = 0; j < maxCol; j++) {
			if (grid[i][j].isVisited) continue;
			grid[i][j].isVisited = true;
			if (grid[i][j].isPoint) {
				traverse(grid, j, i);
				objCount++;
			}
		}
	}

	printf("Count: %d\n", objCount);
}