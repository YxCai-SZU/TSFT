#include <stdbool.h>
#include <stddef.h>

/*@
    predicate can_have_cats(integer a, integer b, integer x) =
        b >= x && a <= b - x;
 */

bool is_possible_to_have_x_cats(long a, long b, long x)
{
    long diff = b - a;
    
    //@ assert diff == b - a;
    
    if (diff >= x && a <= b - x)
    {
        //@ assert can_have_cats(a, b, x);
        return true;
    }
    else
    {
        //@ assert !can_have_cats(a, b, x);
        return false;
    }
}

/*@
    predicate is_valid_range(unsigned int *arr, integer len) =
        \valid(arr + (0 .. len-1));
*/

/*@
    logic integer seq_at(unsigned int *arr, integer idx) =
        arr[idx];
*/

/*@
    lemma product_lower_bound:
        \forall integer a, b;
            1 <= a <= 9 && 1 <= b <= 9 ==> a * b >= 1;
*/

/*@
    lemma product_upper_bound:
        \forall integer a, b;
            1 <= a <= 9 && 1 <= b <= 9 ==> a * b <= 81;
*/

bool func(unsigned int a, unsigned int b)
{
    //@ assert 1 <= a && a <= 9;
    //@ assert 1 <= b && b <= 9;
    //@ assert a * b >= 1;
    //@ assert a * b <= 81;
    return a * b >= 50;
}

bool can_move_cats_and_product_check(long a, long b, long x)
{
    bool can_cats = is_possible_to_have_x_cats(a, b, x);
    
    bool product_check = func((unsigned int)a, (unsigned int)b);
    
    //@ assert can_cats == (b - a >= x && a <= b - x);
    //@ assert product_check == (a * b >= 50);
    
    bool result = can_cats && product_check;
    
    //@ assert result == ((b - a >= x && a <= b - x) && (a * b >= 50));
    
    return result;
}
