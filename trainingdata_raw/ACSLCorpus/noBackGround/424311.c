#include <stdbool.h>

/*@ requires -100 <= a <= 100;
    requires -100 <= b <= 100;
    requires -100 <= c <= 100;
    requires -100 <= d <= 100;
    ensures \result == true <==> (a <= c && d <= b) || (c <= a && b <= d);
*/
bool func(int a, int b, int c, int d)
{
    bool result;

    //@ assert -100 <= a <= 100 && -100 <= b <= 100 && -100 <= c <= 100 && -100 <= d <= 100;

    if (a <= c && d <= b)
    {
        //@ assert ((a) <= (c) && (d) <= (b));
        result = true;
    }
    else if (c <= a && b <= d)
    {
        //@ assert ((c) <= (a) && (b) <= (d));
        result = true;
    }
    else
    {
        //@ assert !((a) <= (c) && (d) <= (b)) && !((c) <= (a) && (b) <= (d));
        result = false;
    }

    //@ assert result == true <==> ((a) <= (c) && (d) <= (b)) || ((c) <= (a) && (b) <= (d));
    return result;
}
