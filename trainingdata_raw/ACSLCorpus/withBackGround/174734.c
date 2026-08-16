/*@
    predicate is_even(integer n) = n % 2 == 0;
    predicate is_odd(integer n) = n % 2 != 0;
    predicate is_between(integer a, integer b, integer c) = a <= b && b <= c;
*/

/*@
    lemma even_10: is_even(10);
    lemma odd_5: is_odd(5);
    lemma between_10_15_20: is_between(10, 15, 20);
*/

#include <limits.h>

/*@
    requires 0 <= n <= 5;
    ensures \result == n * n;
    assigns \nothing;
*/
int func(int n)
{
    //@ assert 0 <= n && n <= 5;
    //@ assert 0 * 0 <= n * n && n * n <= 5 * 5;
    
    return n * n;
}

int main(void)
{
    //@ assert is_even(10);
    //@ assert is_odd(5);
    //@ assert is_between(10, 15, 20);
    
    return 0;
}
