#include <stdbool.h>

/*@
    requires (1 <= (A) <= 100) && (1 <= (B) <= 100) && (1 <= (C) <= 100);
    ensures \result == (B - A == C - B);
*/
bool func(int A, int B, int C) {
    int diff1;
    int diff2;
    bool result;

    diff1 = B - A;
    diff2 = C - B;

    //@ assert diff1 == B - A && diff2 == C - B;
    //@ assert diff1 == diff2 || diff1 != diff2;

    result = (diff1 == diff2);
    return result;
}
