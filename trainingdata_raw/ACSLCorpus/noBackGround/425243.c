#include <stdbool.h>

/*@ requires \valid(v + (0..5));
    requires ((6) == 6 &&
    (v)[0] == 1 &&
    (v)[1] == 1 &&
    (v)[5] == 0 &&
    \forall integer i; 0 <= i < (6) ==> (((v)[i]) == 0 || ((v)[i]) == 1));
    ensures \result == 1 <==> (((v)[2] == 0 && (v)[3] == 0 && (v)[4] == 0) ||
    ((v)[2] == 0 && (v)[3] == 1 && (v)[4] == 1));
*/
bool func(int *v)
{
    bool result;
    
    //@ assert v[0] == 1;
    //@ assert v[1] == 1;
    //@ assert v[5] == 0;
    
    if (v[2] == 0 && v[3] == 0 && v[4] == 0)
    {
        //@ assert v[2] == 0 && v[3] == 0 && v[4] == 0;
        result = true;
    }
    else if (v[2] == 0 && v[3] == 1 && v[4] == 1)
    {
        //@ assert v[2] == 0 && v[3] == 1 && v[4] == 1;
        result = true;
    }
    else
    {
        result = false;
    }
    
    //@ assert result == 1 <==> (((v)[2] == 0 && (v)[3] == 0 && (v)[4] == 0) ||     ((v)[2] == 0 && (v)[3] == 1 && (v)[4] == 1));
    return result;
}
