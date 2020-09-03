// Libraries
#include <cs50.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

bool check(string c); //including function

int main(int argc, string argv[])
{
// Check if user gave a valid key
    if (argc != 2 || !check(argv[1]))
    {
        printf("Usage: ./ceasar key");
        return 1;
    }

    int k = atoi(argv[1]); //Shift argv[1] String to Int

    string t = get_string("plaintext: ");

    printf("ciphertext: ");

// Loop - check each char individually if it is part of the alphabet. If true --> apply 'K'
    for (int i = 0, len = strlen(t); i < len; i++)
    {
        if (isalpha(t[i]) && isupper(t[i]))
        {
            printf("%c", (t[i] - 65 + k) % 26 + 65);
        }
        else if (isalpha(t[i]) && islower(t[i]))
        {
            printf("%c", (t[i] - 97 + k) % 26 + 97);
        }
        else
        {
            printf("%c", t[i]);
        }
    }
    printf("\n");
}

// Functions

bool check(string c)
{
    for (int i = 0, len = strlen(c); i < len; i++)
    {
        if (isalpha(c[i]))
        {
            return false;
        }
    }
    return true;
} 
