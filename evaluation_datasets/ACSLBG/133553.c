#include <limits.h>

/*@
    predicate valid_range(integer v) = 1 <= v <= 100;

    logic integer product(integer x, integer y) = x * y;

    lemma product_bound: \forall integer x, y; 
        valid_range(x) && valid_range(y) ==> product(x, y) <= 10000;
*/


int func(int a, int b, int c, int d)
{
    // Variable declarations at scope top
    int product1;
    int product2;
    int result;

    //@ assert valid_range(a);
    //@ assert valid_range(b);
    //@ assert valid_range(c);
    //@ assert valid_range(d);

    //@ assert product(a, b) <= 10000;
    //@ assert product(c, d) <= 10000;

    product1 = a * b;
    product2 = c * d;

    if (product1 > product2)
    {
        //@ assert product1 == product(a, b);
        //@ assert product2 == product(c, d);
        //@ assert product1 > product2;
        //@ assert product1 >= product(a, b) && product1 >= product(c, d);
        result = product1;
    }
    else
    {
        //@ assert product1 == product(a, b);
        //@ assert product2 == product(c, d);
        //@ assert product1 <= product2;
        //@ assert product2 >= product(a, b) && product2 >= product(c, d);
        result = product2;
    }

    return result;
}
