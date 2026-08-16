#include <stdint.h>

/*@
    predicate valid_radius(integer r) = 1 <= r <= 100;

    logic integer circumference(integer r, integer pi) = r * 2 * pi;

    lemma circumference_bounds:
        \forall integer r, pi;
            valid_radius(r) && pi == 3 ==> circumference(r, pi) <= 600;
*/

/*@
    requires valid_radius(r);
    ensures \result == circumference(r, 3);
    assigns \nothing;
*/
int64_t func(int64_t r)
{
    int64_t pi_approx;
    int64_t circumference;

    // Variable declarations at top
    pi_approx = 3;
    circumference = r * 2 * pi_approx;

    //@ assert r * 2 <= 200;
    //@ assert circumference <= 600;

    return circumference;
}

/*@
    logic integer fibonacci(integer n) =
        n == 0 ? 0 :
        n == 1 ? 1 :
        fibonacci(n - 1) + fibonacci(n - 2);

    lemma fibonacci_10: fibonacci(10) == 55;
*/

/*@
    logic integer factorial(integer n) =
        n == 0 ? 1 :
        n * factorial(n - 1);

    lemma factorial_5: factorial(5) == 120;
*/

void test_fibonacci(void)
{
    //@ assert fibonacci(10) == 55;
}

void test_factorial(void)
{
    //@ assert factorial(5) == 120;
}

int main(void)
{
    return 0;
}
