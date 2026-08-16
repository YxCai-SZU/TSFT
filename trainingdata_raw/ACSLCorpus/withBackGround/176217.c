/*@
    predicate valid_range(integer v) = 1 <= v && v <= 100;

    lemma product_range:
        \forall integer a, b;
            valid_range(a) && valid_range(b) ==> 1 <= a * b && a * b <= 10000;
*/

/*@
    requires valid_range(a) && valid_range(b);
    ensures \result == a * b;
    assigns \nothing;
*/
int func(int a, int b)
{
    //@ assert valid_range(a);
    //@ assert valid_range(b);
    //@ assert 1 <= a * b && a * b <= 10000;
    
    int ans;
    ans = a * b;
    return ans;
}
