package main

import (
	"fmt"
)

func main() {
	g := NewGraph()

	g.AddVertex("r")
	g.AddVertex("v")
	g.AddVertex("s")
	g.AddVertex("w")
	g.AddVertex("t")
	g.AddVertex("x")
	g.AddVertex("u")
	g.AddVertex("y")

	g.AddEdge("r", "v")
	g.AddEdge("r", "s")
	g.AddEdge("s", "w")
	g.AddEdge("w", "t")
	g.AddEdge("w", "x")
	g.AddEdge("t", "u")
	g.AddEdge("x", "u")
	g.AddEdge("x", "y")
	g.AddEdge("u", "y")

	fmt.Println(g.BFS("s"))
}
