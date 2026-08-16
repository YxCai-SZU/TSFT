/*@
    predicate is_valid_n(integer n) = 1 <= n && n <= 100;
    
    logic integer mod3(integer x) = x % 3;
    
    lemma mod_property:
        \forall integer n, r;
        is_valid_n(n) && 0 <= r && r <= n && mod3(n) == mod3(r) ==>
        (r == 0 ==> mod3(n) == 0) &&
        (r == 1 ==> mod3(n) == 1) &&
        (r == 2 ==> mod3(n) == 2);
*/

/*@
    requires is_valid_n(n);
    ensures \result >= 0;
    ensures \result == 0 || \result == 1 || \result == 2;
    ensures \result == 0 ==> n % 3 == 0;
    ensures \result == 1 ==> n % 3 == 1;
    ensures \result == 2 ==> n % 3 == 2;
    assigns \nothing;
*/
int func(int n)
{
    int r;
    r = n;
    
    /*@
        loop invariant 1 <= n && n <= 100;
        loop invariant 0 <= r && r <= n;
        loop invariant n % 3 == r % 3;
        loop assigns r;
        loop variant r;
    */
    while (r >= 3)
    {
        //@ assert r % 3 == (r - 3) % 3;
        r = r - 3;
    }
    
    //@ assert n % 3 == r % 3;
    
    if (r == 0)
    {
        //@ assert n % 3 == 0;
        return 0;
    }
    else if (r == 1)
    {
        //@ assert n % 3 == 1;
        return 1;
    }
    else
    {
        //@ assert r == 2;
        //@ assert n % 3 == 2;
        return 2;
    }
}
