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
    // Variable declarations at top of scope
    int product1;
    int product2;
    int result;

    //@ assert (1 <= (A) <= 10000);
    //@ assert (1 <= (B) <= 10000);
    //@ assert (1 <= (C) <= 10000);
    //@ assert (1 <= (D) <= 10000);

    //@ assert ((A) * (B)) <= INT_MAX;
    //@ assert ((C) * (D)) <= INT_MAX;

    product1 = A * B;
    product2 = C * D;

    if (product1 > product2)
    {
        //@ assert product1 >= ((A) * (B));
        //@ assert product1 >= ((C) * (D));
        result = product1;
    }
    else
    {
        //@ assert product2 >= ((A) * (B));
        //@ assert product2 >= ((C) * (D));
        result = product2;
    }

    return result;
}
