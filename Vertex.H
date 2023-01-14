
#ifndef VERTEX_H_
#define VERTEX_H_
#include <string>
#include <list>
#include <vector>

using namespace std;

class Vertex {
public:
	// implement constructor
	Vertex(){

	}

	Vertex(string s) {
		label = s;
		distance = 0;
	}

	~Vertex(){

	}

	string label;
	int distance;
	vector<int> neighbors;
};

#endif /* VERTEX_H_ */
