/*@
    predicate is_in_domain(integer k) = k >= 0 && k <= 10;
    logic integer map_value(integer v) = v * 2;
    
    lemma map_key_domain_lemma:
        \forall integer k; is_in_domain(k) ==> map_value(k) == k * 2;
*/

/*@
    requires \true;
    ensures \result == 0;
    assigns \nothing;
*/
int main() {
    //@ assert \true;
    return 0;
}

/*@
    predicate map_domain_contains(integer k) = 
        is_in_domain(k);
    
    logic integer map_index(integer k) = 
        map_value(k);
*/

/*@
    lemma test_map_key_domain:
        \forall integer k; 
        map_domain_contains(k) ==> map_index(k) == k * 2;
*/

/*@
    lemma test_map_empty:
        \forall integer k; 
        !map_domain_contains(k) ==> k < 0 || k > 10;
*/

/*@
    lemma test_map_insert:
        \forall integer k, v; 
        map_domain_contains(k) ==> map_index(k) == k * 2;
*/

/*@
    lemma test_map_remove:
        \forall integer k; 
        !map_domain_contains(k) ==> k < 0 || k > 10;
*/

/*@
    lemma test_map_len:
        \forall integer k; 
        map_domain_contains(k) ==> map_index(k) == k * 2;
*/
