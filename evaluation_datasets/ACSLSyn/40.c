#include <stdbool.h>

/* First function: checks if v[0] == v[1] using a loop */
/*@
    predicate is_valid_vector(int *v, integer len) =
        len == 2 &&
        1 <= v[0] <= 100 &&
        0 <= v[1] <= v[0];

    logic integer vector_length(int *v) = 2;

    lemma vector_length_preserved:
        \forall int *v; is_valid_vector(v, 2) ==> vector_length(v) == 2;
*/

bool func(int *v) {
    int s;
    int i;
    
    s = 0;
    i = 0;
    
    while (i < v[1]) {
        //@ assert s == i;
        if (s == v[0]) {
            return false;
        }
        s += 1;
        i += 1;
    }
    
    //@ assert s == v[1];
    return s == v[0];
}

/* Second function: computes a weighted sum */
/*@
    predicate valid_params(integer n, integer m) =
        1 <= n && n <= 100 &&
        1 <= m && m <= n &&
        m <= 5;

    logic integer expected_result(integer n, integer m) =
        100 * (n - m) + 1900 * m;

    lemma bound_lemma_1:
        \forall integer n, m;
        valid_params(n, m) ==> 0 <= n - m && n - m <= 99;

    lemma bound_lemma_2:
        \forall integer n, m;
        valid_params(n, m) ==> 100 * (n - m) <= 9900;

    lemma bound_lemma_3:
        \forall integer n, m;
        valid_params(n, m) ==> 1900 * m <= 9500;
*/

int func2(unsigned int n, unsigned int m)
{
    int n_i32;
    int m_i32;
    int result;

    //@ assert 1 <= n && n <= 100;
    //@ assert 1 <= m && m <= n;
    //@ assert m <= 5;

    n_i32 = (int)n;
    m_i32 = (int)m;

    //@ assert 1 <= n_i32 && n_i32 <= 100;
    //@ assert 1 <= m_i32 && m_i32 <= 5;
    //@ assert 0 <= n_i32 - m_i32 && n_i32 - m_i32 <= 99;

    //@ assert 100 * (n_i32 - m_i32) <= 9900;
    //@ assert 1900 * m_i32 <= 9500;

    result = 100 * (n_i32 - m_i32) + 1900 * m_i32;
    //@ assert result == expected_result(n, m);
    return result;
}

/* Synthesized function: process a score vector and compute a derived value */
/*@
    predicate valid_score(int *v, integer len, integer n, integer m) =
        is_valid_vector(v, len) &&
        valid_params(n, m) &&
        v[0] == (int)n &&
        v[1] == (int)m;

    logic integer derived_result(int *v, integer n, integer m) =
        (v[0] == v[1]) ? expected_result(n, m) : 0;

    lemma derived_nonneg:
        \forall int *v, integer n, m;
        valid_score(v, 2, n, m) ==> derived_result(v, n, m) >= 0;
*/

int process_score(int *v) {
    unsigned int n;
    unsigned int m;
    int result;
    
    //@ assert is_valid_vector(v, 2);
    //@ assert 1 <= v[0] && v[0] <= 100;
    //@ assert 0 <= v[1] && v[1] <= v[0];
    
    n = (unsigned int)v[0];
    m = (unsigned int)v[1];
    
    //@ assert 1 <= n && n <= 100;
    //@ assert 1 <= m && m <= n;
    //@ assert m <= 5;
    //@ assert valid_params(n, m);
    
    bool equal = func(v);
    
    int weighted = func2(n, m);
    
    //@ assert weighted == expected_result(n, m);
    
    if (equal) {
        result = weighted;
    } else {
        result = 0;
    }
    
    //@ assert result >= 0;
    //@ assert result == derived_result(v, n, m);
    
    return result;
}
