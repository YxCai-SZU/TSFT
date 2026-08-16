/*@
    predicate bounds(integer x, integer a) =
        0 <= x <= 9 && 0 <= a <= 9;
    
    logic integer func_spec(integer x, integer a) =
        x < a ? 0 : 10;
*/

/*@
    requires bounds(x, a);
    ensures \result == func_spec(x, a);
    assigns \nothing;
*/
unsigned int func(unsigned int x, unsigned int a)
{
    unsigned int ans;
    
    //@ assert bounds(x, a);
    
    if (x < a) {
        ans = 0;
    } else {
        ans = 10;
    }
    
    //@ assert \at(x, Pre) < \at(a, Pre) ==> ans == 0;
    //@ assert \at(x, Pre) >= \at(a, Pre) ==> ans == 10;
    
    return ans;
}
