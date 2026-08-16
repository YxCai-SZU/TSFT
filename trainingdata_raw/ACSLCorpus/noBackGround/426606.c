#include <stdbool.h>

/*@
    requires (1 <= (A) <= 100) && (1 <= (B) <= 100) && (1 <= (C) <= 100);
    ensures \result == true <==> (((A) * (B)) / 2) >= C;
    assigns \nothing;
*/
bool func(unsigned int A, unsigned int B, unsigned int C)
{
    // Variable declarations at scope top
    unsigned int product_div_2;
    bool result;

    // Precondition assertions
    //@ assert (1 <= (A) <= 100);
    //@ assert (1 <= (B) <= 100);
    //@ assert (1 <= (C) <= 100);

    // Product bound verification
    //@ assert A * B <= 10000;

    product_div_2 = (A * B) / 2;
    result = (product_div_2 >= C);

    // Postcondition verification
    //@ assert result == true <==> (((A) * (B)) / 2) >= C;

    return result;
}
