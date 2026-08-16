#include <stdbool.h>

/*@
    requires (1 <= (n) <= 1000 && 1 <= (m) <= 1000);
    requires 0 <= k <= n * m;
    ensures \result == true <==> ((k) == (n) * (m) || ((k) < (n) * (m) && (n) * (m) - (k) <= (n) + (m)));
*/
bool func(int n, int m, int k) {
    // Variable declarations at top of scope
    int product;
    bool result;

    product = n * m;
    
    //@ assert product <= 1000000;
    
    if (k == product) {
        result = true;
    } else if (k < product && product - k <= n + m) {
        result = true;
    } else {
        result = false;
    }
    
    return result;
}
