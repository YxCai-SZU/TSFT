/*@
    predicate is_nonnegative(integer x) = 0 <= x;
    predicate is_within_range(integer x) = 0 <= x <= 10;
    predicate product_in_range(integer a, integer b) = 
        0 <= a * b <= 100;
    
    lemma product_range_lemma:
        \forall integer a, b;
            is_within_range(a) && is_within_range(b) ==> 
            product_in_range(a, b);
*/

/*@
    requires is_within_range(a);
    requires is_within_range(b);
    ensures \result == a * b;
    assigns \nothing;
*/
int func(int a, int b)
{
    //@ assert is_within_range(a);
    //@ assert is_within_range(b);
    //@ assert product_in_range(a, b);
    
    int answer;
    answer = a * b;
    
    //@ assert answer == a * b;
    return answer;
}

int main()
{
    return 0;
}
