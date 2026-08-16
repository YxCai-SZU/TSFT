#include <limits.h>

/*@
    requires ((a) >= 1 && (a) <= 10000 &&
        (b) >= 1 && (b) <= 10000 &&
        (c) >= 1 && (c) <= 10000 &&
        (d) >= 1 && (d) <= 10000);
    ensures \result == ((a) * (b)) || \result == ((c) * (d));
    ensures \result >= 1 && \result <= 100000000;
    assigns \nothing;
*/
int func(int a, int b, int c, int d)
{
    int result;
    int ab_product;
    int cd_product;

    //@ assert ((a) >= 1 && (a) <= 10000 &&         (b) >= 1 && (b) <= 10000 &&         (c) >= 1 && (c) <= 10000 &&         (d) >= 1 && (d) <= 10000);
    
    ab_product = a * b;
    cd_product = c * d;

    //@ assert ab_product == ((a) * (b));
    //@ assert cd_product == ((c) * (d));
    
    //@ assert ab_product >= 1 && ab_product <= 100000000;
    //@ assert cd_product >= 1 && cd_product <= 100000000;

    if (ab_product > cd_product) {
        result = ab_product;
    } else {
        result = cd_product;
    }

    //@ assert result == ((a) * (b)) || result == ((c) * (d));
    //@ assert result >= 1 && result <= 100000000;
    
    return result;
}
