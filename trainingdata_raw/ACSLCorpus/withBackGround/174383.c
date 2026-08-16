#include <stdbool.h>

/*@ predicate is_ans(integer x, bool ans) = 
      ans == ((x / 100) * 100 <= x);
*/

/*@ requires 1 <= x <= 100000;
    ensures \result == ((x / 100) * 100 <= x);
    ensures is_ans(x, \result);
*/
bool func(unsigned int x) {
    unsigned int n;
    bool ans;
    
    n = x / 100;
    ans = false;
    
    if (n * 100 <= x) {
        ans = true;
    }
    
    //@ assert ans == ((x / 100) * 100 <= x);
    
    return ans;
}
