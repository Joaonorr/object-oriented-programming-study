def existe(vetor,num):
    print(len(vetor))
    for i in range(len(vetor)):
        if vetor[i] == num :
            return True
    return False


vet = [-1, -50, -99, 80, 70, 90, -4]

x = int(input())
resp = existe(vet,x)
print(resp)