// https://www.geeksforgeeks.org/problems/mobile-numeric-keypad5456/1

/*
Ith looks easy but too much typing so i just copied the code from the above link
*/
// A Naive Recursive C program to count number of possible numbers
// of given length
#include <stdio.h>

// left, up, right, down move from current location
int row[] = {0, 0, -1, 0, 1};
int col[] = {0, -1, 0, 1, 0};

// Returns count of numbers of length n starting from key position
// (i, j) in a numeric keyboard.
int getCountUtil(char keypad[][3], int i, int j, int n)
{
    if (keypad == NULL || n <= 0)
        return 0;

    // From a given key, only one number is possible of length 1
    if (n == 1)
        return 1;

    int k = 0, move = 0, ro = 0, co = 0, totalCount = 0;

    // move left, up, right, down from current location and if
    // new location is valid, then get number count of length
    // (n-1) from that new position and add in count obtained so far
    for (move = 0; move < 5; move++)
    {
        ro = i + row[move];
        co = j + col[move];
        if (ro >= 0 && ro <= 3 && co >= 0 && co <= 2 &&
            keypad[ro][co] != '*' && keypad[ro][co] != '#')
        {
            totalCount += getCountUtil(keypad, ro, co, n - 1);
        }
    }

    return totalCount;
}

// Return count of all possible numbers of length n
// in a given numeric keyboard
int getCount(char keypad[][3], int n)
{
    // Base cases
    if (keypad == NULL || n <= 0)
        return 0;
    if (n == 1)
        return 10;

    int i = 0, j = 0, totalCount = 0;
    for (i = 0; i < 4; i++) // Loop on keypad row
    {
        for (j = 0; j < 3; j++) // Loop on keypad column
        {
            // Process for 0 to 9 digits
            if (keypad[i][j] != '*' && keypad[i][j] != '#')
            {
                // Get count when number is starting from key
                // position (i, j) and add in count obtained so far
                totalCount += getCountUtil(keypad, i, j, n);
            }
        }
    }
    return totalCount;
}

// Driver program to test above function
int main(int argc, char *argv[])
{
    char keypad[4][3] = {{'1', '2', '3'},
                         {'4', '5', '6'},
                         {'7', '8', '9'},
                         {'*', '0', '#'}};
    printf("Count for numbers of length %d: %dn \n", 1, getCount(keypad, 1));
    printf("Count for numbers of length %d: %dn \n", 2, getCount(keypad, 2));
    printf("Count for numbers of length %d: %dn \n", 3, getCount(keypad, 3));
    printf("Count for numbers of length %d: %dn \n", 4, getCount(keypad, 4));
    printf("Count for numbers of length %d: %dn", 5, getCount(keypad, 5));

    return 0;
}
