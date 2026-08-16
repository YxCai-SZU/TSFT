#include <limits.h>

/*@
    requires (1 <= (A) <= 10000);
    requires (1 <= (B) <= 10000);
    requires (1 <= (C) <= 10000);
    requires (1 <= (D) <= 10000);
    ensures \result == ((A) * (B)) || \result == ((C) * (D));
    ensures \result >= ((A) * (B));
    ensures \result >= ((C) * (D));
    assigns \nothing;
*/
int func(int A, int B, int C, int D)
{
    // Variable declarations at top of scope
    int max_val;
    long long product_AB;
    long long product_CD;

    // Precondition assertions
    //@ assert (1 <= (A) <= 10000);
    //@ assert (1 <= (B) <= 10000);
    //@ assert (1 <= (C) <= 10000);
    //@ assert (1 <= (D) <= 10000);

    // Overflow safety checks
    product_AB = (long long)A * (long long)B;
    product_CD = (long long)C * (long long)D;

    //@ assert product_AB == ((A) * (B));
    //@ assert product_CD == ((C) * (D));

    //@ assert product_AB <= 100000000LL;
    //@ assert product_CD <= 100000000LL;

    if (product_AB > product_CD)
    {
        max_val = (int)product_AB;
    }
    else
    {
        max_val = (int)product_CD;
    }

    // Postcondition verification
    //@ assert max_val == ((A) * (B)) || max_val == ((C) * (D));
    //@ assert max_val >= ((A) * (B));
    //@ assert max_val >= ((C) * (D));

    return max_val;
}
