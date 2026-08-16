#include <limits.h>

/*@
    predicate valid_range(integer a, integer b) =
        1 <= a <= 100 && 1 <= b <= 100;

    logic integer product_plus_one(integer a, integer b) = a * b + 1;

    lemma product_bounds: \forall integer a, b; valid_range(a, b) ==> 1 <= a * b <= 10000;
    lemma sum_bounds: \forall integer a, b; valid_range(a, b) ==> 1 <= product_plus_one(a, b) <= 10100;
*/

/*@
    requires valid_range(a, b);
    ensures \result == (a * b + 1) / 2;
    assigns \nothing;
*/
int func(int a, int b)
{
    // Variable declarations at top of scope
    int c;
    int result;
    int count;
    int temp_c;

    //@ assert valid_range(a, b);
    
    // Ensure no overflow in a * b
    //@ assert 1 <= a * b <= 10000;
    
    c = a * b + 1;
    result = 0;
    count = 0;
    temp_c = c;
    
    /*@
        loop invariant 1 <= a <= 100;
        loop invariant 1 <= b <= 100;
        loop invariant 0 <= temp_c <= a * b + 1;
        loop invariant temp_c + 2 * count == a * b + 1;
        loop invariant 0 < count ==> count <= (a * b + 1) / 2;
        loop assigns temp_c, count;
        loop variant temp_c;
    */
    while (temp_c >= 2)
    {
        temp_c -= 2;
        count += 1;
    }
    result = count;

    // Verify that c is the product of a and b plus 1
    //@ assert c == a * b + 1;
    
    // Verify the correctness of the division
    //@ assert result == (a * b + 1) / 2;
    
    // Ensure no overflow or underflow in the division result
    //@ assert 1 <= a * b + 1 <= 10100;
    
    return result;
}
