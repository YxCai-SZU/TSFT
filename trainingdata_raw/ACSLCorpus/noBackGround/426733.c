#include <limits.h>

/*@
    requires (1 <= (A) <= 10000) && (1 <= (B) <= 10000) && (1 <= (C) <= 10000) && (1 <= (D) <= 10000);
    ensures \result == A * B || \result == C * D;
    ensures \result >= A * B && \result >= C * D;
    assigns \nothing;
*/
int func(int A, int B, int C, int D)
{
    // Variable declarations at scope top
    int max_val;
    int ab_product;
    int cd_product;
    
    // Precondition verification
    //@ assert (1 <= (A) <= 10000) && (1 <= (B) <= 10000) && (1 <= (C) <= 10000) && (1 <= (D) <= 10000);
    
    // Calculate products
    ab_product = A * B;
    cd_product = C * D;
    
    // Apply product_bound lemma
    //@ assert ab_product <= 10000 * 10000;
    //@ assert cd_product <= 10000 * 10000;
    
    // Determine maximum
    if (ab_product > cd_product) {
        max_val = ab_product;
        //@ assert max_val == A * B;
    } else {
        max_val = cd_product;
        //@ assert max_val == C * D;
    }
    
    // Postcondition verification
    //@ assert max_val == A * B || max_val == C * D;
    //@ assert max_val >= A * B && max_val >= C * D;
    
    return max_val;
}

int main()
{
    // Empty main as in original
    return 0;
}
