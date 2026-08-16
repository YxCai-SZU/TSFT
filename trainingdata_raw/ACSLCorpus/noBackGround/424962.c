#include <stdbool.h>

/*@
    requires ((1) <= (a) <= (500));
    requires ((1) <= (b) <= (500));
    requires ((1) <= (c) <= (1000));
    ensures \result == true <==> a + b >= c;
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    unsigned int max_val;
    unsigned int min_val;
    unsigned int diff;
    unsigned int sum_ab;

    sum_ab = a + b;

    //@ assert sum_ab == a + b;

    if (sum_ab > c)
    {
        max_val = sum_ab;
        //@ assert max_val == ((sum_ab) > (c) ? (sum_ab) : (c));
    }
    else
    {
        max_val = c;
        //@ assert max_val == ((sum_ab) > (c) ? (sum_ab) : (c));
    }

    if (sum_ab < c)
    {
        min_val = sum_ab;
        //@ assert min_val == ((sum_ab) < (c) ? (sum_ab) : (c));
    }
    else
    {
        min_val = c;
        //@ assert min_val == ((sum_ab) < (c) ? (sum_ab) : (c));
    }

    if (sum_ab > c)
    {
        diff = sum_ab - c;
        //@ assert diff == ((sum_ab) > (c) ? (sum_ab) - (c) : (c) - (sum_ab));
    }
    else
    {
        diff = c - sum_ab;
        //@ assert diff == ((sum_ab) > (c) ? (sum_ab) - (c) : (c) - (sum_ab));
    }

    //@ assert max_val - min_val == ((sum_ab) > (c) ? (sum_ab) : (c)) - ((sum_ab) < (c) ? (sum_ab) : (c));
    //@ assert diff == ((sum_ab) > (c) ? (sum_ab) - (c) : (c) - (sum_ab));

    if (max_val - min_val == diff)
    {
        //@ assert max_val - min_val == diff;
        return sum_ab >= c;
    }
    else
    {
        //@ assert max_val - min_val != diff;
        return false;
    }
}
