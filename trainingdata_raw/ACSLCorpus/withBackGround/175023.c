/*@
    predicate is_even(integer n) = n % 2 == 0;
    
    lemma test_is_even:
        is_even(10) && !is_even(11);
*/

/*@
    requires 1 <= n <= 100;
    ensures is_even(n) ==> \result == 1;
    ensures !is_even(n) ==> \result == 0;
*/
int func(unsigned int n)
{
    int result;
    
    //@ assert 1 <= n <= 100;
    
    if (n % 2 == 0) {
        //@ assert is_even(n);
        result = 1;
    } else {
        //@ assert !is_even(n);
        result = 0;
    }
    
    return result;
}
