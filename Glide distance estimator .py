glide_ratio = {
    "aircraft a": 8,          
    "aircraft b": 15,
    "aircraft c": 9,
    "aircraft d": 17,
    "aircraft e": 7,
    "aircraft f": 16,
    "aircraft g": 10,
    "aircraft h": 6,                 
}   

def ind():
    print('''
                aircraft a      
                aircraft b       
                aircraft c      
                aircraft d      
                aircraft e      
                aircraft f      
                aircraft g      
                aircraft h         ''')
    

ind()
print("Enter a aircraft from index and a altitude to get the estamated glide distance.")
print("Enter i for index and x to exit.")
while True:
    try:
        print("Enter a aircraft in index.")
        search = input()
        if search == "i":
            ind()
            continue
        elif search == "x":
            break
        print("Enter a altitude")
        altitude = input()
        if altitude == "i":
            ind()
            continue
        elif altitude == "x":
            break
        print(float(altitude) *   float(glide_ratio[search]) / 5280) 
        print("miles\n")
    except KeyError:
        print("Enter a valid aircraft name.")
        print("Try again.")
    except ValueError:   
        print("Enter a valid altitude.")
        print("Try again.")       
        
        
 
      
    


        
    
