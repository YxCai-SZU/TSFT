#include <stdint.h>

/*@
    predicate bounds_1(integer x, integer y) = 0 <= x <= 8 && 0 <= y <= 8;
    predicate bounds_2(integer x, integer y) = 0 <= x <= 16 && 0 <= y <= 16;
    predicate bounds_3(integer x, integer y) = 0 <= x <= 100 && 0 <= y <= 100;
    predicate bounds_4(integer x, integer y) = 0 <= x <= 1000 && 0 <= y <= 1000;
    predicate bounds_5(integer x, integer y) = 0 <= x <= 10000 && 0 <= y <= 10000;
    predicate bounds_6(integer x, integer y) = 0 <= x <= 100000 && 0 <= y <= 100000;
    predicate bounds_7(integer x, integer y) = 0 <= x <= 1000000 && 0 <= y <= 1000000;
    predicate bounds_8(integer x, integer y) = 0 <= x <= 10000000 && 0 <= y <= 10000000;
    predicate bounds_9(integer x, integer y) = 0 <= x <= 100000000 && 0 <= y <= 100000000;
    predicate bounds_10(integer x, integer y) = 0 <= x <= 1000000000 && 0 <= y <= 1000000000;

    lemma nonlinear_arith_example_1: \forall integer x, y; bounds_1(x, y) ==> x * y <= 64;
    lemma nonlinear_arith_example_2: \forall integer x, y; bounds_2(x, y) ==> x * y <= 256;
    lemma nonlinear_arith_example_3: \forall integer x, y; bounds_3(x, y) ==> x * y <= 10000;
    lemma nonlinear_arith_example_4: \forall integer x, y; bounds_4(x, y) ==> x * y <= 1000000;
    lemma nonlinear_arith_example_5: \forall integer x, y; bounds_5(x, y) ==> x * y <= 100000000;
    lemma nonlinear_arith_example_6: \forall integer x, y; bounds_6(x, y) ==> x * y <= 10000000000;
    lemma nonlinear_arith_example_7: \forall integer x, y; bounds_7(x, y) ==> x * y <= 1000000000000;
    lemma nonlinear_arith_example_8: \forall integer x, y; bounds_8(x, y) ==> x * y <= 100000000000000;
    lemma nonlinear_arith_example_9: \forall integer x, y; bounds_9(x, y) ==> x * y <= 10000000000000000;
    lemma nonlinear_arith_example_10: \forall integer x, y; bounds_10(x, y) ==> x * y <= 1000000000000000000;
 */

/*@
    requires 0 <= x <= 8 && 0 <= y <= 8;
    ensures \result <= 64;
    assigns \nothing;
 */
uint32_t example_1(uint32_t x, uint32_t y)
{
    uint32_t product;
    product = x * y;
    //@ assert product <= 64;
    return product;
}

/*@
    requires 0 <= x <= 16 && 0 <= y <= 16;
    ensures \result <= 256;
    assigns \nothing;
 */
uint32_t example_2(uint32_t x, uint32_t y)
{
    uint32_t product;
    product = x * y;
    //@ assert product <= 256;
    return product;
}

/*@
    requires 0 <= x <= 100 && 0 <= y <= 100;
    ensures \result <= 10000;
    assigns \nothing;
 */
uint32_t example_3(uint32_t x, uint32_t y)
{
    uint32_t product;
    product = x * y;
    //@ assert product <= 10000;
    return product;
}

/*@
    requires 0 <= x <= 1000 && 0 <= y <= 1000;
    ensures \result <= 1000000;
    assigns \nothing;
 */
uint32_t example_4(uint32_t x, uint32_t y)
{
    uint32_t product;
    product = x * y;
    //@ assert product <= 1000000;
    return product;
}

/*@
    requires 0 <= x <= 10000 && 0 <= y <= 10000;
    ensures \result <= 100000000;
    assigns \nothing;
 */
uint32_t example_5(uint32_t x, uint32_t y)
{
    uint32_t product;
    product = x * y;
    //@ assert product <= 100000000;
    return product;
}

/*@
    requires 0 <= x <= 100000 && 0 <= y <= 100000;
    ensures \result <= 10000000000;
    assigns \nothing;
 */
uint64_t example_6(uint32_t x, uint32_t y)
{
    uint64_t product;
    product = (uint64_t)x * (uint64_t)y;
    //@ assert product <= 10000000000;
    return product;
}

/*@
    requires 0 <= x <= 1000000 && 0 <= y <= 1000000;
    ensures \result <= 1000000000000;
    assigns \nothing;
 */
uint64_t example_7(uint32_t x, uint32_t y)
{
    uint64_t product;
    product = (uint64_t)x * (uint64_t)y;
    //@ assert product <= 1000000000000;
    return product;
}

/*@
    requires 0 <= x <= 10000000 && 0 <= y <= 10000000;
    ensures \result <= 100000000000000;
    assigns \nothing;
 */
uint64_t example_8(uint32_t x, uint32_t y)
{
    uint64_t product;
    product = (uint64_t)x * (uint64_t)y;
    //@ assert product <= 100000000000000;
    return product;
}

/*@
    requires 0 <= x <= 100000000 && 0 <= y <= 100000000;
    ensures \result <= 10000000000000000;
    assigns \nothing;
 */
uint64_t example_9(uint32_t x, uint32_t y)
{
    uint64_t product;
    product = (uint64_t)x * (uint64_t)y;
    //@ assert product <= 10000000000000000;
    return product;
}

/*@
    requires 0 <= x <= 1000000000 && 0 <= y <= 1000000000;
    ensures \result <= 1000000000000000000;
    assigns \nothing;
 */
uint64_t example_10(uint32_t x, uint32_t y)
{
    uint64_t product;
    product = (uint64_t)x * (uint64_t)y;
    //@ assert product <= 1000000000000000000;
    return product;
}
