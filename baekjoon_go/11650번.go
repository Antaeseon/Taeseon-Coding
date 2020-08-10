package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func main() {
	var n, a, b int
	type pair struct {
		y int
		x int
	}

	p := make([]pair, 0)
	reader := bufio.NewReader(os.Stdin)
	fmt.Fscanln(reader, &n)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	for i := 0; i < n; i++ {
		fmt.Fscanln(reader, &a, &b)
		p = append(p, pair{a, b})
	}

	sort.Slice(p, func(a, b int) bool {
		if p[a].y < p[b].y {
			return true
		} else if p[a].y == p[b].y {
			if p[a].x < p[b].x {
				return true
			} else {
				return false
			}

		} else {
			return false
		}

	})

	for _, val := range p {
		fmt.Println(val.y, val.x)
	}
}
