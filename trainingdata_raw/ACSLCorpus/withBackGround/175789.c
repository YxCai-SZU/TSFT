/*@
    predicate is_in_range(integer x) = -100 <= x <= 100;
*/

/*@
    requires is_in_range(a) && is_in_range(b) && is_in_range(c);
    ensures (a == b && a != c) ==> \result == c;
    ensures (a != b && a == c) ==> \result == b;
    ensures (a != b && b == c) ==> \result == a;
    ensures (a == b && a == c) ==> \result == a;
    ensures is_in_range(\result);
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int ans;
    
    if (a == b) {
        ans = c;
    } else if (a == c) {
        ans = b;
    } else {
        ans = a;
    }
    
    //@ assert is_in_range(ans);
    
    return ans;
}
