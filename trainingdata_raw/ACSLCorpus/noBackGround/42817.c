#include <stdbool.h>

/*@
    requires \valid(a + (0..4));
    requires ((5) == 5 &&
        \forall integer i; 0 <= i < (5) ==> 0 <= (a)[i] <= 123 &&
        (a)[0] < (a)[1] && (a)[1] < (a)[2] && (a)[2] < (a)[3] && (a)[3] < (a)[4]);
    requires 0 <= k <= 123;
    ensures \result == true <==> (a[4] - a[0] <= k);
    assigns \nothing;
*/
bool func(int* a, int k)
{
    //@ assert ((5) == 5 &&         \forall integer i; 0 <= i < (5) ==> 0 <= (a)[i] <= 123 &&         (a)[0] < (a)[1] && (a)[1] < (a)[2] && (a)[2] < (a)[3] && (a)[3] < (a)[4]);
    //@ assert 0 <= k <= 123;
    
    if (a[4] - a[0] > k)
    {
        return false;
    }
    else
    {
        return true;
    }
}
