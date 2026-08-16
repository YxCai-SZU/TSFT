#include <stdbool.h>

/*@
  requires \valid_read(v + (0..1));
  requires (1 <= (v[0]) <= 100 && 0 <= (v[1]) <= 4111);
  ensures \result == (((v[0]) * 500 - (v[1])) >= 0);
*/
bool func(const int* v) {
    int x;
    
    //@ assert (1 <= (v[0]) <= 100 && 0 <= (v[1]) <= 4111);
    x = v[0] * 500 - v[1];
    
    if (x < 0) {
        //@ assert ((v[0]) * 500 - (v[1])) < 0;
        return false;
    } else {
        //@ assert ((v[0]) * 500 - (v[1])) >= 0;
        return true;
    }
}
