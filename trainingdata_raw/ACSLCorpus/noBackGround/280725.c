#include <stdbool.h>

/*@ requires \valid(v + (0 .. 2));
    requires (\forall integer i; 0 <= i < (3) ==> (((v)[i]) == 0 || ((v)[i]) == 1));
    ensures \result == 1 <==> ((v)[0] == 1 && (v)[1] == 1 && (v)[2] == 0);
*/
bool func(int* v)
{
    //@ assert (\forall integer i; 0 <= i < (3) ==> (((v)[i]) == 0 || ((v)[i]) == 1));
    
    if (v[0] == 1 && v[1] == 1 && v[2] == 0) {
        //@ assert ((v)[0] == 1 && (v)[1] == 1 && (v)[2] == 0);
        return true;
    } else {
        //@ assert !((v)[0] == 1 && (v)[1] == 1 && (v)[2] == 0);
        return false;
    }
}
