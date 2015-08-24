package main

const MODULUS = 10

type HashTable struct {
	array []*StringList
}

func NewHashTable() *HashTable {
	array := make([]*StringList, MODULUS)

	for i := range array {
		array[i] = NewStringList()
	}

	return &HashTable{
		array,
	}
}

func (ht *HashTable) Get(key string) string {
	hash := ht.Hash(key)
	node := ht.array[hash].Find(key)

	if node != nil {
		return node.value
	}

	return ""
}

func (ht *HashTable) Set(key, value string) {
	hash := ht.Hash(key)
	node := ht.array[hash].Find(key)

	if node != nil {
		node.value = value
	} else {
		ht.array[hash].Push(key, value)
	}
}

func (ht *HashTable) Prehash(key string) int {
	preHash := 0

	for _, c := range key {
		preHash += int(c)
	}

	return preHash
}

func (ht *HashTable) Hash(key string) int {
	return ht.Prehash(key) % MODULUS
}
