#include <stdint.h>

/*@
    logic integer multiply(integer a, integer b) = a * b;
    logic integer sum(integer x, integer y) = x + y;
    lemma check_sum_product:
        \forall integer x, y; 0 <= x <= 8 && 0 <= y <= 8 ==> multiply(x, y) <= 64;
    lemma check_sum:
        \forall integer x, y; x <= 100 && y <= 100 ==> sum(x, y) <= 200;
*/

int main() {
    return 0;
}
