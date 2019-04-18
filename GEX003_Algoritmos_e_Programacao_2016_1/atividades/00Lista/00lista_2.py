def ePrimo(x):
    cnt = 0
    for i in range(1, (x+1)):
        if((x%i)==0):
            cnt+=1
    if(cnt == 2):
        return x
    return 1

tot = 1
for y in range(92, 1479):
    tot *= ePrimo(y)
print(tot)
