from matplotlib import pyplot as plt


def plott(y_array, x_array, avgy, avgx, title):
    plt.scatter(avgx, avgy, 10, "#ff2800")
    plt.scatter(x_array, y_array, 0.3)
    plt.title(title)
    plt.show()


file = open('results.txt')
x_ar = []
x_ar2 = []
for n in range(1000, 100001, 1000):
    table = []
    for k in range(50):
        table.append(n)
    x_ar.append(table)
    x_ar2.append(n)

avg = [[], [], [], [], [], []]
k = 0
sums = [0, 0, 0, 0, 0, 0]
results = [[], [], [], [], [], []]
ktab_results = [[], [], [], [], [], []]
for line in file:
    k += 1
    table = line.split()
    for i in range(6):
        sums[i] += int(table[i])
        ktab_results[i].append(int(table[i]))
    if k == 50:
        k = 0
        for i in range(6):
            avg[i].append(sums[i]/50)
        sums = [0, 0, 0, 0, 0, 0]
        for i in range(6):
            results[i].append(ktab_results[i])
        ktab_results = [[], [], [], [], [], []]

file.close()
"""
plott(results[0], x_ar, avg[0], x_ar2, "B - Moment pierwszej kolizji")
plott(results[1], x_ar, avg[1], x_ar2, "U - Liczba pustych urn po wrzuceniu n kul")
plott(results[2], x_ar, avg[2], x_ar2, "L - Maksymalna liczba kul w urnie po wrzuceniu n kul")
plott(results[3], x_ar, avg[3], x_ar2, "C - Minimalna liczba rzutow po ktorej w kazdej urnie min.1")
plott(results[4], x_ar, avg[4], x_ar2, "D - Minimalna liczba rzutow po ktorej w kazdej urnie min.2")
plott(results[5], x_ar, avg[5], x_ar2, "Liczba rzutow od momentu C do D")
"""

