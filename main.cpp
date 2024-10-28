#include <iostream>
#include <limits>
#include <stack>
#include <vector>
#include "dijkstra.hpp"

class MainDijkstra : public Dijkstra {
public:
  MainDijkstra(uint nNodes) : Dijkstra(nNodes) {}

  void printPath(uint start, uint dest) {
    if (dists[dest] == std::numeric_limits<uint>::max()) {
      std::cout << "custo: Inf\n";
      std::cout << "nao existe um caminho entre " << start + 1 << " e " << dest + 1
                << "\n";
      return;
    }

    if (start == dest) {
      std::cout << "custo: 0\n";
      std::cout << "caminho: " << start + 1 << "\n";
      return;
    }

    std::cout << "custo: " << dists[dest] << "\n";
    std::cout << "caminho: ";
    std::stack<int> path;
    int current = dest;

    while (current != -1) {
      path.push(current + 1);
      current = predecessor[current];
    }

    while (!path.empty()) {
      std::cout << path.top();
      path.pop();
      if (!path.empty())
        std::cout << "->";
    }
    std::cout << "\n";
  }
};

int main(void) {
  uint nNodes;

  std::cout << "informe a quantidade de nos no grafo: ";
  std::cin >> nNodes;

  MainDijkstra dijkstra(nNodes);

  for (uint i = 0; i < nNodes; i++) {
    for (uint j = 0; j < nNodes; j++) {
      int val;

      if (i == j) {
        dijkstra.addVertex(i, j, 0);
      } else {
        std::cout << "mAdj(" << i + 1 << "," << j + 1 << "): ";
        std::cin >> val;

        if (val >= 0) dijkstra.addVertex(i, j, val);
      }
    }
  }

  uint origin;

  std::cout << "origem: ";
  std::cin >> origin;
  origin--;

  dijkstra.run(origin);

  char showPath;

  do {
    std::cout << "mostrar caminho ('s' ou 'n'): ";
    std::cin >> showPath;

    if (showPath == 's') {
      uint dest;

      std::cout << "destino: ";
      std::cin >> dest;
      dest--;

      dijkstra.printPath(origin, dest);
    }
  } while (showPath == 's');

  return 0;
}
