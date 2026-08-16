#include <stdbool.h>

/* ========== First snippet: nested_fns_example (adapted) ========== */
/*@
    predicate is_between_5_and_10(integer x) = 5 <= x && x <= 10;
    predicate is_between_5_and_15(integer x) = 5 <= x && x <= 15;
    logic integer times_30(integer x) = x * 30;
    logic integer times_20(integer x) = x * 20;
    lemma f_lemma: \forall integer x; is_between_5_and_10(x) ==> times_30(x) == x * 30;
    lemma g_lemma: \forall integer x; is_between_5_and_15(x) ==> times_20(x) == x * 20;
*/

unsigned int nested_fns_example(void)
{
    unsigned int result_f;
    unsigned int result_g;
    unsigned int ret;

    //@ assert is_between_5_and_10(10);
    //@ assert times_30(10) == 300;
    result_f = 10 * 30;

    //@ assert is_between_5_and_15(15);
    //@ assert times_20(15) == 300;
    result_g = 15 * 20;

    //@ assert result_f == 300;
    //@ assert result_g == 300;
    ret = result_f;
    return ret;
}

/* ========== Second snippet: is_odd_func, is_even_func, func (adapted) ========== */
/*@ predicate is_odd(integer n) = n % 2 == 1; */
/*@ predicate is_even(integer n) = n % 2 == 0; */

/*@ lemma odd_even_bound: \forall integer n; 1 <= n <= 9 ==> (is_odd(n) || is_even(n)); */

bool is_odd_func(unsigned int n) {
    //@ assert 1 <= n <= 9;
    return n % 2 == 1;
}

bool is_even_func(unsigned int n) {
    //@ assert 1 <= n <= 9;
    return n % 2 == 0;
}

unsigned int func(unsigned int n) {
    //@ assert 1 <= n <= 9;
    unsigned int result;
    
    if (is_odd_func(n)) {
        //@ assert n * n >= 1 && n * n <= 81;
        result = n * n * n;
    } else {
        //@ assert n * n >= 1 && n * n <= 81;
        result = n * n;
    }
    //@ assert is_odd(n) ==> result == n * n * n;
    //@ assert is_even(n) ==> result == n * n;
    return result;
}

/* ========== Third snippet: median_odd_func (adapted) ========== */
/*@
    logic integer median_odd(integer x, integer y, integer z) =
        (x <= y && y <= z) ? y :
        (y <= x && x <= z) ? x :
        z;

    lemma median_odd_member:
        \forall integer x, y, z;
            median_odd(x, y, z) == x ||
            median_odd(x, y, z) == y ||
            median_odd(x, y, z) == z;

    lemma median_odd_case1:
        \forall integer x, y, z;
            (x <= y && y <= z) ==> median_odd(x, y, z) == y;

    lemma median_odd_case2:
        \forall integer x, y, z;
            (y <= x && x <= z) ==> median_odd(x, y, z) == x;

    lemma median_odd_case3:
        \forall integer x, y, z;
            (x <= z && z <= y) ==> median_odd(x, y, z) == z;
*/

int median_odd_func(int x, int y, int z)
{
    int result;
    
    if (x <= y && y <= z) {
        //@ assert median_odd(x, y, z) == y;
        result = y;
    } else if (y <= x && x <= z) {
        //@ assert median_odd(x, y, z) == x;
        result = x;
    } else {
        //@ assert median_odd(x, y, z) == z;
        result = z;
    }
    
    return result;
}

/* ========== Synthesized function: score_processing (real-world scenario: game score normalization) ========== */
/* 
   Scenario: In a game, raw scores (1-9) are transformed by func (odd -> cube, even -> square).
   Then a median of three such transformed scores is taken to get a balanced final score.
   The final score must be in [1, 729] because max input 9 -> odd: 9^3=729, even: 9^2=81, median is between min and max.
   The synthesized function verifies this high-level invariant.
*/

unsigned int score_processing(unsigned int a, unsigned int b, unsigned int c) {
    unsigned int fa = func(a);
    unsigned int fb = func(b);
    unsigned int fc = func(c);
    
    //@ assert 1 <= fa <= 729 && 1 <= fb <= 729 && 1 <= fc <= 729;
    
    int median = median_odd_func(fa, fb, fc);
    
    //@ assert 1 <= median <= 729;
    
    return (unsigned int)median;
}
