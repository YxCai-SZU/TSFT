#include <limits.h>

/*@
    requires ((1 <= ((a)) && ((a)) <= 9) && (1 <= ((b)) && ((b)) <= 9) && (1 <= ((c)) && ((c)) <= 9));
    ensures (a < b && b < c) ==> \result == 1;
    ensures (a < b && b == c) ==> \result == 2;
    ensures (a < c && b > c) ==> \result == 3;
    ensures (b < a && a < c) ==> \result == 4;
    ensures (b < a && a == c) ==> \result == 5;
    ensures (b < c && a > c) ==> \result == 6;
    ensures (c < a && a < b) ==> \result == 7;
    ensures (c < a && a == b) ==> \result == 8;
    ensures (c < b && a > b) ==> \result == 9;
*/
long func(long a, long b, long c)
{
    long result = -1;

    //@ assert ((1 <= ((a)) && ((a)) <= 9) && (1 <= ((b)) && ((b)) <= 9) && (1 <= ((c)) && ((c)) <= 9));

    if (a < b && b < c)
    {
        result = 1;
        //@ assert result == 1;
    }
    else if (a < b && b == c)
    {
        result = 2;
        //@ assert result == 2;
    }
    else if (a < c && b > c)
    {
        result = 3;
        //@ assert result == 3;
    }
    else if (b < a && a < c)
    {
        result = 4;
        //@ assert result == 4;
    }
    else if (b < a && a == c)
    {
        result = 5;
        //@ assert result == 5;
    }
    else if (b < c && a > c)
    {
        result = 6;
        //@ assert result == 6;
    }
    else if (c < a && a < b)
    {
        result = 7;
        //@ assert result == 7;
    }
    else if (c < a && a == b)
    {
        result = 8;
        //@ assert result == 8;
    }
    else if (c < b && a > b)
    {
        result = 9;
        //@ assert result == 9;
    }

    //@ assert (a < b && b < c) ==> result == 1;
    //@ assert (a < b && b == c) ==> result == 2;
    //@ assert (a < c && b > c) ==> result == 3;
    //@ assert (b < a && a < c) ==> result == 4;
    //@ assert (b < a && a == c) ==> result == 5;
    //@ assert (b < c && a > c) ==> result == 6;
    //@ assert (c < a && a < b) ==> result == 7;
    //@ assert (c < a && a == b) ==> result == 8;
    //@ assert (c < b && a > b) ==> result == 9;

    return result;
}
