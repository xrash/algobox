package main

import "fmt"

func main() {
	a := []int{1, 50, 30, 60, 55, 44, 15}

	fmt.Println(insertionSort(a))
}

func insertionSort(a []int) []int {
	var tmp int

	for i := 1; i < len(a); i++ {
		j := i

		for (j > 0) && (a[j-1] > a[j]) {
			tmp = a[j-1]
			a[j-1] = a[j]
			a[j] = tmp
			j--
		}
	}

	return a
}