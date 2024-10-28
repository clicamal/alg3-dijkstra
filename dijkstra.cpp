#include "dijkstra.hpp"
#include <iostream>
#include <limits>
#include <queue>
#include <stack>
#include <utility>
#include <vector>

Dijkstra::Dijkstra(uint nVertexes) {
  graph.resize(nVertexes);
  dists.resize(nVertexes, std::numeric_limits<uint>::max());
  predecessor.resize(nVertexes, -1);
}

void Dijkstra::addVertex(uint origin, uint dest, int weight) {
  if (weight >= 0) graph[origin].push_back({ dest, weight });
}

void Dijkstra::run(uint origin) {
  std::vector<bool> closed(graph.size(), false);
  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> priorQ;

  dists[origin] = 0;
  priorQ.push({ 0, origin });

  while (!priorQ.empty()) {
    int i = priorQ.top().second;
    priorQ.pop();

    if (closed[i]) continue;
    closed[i] = true;

    for (const auto& vertex : graph[i]) {
      int j = vertex.dest;
      uint newDist = dists[i] + vertex.weight;

      if (!closed[j] && newDist < dists[j]) {
        dists[j] = newDist;
        predecessor[j] = i;
        priorQ.push({ dists[j], j });
      }
    }
  }
}
