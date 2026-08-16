#include <stdbool.h>

/*@
  requires \valid(l + (0..1));
  requires (1 <= (l[0]) <= 100);
  requires (1 <= (l[1]) <= 100);
  ensures \result == true <==> l[1] < l[0];
*/
bool func(int *l) {
    // Variable declarations at top of scope
    bool result;
    
    //@ assert (1 <= (l[0]) <= 100);
    //@ assert (1 <= (l[1]) <= 100);
    
    if (l[1] >= l[0]) {
        result = false;
    } else {
        result = true;
    }
    
    return result;
}
