#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool areAnagrams(char *s, char *t)
{
    size_t a_len = strlen(s);
    size_t b_len = strlen(t);

    if (a_len != b_len)
        return false;

    int *lettersS = calloc(26, sizeof(int));
    int *lettersT = calloc(26, sizeof(int));

    for (int i = 0; i < a_len; i++)
    {
        lettersS[s[i] - 'a']++;
        lettersT[t[i] - 'a']++;
    }

    for (int i = 0; i < 24; i++)
    {
        if (lettersS[i] != lettersT[i])
            return false;
    }

    return true;
}