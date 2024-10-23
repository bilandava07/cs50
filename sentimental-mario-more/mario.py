def get_int(prompt):
    try:
        return int(input(prompt))
    except ValueError:
        pass

def main():

    height = get_int("Height: ")
    

