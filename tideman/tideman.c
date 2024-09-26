#include <cs50.h>
#include <stdio.h>

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
            return True;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    for (int i = 0; i < candidate_count-2; i++)
    {
        for (int z = 0; z < candidate_count-1; z++)
        {
            preferences[i][z+1]++;
        }
    }
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    pair_count = 0;
    for (int i = 0; i < candidate_count-2; i++)
    {
        for (int j = 0; j < candidate_count-1; j++)
        {
             if (preferences[i][j+1] > preferences[j+1][i])

             {
                 pairs[counter].winner = i;
                 pairs[counter].loser = j+1;
                 pair_count++;
             }
             else if(preferences[i][j+1] < preferences[j+1][i])
             {
                 pairs[counter].winner = j+1;
                 pairs[counter].loser = i;
                 pair_count++;
             }
        }
    }
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    int counter = pair_count;
    int swap_counter = 1;

    for (int i = 0; i < counter -1; i++)
    {
        swap_counter = 0;
        for(int z = 0; z < counter - 1; z++)
        {
            if (pairs[i].winner < pairs[i+1].winner)
            {
                tmp.winner = pairs[i].winner;
                pairs[i].winner = pairs[i+1].winner;
                pairs[i+1].winner = tmp.winner;

                tmp.loser = pairs[i].loser;
                pairs[i].loser = pairs[i+1].loser;
                pairs[i+1].loser = tmp.loser;

                swap_counter++;
            }
        }
        if (swap_counter == 0)
        {
            return;
        }
    }

    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    for (int i = 0; i < candidate_count - 1; i++)
    {
        locked[pairs[i].winner][pairs[i].loser] = true;
    }

    for (int i = candidate_count - 1; i < pair_count; i++)
    {
        for (int z = 0; z < candidate_count -1; z++)
        {
            if (pairs[i].winner == pairs[z].winner)
            {
                locked[pairs[z].winner][pairs[z].loser] = true;
                break;
            }
        }
    }
    return;
}

// Print the winner of the election
void print_winner(void)
{
    int losers[candidate_count];
    losers_index = 0;

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


    for (int i = 0; i < losers_index+1; i++)
    {
        bool found = false;

        for (int z = 0; z < candidate_count; z++)
        {
            if (losers[i] == z)
            {
                found = true;
            }
        }
    }
}
