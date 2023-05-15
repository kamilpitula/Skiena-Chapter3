#include <stddef.h>
#include <stdlib.h>

int areAnagrams(char *a, size_t a_len, char *b, size_t b_len)
{
    if (a_len != b_len)
        return 0;

    int *letters = calloc(24, sizeof(int));

    for (int i = 0; i < a_len; i++)
    {
        letters[a[i] - 'a']++;
        letters[b[i] - 'a']++;
    }

    for (int i = 0; i < 24; i++)
    {
        if (letters[i] % 2 != 0)
            return 0;
    }

    return 1;
}