#include <stdbool.h>

/*@
    requires (1 <= (A) <= 10000) && (1 <= (B) <= 10000) && (1 <= (C) <= 10000) && (1 <= (D) <= 10000);
    ensures \result == true <==> (((A) * (B)) > ((C) * (D)));
    assigns \nothing;
*/
bool func(unsigned int A, unsigned int B, unsigned int C, unsigned int D)
{
    // Variable declarations at top of scope
    unsigned int ab_product;
    unsigned int cd_product;
    bool result;

    //@ assert (1 <= (A) <= 10000);
    //@ assert (1 <= (B) <= 10000);
    //@ assert (1 <= (C) <= 10000);
    //@ assert (1 <= (D) <= 10000);

    //@ assert ((A) * (B)) <= 100000000;
    ab_product = A * B;

    //@ assert ((C) * (D)) <= 100000000;
    cd_product = C * D;

    result = ab_product > cd_product;
    //@ assert result == (((A) * (B)) > ((C) * (D)));
    return result;
}
