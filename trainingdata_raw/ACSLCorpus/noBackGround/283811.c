#include <stdbool.h>

/*@
    requires (1 <= (a) <= 500 &&
        1 <= (b) <= 500 &&
        1 <= (c) <= 1000);
    ensures \result == (a + b >= c);
    assigns \nothing;
*/
bool func(int a, int b, int c)
{
    int sum;
    bool result;

    sum = a + b;
    if (sum >= c)
    {
        //@ assert ((a) + (b)) >= c;
        result = true;
    }
    else
    {
        //@ assert ((a) + (b)) < c;
        result = false;
    }
    return result;
}

/*@
    requires (1 <= (a) <= 500 &&
        1 <= (b) <= 500 &&
        1 <= (c) <= 1000);
    ensures \result == (a + b >= c);
    assigns \nothing;
*/
bool func2(int a, int b, int c)
{
    int sum;
    bool result;

    sum = a + b;
    if (sum >= c)
    {
        //@ assert ((a) + (b)) >= c;
        result = true;
    }
    else
    {
        //@ assert ((a) + (b)) < c;
        result = false;
    }
    return result;
}
