#include <stdbool.h>

/*@
    predicate valid_input(integer a, integer b, integer h) =
        1 <= a <= 100 &&
        1 <= b <= 100 &&
        1 <= h <= 100 &&
        h % 2 == 0;

    logic integer product(integer a, integer b, integer h) = (a + b) * h;

    lemma product_bounds:
        \forall integer a, b, h;
        valid_input(a, b, h) ==>
        1 * 1 <= product(a, b, h) <= 200 * 100;

    lemma division_property:
        \forall integer a, b, h, p, r;
        valid_input(a, b, h) && p == product(a, b, h) && r == p / 2 ==>
        r * 2 == p;
*/

/*@
    requires valid_input(a, b, h);
    ensures \result == ((a + b) * h / 2);
    assigns \nothing;
*/
int func(int a, int b, int h)
{
    int sum;
    int product;
    int half;
    int result;
    int temp;

    //@ assert valid_input(a, b, h);
    
    sum = a + b;
    
    //@ assert 1 * 1 <= (a + b) * h <= 200 * 100;
    
    product = sum * h;
    half = 2;
    result = 0;
    temp = product;

    /*@
        loop invariant 1 <= a <= 100;
        loop invariant 1 <= b <= 100;
        loop invariant 1 <= h <= 100;
        loop invariant h % 2 == 0;
        loop invariant temp >= 0;
        loop invariant temp <= product;
        loop invariant result * 2 == product - temp;
        loop invariant 1 * 1 <= (a + b) * h <= 200 * 100;
        loop invariant product <= 20000;
        loop invariant product >= 1 * 1;
        loop invariant result <= (200 * 100) / 2;
        loop assigns temp, result;
        loop variant temp;
    */
    while (temp >= half)
    {
        //@ assert temp >= half;
        
        temp -= half;
        result += 1;
        
        //@ assert result * 2 == product - temp;
    }

    //@ assert result == ((a + b) * h / 2);
    
    return result;
}
