blood = [int(i) for i in input().split()]
patients = [int(i) for i in input().split()]

total = 0
for i in range(0, 7):
    mini = min(blood[i], patients[i])
    blood[i] = blood[i] - mini
    patients[i] = patients[i] - mini
    total = total + mini
    need_dic = {1: [0],
                2: [0],
                4: [0],
                6: [2, 4, 0],
                3: [2, 1, 0],
                5: [4, 0, 1],
                7: [0,1,2,3,4,5,6]}

for i in range(1, 7):
    if patients[i] > 0:
        for bl in need_dic[i]:
            mini = min(blood[bl], patients[i])
            total = total + mini
            blood[bl] = blood[bl] - mini
            patients[i] = patients[i] - mini
            
print(total)
