#include <stdint.h>

/*@
    predicate is_valid_range(integer l) = 1 <= l <= 1000;

    logic integer cube(integer l) = l * l * l;

    lemma cube_bounds:
        \forall integer l; is_valid_range(l) ==> cube(l) <= 1000000000;

    lemma division_property:
        \forall integer l, integer ans, integer res;
            is_valid_range(l) && res >= 0 && ans >= 0 && 
            res == cube(l) - ans * 27 &&
            res < 27 ==>
            ans == cube(l) / 27;
*/

/*@
    requires is_valid_range(l);
    ensures \result == (l * l * l) / 27;
    assigns \nothing;
*/
int64_t func(int64_t l)
{
    int64_t res;
    int64_t ans;
    int64_t divisor;

    //@ assert l >= 1 && l <= 1000;
    
    //@ assert l * l <= 1000 * 1000;
    //@ assert l * l * l <= 1000 * 1000 * 1000;

    res = l * l * l;
    ans = 0;
    divisor = 27;

    /*@
        loop invariant 1 <= l <= 1000;
        loop invariant res >= 0;
        loop invariant ans >= 0;
        loop invariant res == cube(l) - ans * divisor;
        loop invariant ans * divisor <= cube(l);
        loop assigns res, ans;
        loop variant res;
    */
    while (res >= divisor)
    {
        //@ assert res >= divisor;
        res -= divisor;
        ans += 1;
        //@ assert res == cube(l) - ans * divisor;
    }

    //@ assert res == cube(l) - ans * divisor;
    //@ assert res < divisor;
    return ans;
}

/*@
    assigns \nothing;
*/
int main()
{
    return 0;
}
