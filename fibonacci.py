# naive
def fibonacci(n):
    if n == 1 or n == 2:
        result = 1
    else:
        result = fibonacci(n-1) + fibonacci(n-2)
    return result

# with memory
def fibonacci2(n, memory):
    if n in memory:
        return memory[n]
    else:
        result = fibonacci2(n-1, memory) + fibonacci2(n-2, memory)
    memory[n] = result
    return result

def fibonacci_with_memory(n):
    memory = { 1 : 1, 2 : 1 }
    return fibonacci2(n, memory)

print(fibonacci_with_memory(993))