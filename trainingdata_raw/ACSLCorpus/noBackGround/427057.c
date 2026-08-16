#include <limits.h>

/*@
    requires (-1000 <= (a) <= 1000) && (-1000 <= (b) <= 1000);
    ensures \result == ((a) + (b)) || \result == ((a) * (b)) || \result == ((a) - (b));
    ensures \result >= ((a) + (b));
    ensures \result >= ((a) * (b));
    ensures \result >= ((a) - (b));
*/
int func(int a, int b) {
    int product1;
    int product2;
    int max_value;
    
    //@ assert (-1000 <= (a) <= 1000);
    //@ assert (-1000 <= (b) <= 1000);
    
    //@ assert -1000000 <= a * b <= 1000000;
    
    product1 = a * b;
    product2 = a - b;
    
    if (a + b > product1) {
        if (a + b > product2) {
            max_value = a + b;
        } else {
            max_value = product2;
        }
    } else if (product1 > product2) {
        max_value = product1;
    } else {
        max_value = product2;
    }
    
    //@ assert max_value >= a + b;
    //@ assert max_value >= a * b;
    //@ assert max_value >= a - b;
    
    return max_value;
}
