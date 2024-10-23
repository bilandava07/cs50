import re



def main():

    possibly_valid = False

    amex_regex = re.compile('^3[47][0-9]{13}$')
    master_regex = re.compile('^5[1-5][0-9]{14}$')
    visa_regex = re.compile('^4([0-9]{13}|[0-9]{16})$')

    card_number = input("Number: ")

    match = amex_regex.match(card_number)
    if match:
        possibly_valid = True
    match = master_regex.match(card_number)
    if match:
        break




