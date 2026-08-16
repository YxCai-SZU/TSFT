#include <stdbool.h>

/*@
  requires \valid(v+(0..2));
  requires (1 <= (v[0]) && (v[0]) <= 13) && (1 <= (v[1]) && (v[1]) <= 13) && (1 <= (v[2]) && (v[2]) <= 13);
  ensures \result == (v[0] + v[1] + v[2] >= 22);
*/
bool func(unsigned int v[3]) {
    unsigned int n;
    
    n = v[0] + v[1] + v[2];
    
    //@ assert n == v[0] + v[1] + v[2];
    
    return n >= 22;
}
