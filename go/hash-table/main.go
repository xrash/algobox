package main

import (
	"fmt"
)

func main() {
	ht := NewHashTable()

	ht.Set("a", "papaya")
	ht.Set("b", "ananas")
	ht.Set("ok", "woo")
	ht.Set("ok", "waa")
	ht.Set("wachacha", "wololo")

	fmt.Println(ht.Get("a"))
	fmt.Println(ht.Get("b"))
	fmt.Println(ht.Get("ok"))
	fmt.Println(ht.Get("wachacha"))
}
