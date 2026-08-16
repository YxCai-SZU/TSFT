#include <stdbool.h>

/*@
    predicate valid_input(integer r, integer g, integer b) =
        1 <= r && r <= 9 &&
        1 <= g && g <= 9 &&
        1 <= b && b <= 9;

    logic integer compute_ans(integer r, integer g, integer b) =
        r * 100 + g * 10 + b;

    lemma ans_mod_preserved:
        \forall integer ans, temp_ans;
        ans >= 0 && temp_ans >= 0 && temp_ans <= ans &&
        (ans - temp_ans) % 4 == 0 ==>
        ans % 4 == temp_ans % 4;
*/

/*@
    requires valid_input(r, g, b);
    ensures \result == (compute_ans(r, g, b) % 4 == 0);
*/
bool func(unsigned int r, unsigned int g, unsigned int b)
{
    unsigned int ans;
    bool is_divisible_by_4;
    unsigned int temp_ans;

    //@ assert valid_input(r, g, b);
    
    ans = r * 100 + g * 10 + b;
    is_divisible_by_4 = false;
    temp_ans = ans;

    /*@
        loop invariant 1 <= r && r <= 9;
        loop invariant 1 <= g && g <= 9;
        loop invariant 1 <= b && b <= 9;
        loop invariant 0 <= temp_ans;
        loop invariant temp_ans <= ans;
        loop invariant ans == r * 100 + g * 10 + b;
        loop invariant ans % 4 == temp_ans % 4;
        loop assigns temp_ans;
    */
    while (temp_ans >= 4)
    {
        temp_ans -= 4;
    }

    //@ assert ans % 4 == temp_ans % 4;
    
    if (temp_ans == 0)
    {
        is_divisible_by_4 = true;
    }

    //@ assert ans % 4 == 0 ==> is_divisible_by_4;
    
    return is_divisible_by_4;
}
