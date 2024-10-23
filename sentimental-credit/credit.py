import re



def main():
    amex_regex = re.compile('3(4|7)[0-9]{13}$')
    master_regex = re.compile('5[1-5])
