#include <limits.h>

/*@
    predicate in_range(integer a) = -100 <= a <= 100;
    
    logic integer max_of_three(integer x, integer y, integer z) =
        (x >= y && x >= z) ? x : ((y >= z) ? y : z);
    
    lemma max_property:
        \forall integer x, y, z;
            max_of_three(x, y, z) >= x &&
            max_of_three(x, y, z) >= y &&
            max_of_three(x, y, z) >= z;
*/

/*@
    requires in_range(a) && in_range(b);
    ensures \result == a + b || \result == a - b || \result == a * b;
    ensures \result >= a + b && \result >= a - b && \result >= a * b;
    assigns \nothing;
*/
int func(int a, int b) {
    int product;
    int sum;
    int difference;
    int result;
    
    //@ assert -10000 <= a * b <= 10000;
    
    product = a * b;
    sum = a + b;
    difference = a - b;
    
    if (product > sum && product > difference) {
        result = product;
    } else if (sum > difference) {
        result = sum;
    } else {
        result = difference;
    }
    
    //@ assert result == max_of_three(product, sum, difference);
    return result;
}
