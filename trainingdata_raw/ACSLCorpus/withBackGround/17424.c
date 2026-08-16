/*@
    predicate valid_range(integer x) = -100 <= x <= 100;

    predicate cond_AB(integer a, integer b, integer c) = a == b && a != c;
    predicate cond_BC(integer a, integer b, integer c) = b == c && a != b;
    predicate cond_AC(integer a, integer b, integer c) = a == c && a != b;

    lemma range_preserved:
        \forall integer a, b, c;
        valid_range(a) && valid_range(b) && valid_range(c) ==>
        valid_range(a) && valid_range(b) && valid_range(c);
*/

#include <stdbool.h>

/*@
    requires valid_range(A) && valid_range(B) && valid_range(C);
    ensures cond_AB(A,B,C) ==> \result == C;
    ensures cond_BC(A,B,C) ==> \result == A;
    ensures cond_AC(A,B,C) ==> \result == B;
    ensures !cond_AB(A,B,C) && !cond_BC(A,B,C) && !cond_AC(A,B,C) ==> \result == A;
*/
int func(int A, int B, int C)
{
    int result;
    int i;

    //@ assert valid_range(A) && valid_range(B) && valid_range(C);
    
    if (A == B && A != C) {
        result = C;
        //@ assert cond_AB(A,B,C);
        return result;
    } else if (B == C && A != B) {
        result = A;
        //@ assert cond_BC(A,B,C);
        return result;
    } else if (A == C && A != B) {
        result = B;
        //@ assert cond_AC(A,B,C);
        return result;
    } else {
        i = 0;
        /*@
            loop invariant 0 <= i <= 10;
            loop assigns i;
        */
        while (i < 10) {
            if (i > 5) {
                // Do something when i is greater than 5
            } else {
                // Do something when i is less than or equal to 5
            }
            i = i + 1;
        }
        //@ assert valid_range(A) && valid_range(B) && valid_range(C);
        result = A;
        //@ assert !cond_AB(A,B,C) && !cond_BC(A,B,C) && !cond_AC(A,B,C);
        return result;
    }
}
