/*@
    predicate is_in_range(integer x) = 1 <= x <= 100;
    
    logic integer safe_sum(integer a, integer b) = a + b;
    
    lemma sum_range: \forall integer a, b; is_in_range(a) && is_in_range(b) ==> 2 <= safe_sum(a, b) <= 200;
*/

/*@
    requires is_in_range(a) && is_in_range(b);
    ensures \result == ((a + b) / 2 % 2 != 0);
*/
int func(unsigned long long a, unsigned long long b) {
    unsigned long long sum;
    unsigned long long half;
    unsigned long long remainder;
    int result;
    
    //@ assert 2 <= a + b <= 200;
    
    sum = a + b;
    
    //@ assert sum >= 2;
    
    half = sum / 2;
    
    remainder = half % 2;
    
    //@ assert remainder == 0 || remainder == 1;
    
    result = (remainder != 0);
    
    //@ assert result == ((a + b) / 2 % 2 != 0);
    
    return result;
}
