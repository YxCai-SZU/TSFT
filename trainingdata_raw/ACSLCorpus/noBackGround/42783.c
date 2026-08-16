#include <stdbool.h>

/*@
  requires ((len) >= 3 &&
    \valid((v) + (0 .. 2)) &&
    1 <= (v)[0] && (v)[0] <= 100 &&
    1 <= (v)[1] && (v)[1] <= 100 &&
    1 <= (v)[2] && (v)[2] <= 100);
  ensures \result == (v[0] <= v[1] + v[2]);
*/
bool func(int *v, int len)
{
    bool result;
    
    //@ assert len >= 3;
    //@ assert 1 <= v[0] && v[0] <= 100;
    //@ assert 1 <= v[1] && v[1] <= 100;
    //@ assert 1 <= v[2] && v[2] <= 100;
    
    result = v[0] <= v[1] + v[2];
    
    return result;
}
