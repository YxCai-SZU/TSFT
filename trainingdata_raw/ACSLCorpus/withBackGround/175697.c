#include <stdint.h>

/*@
    predicate valid_range(integer a) = 1 <= a && a <= 10;
    logic integer product(integer a, integer b) = a * b;
*/

/*@
    requires valid_range(a) && valid_range(b);
    ensures \result == product(a, b);
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b)
{
    //@ assert valid_range(a);
    //@ assert valid_range(b);
    //@ assert 1 <= product(a, b) && product(a, b) <= 100;
    return a * b;
}

/*@
    lemma nonlinear_arithmetic_example_1:
        \forall integer a, b, c, d;
            a > 0 && b > 0 && c > 0 && d > 0 ==>
            a * b * c * d == (a * b) * (c * d);
*/

/*@
    lemma nonlinear_arithmetic_example_2:
        \forall integer a, b, c, d;
            a > 0 && b > 0 && c > 0 && d > 0 ==>
            a * b * c * d == (a * b) * (c * d);
*/

/*@
    lemma nonlinear_arithmetic_example_3:
        \forall integer a, b, c, d;
            a > 0 && b > 0 && c > 0 && d > 0 ==>
            a * b * c * d == (a * b) * (c * d);
*/

/*@
    lemma nonlinear_arithmetic_example_4:
        \forall integer a, b, c, d;
            a > 0 && b > 0 && c > 0 && d > 0 ==>
            a * b * c * d == (a * b) * (c * d);
*/

/*@
    lemma nonlinear_arithmetic_example_5:
        \forall integer a, b, c, d;
            a > 0 && b > 0 && c > 0 && d > 0 ==>
            a * b * c * d == (a * b) * (c * d);
*/

/*@
    lemma nonlinear_arithmetic_example_6:
        \forall integer a, b, c, d;
            a > 0 && b > 0 && c > 0 && d > 0 ==>
            a * b * c * d == (a * b) * (c * d);
*/

/*@
    lemma nonlinear_arithmetic_example_7:
        \forall integer a, b, c, d;
            a > 0 && b > 0 && c > 0 && d > 0 ==>
            a * b * c * d == (a * b) * (c * d);
*/

/*@
    lemma nonlinear_arithmetic_example_8:
        \forall integer a, b, c, d;
            a > 0 && b > 0 && c > 0 && d > 0 ==>
            a * b * c * d == (a * b) * (c * d);
*/

/*@
    lemma nonlinear_arithmetic_example_9:
        \forall integer a, b, c, d;
            a > 0 && b > 0 && c > 0 && d > 0 ==>
            a * b * c * d == (a * b) * (c * d);
*/

/*@
    lemma nonlinear_arithmetic_example_10:
        \forall integer a, b, c, d;
            a > 0 && b > 0 && c > 0 && d > 0 ==>
            a * b * c * d == (a * b) * (c * d);
*/

int main()
{
    return 0;
}
