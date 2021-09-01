"""
Node is defined as
self.left (the left child of the node)
self.right (the right child of the node)
self.info (the value of the node)
"""
from collections import defaultdict


def topView(root):
    if root is None:
        return None
    queue = [(root, 0)]
    hash = defaultdict(list)
    for node, level in queue:
        if node is not None:
            hash[level].append(node.info)
        if node.left is not None:
            queue.extend([(node.left, level - 1)])
        if node.right is not None:
            queue.extend([(node.right, level + 1)])
    if hash:
        for level in range(min(hash.keys()),
                           max(hash.keys()) + 1):
            print(hash[level][0], end=' ')
    else:
        return None