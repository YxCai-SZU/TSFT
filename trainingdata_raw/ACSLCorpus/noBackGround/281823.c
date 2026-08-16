#include <limits.h>

/*@
    requires (1 <= (A) <= 10000 &&
        1 <= (B) <= 10000 &&
        1 <= (C) <= 10000 &&
        1 <= (D) <= 10000);
    ensures \result == ((A) * (B)) || \result == ((C) * (D));
    ensures \result >= ((A) * (B));
    ensures \result >= ((C) * (D));
    assigns \nothing;
*/
int func(int A, int B, int C, int D)
{
    // Variable declarations at scope top
    int result;
    int ab_product;
    int cd_product;

    //@ assert (1 <= (A) <= 10000 &&         1 <= (B) <= 10000 &&         1 <= (C) <= 10000 &&         1 <= (D) <= 10000);
    
    // Calculate products
    ab_product = A * B;
    cd_product = C * D;

    //@ assert ab_product == ((A) * (B));
    //@ assert cd_product == ((C) * (D));
    
    //@ assert ab_product >= ((A) * (B));
    //@ assert cd_product >= ((C) * (D));

    if (ab_product > cd_product) {
        result = ab_product;
    } else {
        result = cd_product;
    }

    //@ assert result == ((A) * (B)) || result == ((C) * (D));
    //@ assert result >= ((A) * (B));
    //@ assert result >= ((C) * (D));
    
    return result;
}

int main() {
    return 0;
}
