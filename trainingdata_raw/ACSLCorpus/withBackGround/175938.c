/*@
    predicate is_even(integer x) = x % 2 == 0;
    
    logic integer double_val(integer x) = x * 2;
    
    lemma double_is_even_for_10: is_even(10);
    lemma double_is_odd_for_11: !is_even(11);
    lemma double_value_for_10: double_val(10) == 20;
    lemma double_value_for_11: double_val(11) == 22;
*/

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    ensures \result <= a;
    ensures \result <= b;
    ensures \result == a || \result == b;
*/
unsigned int func(unsigned int a, unsigned int b)
{
    unsigned int ans;
    
    if (a > b) {
        ans = b;
    } else {
        ans = a;
    }
    
    //@ assert ans <= a;
    //@ assert ans <= b;
    //@ assert ans == a || ans == b;
    
    return ans;
}

int main()
{
    //@ assert is_even(10);
    //@ assert !is_even(11);
    //@ assert double_val(10) == 20;
    //@ assert double_val(11) == 22;
    
    return 0;
}
