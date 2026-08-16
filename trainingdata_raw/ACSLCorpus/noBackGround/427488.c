#include <stdbool.h>

/*@
    requires a > -0x8000000000000000 && a < 0x8000000000000000;
    requires b > -0x8000000000000000 && b < 0x8000000000000000;
    requires c > -0x8000000000000000 && c < 0x8000000000000000;
    ensures \result == true <==> ((a) < (b) && (b) < (c));
*/
bool func(long long a, long long b, long long c)
{
    bool is_possible = false;

    //@ assert is_possible == false;

    if (a < b)
    {
        is_possible = true;
        //@ assert is_possible == true;
    }

    if (is_possible && b < c)
    {
        is_possible = true;
        //@ assert is_possible == true;
    }
    else
    {
        is_possible = false;
        //@ assert is_possible == false;
    }

    //@ assert is_possible == true <==> ((a) < (b) && (b) < (c));

    return is_possible;
}
