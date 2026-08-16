/*@
    predicate seq_len_eq(integer a, integer b, integer c) =
        a + b + c == a + b + c;

    lemma calc_example_5:
        \forall integer s1_len, s2_len, s3_len;
            seq_len_eq(s1_len, s2_len, s3_len) ==>
            (s1_len + s2_len) + s3_len == s1_len + s2_len + s3_len;

    lemma additional_calc_example_5:
        \forall integer a_len, b_len, c_len;
            seq_len_eq(a_len, b_len, c_len) ==>
            (a_len + b_len) + c_len == a_len + b_len + c_len;

    lemma extra_calc_example_5:
        \forall integer d_len, e_len, f_len;
            seq_len_eq(d_len, e_len, f_len) ==>
            (d_len + e_len) + f_len == d_len + e_len + f_len;

    lemma further_calc_example_5:
        \forall integer g_len, h_len, i_len;
            seq_len_eq(g_len, h_len, i_len) ==>
            (g_len + h_len) + i_len == g_len + h_len + i_len;

    lemma next_calc_example_5:
        \forall integer j_len, k_len, l_len;
            seq_len_eq(j_len, k_len, l_len) ==>
            (j_len + k_len) + l_len == j_len + k_len + l_len;

    lemma next_next_calc_example_5:
        \forall integer m_len, n_len, o_len;
            seq_len_eq(m_len, n_len, o_len) ==>
            (m_len + n_len) + o_len == m_len + n_len + o_len;

    lemma next_next_next_calc_example_5:
        \forall integer p_len, q_len, r_len;
            seq_len_eq(p_len, q_len, r_len) ==>
            (p_len + q_len) + r_len == p_len + q_len + r_len;
*/

#include <stddef.h>

void main() {
    int a;
    int b;
    int c;
    int result;

    a = 5;
    b = 3;
    c = 2;

    //@ assert a + b + c == 10;
    result = a + b + c;
    //@ assert result == 10;
}
