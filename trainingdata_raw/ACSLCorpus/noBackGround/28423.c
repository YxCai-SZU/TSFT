#include <stdbool.h>

/*@
    assigns \nothing;
*/
void test_map_equality_operator_proof(void) {
    /*@ assert \forall integer k; ((k) > 0 && (k) < 5) ==> ((k) * 3) == ((k) * 3); */
}

/*@
    assigns \nothing;
*/
void test_map_insert_remove_proof(void) {
    /*@ assert \forall integer k, v; (((k) == 10 && (v) == 100) ||
        ((k) == 20 && (v) == 200)) ==> (k == 10 ==> v == 100); */
}

/*@
    assigns \nothing;
*/
void test_map_len_proof(void) {
    /*@ assert \forall integer k, v; (((k) == 10 && (v) == 100) ||
        ((k) == 20 && (v) == 200)) ==> (k == 10 || k == 20); */
}

/*@
    assigns \nothing;
*/
void test_set_subset_of_proof(void) {
    /*@ assert \forall integer x; (x == 10 || x == 20) ==> (x == 10 ==> \true); */
}

/*@
    assigns \nothing;
*/
void test_set_choose_proof(void) {
    /*@ assert \forall integer x; (x == 10 || x == 20) ==> (x == 10 ==> \true); */
}

/*@
    assigns \nothing;
*/
int main(void) {
    test_map_equality_operator_proof();
    test_map_insert_remove_proof();
    test_map_len_proof();
    test_set_subset_of_proof();
    test_set_choose_proof();
    
    return 0;
}
