package main

type StringQueue struct {
	elements []string
}

func NewStringQueue() *StringQueue {
	return &StringQueue{
		make([]string, 0),
	}
}

func (sq *StringQueue) Push(element string) {
	sq.elements = append(sq.elements, element)
}

func (sq *StringQueue) Pop(element string) {
	lastElement := sq.elements[len(sq.elements) - 1]
	sq.elements = sq.elements[0:len(sq.elements) - 1]
	return lastElement
}

func (sq *StringQueue) Empty() bool {
	return len(sq.elements) == 0
}
