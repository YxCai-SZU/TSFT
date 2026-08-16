#include <stdint.h>

/*@
    predicate product_in_range(integer r, integer prod) =
        1 <= r <= 100 && prod == 2 * r * 314;

    predicate loop_invariant(integer r, integer pi, integer scale, 
                             integer product, integer result, 
                             integer remainder) =
        1 <= r <= 100 &&
        pi == 314 &&
        scale == 100 &&
        product == 2 * r * pi &&
        result * scale + remainder == product &&
        0 <= remainder &&
        remainder < product + scale;

    lemma loop_decreases:
        \forall integer remainder, scale; 
        scale > 0 ==> remainder >= scale ==> remainder - scale < remainder;
*/

/*@
    requires 1 <= r <= 100;
    ensures \result == 2 * r * 314 / 100;
    assigns \nothing;
*/
int64_t func(int64_t r)
{
    int64_t pi;
    int64_t scale;
    int64_t product;
    int64_t result;
    int64_t remainder;
    
    pi = 314;
    scale = 100;
    product = 2 * r * pi;
    
    //@ assert product_in_range(r, product);
    
    result = 0;
    remainder = product;
    
    /*@
        loop invariant loop_invariant(r, pi, scale, product, result, remainder);
        loop assigns result, remainder;
        loop variant remainder;
    */
    while (remainder >= scale)
    {
        //@ assert remainder >= scale;
        result += 1;
        remainder -= scale;
        //@ assert result * scale + remainder == product;
    }
    
    //@ assert result * scale + remainder == product;
    //@ assert remainder < scale;
    //@ assert result == 2 * r * 314 / 100;
    
    return result;
}
