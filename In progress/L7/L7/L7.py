while 1:
    v1 = input("Enter first value: ") 
    v2 = input("Enter second value: ")

    try:
        v1 = int(v1);
        print("First value is int")
    except:
        print("First value is str")
    try:
        v2 = int(v2);
        print("Second value is int")
    except:
        print("Second value is str")    
       
    t1 = type(v1)
    t2 = type(v2)
    if (t1 is str):
        if (t2 == t1):
            print(v1+v2)
        if (t2 is int):
            print(v1*v2)
    elif (t1 is int and t1 == t2):
        print(v1/v2)
    else:
        print("Type error. Please, enter values again")
    