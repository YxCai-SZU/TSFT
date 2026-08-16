#include <stdbool.h>

/*@
    requires (0 <= (a) <= 100);
    requires (0 <= (b) <= 100);
    requires (0 <= (x) <= 100);
    ensures \result == true <==> ((((x)) - ((a))) >= 0 && (((x)) - ((a))) <= (b));
*/
bool func(int a, int b, int x)
{
    int diff_val;

    diff_val = x - a;

    //@ assert (0 <= (a) <= 100) && (0 <= (b) <= 100) && (0 <= (x) <= 100);

    if (diff_val < 0 || diff_val > b)
    {
        //@ assert diff_val < 0 || diff_val > b;
        return false;
    }
    else
    {
        //@ assert diff_val >= 0 && diff_val <= b;
        return true;
    }
}
