#include <stdbool.h>

/*@
    requires ((5) == 5 &&
        \forall integer i; 0 <= i < (5) ==> 0 <= (v)[i] && (v)[i] <= 123 &&
        (v)[0] < (v)[1] && (v)[1] < (v)[2] && (v)[2] < (v)[3] && (v)[3] < (v)[4]);
    requires 0 <= k && k <= 123;
    ensures \result == true <==> (v[4] - v[0] <= k);
*/
bool func(int *v, int k)
{
    int diff;
    
    //@ assert v[0] < v[1] && v[1] < v[2] && v[2] < v[3] && v[3] < v[4];
    diff = v[4] - v[0];
    
    //@ assert diff == v[4] - v[0];
    
    if (diff <= k)
    {
        return true;
    }
    else
    {
        return false;
    }
}
