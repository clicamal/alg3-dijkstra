#include <queue>
#include <unordered_map>
#include <vector>

struct Edge {
  unsigned int origin, destination;
  float weight;

  Edge(unsigned int origin, unsigned int destination, float weight) {
    this->origin = origin;
    this->destination = destination;
    this->weight = weight;
  }
};

struct Path {
  Edge *edge;
  float cost;
};

class Dijkstra {
private:
  unsigned int origin;
  std::unordered_map<unsigned int, std::vector<Edge>> edges;

public:
  void setEdge(unsigned int origin, unsigned int destination, float weight) {
    edges.insert_or_assign(origin, new Edge(origin, destination, weight));
  }

  std::queue<Path> getMinPath(unsigned int destination) {
    std::queue<Path> result;

    return result;
  }
};
