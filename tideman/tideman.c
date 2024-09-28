#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
} pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i], name) == 0)
        {
            ranks[rank] = i;
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    int counter = 1;
    int z;
    for (int i = 0; i < candidate_count-1; i++)
    {
        z = counter;
        while (z < candidate_count)
        {
            preferences[ranks[i]][ranks[z]]++;
            z++;
        };
        counter++;
    }
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    pair_count = 0;
    int counter = 0;
    int j;
    for (int i = 0; i < candidate_count; i++)
    {
        j = counter;
        while (j < candidate_count)
        {
            if (preferences[i][j+1] > preferences[j+1][i])

            {
                pairs[pair_count].winner = i;
                pairs[pair_count].loser = j+1;
                pair_count++;
            }
            else if(preferences[i][j+1] < preferences[j+1][i])
            {
                pairs[pair_count].winner = j+1;
                pairs[pair_count].loser = i;
                pair_count++;
            }
            j++;
        };
        counter++;
    }
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    int swap_counter;
    int tmp_winner;
    int tmp_loser;

    int counter = pair_count;
    for (int i = 0; i < pair_count; i++)
    {
        swap_counter = 0;

        for (int z = 0; z < counter-1; z++)
        {

            if (preferences[pairs[z].winner][pairs[z].loser] < preferences[pairs[z+1].winner][pairs[z+1].loser])
            {
                //swap
                tmp_winner = pairs[z+1].winner;
                tmp_loser = pairs[z+1].loser;

                pairs[z+1].winner = pairs[z].winner;
                pairs[z+1].loser = pairs[z].loser;

                pairs[z].winner = tmp_winner;
                pairs[z].loser = tmp_loser;

                swap_counter++;
            }
        }

        if (swap_counter == 0)
        {
            return;
        }
        counter--;
    }
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    bool found;
    bool found_true;
    //add 3 pairs (minimum to create a cycle)
    for (int o = 0; o < 3; o++)
    {
        locked[pairs[o].winner][pairs[o].loser] = true;
    }

    for (int i = 3; i < pair_count; i++)
    {
        locked[pairs[i].winner][pairs[i].loser] = true;

        for(int z = 0; z < candidate_count; z++)
        {
            found_true = false;
            for (int y = 0; y < candidate_count; y++)
            {
                if (locked[y][z] == true)
                {
                    found_true = true;
                }
            }
            if (found_true == false)
            {
                locked[pairs[i].winner][pairs[i].loser] = false;
            }
        }
    }


}

// Print the winner of the election
void print_winner(void)
{
    int losers[candidate_count];
    int losers_index = 0;

    // fill the array losers with the indices of the candidates, whenever they are locked
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if (locked[i][j] == true)
            {
                losers[losers_index] = j;
                losers_index++;
            }
        }
    }

    for (int z = 0; z < candidate_count; z++)
    {
        bool found = false;

        for (int i = 0; i < losers_index+1; i++)
        {
            if (losers[z] == i)
            {
                found = true;
            }
        }

        if (found == false)
        {
            printf("The winner is: %s\n", candidates[z]);
        }
    }

}
