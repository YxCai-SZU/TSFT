#include <stdbool.h>

/*@
    requires \valid(v + (0..2));
    requires ((3) == 3 &&
        \forall integer i; 0 <= i < (3) ==> 1 <= (v)[i] && (v)[i] <= 100);
    ensures \result == (v[1] < v[2] && v[2] < v[0]);
*/
bool func(int *v)
{
    bool condition;
    
    condition = (v[1] < v[2]) && (v[2] < v[0]);
    
    //@ assert condition == (v[1] < v[2] && v[2] < v[0]);
    
    return condition;
}
