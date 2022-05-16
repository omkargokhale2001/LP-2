class Node:

    def __init__(self, data, level, fval):
        self.data = data
        self.level = level
        self.fval = fval

        def generate_child(self):
            x, y = self.find(self.data, '_')
            val_list = [[x, y-1], [x, y+1], [x+1, y], [x-1, y]]
            children = []
            for i in val_list:
                child = self.shuffle(data, x, y, i[0], i[1])
                if child != None:
                    child = Node(child, self.level+1, 0)
                    children.append(child)
            return children

        def shuffle(self, data, x, y, x_new, y_new):
            if x_new >= 0 and x_new < len(data) and y_new >= 0 and y_new < len(data):
                temp = data[x][y]
                data[x][y] = data[x_new][y_new]
                data[x_new][y_new] = temp
            else:
                return None

        def find(self, data, x):
            for i in range(len(data)):
                for j in range(len(data)):
                    if data[i][j] == x:
                        return i, j

        def copy(self):
            temp = []
            for i in range(len(data)):
                t = []
                for j in range(len(data)):
                    t.append(data[i][j])
                temp.append(t)
            return temp


class Puzzle:
    def __init__(self, size):
        self.size = size
        self.open = []
        self.closed = []

    def accept(self):
        arr = []
        for i in range(self.size):
            temp = input().split(" ")
            arr.append(temp)
        return arr

    def f(self, start, goal):
        return self.h(start.data, goal) + start.level

    def h(self, start, goal):
        heuristic = 0
        for i in range(self.size):
            for j in range(self.size):
                if start[i][j] != goal[i][j] and start[i][j] != "_":
                    heuristic += 1
        return heuristic

    def process(self):
        print("Enter first state:")
        start = self.accept()
        print("Enter goal state:")
        goal = self.accept()
        start = Node(start, 0, 0)
        start.fval = self.f(start.data, goal)
        open.append(start)
        while True:
            print()
            print()
            cur = self.open[0]
            for i in range(self.size):
                for j in range(self.size):
                    print(cur.data[i][j], end="")
                print("")
            print(" |")
            print(" |")
            print("\/")
            if self.h(cur.data, goal) == 0:
                break
            children = cur.generate_child()
            for i in children:
                i.fval = self.f(i, goal)
                self.open.append(i)
            self.closed.append(cur)
            del self.open[0]
            self.open.sort(key=lambda x: x.fval, reverse=False)


puz = Puzzle(3)
puz.process()
