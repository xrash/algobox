package main

type StringListNode struct {
	key string
	value string
	next *StringListNode
}

type StringList struct {
	head *StringListNode
}

func NewStringList() *StringList {
	return &StringList{}
}

func (sl *StringList) Find(key string) *StringListNode {
	current := sl.head

	for current != nil {
		if current.key == key {
			return current
		}

		current = current.next
	}

	return nil
}

func (sl *StringList) Push(key, value string) {
	sln := &StringListNode{
		key,
		value,
		sl.head,
	}

	sl.head = sln
}
