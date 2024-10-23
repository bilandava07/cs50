import re

def checksum(card_number):
    
    pass


def main():

    amex_regex = re.compile('^3[47][0-9]{13}$')
    master_regex = re.compile('^5[1-5][0-9]{14}$')
    visa_regex = re.compile('^4([0-9]{13}|[0-9]{16})$')

    card_number = input("Number: ")

    match = amex_regex.match(card_number)
    if match:
        if checksum(card_number):
            print("AMEX")
            return

    match = master_regex.match(card_number)
    if match:
        if checksum(card_number):
            print("MASTERCARD")
            return

    match = visa_regex.match(card_number)
    if match:
        if checksum(card_number):
            print("VISA")
            return


    # if no matches -> the card is invalid
    print("INVALID")
    return

main()


