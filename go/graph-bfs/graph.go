package main

type Graph struct {
	adj map[string][]string
}

func NewGraph() *Graph {
	return &Graph{
		make(map[string][]string),
	}
}

func (g *Graph) AddVertex(v string) {
	g.adj[v] = make([]string, 0)
}

func (g *Graph) AddEdge(v, u string) {
	g.adj[v] = append(g.adj[v], u)
	g.adj[u] = append(g.adj[u], v)
}

func (g *Graph) BFS(s string) map[string]int {
	distances := make(map[string]int)

	for v := range g.adj {
		distances[v] = -1
	}

	q := NewStringQueue()
	q.Enqueue(s)
	distances[s] = 0

	for !q.Empty() {
		u := q.Dequeue()

		for _, v := range g.adj[u] {
			if distances[v] == -1 {
				distances[v] = distances[u] + 1
				q.Enqueue(v)
			}
		}
	}

	return distances
}
