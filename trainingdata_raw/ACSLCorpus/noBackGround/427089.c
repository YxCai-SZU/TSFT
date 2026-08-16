#include <limits.h>

/*@
    requires (2 <= (A) && (A) <= 100 &&
        2 <= (B) && (B) <= 100);
    ensures \result == (((A) - 1) * ((B) - 1));
    assigns \nothing;
*/
int func(int A, int B) {
    int result;
    
    //@ assert 1 <= A - 1 && A - 1 <= 99;
    //@ assert 1 <= B - 1 && B - 1 <= 99;
    //@ assert 1 <= (A - 1) * (B - 1) && (A - 1) * (B - 1) <= 9801;
    
    result = (A - 1) * (B - 1);
    
    //@ assert result == (((A) - 1) * ((B) - 1));
    return result;
}
