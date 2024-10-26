



def main ():

    punctuation = ['.','?','!']

    # Initialize the counter variables

    letters = 0
    words = 0
    sentences = 0

    text = input("Text: ")

    for char in text:
        if char.isalpha():
            letters += 1
        elif char == " ":
            words += 1
        elif char in punctuation:
            sentences += 1

    words += 1

