/**
* Course: CS010C Summer 2022
*
* First Name: Rovin
* Last Name: Soriano
* Username:	rsori013
* email address: rsori013@ucr.edu
*
*
* Assignment:  Programming Assignment 5
* Filename : Graph.h
*
* I hereby certify that the contents of this file represent
* my own original individual work. Nowhere herein is there
* code from any outside resources such as another individual,
* a website, or publishings unless specifically designated as
* permissible by the instructor or TA.
*/
/*
 * cs10c_sum21
 * Graph.H
 */

#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>
#include <list>
#include <queue>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <map>
#include "Vertex.H"

using namespace std;

class Graph {
public:
	Graph(){

	}

	// implement overloaded constructor
	Graph(ifstream& ifs){
		build_graph(ifs);
	}

	~Graph(){
		vertices.pop_back();
	}

	// implement build graph
	void build_graph(ifstream& ifs){
		int N, M;
		ifs >> N >> M;
		string s;
		string a, b;

		for (int i=0; i<N; i++) {
			ifs >> s;
			vertices.push_back(Vertex(s)); // for every iteration the vertex is being push with label and distance
		}
		//for (auto i : vertices) {cout << i.label << endl;} //Testing print vertices
		
		//assigning
		for (int i=0; i<M; i++) {
			ifs >> a >> b; // parent, neighboir
			int a_index = 0;
			int b_index = 0;
			for (int j=0; j<N; j++) {
				if (vertices[j].label == a){ 
					a_index = j;
				}
				if (vertices[j].label == b){ 
					b_index = j;
				}
			}
			vertices[a_index].neighbors.push_back(b_index);
			//neighbor list stores all the neighbors of that vertex
		}
	}

	// implement output graph
	void output_graph(){
		ofstream ofs("graph.dot");
		ofs << "digraph G {" << endl << endl;
		ofs << "rankdir=\"LR\";";
		ofs << endl << endl;
		
		//priting nodes w distance
		ofs << "// nodes" << endl;
		for (auto i : vertices){ 
			ofs << i.label << " [label=\"" << i.label << " (" << i.distance << ")\"];" << endl;
		}
		ofs << endl;
		ofs << "// edges" << endl;
		for (auto i : vertices){ 
			for (auto j : i.neighbors) {
				ofs << i.label << "->" << vertices[j].label << " [style=";
				if (shortestpaths[i.label + vertices[j].label]){ 
					ofs << "bold";
				}
				else{ 
					ofs << "dotted";
				}
			ofs << "];" << endl;
			}
		}
		ofs << "}" << endl;
		print_adjacency_list();

	}

	// print adjacency list
	void print_adjacency_list() {
		for (auto i : vertices) {
			cout << i.label << " -----> ";
			for (auto j : i.neighbors) {
				cout << vertices[j].label << "(d=" << vertices[j].distance << "), ";
			}
			cout << endl;
		}
	}

	// implement bfs
	void bfs(){
		int INF = 10000000;
		for (unsigned int i=0; i<vertices.size(); ++i) {
			vertices[i].distance = INF;
		}
		vertices[0].distance = 0; // distance of root

		queue<Vertex> q;
		q.push(vertices[0]);
		while (!q.empty()) {
			Vertex u = q.front();
			q.pop();
			for (auto v : u.neighbors) {
				if (vertices[v].distance == INF) { // INF means not visited
					vertices[v].distance = u.distance+1;
					q.push(vertices[v]);
					shortestpaths[u.label + vertices[v].label] = true; // include this edge in shortest path tree
				}
			}
		}
	}
private:
	vector<Vertex> vertices;
	map<string,bool> shortestpaths; // edges included in shortest path tree
};

#endif /* GRAPH_H_ */
