#include <stdbool.h>

/*@
    requires \valid(v + (0..2));
    requires ((3) == 3 &&
        \forall integer i; 0 <= i < (3) ==> (v)[i] <= 100);
    ensures \result == true ==> ((v[0]) + (v[1]) == (v[2]) || (v[1]) + (v[2]) == (v[0]) || (v[0]) + (v[2]) == (v[1]));
    ensures \result == false ==> !((v[0]) + (v[1]) == (v[2]) || (v[1]) + (v[2]) == (v[0]) || (v[0]) + (v[2]) == (v[1]));
*/
bool can_distribute_equally(int v[3])
{
    //@ assert ((3) == 3 &&         \forall integer i; 0 <= i < (3) ==> (v)[i] <= 100);
    
    bool result;
    result = (v[0] + v[1] == v[2]) || 
             (v[1] + v[2] == v[0]) || 
             (v[0] + v[2] == v[1]);
    
    //@ assert result == true ==> ((v[0]) + (v[1]) == (v[2]) || (v[1]) + (v[2]) == (v[0]) || (v[0]) + (v[2]) == (v[1]));
    
    return result;
}

int main()
{
    return 0;
}
