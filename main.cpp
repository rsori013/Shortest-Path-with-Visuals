
#include "Graph.H"
#include <iostream>

int main(int argc, char* argv[]) {

    if(argc != 2) {
      cerr << "Usage error: expected <executable> <input>" << endl;
      exit(1);
    }
    
    ifstream ifs(argv[1]);
    if(!ifs) {
      cerr << "Input file not found." << endl;
      exit(1);
    }

    Graph g(ifs);
    ifs.close();
    g.bfs();
    g.output_graph();
    g.print_adjacency_list();

    cout << "The End." << endl;

    return 0;
}
