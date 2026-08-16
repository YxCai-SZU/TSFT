/*@
    predicate is_even(integer x, integer k) = k % 2 == 0;
    
    lemma test_is_even:
        is_even(2, 10) && !is_even(2, 11);
*/

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    ensures \result == a * b;
    assigns \nothing;
*/
unsigned int func(unsigned int a, unsigned int b)
{
    //@ assert 1 <= a && a <= 100;
    //@ assert 1 <= b && b <= 100;
    //@ assert a * b <= 10000;
    
    return a * b;
}

int main()
{
    return 0;
}
