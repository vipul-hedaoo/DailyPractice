#Python programe for n fibonachi number
def fibonachi(num):
    if num<=0:
        print("incorrect input")
    elif num==1:
        return 0
    elif num==2:
        return 1
    else:
        return fibonachi(num-1)+fibonachi(num-2)
num=int(input("please enter the value of fibonachi number you want"))
print("the fibonachi number is",fibonachi(num))
