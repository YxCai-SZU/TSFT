#include <stdbool.h>

/*@
    requires (1 <= (A) && (A) <= 10 &&
        1 <= (B) && (B) <= 10 &&
        1 <= (C) && (C) <= 10);
    ensures \result == true <==> (((A) == 5 && (B) == 5 && (C) == 7) ||
        ((A) == 5 && (B) == 7 && (C) == 5) ||
        ((A) == 7 && (B) == 5 && (C) == 5));
    assigns \nothing;
*/
bool func(unsigned int A, unsigned int B, unsigned int C)
{
    unsigned int five = 0;
    unsigned int seven = 0;

    //@ assert (1 <= (A) && (A) <= 10 &&         1 <= (B) && (B) <= 10 &&         1 <= (C) && (C) <= 10);

    if (A == 5) {
        five += 1;
    }
    if (A == 7) {
        seven += 1;
    }
    if (B == 5) {
        five += 1;
    }
    if (B == 7) {
        seven += 1;
    }
    if (C == 5) {
        five += 1;
    }
    if (C == 7) {
        seven += 1;
    }

    //@ assert five == (((A) == 5 ? 1 : 0) + ((B) == 5 ? 1 : 0) + ((C) == 5 ? 1 : 0));
    //@ assert seven == (((A) == 7 ? 1 : 0) + ((B) == 7 ? 1 : 0) + ((C) == 7 ? 1 : 0));

    if (five == 2 && seven == 1) {
        //@ assert (((A) == 5 && (B) == 5 && (C) == 7) ||         ((A) == 5 && (B) == 7 && (C) == 5) ||         ((A) == 7 && (B) == 5 && (C) == 5));
        return true;
    } else {
        //@ assert !(((A) == 5 && (B) == 5 && (C) == 7) ||         ((A) == 5 && (B) == 7 && (C) == 5) ||         ((A) == 7 && (B) == 5 && (C) == 5));
        return false;
    }
}
