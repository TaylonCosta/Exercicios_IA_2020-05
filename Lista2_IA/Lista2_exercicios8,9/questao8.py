def soma_recursiva (numbers, tamanho):

    if len(numbers)==1:
        return numbers[0]
    else:
        return numbers[0]+soma_recursiva(numbers[1:], tamanho)


numbers = [12, 4, 6, 10, 22, 17, 42, 55, 80]


tamanho = len(numbers)
total = soma_recursiva(numbers, tamanho)
print(total)