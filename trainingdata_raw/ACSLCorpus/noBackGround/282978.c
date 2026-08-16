#include <stdbool.h>

/*@
  requires (1 <= (k) && (k) <= 100) && (1 <= (x) && (x) <= 100000);
  ensures \result == ((500 * (k)) >= x);
  assigns \nothing;
*/
bool func(int k, int x) {
    int target;
    bool result;
    
    //@ assert (1 <= (k) && (k) <= 100);
    //@ assert (1 <= (x) && (x) <= 100000);
    
    target = 500 * k;
    
    //@ assert target == (500 * (k));
    //@ assert target <= 50000;
    
    result = (target >= x);
    
    //@ assert result == ((500 * (k)) >= x);
    
    return result;
}
