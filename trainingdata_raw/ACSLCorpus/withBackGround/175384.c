#include <stdbool.h>

/*@ predicate is_even(integer x) = x % 2 == 0; */

/*@ lemma product_range: 
      \forall integer n, m; 
      1 <= n <= 10000 && 1 <= m <= 10000 ==> 
      1 <= n * m <= 100000000; */

/*@ requires 1 <= n <= 10000;
    requires 1 <= m <= 10000;
    ensures \result == (bool)((n * m) % 2 == 0);
    assigns \nothing;
 */
bool func(unsigned int n, unsigned int m)
{
    //@ assert 1 <= n && n <= 10000;
    //@ assert 1 <= m && m <= 10000;
    //@ assert 1 <= n * m && n * m <= 100000000;
    return (n * m) % 2 == 0;
}

/*@ assigns \nothing; */
int main()
{
    return 0;
}
