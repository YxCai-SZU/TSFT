/*@
    logic integer sum_of_natural(integer x) = x * (x + 1) / 2;

    predicate sum_of_natural_is_nonnegative(integer x) = x >= 0 ==> sum_of_natural(x) >= 0;

    lemma sum_of_natural_nonnegative: \forall integer x; x >= 0 ==> sum_of_natural(x) >= 0;
*/

/*@
    requires x >= 0;
    ensures \result == sum_of_natural(x);
    ensures \result >= 0;
*/
int compute_sum_of_natural(int x) {
    //@ assert x >= 0;
    //@ assert sum_of_natural(x) >= 0;
    int result = x * (x + 1) / 2;
    //@ assert result == sum_of_natural(x);
    //@ assert result >= 0;
    return result;
}

int main() {
    int a = 3;
    int b = 5;
    int c = 10;
    
    //@ assert a >= 0;
    int sum_a = compute_sum_of_natural(a);
    //@ assert sum_a >= 0;
    
    //@ assert b >= 0;
    int sum_b = compute_sum_of_natural(b);
    //@ assert sum_b >= 0;
    
    //@ assert c >= 0;
    int sum_c = compute_sum_of_natural(c);
    //@ assert sum_c >= 0;
    
    return 0;
}
