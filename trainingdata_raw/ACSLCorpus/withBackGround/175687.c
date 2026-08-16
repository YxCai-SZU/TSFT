#include <limits.h>

/*@
    predicate bounds(integer a, integer b) =
        -100 <= a <= 100 && -100 <= b <= 100;

    predicate product_in_range(integer a, integer b) =
        -10000 <= a * b <= 10000;

    lemma product_range_lemma:
        \forall integer a, b; bounds(a, b) ==> product_in_range(a, b);
*/

/*@
    requires bounds(a, b);
    ensures \result == a + b || \result == a - b || \result == a * b;
    ensures \result >= a + b;
    ensures \result >= a - b;
    ensures \result >= a * b;
    assigns \nothing;
*/
int func(int a, int b)
{
    //@ assert bounds(a, b);
    //@ assert product_in_range(a, b);
    
    int product = a * b;
    int sum = a + b;
    int difference = a - b;
    
    if (product > sum && product > difference)
    {
        //@ assert product >= a + b;
        //@ assert product >= a - b;
        //@ assert product >= a * b;
        return product;
    }
    else if (sum > difference)
    {
        //@ assert sum >= a + b;
        //@ assert sum >= a - b;
        //@ assert sum >= a * b;
        return sum;
    }
    else
    {
        //@ assert difference >= a + b;
        //@ assert difference >= a - b;
        //@ assert difference >= a * b;
        return difference;
    }
}
