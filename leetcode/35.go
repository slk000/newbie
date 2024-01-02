package main

import (
	"fmt"
	"strconv"
)

type Node struct {
	Val    int
	Next   *Node
	Random *Node
}

func copyRandomList(head *Node) *Node {
	m := make(map[*Node]*Node)

	cur := head
	for cur != nil {
		new := &Node{
			cur.Val,
			cur.Next,
			cur.Random,
		}
		m[cur] = new
		cur = cur.Next
	}

	cur = m[head]
	for cur != nil {
		if cur.Random != nil {
			fmt.Println("changing ", &cur)
			cur.Random = m[cur.Random]
		}
		cur = cur.Next
	}
	return m[head]
}

func main() {
	node2 := &Node{2, nil, nil}
	node1 := &Node{1, node2, nil}
	node2.Random = node2
	fmt.Println("old values: ")
	fmt.Printf("add:%p %v\n", &node1, node1)
	fmt.Printf("add:%p %v\n", &node2, node2)
	fmt.Print("\n\n")
	res := copyRandomList(node1)
	fmt.Println("new values: ")
	fmt.Printf("add:%p %v\n", &node1, node1)
	fmt.Printf("add:%p %v\n", &node2, node2)
	fmt.Print("\n\n")

	fmt.Println("copied values: ")
	for res != nil {
		fmt.Printf("add:%p %v\n", &res, res)
		res = res.Next
	}
	strconv.ParseBool("t")
}
