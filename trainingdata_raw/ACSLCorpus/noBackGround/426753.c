#include <stdbool.h>

/*@
    requires (1 <= (n) <= 100 &&
        1 <= (x) <= (n) * 100);
    ensures \result == (n * 100 >= x);
*/
bool func(int n, int x) {
    int n_i = 1;
    int total = 0;

    /*@
        loop invariant (1 <= (n_i) <= (n) + 1 &&
        (total) == ((n_i) - 1) * 100);
        loop assigns n_i, total;
    */
    while (n_i <= n) {
        total += 100;
        n_i += 1;
    }

    //@ assert total == n * 100;
    return total >= x;
}
