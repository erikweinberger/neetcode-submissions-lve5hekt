class MinStack:

    def __init__(self):
        self.stack = []
        self.minstack = []
        

    def push(self, val: int) -> None:
        self.stack.append(val)
        if (not self.minstack or self.minstack[-1] >= val):
            self.minstack.append(val)
        

    def pop(self) -> None:
        pop = self.stack.pop()
        if self.minstack[-1] == pop:
            self.minstack.pop()
        

    def top(self) -> int:
        return self.stack[-1]

    def getMin(self) -> int:
        return self.minstack[-1]
