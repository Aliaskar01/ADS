class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None

    def append(self, data):
        new_node = Node(data)
        if self.head is None:
            self.head = new_node
        else:
            current = self.head
            while current.next:
                current = current.next
            current.next = new_node

    
    def insert_at_position(self, data, position):
        new_node = Node(data)
        if position == 0:
            new_node.next = self.head
            self.head = new_node
        else:
            current = self.head
            count = 0
            prev = None
          
            while current is not None and count < position:
                prev = current
                current = current.next
                count += 1
            
            if prev is not None:
                prev.next = new_node
                new_node.next = current
            else:
                print("Position out of bounds")

    def print_list(self):
        current = self.head
        if current is None:
            print("The list is empty.")
            return
        while current:
            print(current.data,end=" ")
            current = current.next
        


ll = LinkedList()

num_elements = int(input())

for i in range(num_elements):
    element = int(input())
    ll.append(element)

   
new_data = int(input())
position = int(input())

ll.insert_at_position(new_data, position)
ll.print_list()