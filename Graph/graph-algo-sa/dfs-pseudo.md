# Recursive Approach

```python

procedure DFS(G, source):
    visited[] <- false for all vertices

    call DFS_Visit(source)

procedure DFS_Visit(u):
    visited[u] <- true

    for all edges from u to v in G.adjacentEdges(u)
        do
            if visited[v] = false:
                DFS_Visit(v)
            end if
    end for
```


# Using Stack

```python

procedure DFS(G, source):
    S <- stack(), visited[] <- false
    S.push(source)

    while S is not empty:
        u <- S.pop()

        if visited[u] = false:
            visited[u] <- true

            for all edges from u to v in G.adjacentEdges(u)
                do
                    if visited[v] = false:
                        S.push(v)
                    end if
            end for
    end while
