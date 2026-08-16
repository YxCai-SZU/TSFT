/*@
    predicate is_small(integer x) = 1 <= x <= 16;
    predicate both_small(integer a, integer b) = a <= 8 && b <= 8;
    logic integer max_val(integer a, integer b) = (a > b) ? a : b;
    logic integer min_val(integer a, integer b) = (a < b) ? a : b;
    lemma max_val_range: \forall integer a, b; is_small(a) && is_small(b) ==> 1 <= max_val(a,b) <= 16;
    lemma min_val_range: \forall integer a, b; is_small(a) && is_small(b) ==> 1 <= min_val(a,b) <= 16;
    lemma sum_constraint: \forall integer a, b; is_small(a) && is_small(b) && a + b <= 16 ==> both_small(a,b) ==> max_val(a,b) <= 8;
    lemma negation_lemma: \forall integer a, b; is_small(a) && is_small(b) && a + b <= 16 ==> (!both_small(a,b)) ==> (max_val(a,b) > 8 || min_val(a,b) > 8);
*/

/*@
    requires 1 <= a <= 16;
    requires 1 <= b <= 16;
    requires a + b <= 16;
    ensures \result == 1 <==> (a <= 8 && b <= 8);
    assigns \nothing;
*/
int func(long a, long b) {
    int is_a;
    int is_b;
    long max_val;
    long min_val;
    
    is_a = 1;
    is_b = 1;
    
    //@ assert is_small(a) && is_small(b);
    
    // Implementing max function manually
    if (a > b) {
        max_val = a;
    } else {
        max_val = b;
    }
    //@ assert max_val == max_val(a,b);
    
    if (max_val > 8) {
        if (a > 8) {
            is_a = 0;
        }
        if (b > 8) {
            is_b = 0;
        }
    }
    
    // Implementing min function manually
    if (a < b) {
        min_val = a;
    } else {
        min_val = b;
    }
    //@ assert min_val == min_val(a,b);
    
    if (min_val > 8) {
        is_a = 0;
        is_b = 0;
    }
    
    if (is_a && is_b) {
        //@ assert both_small(a,b);
        return 1;
    } else {
        //@ assert !both_small(a,b);
        return 0;
    }
}
