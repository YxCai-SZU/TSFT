#include <stdbool.h>

/*@ requires \valid(v+(0..5));
    requires ((6) == 6 &&
      \forall integer i; 0 <= i < (6) ==> (((v)[i]) == 0 || ((v)[i]) == 1 || ((v)[i]) == 2));
    ensures \result == true <==> ((v)[0] == 0 && (v)[1] == 1 && (v)[2] == 0 && 
      (v)[3] == 2 && (v)[4] == 1 && (v)[5] == 0);
*/
bool func(int *v)
{
    // Variable declarations at top of scope
    bool result;
    
    //@ assert ((6) == 6 &&       \forall integer i; 0 <= i < (6) ==> (((v)[i]) == 0 || ((v)[i]) == 1 || ((v)[i]) == 2));
    //@ assert v[0] == 0 || v[0] == 1 || v[0] == 2;
    //@ assert v[1] == 0 || v[1] == 1 || v[1] == 2;
    //@ assert v[2] == 0 || v[2] == 1 || v[2] == 2;
    //@ assert v[3] == 0 || v[3] == 1 || v[3] == 2;
    //@ assert v[4] == 0 || v[4] == 1 || v[4] == 2;
    //@ assert v[5] == 0 || v[5] == 1 || v[5] == 2;
    
    result = (v[0] == 0 && v[1] == 1 && v[2] == 0 && 
              v[3] == 2 && v[4] == 1 && v[5] == 0);
    
    //@ assert result == true <==> ((v)[0] == 0 && (v)[1] == 1 && (v)[2] == 0 &&        (v)[3] == 2 && (v)[4] == 1 && (v)[5] == 0);
    return result;
}
