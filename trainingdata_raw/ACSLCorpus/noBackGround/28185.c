#include <stdbool.h>

/*@
    requires (1 <= (A) <= 9) && (1 <= (B) <= 9) && (1 <= (C) <= 9);
    ensures \result == (((B * 10 + C) % 4) < A);
*/
bool func(long A, long B, long C)
{
    // Variable declarations
    unsigned long B_unsigned;
    unsigned long C_unsigned;
    unsigned long A_unsigned;
    unsigned long temp;
    bool result;

    // Initial assignments
    B_unsigned = (unsigned long)B;
    C_unsigned = (unsigned long)C;
    A_unsigned = (unsigned long)A;
    temp = B_unsigned * 10 + C_unsigned;

    //@ assert 0 <= temp <= B_unsigned * 10 + C_unsigned;
    //@ assert temp % 4 == ((B_unsigned * 10 + C_unsigned) % 4);

    /*@
        loop invariant 0 <= temp <= B_unsigned * 10 + C_unsigned;
        loop invariant temp % 4 == ((B_unsigned * 10 + C_unsigned) % 4);
        loop assigns temp;
    */
    while (temp >= 4)
    {
        //@ assert temp >= 4;
        temp -= 4;
        //@ assert temp % 4 == ((B_unsigned * 10 + C_unsigned) % 4);
    }

    //@ assert temp == ((B_unsigned * 10 + C_unsigned) % 4);
    result = temp < A_unsigned;
    //@ assert result == (((B * 10 + C) % 4) < A);
    return result;
}
