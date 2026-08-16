#include <stdbool.h>

/*@
    predicate is_product(integer a, integer b, integer p) = p == a * b;
    predicate is_division(integer p, integer c, integer d) = d == -(p * c);
*/

/*@
    lemma distribute_integer_negation:
        \forall integer a, b, c; b == 3 && c == 4 ==> -(a * b) * c == -a * b * c;
*/

/*@
    requires a * b == 2;
    requires b == 3;
    requires c == 4;
    ensures \result == 2;
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int product;
    int division;

    product = a * b;
    //@ assert is_product(a, b, product);
    
    division = -(product * c);
    //@ assert is_division(product, c, division);
    
    return division;
}
