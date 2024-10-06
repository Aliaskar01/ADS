class TreeNode:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None
        self.cnt = 1

class BST:
    def __init__(self):
        self.root = None

    def get_min(self, root):
        while root.left is not None:
            root = root.left
        return root

    def insert(self, val):
        self.root = self._insert(self.root, val)

    def _insert(self, root, val):
        if root is None:
            return TreeNode(val)
        if val < root.data:
            root.left = self._insert(root.left, val)
        elif val > root.data:
            root.right = self._insert(root.right, val)
        else:
            root.cnt += 1
        return root

    def delete_node(self, val):
        temp = self.find(val)
        if temp is None:
            return
        elif temp.cnt > 1:
            temp.cnt -= 1
        elif temp == self.root and temp.right is None and temp.left is None:
            self.root = None
        else:
            self.root = self._delete_node(self.root, val)

    def _delete_node(self, root, data):
        if root is None:
            return None
        if root.data > data:
            root.left = self._delete_node(root.left, data)
            return root
        elif root.data < data:
            root.right = self._delete_node(root.right, data)
            return root
        else:
            if root.left is None and root.right is None:
                return None
            elif root.right is None:
                return root.left
            elif root.left is None:
                return root.right
            else:
                temp = self.get_min(root.right)
                root.data = temp.data
                root.cnt = temp.cnt
                root.right = self._delete_node(root.right, temp.data)
                return root

    def find(self, key):
        temp = self.find_node(self.root, key)
        if temp is None:
            return None
        else:
            return temp

    def find_node(self, root, key):
        if root is None or root.data == key:
            return root
        if key < root.data:
            return self.find_node(root.left, key)
        else:
            return self.find_node(root.right, key)

    def solve(self, s, val):
        if s == "insert":
            self.insert(val)
        elif s == "delete":
            self.delete_node(val)
        else:
            temp = self.find(val)
            if temp is None:
               print(0)
            else:
                print(temp.cnt)


n = int(input())
bst = BST()
for _ in range(n):
    try:
        command, value = input().split()
        bst.solve(command, int(value))
    except:
        pass
