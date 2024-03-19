import random
tab = []
for i in range(0, 501):
    tab.append(i)

# print(tab)
for i in range(0, 500):
    var = random.choice(tab)
    print(var, " " ,end='')
    tab.remove(var)
