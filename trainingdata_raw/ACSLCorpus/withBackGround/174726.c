/*@
    predicate is_valid_x(integer x) = 0 <= x && x <= 1;
    
    logic integer complement(integer x) = 1 - x;
    
    lemma complement_range: \forall integer x; is_valid_x(x) ==> (complement(x) == 0 || complement(x) == 1);
*/

/*@
    requires is_valid_x(x);
    ensures \result == complement(x);
    assigns \nothing;
*/
int func(int x)
{
    int result;
    
    //@ assert x == 0 || x == 1;
    
    if (x == 0) {
        result = 1;
    } else {
        result = 0;
    }
    
    //@ assert result == complement(x);
    return result;
}

int main()
{
    return 0;
}
