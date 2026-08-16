#include <limits.h>

/*@
    requires (-1000 <= (a) <= 1000) && (-1000 <= (b) <= 1000);
    ensures \result == ((a) + (b)) || \result == ((a) * (b));
    ensures \result >= ((a) + (b));
    ensures \result >= ((a) * (b));
    assigns \nothing;
*/
int func(int a, int b) {
    int sum;
    int product;
    int result;
    
    //@ assert (-1000 <= (a) <= 1000) && (-1000 <= (b) <= 1000);
    //@ assert -1000000 <= a * b <= 1000000;
    
    sum = a + b;
    product = a * b;
    
    if (sum > product) {
        result = sum;
    } else {
        result = product;
    }
    
    //@ assert result == ((a) + (b)) || result == ((a) * (b));
    //@ assert result >= ((a) + (b));
    //@ assert result >= ((a) * (b));
    
    return result;
}
