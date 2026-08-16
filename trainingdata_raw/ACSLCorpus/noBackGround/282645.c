#include <stdbool.h>

/*@
    requires (-1000 <= (a) <= 1000) && (-1000 <= (b) <= 1000) && (-1000 <= (c) <= 1000) && (-1000 <= (d) <= 1000);
    ensures \result == a * c || \result == a * d || \result == b * c || \result == b * d;
    ensures -1000000 <= \result <= 1000000;
*/
int func(int a, int b, int c, int d)
{
    int tmp[4];
    int max_value;
    int i;

    //@ assert (-1000000 <= (a) * (c) <= 1000000);
    tmp[0] = a * c;

    //@ assert (-1000000 <= (a) * (d) <= 1000000);
    tmp[1] = a * d;

    //@ assert (-1000000 <= (b) * (c) <= 1000000);
    tmp[2] = b * c;

    //@ assert (-1000000 <= (b) * (d) <= 1000000);
    tmp[3] = b * d;

    max_value = tmp[0];
    i = 1;

    /*@
        loop invariant 1 <= i <= 4;
        loop invariant \exists integer j; 0 <= j < i && max_value == tmp[j];
        loop invariant tmp[0] == a * c && tmp[1] == a * d && tmp[2] == b * c && tmp[3] == b * d;
        loop invariant (-1000000 <= (a) * (c) <= 1000000) && (-1000000 <= (a) * (d) <= 1000000) && (-1000000 <= (b) * (c) <= 1000000) && (-1000000 <= (b) * (d) <= 1000000);
        loop assigns i, max_value;
    */
    while (i < 4)
    {
        if (tmp[i] > max_value)
        {
            max_value = tmp[i];
        }
        i++;
    }

    return max_value;
}
