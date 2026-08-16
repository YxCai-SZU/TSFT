/*@
    predicate r_in_range(integer r) = 1 <= r && r <= 100;
    
    lemma r_bound_lemma: 
        \forall integer r; r_in_range(r) ==> 3 * r * r <= 3 * 100 * 100;
*/

/*@
    requires 1 <= r <= 100;
    ensures \result == 3 * r * r;
    assigns \nothing;
*/
unsigned int func(unsigned int r) {
    // Variable declarations at top of scope
    unsigned int res;
    
    //@ assert 1 <= r <= 100;
    
    //@ assert 3 * r * r <= 3 * 100 * 100;
    
    res = 3 * r * r;
    return res;
}

int main() {
    return 0;
}
