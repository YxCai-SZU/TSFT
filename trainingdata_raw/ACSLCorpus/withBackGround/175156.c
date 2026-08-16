/*@
    predicate is_in_range(integer n, integer k) = k <= n;
*/

/*@
    lemma test_is_in_range:
        \forall integer n, integer k; is_in_range(n, k) ==> (k <= n);
*/

/*@
    requires 1 <= r <= 100;
    ensures \result == 2 * r * 3;
    assigns \nothing;
*/
long long func(long long r)
{
    long long pi;
    long long circumference;
    
    pi = 3;
    
    //@ assert 2 * r * pi <= 2 * 100 * 3;
    
    circumference = 2 * r * pi;
    
    return circumference;
}

int main()
{
    return 0;
}
