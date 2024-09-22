class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None
        self.size = 0 

    def insert(self, data):
        if self.head is None:
            new_node = Node(data)
            self.head = new_node
            self.size += 1
        elif self.head.data != data:
            new_node = Node(data)
            new_node.next = self.head
            self.head = new_node
            self.size += 1

    def display_lifo(self):
        elements = []
        current = self.head
        
        while current:
            elements.append(current.data)
            current = current.next
            
        return elements

  
    def total_elements(self):
        return self.size


ll = LinkedList()
n = int(input())

for i in range(n):
    student = str(input())
    ll.insert(student)

print("All in all:", ll.total_elements())
print("Students:")
for el in ll.display_lifo():
    print(el)