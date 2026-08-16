#include <stdbool.h>

/*@ requires (1 <= (r) && (r) <= 100);
    ensures \result == (2 * 3 * (r)); */
int func(int r)
{
    int pi_approx = 3;
    int circumference;
    
    //@ assert (2 * 3 * (r)) == 2 * pi_approx * r;
    circumference = 2 * pi_approx * r;
    
    return circumference;
}

/*@ requires (1 <= (n) && (n) <= 100);
    ensures \result == n; */
int input_int_tuple(int n)
{
    return n;
}
