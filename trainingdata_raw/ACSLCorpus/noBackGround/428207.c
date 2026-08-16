#include <stdbool.h>

/*@ requires \valid(a+(0..4));
    requires (\forall integer i; 0 <= i < (5)-1 ==> (a)[i] < (a)[i+1]);
    requires (\forall integer i; 0 <= i < (5) ==> 0 <= (a)[i] <= 123);
    requires 0 <= k <= 123;
    ensures \result == true <==> a[4] - a[0] <= k;
    assigns \nothing;
*/
bool func(int *a, int k)
{
    int diff;
    bool result;

    //@ assert a[0] < a[1];
    //@ assert a[1] < a[2];
    //@ assert a[2] < a[3];
    //@ assert a[3] < a[4];
    
    diff = a[4] - a[0];
    result = diff <= k;
    
    //@ assert result == true <==> a[4] - a[0] <= k;
    return result;
}
