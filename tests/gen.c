#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

int rnd(int n)
{
    return rand() % n;
}

int count_hashs(char ** str)
{
    int i = 0;
    int n = 0;
    int hashs = 0;

    while(i < 5)
    {
        n = 0;
        while(n < 5)
        {
            if (str[i][n] == '#')
                hashs++;
            n++;
        }
        i++;
    }
    return (hashs);
}

static int  check_hash(char *str, int i, int count)
{
    if ((i - 3) % 5 != 0 && str[i + 1] == '#')
        return (1);
    if (i % 5 != 0 && i < 15 && str[i + 4] == '#' && str[i - 1] == '#')
        return (1);
    if ((i  - 1) % 5 != 0 && i % 5 == 0 && i < 15 && str[i + 3] == '#' )
        if (str[i - 1] == '#')
            return (1);
    if (i < 15 && str[i + 5] == '#')
        return (1);
    if (count == 4)
        return (1);
    return (0);
}

int         check_piece(char *s)
{
    int         i;
    int         x;
    int         size;

    i = -1;
    x = 0;
    size = 0;
    while (s[++i])
    {
        if (s[i] == '.' && ++x > 4)
            return (0);
        else if (s[i] == '\n')
        {
            if (x == 4 || (x == 0 && i != 0 && (s[i + 1] == '\0')))
                x = 0;
            else
                return (0);
        }
        else if (s[i] == '#' && (++size > 4 || ++x > 4 || !check_hash(s, i, size)))
            return (0);
        else if (s[i] != '.' && s[i] != '#' && s[i] != '\n')
            return (0);
    }
    if (size != 4)
        return (0);
    return (1);
}


//-1 = invalid
//0  = wtf
//1 = valid
int generate_piece(int validity, int max)
{
    char *str[5];
    char piece[100];
    int result;

    piece[0] = '\0';

    int i = 0;
    str[0] = strdup("....\n");
    str[1] = strdup("....\n");
    str[2] = strdup("....\n");
    str[3] = strdup("....\n");
	if (!max)
		str[4] = strdup("\n");
	else
		str[4] = strdup("\0");

    while(count_hashs(str) < 4)
    {
        str[rnd(4)][rnd(4)] = '#';
    }
    i = 0;
    while(i < 5)
    {
        strcat(piece, str[i]);
        i++;
    }
    result = 0;
    result  +=  (validity == -1 && check_piece(piece) == 0);
    result  +=  (validity == 0);
    result  +=  (validity == 1 && check_piece(piece) == 1);

    if (result)
        printf("%s", piece);
    return (result);
}

int main(int ac, char **av)
{
    time_t t;
    int max = 0;
    int results = 0;
    srand((unsigned) time(&t));

    if (ac != 3)
    {
        printf("usage: \n");
        printf("./gen_pieces valid 10\n");
        printf("./gen_pieces invalid 10\n");
        printf("./gen_pieces wtf 10\n");
        return (1);
    }
    max = atoi(av[2]);

    if (strcmp(av[1], "invalid") == 0)
    {
        while(results < max)
            results += generate_piece(-1, (results == max - 1));
    }
    if (strcmp(av[1], "wtf") == 0)
    {
        while(results < max)
            results += generate_piece(0, (results == max - 1));
    }
    if (strcmp(av[1], "valid") == 0)
    {
        while(results < max)
            results += generate_piece(1, (results == max - 1));
    }
    return (0);
}
