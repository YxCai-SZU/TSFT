#include <stdbool.h>

/*@
    requires (1 <= (A) && (A) <= 100 &&
        1 <= (B) && (B) <= 100 &&
        1 <= (C) && (C) <= 100);
    ensures \result == true <==> ((A) == (B) + (C) || (B) == (A) + (C) || (C) == (A) + (B));
    assigns \nothing;
*/
bool func(unsigned int A, unsigned int B, unsigned int C)
{
    bool result;

    //@ assert A + B <= 200;
    //@ assert A + C <= 200;
    //@ assert B + C <= 200;

    //@ assert ((A) == (B) + (C) || (B) == (A) + (C) || (C) == (A) + (B)) <==> (A == B + C || B == A + C || C == A + B);

    if (A == B + C || B == A + C || C == A + B) {
        //@ assert ((A) == (B) + (C) || (B) == (A) + (C) || (C) == (A) + (B));
        result = true;
    } else {
        //@ assert !((A) == (B) + (C) || (B) == (A) + (C) || (C) == (A) + (B));
        result = false;
    }

    return result;
}
