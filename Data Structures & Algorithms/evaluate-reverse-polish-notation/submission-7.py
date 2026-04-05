class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        num_stack = []
        operation_set = set(['+', '-', '*', '/'])

        for token in tokens:
            if (token == '+'):
                num1 = num_stack.pop()
                num2 = num_stack.pop()
                num_stack.append(num2 + num1)
            elif (token == '-'):
                num1 = num_stack.pop()
                num2 = num_stack.pop()
                num_stack.append(num2 - num1)
            elif (token == '*'):
                num1 = num_stack.pop()
                num2 = num_stack.pop()
                num_stack.append(num2 * num1)
            elif (token == '/'):
                num1 = num_stack.pop()
                num2 = num_stack.pop()
                num_stack.append(int(num2 / num1))
            else:
                num_stack.append(int(token))
        print(num_stack)
        return num_stack[0]