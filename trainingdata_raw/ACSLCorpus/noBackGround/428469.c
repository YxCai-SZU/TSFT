#include <stdbool.h>

/*@ requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    ensures \result == ((a < c && b > c) || (a > c && b < c));
    assigns \nothing;
*/
bool func(int a, int b, int c) {
    int min;
    int max;
    
    if (a < b) {
        min = a;
        max = b;
    } else {
        min = b;
        max = a;
    }
    
    //@ assert (((a) < (b) ==> (min) == (a) && (max) == (b)) &&       ((a) >= (b) ==> (min) == (b) && (max) == (a)));
    
    return (c > min && c < max);
}
