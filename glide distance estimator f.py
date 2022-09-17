glide_ratio = {
    "Aircraft A": 15,
    "Aircraft B": 9,
    "Aircraft C": 17,
    "Aircraft D": 7,
    "Aircraft E": 16,
    "Aircraft F": 10,
}     
def ind():
    print('''
              index        
            Aircraft A     
            Aircraft B     
            Aircraft C     
            Aircraft D     
            Aircraft E     
            Aircraft F     ''')
    

def calc():
    return float(altitude) *  float(glide_ratio[search]) / 5280


ind()
print("Enter a aircraft from index and a altitude to get the estamated glide distance.")
print("Enter i for index and x to exit.")
while True:
    try:
        print("Enter a aircraft in index.")
        search = input()
        if   search  == "i" :
            ind()
            continue
        elif search == "x":
            break
        print("Enter a altitude.")
        altitude = input()
        if altitude == "i":
            ind()
            continue
        elif altitude == "x":
            break
        print(calc())
        print("miles\n")
    except KeyError:
        print("Enter a valid aircraft name.")
        print("Try again.")
    except ValueError:   
        print("Enter a valid altitude.")
        print("Try again.")    
           
   
      
        
    
           
