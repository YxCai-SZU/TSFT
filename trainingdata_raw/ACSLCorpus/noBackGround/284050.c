#include <limits.h>

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    ensures \result == (((a) + (b)) * (c)) || \result == ((a) * (c) + (b)) || \result == ((a) * ((b) + (c)));
    assigns \nothing;
*/
int func(int a, int b, int c) {
    int product_1;
    int product_2;
    int product_3;
    int result;

    //@ assert (1 <= (a) <= 100);
    //@ assert (1 <= (b) <= 100);
    //@ assert (1 <= (c) <= 100);
    
    //@ assert 1 <= a + b <= 200;
    //@ assert 1 <= a * c <= 10000;
    //@ assert 1 <= b * c <= 10000;
    //@ assert 1 <= a * (b + c) <= 20000;
    //@ assert 1 <= (a + b) * c <= 20000;
    //@ assert 1 <= a * c + b <= 10100;

    product_1 = (a + b) * c;
    product_2 = a * c + b;
    product_3 = a * (b + c);

    if (product_1 < product_2 && product_1 < product_3) {
        result = product_1;
    } else if (product_2 < product_1 && product_2 < product_3) {
        result = product_2;
    } else {
        result = product_3;
    }

    //@ assert result == product_1 || result == product_2 || result == product_3;
    return result;
}
