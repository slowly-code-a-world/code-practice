package main
import (
    "fmt"
    "net"
    "encoding/gob"
)

func main() {
    go server()
    go client()

    var input string
    fmt.Scanln(&input)
}

func handleServerConnection(conn net.Conn) {
    var msg string
    err := gob.NewDecoder(conn).Decode(&msg)
    if err != nil {
        fmt.Println(err)
    } else {
        fmt.Println("Received:", msg)
    }
    conn.Close()
}

func server() {
    // listen on a port
    conn, err := net.Listen("tcp", ":9999")
    if err != nil {
        fmt.Println(err)
        return
    }

    for {
        c, err := conn.Accept()
        if err != nil {
            fmt.Println(err)
            continue
        }
        go handleServerConnection(c)

    }
}

func client() {
    c, err := net.Dial("tcp", "127.0.0.1:9999")
    if err != nil {
        fmt.Println(err)
        return
    }
    msg := "Hello World"
    fmt.Println("sending...", msg)
    err = gob.NewEncoder(c).Encode(msg)
    if err != nil {
        fmt.Println(err)
    }
    c.Close()
}