class single_ll:
    def __init__(self):
        self.head = None
        self.length = 0

    def add_node(self, data):
        new_node = node(data)
        self.length += 1
        current = self.head
        if current:
            while current.next:
                current = current.next
            current.next = new_node
        else:
            self.head = new_node

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


def reverse(ll):
    head = ll.head
    if head.next == None:
        return
    temp1, temp2 = None, 0

    while temp2 != None:
        temp2 = head.next
        head.next = temp1
        temp1 = head
        if temp2 != None:
            head = temp2
    ll.head = head


ll = single_ll()
for ele in [int(i) for i in input().split(" ")]:
    ll.add_node(ele)

ll.print()
reverse(ll)
ll.print()
