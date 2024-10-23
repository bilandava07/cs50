import re

def checksum(card_number):
    sum_mult2 = 0
    sum_other = 0
    length = len(card_number)

    # if the card number is even start with the first element to iterate through (every other number from the end )

    if length % 2 == 0:
        for i in range(0,length,2):
            sum_mult2 += int(card_number[i]) * 2
        for y in range(1,length,2):
            sum_other += int(card_number[y])

    # else -> other way around
    else:
        for i in range(0,length,2):
            sum_other += int(card_number[i])
        for y in range(1,length,2):
            sum_mult2 += int(card_number[y]) * 2

    if (sum_mult2 + sum_other) % 2 == 0:
        return True
    else:
        return False


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


