
T = None
visited = [False for _ in range(5)]

def preorder():
    ans = []
    preorderAux(0, ans)
    return ans

def preorderAux(u, ans):
    global visited
    ans.append(u)
    visited[u] = True
    for i in range(len(T[u])):
        v = T[u][i]
        if not visited[v]:
            preorderAux(v, ans)

def postorder():
    ans = []
    postorderAux(0, ans)
    return ans

def postorderAux(u, ans):
    global visited
    visited[u] = True
    for i in range(len(T[u])):
        v = T[u][i]
        if not visited[v]:
            postorderAux(v, ans)
    ans.append(u)

def inorder():
    ans = []
    inorderAux(0, ans)
    return ans

def inorderAux(u, ans):
    global visited
    #visited[u] = True

    #if len(T[u]) >= 2:
    if len(T[u]) >= 1:
        i = 0
        #if visited[T[u][i]]: i += 1
        inorderAux(T[u][i], ans)
    ans.append(u)
    for i in range(1, len(T[u])):
        v = T[u][i]
        #if not visited[v]:
        inorderAux(v, ans)

            
def main():
    global T
    #T = [[1, 2], [0, 3, 4], [0], [1], [1]]
    T = [[1, 2], [3, 4], [], [], []]
    #print(preorder())
    #print(postorder())
    print(inorder())

main()
