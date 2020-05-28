#include <iostream>
#include "LinkedList.h"

using namespace std;

class Graph 
{
public:
	Graph(int n) 
	{
		size = n;
		array = new LinkedList[size];
	}
	void DFS();
	void BFS();
private:
	int size;
	LinkedList* array;
};
int main(int argc, char *argv[]) {
	
}