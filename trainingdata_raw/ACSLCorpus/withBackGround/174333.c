#include <stdbool.h>

/*@
    predicate valid_range(integer l) = 1 <= l <= 1000;
    
    logic integer cube(integer l) = l * l * l;
    
    lemma cube_bound: \forall integer l; valid_range(l) ==> cube(l) <= 1000000000;
    
    lemma division_property: \forall integer l, integer l_cubed, integer ans, integer divisor;
        valid_range(l) && divisor == 27 && l_cubed >= 0 && 
        l_cubed + ans * divisor == cube(l) ==> ans == (cube(l) - l_cubed) / divisor;
*/

/*@
    requires valid_range(l);
    ensures \result == (l * l * l) / 27;
    assigns \nothing;
*/
int func(int l)
{
    // Variable declarations at top of scope
    int l_cubed;
    int ans;
    int divisor;
    
    //@ assert 1 <= l && l <= 1000;
    
    //@ assert l * l <= 1000 * 1000;
    //@ assert l * l * l <= 1000 * 1000 * 1000;
    
    l_cubed = l * l * l;
    ans = 0;
    divisor = 27;
    
    /*@
        loop invariant 1 <= l <= 1000;
        loop invariant l_cubed >= 0;
        loop invariant ans == (l * l * l - l_cubed) / divisor;
        loop invariant l_cubed + ans * divisor == l * l * l;
        loop assigns l_cubed, ans;
        loop variant l_cubed;
    */
    while (l_cubed >= divisor)
    {
        l_cubed -= divisor;
        ans += 1;
    }
    
    return ans;
}

int main()
{
    return 0;
}
