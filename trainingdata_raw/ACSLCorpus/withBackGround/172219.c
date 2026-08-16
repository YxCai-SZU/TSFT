#include <stdbool.h>

/*@
    predicate is_valid_range(integer x) = 1 <= x && x <= 9;
*/

/*@
    requires is_valid_range(A) && is_valid_range(B) && is_valid_range(C);
    ensures \result == ((A == B + 1 && B == C + 1) || (A == B && B == C + 1) || (A == B + 1 && B == C) || (A == B && B == C));
*/
bool func(unsigned int A, unsigned int B, unsigned int C)
{
    bool ans = false;
    //@ assert is_valid_range(A) && is_valid_range(B) && is_valid_range(C);
    
    if (A == B + 1 && B == C + 1) {
        ans = true;
    }
    if (A == B && B == C + 1) {
        ans = true;
    }
    if (A == B + 1 && B == C) {
        ans = true;
    }
    if (A == B && B == C) {
        ans = true;
    }
    
    //@ assert ans == ((A == B + 1 && B == C + 1) || (A == B && B == C + 1) || (A == B + 1 && B == C) || (A == B && B == C));
    return ans;
}
