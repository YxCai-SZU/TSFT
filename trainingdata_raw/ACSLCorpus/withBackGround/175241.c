/*@
    predicate division_product_lemma(integer x, integer y) =
        y != 0 ==> (x / y) * y + x % y == x;

    lemma division_product:
        \forall integer x, y; y != 0 ==> (x / y) * y + x % y == x;

    logic integer mul_distributive_add(integer x, integer y, integer z) =
        x * (y + z);

    logic integer mul_distributive_add_result(integer x, integer y, integer z) =
        x * y + x * z;

    predicate mul_distributive_add_lemma(integer x, integer y, integer z) =
        mul_distributive_add(x, y, z) == mul_distributive_add_result(x, y, z);

    lemma mul_distributive_add_proof:
        \forall integer x, y, z; mul_distributive_add(x, y, z) == mul_distributive_add_result(x, y, z);
*/

#include <stdint.h>

/*@
    requires y != 0;
    ensures \result == (x / y) * y + x % y;
    ensures \result == x;
*/
uint32_t division_product(uint32_t x, uint32_t y) {
    //@ assert y != 0;
    uint32_t quotient = x / y;
    uint32_t remainder = x % y;
    uint32_t product = quotient * y;
    uint32_t sum = product + remainder;
    
    //@ assert sum == x;
    return sum;
}

/*@
    requires \true;
    ensures \result == x * (y + z);
    ensures \result == x * y + x * z;
*/
int mul_distributive_add(int x, int y, int z) {
    int sum_yz = y + z;
    int product_x_sum = x * sum_yz;
    int product_xy = x * y;
    int product_xz = x * z;
    int sum_products = product_xy + product_xz;
    
    //@ assert product_x_sum == sum_products;
    return product_x_sum;
}

/*@
    requires \true;
    ensures \result == x * (y + z);
    ensures \result == x * y + x * z;
*/
int mul_distributive_add2(int x, int y, int z) {
    int result = mul_distributive_add(x, y, z);
    return result;
}

/*@
    requires \true;
    ensures \result == x * (y + z);
    ensures \result == x * y + x * z;
*/
int mul_distributive_add3(int x, int y, int z) {
    int result = mul_distributive_add(x, y, z);
    return result;
}

int main() {
    return 0;
}
