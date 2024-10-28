#pragma once

#include <vector>

typedef unsigned int uint;

struct Vertex {
  uint dest;
  int weight;
};

class Dijkstra {
private:
  std::vector<std::vector<Vertex>> graph;

protected:
  std::vector<uint> dists, predecessor;

public:
  Dijkstra(uint nVertexes);

  void addVertex(uint origin, uint dest, int weight);

  void run(uint origin);
};
