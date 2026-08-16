/*@
    predicate is_valid_range(integer a) = 1 <= a && a <= 10;
    
    logic integer pow2(integer a) = a * a;
    logic integer pow3(integer a) = a * a * a;
    
    lemma pow2_bounds: \forall integer a; is_valid_range(a) ==> 1 <= pow2(a) && pow2(a) <= 100;
    lemma pow3_bounds: \forall integer a; is_valid_range(a) ==> 1 <= pow3(a) && pow3(a) <= 1000;
    
    lemma func_lemma: \forall integer a; is_valid_range(a) ==> 
        a + pow2(a) + pow3(a) == a + a * a + a * a * a;
*/

/*@
    requires 1 <= a <= 10;
    ensures \result == a + a * a + a * a * a;
    assigns \nothing;
*/
int func(int a)
{
    // Declare all variables at the top
    int a_pow_2;
    int a_pow_3;
    int ans;
    
    //@ assert 1 <= a && a <= 10;
    
    a_pow_2 = a * a;
    //@ assert a_pow_2 == a * a;
    
    a_pow_3 = a * a * a;
    //@ assert a_pow_3 == a * a * a;
    
    //@ assert 1 <= a_pow_2 && a_pow_2 <= 100;
    //@ assert 1 <= a_pow_3 && a_pow_3 <= 1000;
    
    ans = a + a_pow_2 + a_pow_3;
    //@ assert ans == a + a * a + a * a * a;
    
    return ans;
}

int main()
{
    return 0;
}
