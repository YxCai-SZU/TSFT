/*@
    predicate a_less_than_5(integer a) = a < 5;
    predicate b_nonnegative(integer b) = b >= 0;
    predicate sum_less_than_7(integer a, integer b) = a + 2 < 7;
    
    lemma func_lemma: 
        \forall integer a, b; 
        a_less_than_5(a) && b_nonnegative(b) ==> sum_less_than_7(a, b);
*/

/*@
    requires a_less_than_5(a) && b_nonnegative(b);
    ensures sum_less_than_7(a, b);
*/
void func(int a, int b) {
    // Variable declarations at scope top
    int temp_sum;
    
    //@ assert a < 5;
    //@ assert b >= 0;
    
    temp_sum = a + 2;
    //@ assert temp_sum < 7;
    //@ assert temp_sum <= 6;
}

int main() {
    return 0;
}
