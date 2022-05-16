covidsuscounter = 0
severity = 0
oxygen = 0
temp = 0

yes_no_questions = [
    "Can you smell and taste things?",
    "Do you have a cough or cold?",
    "Do you have a sore throat?",
    "Do you have a headache?",
    "Do you have BP/diabetes?",
    "Have you come in contact with a Covid patient?"
]

questions = [
    "What is your temperature?",
    "What is your oxygen level?",
    "How many vaccines have you taken?",
    "What is your age?"

]

for i in range(len(yes_no_questions)):
    print(yes_no_questions[i])
    print()
    ans = input()
    if i == 0 and ans == "no":
        covidsuscounter += 1
    elif i != 0 and ans == "yes":
        covidsuscounter += 1


for i in range(len(questions)):
    print(questions[i])
    print()
    ans = float(input())
    if i == 0:
        if ans > 101.0:
            severity += 2
            covidsuscounter += 1
            temp = 1
        elif 99.6 < ans < 101.0:
            severity += 1
    if i == 1:
        if ans < 94 and ans > 86:
            severity += 1
        elif ans < 86:
            severity += 1
            covidsuscounter += 1
            oxygen = 1
    if i == 2:
        if ans == 0:
            severity += 2
            covidsuscounter += 1
        elif ans == 1:
            severity += 1
    if i == 3:
        if ans > 31 and ans < 51:
            severity += 1
        elif ans > 51:
            severity += 2
            covidsuscounter += 1


if covidsuscounter > 3:
    print("The patient probably has covid")
    print()
    if severity < 3:
        print("symptoms are mild")
    elif severity >= 3 and severity < 6:
        print("Admit patient to general ward")
    else:
        print("Pateint is critical")
if oxygen == 1:
    print("Monitor oxygen level")

if temp == 1:
    print("Monitor temperature level")
