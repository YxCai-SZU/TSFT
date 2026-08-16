#include <stdint.h>

/*@
    predicate subtraction_lemma = 5 - 3 == 2;

    lemma compute_subtraction: subtraction_lemma;

    logic integer seq_concat(integer a, integer b, integer c, integer d) =
        a + b + c + d;

    predicate seq_equality_lemma(integer a, integer b, integer c, integer d) =
        seq_concat(a, b, c, d) == seq_concat(a, b, 0, 0) + seq_concat(0, 0, c, d);

    lemma seq_equality_proof: \forall integer a, b, c, d; seq_equality_lemma(a, b, c, d);

    predicate equality_lemma(integer a, integer b) = a == b ==> a <= b;

    lemma equality_proof: \forall integer a, b; equality_lemma(a, b);

    predicate transitivity_lemma(integer a, integer b, integer c) = 
        (a <= b && b <= c) ==> a <= c;

    lemma transitivity_proof: \forall integer a, b, c; transitivity_lemma(a, b, c);

    predicate bound_lemma(integer num_entries, integer elem_size, integer meta_size) =
        num_entries <= 18446744073709551615 / (elem_size + meta_size) ==>
        num_entries * (elem_size + meta_size) <= 18446744073709551615;

    lemma bound_proof: \forall integer num_entries, elem_size, meta_size; 
        (elem_size >= 0 && meta_size >= 0 && num_entries >= 0) ==> bound_lemma(num_entries, elem_size, meta_size);
*/

/*@
    assigns \nothing;
*/
void compute_proof_subtraction(void) {
    //@ assert subtraction_lemma;
}

/*@
    assigns \nothing;
*/
void seq_equality(uint64_t a, uint64_t b, uint64_t c, uint64_t d) {
    //@ assert seq_equality_lemma(a, b, c, d);
}

/*@
    assigns \nothing;
*/
void equality(uint64_t a, uint64_t b) {
    //@ assert equality_lemma(a, b);
}

/*@
    assigns \nothing;
*/
void nonlinear_arithmetic(uint64_t a, uint64_t b, uint64_t c) {
    //@ assert transitivity_lemma(a, b, c);
}

/*@
    assigns \nothing;
*/
void nonlinear_arithmetic_example_2(
    uint64_t num_list_entries_per_node,
    uint32_t list_element_size,
    uint32_t metadata_size
) {
    //@ assert bound_lemma(num_list_entries_per_node, list_element_size, metadata_size);
}
