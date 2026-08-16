#include <stdbool.h>

/*@ predicate valid_range(integer x) = 1 <= x && x <= 13; */

/*@
    requires valid_range(A) && valid_range(B) && valid_range(C);
    ensures \result == true <==> A + B + C >= 22;
    assigns \nothing;
*/
bool func(unsigned long A, unsigned long B, unsigned long C) {
    bool ans = false;
    unsigned long sum = 0;
    
    sum = A + B + C;
    
    if (sum >= 22) {
        ans = true;
    } else {
        ans = false;
    }
    
    //@ assert ans == true <==> A + B + C >= 22;
    
    return ans;
}
