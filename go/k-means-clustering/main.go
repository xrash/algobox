package main

import (
	"fmt"
	"math"
	"math/rand"
	"time"
)

type point struct {
	x float64
	y float64
	centroid int
}

type centroid struct {
	x float64
	y float64
	points []int
}

var __max float64 = 100

func main() {
	sample := []point{
		// next to the origin
		point{0, 0, 0},
		point{1, 5, 0},
		point{10, 10, 0},
		// next to the top
		point{80, 87, 0},
		point{85, 91, 0},
		point{86, 79, 0},
	}

	k := 2

	centroids, iterations := clusterize(sample, k)

	fmt.Println(centroids, iterations)
}

func clusterize(points []point, k int) ([]centroid, int) {
	centroids := makeCentroids(k)
	iterations := 0

	for {
		clearCentroids(centroids)
		changed := assignPointsToCentroids(points, centroids)

		if !changed {
			return centroids, iterations
		}

		recalculateCentroids(points, centroids)

		iterations++
	}

	return nil, iterations
}

func makeCentroids(k int) []centroid {
	rand.Seed(time.Now().UTC().UnixNano())

	centroids := make([]centroid, k)

	for i := 0; i < k; i++ {
		x := rand.Float64() * __max
		y := rand.Float64() * __max
		centroids[i] = centroid{x, y, nil}
	}

	return centroids
}

func clearCentroids(centroids []centroid) {
	for i := range centroids {
		centroids[i].points = []int{}
	}
}

func assignPointsToCentroids(points []point, centroids []centroid) bool {
	changed := false

	for i, point := range points {
		minDistance := float64(__max * 2 + 1)
		minCentroid := -1

		for j, centroid := range centroids {
			xpow := ((point.x - centroid.x) * (point.x - centroid.x))
			ypow := ((point.y - centroid.y) * (point.y - centroid.y))
			distance := math.Sqrt(float64(xpow + ypow))

			if distance < minDistance {
				minDistance = distance
				minCentroid = j
			}
		}

		if points[i].centroid != minCentroid {
			changed = true
			points[i].centroid = minCentroid
		}

		centroids[minCentroid].points = append(centroids[minCentroid].points, i)
	}

	return changed
}

func recalculateCentroids(points []point, centroids []centroid) {
	for i, centroid := range centroids {
		if len(centroid.points) < 1 {
			continue
		}

		var sumx float64 = 0
		var sumy float64 = 0

		for _, point := range centroid.points {
			sumx += points[point].x
			sumy += points[point].y
		}

		centroids[i].x = sumx/float64(len(centroid.points))
		centroids[i].y = sumy/float64(len(centroid.points))
	}
}
