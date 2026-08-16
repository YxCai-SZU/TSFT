#include <stdbool.h>

/*@ requires ((a) >= 0 && (b) >= 0 && (c) >= 0 && (d) >= 0 && (e) >= 0 && (k) >= 0 &&
       (a) < 123 && (b) < 123 && (c) < 123 && (d) < 123 && (e) < 123 && (k) < 123 &&
       (e) - (a) <= 123);
    requires ((a) <= (b) && (b) <= (c) && (c) <= (d) && (d) <= (e));
    ensures \result == (b - a <= k || c - a <= k || d - a <= k || e - a <= k);
    assigns \nothing;
*/
bool func(int a, int b, int c, int d, int e, int k) {
    bool result;
    
    //@ assert e - a <= 123;
    
    if (b - a <= k) {
        result = true;
    } else if (c - a <= k) {
        result = true;
    } else if (d - a <= k) {
        result = true;
    } else if (e - a <= k) {
        result = true;
    } else {
        result = false;
    }
    
    return result;
}
