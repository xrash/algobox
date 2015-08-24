package main

type StringQueueNode struct {
	element string
	next *StringQueueNode
}

type StringQueue struct {
	head *StringQueueNode
	tail *StringQueueNode
}

func NewStringQueue() *StringQueue {
	return &StringQueue{}
}

func (sq *StringQueue) Enqueue(element string) {
	sqn := &StringQueueNode{
		element,
		nil,
	}

	if sq.tail != nil {
		sq.tail.next = sqn
	}

	sq.tail = sqn

	if sq.head == nil {
		sq.head = sqn
	}
}

func (sq *StringQueue) Dequeue() string {
	tmp := sq.head.element

	sq.head = sq.head.next

	return tmp
}

func (sq *StringQueue) Empty() bool {
	return sq.head == nil
}
