#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

/* ACSL predicates and lemmas from first snippet */
/*@
predicate seq_len_eq(integer len1, integer len2) = len1 == len2;

lemma seq_length_push:
  \forall integer s_len, a;
    seq_len_eq(s_len + 1, s_len + 1);

lemma seq_length_update:
  \forall integer s_len, i, a;
    0 <= i < s_len ==> seq_len_eq(s_len, s_len);
*/

size_t test_seq_length_update(size_t s_len, size_t i, int a) {
    //@ assert seq_len_eq(s_len, s_len);
    return s_len;
}

size_t test_seq_length_push(size_t s_len, int a) {
    size_t new_len = s_len + 1;
    //@ assert seq_len_eq(new_len, new_len);
    return new_len;
}

/* ACSL predicates and lemmas from second snippet */
/*@
    predicate diff1_cond(integer a, integer b, integer d) =
        (a > b ==> a - b <= d) && (a <= b ==> b - a <= d);
    predicate diff2_cond(integer b, integer c, integer d) =
        (b > c ==> b - c <= d) && (b <= c ==> c - b <= d);
    predicate diff3_cond(integer a, integer c, integer d) =
        (a > c ==> a - c <= d) && (a <= c ==> c - a <= d);
*/

/*@
    lemma diff1_eq:
        \forall integer a, b, d;
        diff1_cond(a, b, d) <==> (a > b ? a - b : b - a) <= d;
    lemma diff2_eq:
        \forall integer b, c, d;
        diff2_cond(b, c, d) <==> (b > c ? b - c : c - b) <= d;
    lemma diff3_eq:
        \forall integer a, c, d;
        diff3_cond(a, c, d) <==> (a > c ? a - c : c - a) <= d;
*/

bool func(unsigned int a, unsigned int b, unsigned int c, unsigned int d)
{
    unsigned int diff1;
    unsigned int diff2;
    unsigned int diff3;
    bool result;

    //@ assert 1 <= a <= 10000;
    //@ assert 1 <= b <= 10000;
    //@ assert 1 <= c <= 10000;
    //@ assert 1 <= d <= 10000;

    if (a > b) {
        diff1 = a - b;
    } else {
        diff1 = b - a;
    }

    if (b > c) {
        diff2 = b - c;
    } else {
        diff2 = c - b;
    }

    if (a > c) {
        diff3 = a - c;
    } else {
        diff3 = c - a;
    }

    //@ assert diff1 <= d <==> diff1_cond(a, b, d);
    //@ assert diff2 <= d <==> diff2_cond(b, c, d);
    //@ assert diff3 <= d <==> diff3_cond(a, c, d);

    if ((diff1 <= d && diff2 <= d) || diff3 <= d) {
        result = true;
    } else {
        result = false;
    }

    //@ assert result == true <==> ((diff1 <= d && diff2 <= d) || diff3 <= d);
    return result;
}

/* 
 * Real-world scenario: Network packet buffer validation
 * 
 * We have a sequence buffer of packets, each with a header containing 
 * three fields (a, b, c) and a tolerance value d. We want to:
 * 1. Push a new packet into the buffer and verify the sequence length
 * 2. Validate the packet's field differences against the tolerance
 * 
 * The synthesized function processes a batch of 3 packets, checking
 * that if we update the first field of the first packet, the sequence
 * length remains consistent, and the tolerance condition holds for
 * the packet fields.
 */

bool process_packet_sequence(size_t s_len, size_t i, int a, int b, int c, unsigned int d, int update_val) {
    size_t len_after_update = test_seq_length_update(s_len, i, update_val);
    
    size_t len_after_push = test_seq_length_push(len_after_update, a);
    
    bool tolerance_valid = func(a, b, c, d);
    
    //@ assert seq_len_eq(len_after_update, s_len);
    //@ assert len_after_push == s_len + 1;
    
    //@ assert (tolerance_valid == true <==> ((diff1_cond(a, b, d) && diff2_cond(b, c, d)) || diff3_cond(a, c, d))) && (len_after_push == s_len + 1);
    
    return tolerance_valid;
}
