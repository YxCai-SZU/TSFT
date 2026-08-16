#include <stdint.h>

/*@
    logic integer sum_n(integer n) = n * (n + 1) / 2;

    lemma sum_n_properties:
        \forall integer n; n >= 0 ==>
            sum_n(n) >= 0 &&
            sum_n(n) <= n * (n + 1) &&
            sum_n(n) == n * (n + 1) / 2;
*/

int main() {
    return 0;
}
