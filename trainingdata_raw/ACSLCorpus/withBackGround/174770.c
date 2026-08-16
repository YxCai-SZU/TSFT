#include <stdbool.h>
#include <stddef.h>

/*@
    predicate valid_vec(unsigned int *vec, size_t len) =
        len > 0 && len < 0x80000000 && \valid(vec + (0 .. len-1));

    logic integer vec_len(unsigned int *vec, size_t len) = (integer)len;

    lemma sum_bounds:
        \forall unsigned int *p, *q, *r, size_t p_len, q_len, r_len;
        valid_vec(p, p_len) && valid_vec(q, q_len) && valid_vec(r, r_len) &&
        vec_len(p, p_len) + vec_len(q, q_len) + vec_len(r, r_len) < 0x80000000
        ==>
        vec_len(p, p_len) + vec_len(q, q_len) < 0x80000000;

    lemma total_sum_bounds:
        \forall unsigned int *p, *q, *r, size_t p_len, q_len, r_len;
        valid_vec(p, p_len) && valid_vec(q, q_len) && valid_vec(r, r_len) &&
        vec_len(p, p_len) + vec_len(q, q_len) + vec_len(r, r_len) < 0x80000000
        ==>
        vec_len(p, p_len) + vec_len(q, q_len) + vec_len(r, r_len) < 0x80000000;
*/

/*@
    requires valid_vec(p, p_len) && valid_vec(q, q_len) && valid_vec(r, r_len);
    requires vec_len(p, p_len) + vec_len(q, q_len) + vec_len(r, r_len) < 0x80000000;
    ensures \result == (vec_len(p, p_len) + vec_len(q, q_len) == vec_len(r, r_len));
*/
bool func(unsigned int *p, size_t p_len,
          unsigned int *q, size_t q_len,
          unsigned int *r, size_t r_len)
{
    bool result = false;
    size_t sum_pq;
    size_t sum_total;

    //@ assert vec_len(p, p_len) + vec_len(q, q_len) < 0x80000000;
    sum_pq = p_len + q_len;

    //@ assert vec_len(p, p_len) + vec_len(q, q_len) + vec_len(r, r_len) < 0x80000000;
    sum_total = p_len + q_len + r_len;

    if (sum_pq == r_len) {
        result = true;
    }

    return result;
}
