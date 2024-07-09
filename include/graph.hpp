#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <unordered_set>
#include <unordered_map>
#include <vector>

class Graph {
private:
    std::unordered_map<int, std::unordered_map<int, int>> adjList;
    int numVerts;
    int numEdges;

public:
    Graph();

    Graph(const Graph& rhs);

    Graph& operator=(const Graph& rhs);

    ~Graph();

    void clear();

    bool addVertex(int vertex);

    bool addEdge(int from, int to, int weight);

    bool getWeight(int from, int to, int& weight) const;

    std::unordered_set<int> neighbors(int v) const;

    std::vector<int> getVertices() const;

    int NumVertices() const;

    int NumEdges() const;

    std::vector<int> dijkstra(int start, int target);

    std::vector<int> bfs(int start, int target);

    std::vector<int> dfs(int start, int target);
};

#endif