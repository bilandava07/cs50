def get_int(prompt):
    while(True):
        try:
            return int(input(prompt))
        except ValueError:
            pass

def main():

    height = get_int("Height: ")

    blanks = height - 1
    hashes = 1

    for _ in range(height):

        # print the left half

        for blank in range(blanks):
            print(" ", end='')
        for hash in range(hashes):
            print("#", end ='')

        #print the gap
        print("  ", end='')

        # print the right half

        for hash in range(hashes):
            print("#", end ='')

        blanks -= 1
        hashes += 1
        print()

main()

