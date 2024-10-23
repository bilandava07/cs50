import re



def main():

    amex_regex = re.compile('^3[47][0-9]{13}$')
    master_regex = re.compile('^5[1-5][0-9]{14}$')
    visa_regex = re.compile('^4([0-9]{13}|[0-9]{16})$')

    while(True):
        card_number = input("Number: ")

        if 




