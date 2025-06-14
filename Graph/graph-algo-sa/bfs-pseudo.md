procedure BFS(G, source):
    Q <- queue(), level[] <- infinity
    Q.enqueue(source)
    level[source] <- 0

    while Q is not empty
        u <- Q.pop()

        for all edges from u to v in G.adjacentEdges(u)
            do
                if level[v] = infinity:
                    level[v] <- level[u] + 1;
                    Q.enqueue(v)
                end if
        end for

    end while

    return distance
