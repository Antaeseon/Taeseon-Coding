package main

import "fmt"

func main() {
	var a string
	fmt.Scan(&a)
	fmt.Println([]byte(a)[0])

}
