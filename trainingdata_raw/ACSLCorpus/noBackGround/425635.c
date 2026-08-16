#include <limits.h>

/*@
    requires (1 <= (A) <= 10000) && (1 <= (B) <= 10000);
    requires (1 <= (C) <= 10000) && (1 <= (D) <= 10000);
    ensures \result == ((A) * (B)) || \result == ((C) * (D));
    ensures \result >= ((A) * (B));
    ensures \result >= ((C) * (D));
    assigns \nothing;
*/
int func(int A, int B, int C, int D)
{
    // Variable declarations at scope top
    int product1;
    int product2;
    int result;

    // Precondition verification
    //@ assert (1 <= (A) <= 10000);
    //@ assert (1 <= (B) <= 10000);
    //@ assert (1 <= (C) <= 10000);
    //@ assert (1 <= (D) <= 10000);

    // Product bounds verification
    //@ assert 1 <= ((A) * (B)) <= 10000 * 10000;
    product1 = A * B;

    //@ assert 1 <= ((C) * (D)) <= 10000 * 10000;
    product2 = C * D;

    // Manual max implementation
    if (product1 > product2) {
        result = product1;
    } else {
        result = product2;
    }

    // Postcondition verification
    //@ assert result == ((A) * (B)) || result == ((C) * (D));
    //@ assert result >= ((A) * (B));
    //@ assert result >= ((C) * (D));

    return result;
}
