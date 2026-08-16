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
    int result;
    long long prod_AB;
    long long prod_CD;

    // Precondition bounds check
    //@ assert (1 <= (A) <= 10000) && (1 <= (B) <= 10000) && (1 <= (C) <= 10000) && (1 <= (D) <= 10000);

    // Calculate products with overflow protection
    prod_AB = (long long)A * (long long)B;
    prod_CD = (long long)C * (long long)D;

    // Product bounds verification
    //@ assert prod_AB <= 10000LL * 10000LL;
    //@ assert prod_CD <= 10000LL * 10000LL;

    if (prod_AB < prod_CD)
    {
        result = (int)prod_CD;
        //@ assert result == ((C) * (D));
    }
    else
    {
        result = (int)prod_AB;
        //@ assert result == ((A) * (B));
    }

    // Postcondition verification
    //@ assert result >= ((A) * (B)) && result >= ((C) * (D));
    return result;
}
