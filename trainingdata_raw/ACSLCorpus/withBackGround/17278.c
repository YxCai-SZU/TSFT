#include <stdbool.h>

/*@ predicate X_in_range(integer x) = -40 <= x && x <= 40; */

/*@
    requires X_in_range(X);
    ensures \result == (X >= 30);
    assigns \nothing;
*/
bool func(int X) {
    bool result;
    int i;
    
    if (X >= 30) {
        result = true;
    } else {
        i = 0;
        /*@
            loop invariant 0 <= i <= 10000000;
            loop invariant X < 30;
            loop assigns i;
            loop variant 10000000 - i;
        */
        while (i < 10000000) {
            i = i + 1;
        }
        //@ assert X < 30;
        result = false;
    }
    
    return result;
}

int main() {
    return 0;
}
