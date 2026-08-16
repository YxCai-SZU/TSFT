#include <stdbool.h>

/*@ requires (1 <= (n) && (n) <= 20 &&
      1 <= (aa) && (aa) <= 100 &&
      1 <= (bb) && (bb) <= 2000);
    ensures \result == ((n) * (aa)) || \result == bb;
    ensures \result <= bb;
    assigns \nothing;
*/
int func(int n, int aa, int bb) {
    int product;
    int result;

    //@ assert 1 <= n && n <= 20;
    //@ assert 1 <= aa && aa <= 100;
    //@ assert ((n) * (aa)) <= 2000;

    product = n * aa;
    
    if (product < bb) {
        result = product;
    } else {
        result = bb;
    }

    //@ assert result == ((n) * (aa)) || result == bb;
    //@ assert result <= bb;
    
    return result;
}
