import csv
import sys


def main():

    # Check for command-line usage
    if len(sys.argv) != 3:
        print("Error! Usage: python dna.py [database] [dna-file]")
        return

    # Read database file into a variable
    database = []
    fieldnames = []
    with open(sys.argv[1], "r") as file:
        reader = csv.DictReader(file)
        fieldnames = reader.fieldnames
        for row in reader:
            database.append(row)

    # Read DNA sequence file into a variable
    with open(sys.argv[2], "r") as file:
        dna_file = file.read().strip("\n")

    # Find longest match of each STR in DNA sequence

    # pop the first element "name" from the fieldnames to get a list of the STRs only
    fieldnames.pop(0)

    str_matches = {}
    for i in fieldnames:
        str_matches[i] = str(longest_match(dna_file, i))
    print(str_matches)
    # Check database for matching profiles

    # set the amount of matches needed

    target_amount = len(str_matches.keys())

    for entry in database:
        counter = 0
        for key, value in entry.items():
            if key in str_matches.keys():
                if value == str_matches[key]:
                    counter += 1
        # if reached the targe amoutn of matches i.e. if all STR in str_matches are present in person's DNA exact number of times
        if counter == target_amount:
            print(entry["name"])
            return
    print("No match")
    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
