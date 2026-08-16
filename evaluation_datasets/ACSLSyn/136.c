#include <stdbool.h>

/* ====== Original function 1: monotonic check ====== */
/*@
    predicate is_increasing(integer a, integer b, integer c) =
        a < b && b < c;

    predicate is_decreasing(integer a, integer b, integer c) =
        a > b && b > c;

    logic integer triangle(integer n) =
        n <= 0 ? 0 : n + triangle(n - 1);

    lemma triangle_10:
        triangle(10) == 55;
*/

int func(int a, int b, int c)
{
    //@ assert 1 <= a && a <= 9;
    //@ assert 1 <= b && b <= 9;
    //@ assert 1 <= c && c <= 9;
    
    if (a < b && b < c)
    {
        //@ assert is_increasing(a, b, c);
        return 1;
    }
    else if (a > b && b > c)
    {
        //@ assert is_decreasing(a, b, c);
        return 1;
    }
    else
    {
        //@ assert !is_increasing(a, b, c) && !is_decreasing(a, b, c);
        return 0;
    }
}

/* ====== Original function 2: range validity check ====== */

/*@
    predicate is_valid_range(integer a, integer b) =
        1 <= a <= 16 && 1 <= b <= 16 && a + b <= 16;

    logic integer max_val(integer a, integer b) =
        a > b ? a : b;

    lemma max_val_property:
        \forall integer a, b; max_val(a, b) == a || max_val(a, b) == b;
*/

int func_range(unsigned long long a, unsigned long long b)
{
    unsigned long long max_val;
    //@ assert is_valid_range(a, b);
    
    max_val = a > b ? a : b;
    //@ assert max_val == a || max_val == b;
    
    return (a <= 8 || b <= 8) ? 1 : 0;
}

/* ====== Synthesized function: score-based monotonic check ====== */
/* Scenario: In a game scoring system, three players have scores a,b,c (1-9).
   We first check if the scores form a valid range (scaled by 2 for comparison).
   Then we check if the sequence is monotonic. The final result indicates
   whether the scores are both valid-range compliant AND monotonic. */

int check_game_scores(int a, int b, int c)
{
    int monotonic_result;
    int range_ok;
    
    monotonic_result = func(a, b, c);
    
    range_ok = func_range((unsigned long long)(a*2), (unsigned long long)(b*2));
    
    //@ assert (monotonic_result == 1) <==> (is_increasing(a,b,c) || is_decreasing(a,b,c));
    //@ assert range_ok <==> (a*2 <= 8 || b*2 <= 8);
    
    //@ assert (monotonic_result == 1 && range_ok) ==> (is_increasing(a,b,c) || is_decreasing(a,b,c));
    
    return (monotonic_result == 1 && range_ok) ? 1 : 0;
}
