from queue import PriorityQueue

q = PriorityQueue()

n = 0
string = ""

for x in range (0, 3):
    n = input()
    string = input()
    q.put((-n, string))


while not q.empty():
    prox_item = q.get()
    print(prox_item)