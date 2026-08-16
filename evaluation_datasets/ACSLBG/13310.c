#include <limits.h>

/*@
    predicate valid_params(integer n, integer m) =
        1 <= n && n <= 100 &&
        1 <= m && m <= 100;

    logic integer product(integer n, integer m) = n * m;

    lemma product_bound: \forall integer n, m;
        valid_params(n, m) ==> product(n, m) <= 10000;
*/


int func(int n, int m)
{
    // Variable declarations at scope top
    int product;
    int result;
    int temp;
    int count;

    //@ assert valid_params(n, m);
    //@ assert product(n, m) <= 10000;

    product = n * m;
    result = 0;
    temp = product;
    count = 0;

    
    while (temp >= 2)
    {
        //@ assert temp >= 2;
        temp -= 2;
        count += 1;
    }

    result = count;
    //@ assert result == product / 2;
    //@ assert result >= 0;
    return result;
}
