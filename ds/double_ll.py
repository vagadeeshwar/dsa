class double_ll:
    def __init__(self):
        self.head = None
        self.tail = None
        self.length = 0

    def add_node(self, data, idx=-1):
        new_node = node(data)
        self.length += 1
        current = self.head
        if current:
            if idx == -1:
                self.tail.next = new_node
                new_node.prev = self.tail
                self.tail = new_node
                return
            while idx>0:
                current = current.next
                idx-=1
            temp=current
            temp.prev.next=new_node
            new_node.prev=temp.prev
            new_node.next=temp
            temp.prev=new_node

        else:
            self.head = new_node
            self.tail = new_node

    def print(self):
        temp = self.head
        while temp is not None:
            print(temp.data, end=" ")
            temp = temp.next
        print()


class node:
    def __init__(self, data):
        self.data = data
        self.next = None
        self.prev = None


# ll = linked_list()
# for ele in [int(i) for i in input().split(' ')]:
#     ll.add_node(ele)

# ll.print()
# reverse(ll)
# ll.print()
