#include <stdint.h>
#include <stdbool.h>

/*@
    predicate width_height_safe(unsigned long width, unsigned long height) =
        width <= 18446744073709551615UL / height;

    lemma nonlinear_arithmetic_example_1:
        \forall unsigned long width, height;
        width_height_safe(width, height) ==> width * height <= 18446744073709551615UL;

    lemma nonlinear_arithmetic_example_2:
        \forall unsigned long width, height;
        width_height_safe(width, height) ==> width * height <= 18446744073709551615UL;

    lemma nonlinear_arithmetic_example_3:
        \forall integer a, b;
        0 <= a && a <= 100 && 0 <= b && b <= 100 ==> a * b <= 10000;
*/

/*@
    requires width_height_safe(width, height);
    ensures \result == true;
*/
bool verify_multiplication_safety_1(unsigned long width, unsigned long height)
{
    //@ assert width_height_safe(width, height);
    //@ assert width * height <= 18446744073709551615UL;
    return true;
}

/*@
    requires width_height_safe(width, height);
    ensures \result == true;
*/
bool verify_multiplication_safety_2(unsigned long width, unsigned long height)
{
    //@ assert width_height_safe(width, height);
    //@ assert width * height <= 18446744073709551615UL;
    return true;
}

/*@
    requires 0 <= a && a <= 100;
    requires 0 <= b && b <= 100;
    ensures \result == true;
*/
bool verify_bounded_multiplication(int a, int b)
{
    //@ assert 0 <= a && a <= 100;
    //@ assert 0 <= b && b <= 100;
    //@ assert a * b <= 10000;
    return true;
}

int main()
{
    return 0;
}
