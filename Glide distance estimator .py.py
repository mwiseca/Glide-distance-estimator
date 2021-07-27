glide_ratio = {
    "i":          0,
    "aircraft a": 15,
    "aircraft b": 9,
    "aircraft c": 17,
    "aircraft d": 7,
    "aircraft e": 16,
    "aircraft f": 10,
    "x":          0,       
}   

def ind():
    print("   index           ")
    print("   aircraft a      ") 
    print("   aircraft b      ")
    print("   aircraft c      ")
    print("   aircraft d      ")
    print("   aircraft e      ") 
    print("   aircraft f      ") 
    

ind()
print("Enter i for aircraft and 0 for altitude for index.")
print("Enter x for aircraft and 0 for altitude to exit.")
while True:
    try:
        print("Enter a aircraft in index.")
        search = input()  
        print("Enter a altitude")
        altitude = input()
        result = float(altitude) *   float(glide_ratio[search]) / 5280 
        print(result)
        print("miles")
        if   search  == "i" :
            ind()
        elif search == "x":
            break
    except KeyError:
        print("Enter a valid aircraft name.")
        print("Try again.")
    except ValueError:   
        print("Enter a valid altitude.")
        print("Try again.")     
    


        
    
