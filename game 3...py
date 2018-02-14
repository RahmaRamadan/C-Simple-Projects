import random 
print("                     Welcome To Number Scrabble Game" )
print("let's start")
print ("  ")
arr=[1,2,3,4,5,6,7,8,9]
z=[ ]
c=[ ]
sum1=0
sum2=0
test = 0
testwin = 0
print ( "list : " , arr )
print ("--------------------------------------------------------------------------------")
print("   ")
for i in range (0,3,1):
        if testwin == 0 :
            while True :
                try :
                    print("  ")
                    x = int ( input ( "player 1 : "))
                    print ("   ")
                    arr.remove(x)
                    z.append (x)
                    if x > 9 or x < 1 :
                        print ("invalid , please try again !")
                        print("  ")
                        print ("new list : ", arr)
                        print("  ")
                        print ("--------------------------------------------------------------------------------")
                        print ("--------------------------------------------------------------------------------")
                        continue
                except Exception as e:
                    print ("invalid , please try again !")
                    continue
                break
        sum1 = sum1 + x
        if sum1 == 15 and i == 2 :
            print ("player 1 Won ! ")
            print (z)
            testwin = 1
        if testwin == 0:
            while True :
                try :
                    print("  ")
                    y=int(input("player 2 : "))
                    print ("  ")
                    arr.remove (y)
                    c.append (y)
                    print ("   ")
                    print ("new list : " , arr)
                    print("  ")
                    print("--------------------------------------------------------------------------------")
                    print("--------------------------------------------------------------------------------")
                    if y > 9 or y < 1 :
                        print ("invalid , please try again !")
                        continue
                except Exception as e :
                    print ("invalid, pleasee try again !")
                    continue
                break
        sum2 = sum2 + y
        if sum2 == 15 and i == 2 :
            print ("player 2 Won ! ")
            testwin = 1
            print (c)
if testwin == 0 :
    for num in range (0,1,1) :
        while True :
                try :
                    print("  ")
                    x = int ( input ( "player 1 : "))
                    print ("________________________________________________________________________________")
                    print("  ")
                    z.append (x)
                    arr.remove(x)
                    print("   ")
                    print("new list : ", arr)
                    print("  ")
                    print("--------------------------------------------------------------------------------")
                    print("--------------------------------------------------------------------------------")
                    if x > 9 or x < 1 : 
                        print ("invalid, please try again !")
                        continue
                        
                except Exception as e:
                    print ("invalid, please try again !")
                    continue
                break
    for n in z :
             sump1 = z[0] + z[1] + z[2] + z[3]
             if sump1 - n ==15 and testwin==0:
                 print ("player1 : ",15)    
                 print("player1 is winner")
                 testwin = 1
                 print ( z , " - " , n )
    if testwin == 0 :
        while True :
                    try :
                        print("  ")
                        y=int(input("player 2 : "))
                        print ("________________________________________________________________________________")
                        print("   ")
                        c.append (y)
                        arr.remove (y)
                        print ("   ")
                        print ("new list : " , arr)
                        print("  ")
                        print ("--------------------------------------------------------------------------------")
                        print ("--------------------------------------------------------------------------------")
                        if y > 9 or y < 1 :
                            print ("invalid, please try again !")
                            continue
                    except Exception as e :
                        print ("invalid, please try again !")
                        continue
                    break
        for d in c :
           sump2 = c[0] + c[1] + c[2] + c[3]
           if len(c)==4 :
                if (sump2 - d ==15 ) and testwin == 0:
                    print ("player2 : ",15 )
                    print("player2 is winner ")
                    testwin = 1
                    print ( c , " - " , d)

if testwin == 0 :
    print ("Draw")
print (" END GAME ")
