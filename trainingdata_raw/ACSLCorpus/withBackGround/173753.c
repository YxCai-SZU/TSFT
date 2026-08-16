/*@
    predicate is_valid_k(integer k) = 2 <= k && k <= 100;
    
    logic integer func_spec(integer k) = (k / 2) * ((k + 1) / 2);
    
    lemma a_bounds: \forall integer k; is_valid_k(k) ==> 1 <= (k / 2) && (k / 2) <= 50;
    lemma b_bounds: \forall integer k; is_valid_k(k) ==> 1 <= ((k + 1) / 2) && ((k + 1) / 2) <= 51;
    lemma product_bounds: \forall integer a, b; 1 <= a <= 50 && 1 <= b <= 51 ==> a * b <= 50 * 51;
    lemma func_correct: \forall integer k; is_valid_k(k) ==> (k / 2) * ((k + 1) / 2) == func_spec(k);
*/

/*@
    requires is_valid_k(k);
    ensures \result == func_spec(k);
    assigns \nothing;
*/
unsigned int func(unsigned int k)
{
    unsigned int a;
    unsigned int b;
    unsigned int result;
    
    a = k / 2;
    b = (k + 1) / 2;
    
    //@ assert a >= 1 && a <= 50;
    //@ assert b >= 1 && b <= 51;
    //@ assert a * b <= 50 * 51;
    
    result = a * b;
    
    //@ assert result == func_spec(k);
    return result;
}
