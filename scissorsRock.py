
import sys
# generate random integer values
from random import seed
from random import randint
# seed random number generator
#seed(1)
#sel = input()
def getName(sel):
    if sel == '1':
        name = "가위"
    elif sel == '2':
        name = "바위"
    else:
        name = "보"
    return name
def getResult(person1, person2):
    if person1 == "가위" and person2 == "가위":
        return 0
    if person1 == "가위" and person2 == "바위":
        return -1
    if person1 == "가위" and person2 == "보":
        return 1
    if person1 == "바위" and person2 == "가위":
        return 1
    if person1 == "바위" and person2 == "바위":
        return 0
    if person1 == "바위" and person2 == "보":
        return -1
    if person1 == "보" and person2 == "가위":
        return -1
    if person1 == "보" and person2 == "바위":
        return 1
    if person1 == "보" and person2 == "보":
        return 0
def getResultName(res):
    if res == 0:
        return "비겼어"
    elif res == 1:
        return "이겼어"
    elif res == -1:
        return "졌어"
print("가위 바위 보 게임할래?")
    
while True:
    print("너가 골라봐! (1:가위, 2:바위, 3:보) : ")
    sel = input()
    name = ""
    print(f"너가 고른 것은 '{getName(sel)}' 야 ")
    #for i in range(10):
    #    random = str(randint(1,3))
    #    print(random)
    random = str(randint(1,3))                    
    print(f"그런데 나는 {getName(random)}를 냈어")
    answer = getResult(getName(sel), getName(random))
    print(f"그래서 너는 {getResultName(answer)}")
    #print("또 게임할래?")
    #input()

    