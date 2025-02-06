class Node:
    def __init__(self, start, end = None, suffixLink = None, leaf = False):
        self.children = {}
        self.leaf = leaf
        self.start = start
        self.end = end
        self.suffixLink = suffixLink
        self.suffixIndex = -1

    def length(self):
        ans = self.end - self.start + 1
        return ans


class SuffixTree:
    def __init__(self, data):
        self.root = None
        self.s = data
        self.size = len(data)

    def build(self):
        self.root = Node(-1, -1)
        activeNode, activeEdge, activeLength = self.root, -1, 0 
        remainingSuffix = 0

        for i in range(self.size):
            # Rule 1 is implicitly performed by establishing the end value for any leaf node when it is created (i - 1 extensions)
            remainingSuffix += 1
            lastNewNode, flag = None, False

            # Add all the pending suffixes one by one in tree
            while remainingSuffix > 0:
                flag = False
                # case 1
                if activeLength == 0: activeEdge = i
                
                # There is no outgoing edge starting with activeEdge from activeNode
                if activeNode.children.get(self.s[activeEdge]) == None:
                    # Rule 2 (A new leaf node is created)
                    activeNode.children[self.s[activeEdge]] = Node(i, suffixLink = self.root, end = self.size - 1, leaf = True)

                     # If there is an internal node created previously in the same phase, its suffix links will point to the new node
                    if lastNewNode != None:
                        lastNewNode.suffixLink = activeNode
                        lastNewNode = None
                # There is an outgoing edge starting with activeEdge from activeNode
                else:
                    # Get the next node at the end of edge starting with activeEdge
                    next = activeNode.children.get(self.s[activeEdge])

                    # RUle 3 (current character s[i] is already on the edge)
                    length = next.length()
                    # walk down in next
                    if activeLength >= length:
                        # Case 3
                        activeEdge += length
                        activeLength -= length
                        activeNode = next
                        flag = True
                    else:
                        # Rule 3
                        if self.s[next.start + activeLength] == self.s[i]:
                            # If a newly created node waiting for its suffix link to be set, then set suffix link
                            # of that waiting node to current active node
                            if ((lastNewNode != None) and (activeNode != self.root)):
                                lastNewNode.suffixLink = activeNode
                                lastNewNode = None
                            # Case 2
                            activeLength += 1
                            # Due to Rule 3 is applied the current phase is finished
                            break

                        # Rule 2: activePoint is in the middle of the edge and the current character s[i] is not on the edge
                        splitEnd = next.start + activeLength - 1
                        # New internal node
                        split = Node(next.start, end = splitEnd, suffixLink = self.root)
                        activeNode.children[self.s[activeEdge]] = split
                        # New leaf node coming out of new internal node
                        split.children[self.s[i]] = Node(i, suffixLink = self.root, end = self.size - 1, leaf = True)

                        # Update the existent leaf node
                        next.start += activeLength
                        split.children[self.s[next.start]] = next

                        # If a newly created node waiting for its suffix link to be set, then set suffix link
                        # of that waiting node to the new internal node split
                        if lastNewNode != None: lastNewNode.suffixLink = split
                        lastNewNode = split
                if not flag:
                    remainingSuffix -= 1
                    # Case 4a
                    if activeNode == self.root and activeLength > 0:
                        activeLength -= 1
                        activeEdge = i - remainingSuffix + 1
                    # Case 4b
                    elif activeNode != self.root:
                        activeNode = activeNode.suffixLink
        self.setSuffixIndex(self.root, 0)

    def setSuffixIndex(self, curr, h):
        leaf = True
        for node in curr.children.values():
            if node:
                leaf = False
                self.setSuffixIndex(node, h + node.length())
        if leaf: curr.suffixIndex = len(self.s) - h

    def print(self):
        self.printAux(self.root, "")

    def printAux(self, curr, ac):
        leaf = True
        ac += self.s[curr.start : curr.end + 1]
        #print("Edge %d %d %s" % (curr.start, curr.end, self.s[curr.start : curr.end + 1]))

        for node in curr.children.values():
            if node:
                leaf = False
                self.printAux(node, ac)

        if leaf: print("Leaf %s %d" % (ac, curr.suffixIndex))

s1 = "abcabxabcd$"
tree = SuffixTree(s1)
tree.build()
tree.print()

print("****************************************************")

s2 = "aabcdeabcabd$"

tree = SuffixTree(s2)
tree.build()
tree.print()

print("****************************************************")

s3 = "abcabxabed$"

tree = SuffixTree(s3)
tree.build()
tree.print()

print("****************************************************")

s4 = "aaabcabxabeabd$"

tree = SuffixTree(s4)
tree.build()
tree.print()

print("****************************************************")

s5 = "abcde$"

tree = SuffixTree(s5)
tree.build()
tree.print()
