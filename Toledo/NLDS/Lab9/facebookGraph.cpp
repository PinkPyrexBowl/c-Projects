#include <fstream>
#include <iostream>
class Node {
public:
    int key;
	int neighbor
    Node(int nodeKey, int nodeNeighbor) {
        key = nodeKey;
		neighbor = nodeNeighbor;
    }
};

class Graph
{
public:
    Graph() {};
    int numEdges(Node* node);
    void insert(Node* node);
	numNodeWithDegree(int degree);
private:
};


int main()
{
	Graph facebookNewOrleans;
	std::string userData;
	Node* user;
	std::fstream f;
	int tabIndex;
	f.open("facebook-links.txt");
	while(std::getline(f, userData))
	//for(int i = 0; i < 10; i++)
	{
		//std::getline(f, userData);
		tabIndex = user.find('	');
		//std::cout << userData.substr(0, tabIndex) << '\n';
		//std::cout << userData.substr(tabIndex + 1, user.find('	')) << std::endl;
		user = new user(userData.substr(0, tabIndex), userData.substr(tabIndex + 1, user.find('	')));	

	}

}

