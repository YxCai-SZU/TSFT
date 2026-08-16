/*@
    predicate bounds(integer x) = 1 <= x <= 100;
    predicate no_overflow(integer x) = x * x * x <= 1000000;
    
    lemma cubic_bound: \forall integer x; bounds(x) ==> no_overflow(x);
*/

/*@
    requires 1 <= x <= 100;
    ensures \result == x * x * x;
    assigns \nothing;
*/
int func(int x)
{
    //@ assert 1 <= x <= 100;
    int ans = x * x * x;
    //@ assert ans == x * x * x;
    return ans;
}

int main()
{
    return 0;
}
