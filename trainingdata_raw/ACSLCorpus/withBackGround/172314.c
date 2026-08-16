#include <stdint.h>

/*@
    predicate is_valid_range(integer x) = 1 <= x <= 100000;

    logic integer calculate_result(integer x) =
        (x / 500) * 1000 + (x % 500) / 5 * 5;

    lemma loop1_invariant_maintained:
        \forall integer x, temp_x, div_500;
        is_valid_range(x) && 0 <= temp_x <= x && temp_x == x - 500 * div_500 && div_500 >= 0
        ==> (temp_x >= 500 ==> is_valid_range(x) && 0 <= temp_x - 500 <= x && 
             temp_x - 500 == x - 500 * (div_500 + 1) && div_500 + 1 >= 0);

    lemma loop2_invariant_maintained:
        \forall integer x, mod_500, div_5;
        is_valid_range(x) && 0 <= mod_500 <= x % 500 && mod_500 == (x % 500) - 5 * div_5 && 
        div_5 >= 0 && div_5 <= (x % 500) / 5
        ==> (mod_500 >= 5 ==> is_valid_range(x) && 0 <= mod_500 - 5 <= x % 500 && 
             mod_500 - 5 == (x % 500) - 5 * (div_5 + 1) && div_5 + 1 >= 0 && 
             div_5 + 1 <= (x % 500) / 5);
*/

/*@
    requires is_valid_range(x);
    ensures \result == calculate_result(x);
*/
int64_t func(int64_t x)
{
    int64_t result = 0;
    int64_t temp_x = x;
    int64_t div_500 = 0;
    
    //@ ghost int64_t original_x = x;
    
    /*@
        loop invariant is_valid_range(original_x);
        loop invariant 0 <= temp_x <= original_x;
        loop invariant temp_x == original_x - 500 * div_500;
        loop invariant div_500 >= 0;
        loop assigns temp_x, div_500;
        loop variant temp_x;
    */
    while (temp_x >= 500)
    {
        //@ assert temp_x >= 500;
        temp_x -= 500;
        div_500 += 1;
    }
    
    result += div_500 * 1000;
    int64_t mod_500 = temp_x;
    int64_t div_5 = 0;
    
    /*@
        loop invariant is_valid_range(original_x);
        loop invariant 0 <= mod_500 <= original_x % 500;
        loop invariant mod_500 == (original_x % 500) - 5 * div_5;
        loop invariant div_5 >= 0;
        loop invariant div_5 <= (original_x % 500) / 5;
        loop assigns mod_500, div_5;
        loop variant mod_500;
    */
    while (mod_500 >= 5)
    {
        //@ assert mod_500 >= 5;
        mod_500 -= 5;
        div_5 += 1;
    }
    
    result += div_5 * 5;
    //@ assert result == calculate_result(original_x);
    return result;
}

int main()
{
    return 0;
}
