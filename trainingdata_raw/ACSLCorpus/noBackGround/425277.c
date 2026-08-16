#include <stdbool.h>

/*@
    requires (0 <= (a) && (a) <= 100) && (0 <= (b) && (b) <= 100);
    ensures \result == ((a) + (b)) || \result == ((a) * (b)) || \result == ((a) - (b));
    ensures \result >= 0;
    assigns \nothing;
*/
int func(int a, int b) {
    int sum;
    int product;
    int difference;
    int max_value;

    //@ assert (0 <= (a) && (a) <= 100) && (0 <= (b) && (b) <= 100);
    //@ assert 0 <= ((a) + (b)) && ((a) + (b)) <= 200;
    sum = a + b;

    //@ assert 0 <= ((a) * (b)) && ((a) * (b)) <= 10000;
    product = a * b;

    //@ assert ((a) - (b)) >= -100 && ((a) - (b)) <= 100;
    difference = a - b;

    max_value = sum;
    
    if (product > max_value) {
        max_value = product;
    }
    
    if (difference > max_value) {
        max_value = difference;
    }

    //@ assert max_value >= 0;
    return max_value;
}
