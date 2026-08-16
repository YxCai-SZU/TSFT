#include <limits.h>

/*@
    requires (1 <= (A) <= 10000) && (1 <= (B) <= 10000) && (1 <= (C) <= 10000) && (1 <= (D) <= 10000);
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
    int max_value;

    // Precondition assertions
    //@ assert (1 <= (A) <= 10000);
    //@ assert (1 <= (B) <= 10000);
    //@ assert (1 <= (C) <= 10000);
    //@ assert (1 <= (D) <= 10000);

    // Overflow safety
    //@ assert ((A) * (B)) <= 100000000;
    //@ assert ((C) * (D)) <= 100000000;

    product1 = A * B;
    product2 = C * D;

    if (product1 > product2) {
        max_value = product1;
    } else {
        max_value = product2;
    }

    // Postcondition verification
    //@ assert max_value == ((A) * (B)) || max_value == ((C) * (D));
    //@ assert max_value >= ((A) * (B));
    //@ assert max_value >= ((C) * (D));

    return max_value;
}
