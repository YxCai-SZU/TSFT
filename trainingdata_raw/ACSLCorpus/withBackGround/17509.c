/*@
    predicate valid_range(integer a, integer b) =
        1 <= a <= 100 && 1 <= b <= 100;

    lemma product_bounds:
        \forall integer a, b;
            valid_range(a, b) ==> a * b >= 1 && a * b <= 10000;
*/

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    ensures \result == a * b;
    assigns \nothing;
*/
int func(int a, int b)
{
    //@ assert valid_range(a, b);
    //@ assert a * b >= 1;
    //@ assert a * b <= 10000;
    
    int ans = a * b;
    //@ assert ans == a * b;
    
    return ans;
}
