#include <stdbool.h>

/*@ requires a <= b;
    ensures \result == (c >= a && c <= b);
*/
bool func(int a, int b, int c)
{
    int min_val;
    int max_val;

    //@ assert a <= b;

    if (a < b) {
        min_val = a;
    } else {
        min_val = b;
    }

    if (a > b) {
        max_val = a;
    } else {
        max_val = b;
    }

    //@ assert (((a) < (b) ==> (min_val) == (a)) && ((a) >= (b) ==> (min_val) == (b)));
    //@ assert (((a) > (b) ==> (max_val) == (a)) && ((a) <= (b) ==> (max_val) == (b)));
    //@ assert min_val <= max_val;

    if (c >= min_val && c <= max_val) {
        //@ assert c >= min_val && c <= max_val;
        return true;
    } else {
        //@ assert !(c >= min_val && c <= max_val);
        return false;
    }
}
