#include <stdbool.h>

/*@
    requires 0 <= a <= 123;
    requires 0 <= b <= 123;
    requires 0 <= c <= 123;
    requires 0 <= d <= 123;
    requires 0 <= e <= 123;
    requires 0 <= k <= 123;
    requires ((a) < (b) && (b) < (c) && (c) < (d) && (d) < (e));
    ensures \result == true <==> (e - a <= k);
*/
bool func(int a, int b, int c, int d, int e, int k)
{
    int max_val;
    int min_val;
    int diff_val;

    //@ assert ((a) < (b) && (b) < (c) && (c) < (d) && (d) < (e));
    //@ assert e - a >= 0;

    if (a > e) {
        max_val = a;
        min_val = e;
    } else {
        max_val = e;
        min_val = a;
    }

    //@ assert max_val == (((a) > (e)) ? (a) : (e));
    //@ assert min_val == (((a) < (e)) ? (a) : (e));

    diff_val = max_val - min_val;

    //@ assert diff_val == (((((a)) > ((e))) ? ((a)) : ((e))) - ((((a)) < ((e))) ? ((a)) : ((e))));
    //@ assert diff_val == e - a;

    if (diff_val <= k) {
        //@ assert e - a <= k;
        return true;
    } else {
        //@ assert diff_val > k;
        //@ assert e - a > k;
        return false;
    }
}
