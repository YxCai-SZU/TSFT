#include <stdbool.h>
#include <stddef.h>

/* First function: game win condition check */
/*@ predicate is_in_range(integer x) = 1 <= x <= 10; */

bool check_win(int a, int b, int c)
{
    bool win = false;

    //@ assert is_in_range(a);
    //@ assert is_in_range(b);
    //@ assert is_in_range(c);

    win = win || (a == 5 && (b == 5 || c == 5 || b == 7 || c == 7));
    win = win || (b == 5 && (a == 5 || c == 5 || a == 7 || c == 7));
    win = win || (c == 5 && (a == 5 || b == 5 || a == 7 || b == 7));

    return win;
}

/* Second function: parity check */
/*@
    predicate is_less_than_0x100(integer a) = 0 <= a < 0x100;
*/

/*@
    lemma a_in_range: \forall integer a; is_less_than_0x100(a) ==> 0 <= a < 0x100;
*/

bool is_odd(unsigned int a)
{
    //@ assert 0 <= a < 0x100;
    
    return (a & 0x1) != 0;
}

/* Third function: bounded minimum selection */
/*@
    predicate is_nonnegative(integer x) = x >= 0;
    predicate is_within_bounds(integer x) = 0 <= x <= 100;

    logic integer half_plus_remainder(integer m) = (m / 2) + (m % 2);

    lemma half_plus_remainder_bound: \forall integer m; 0 <= m <= 100 ==> half_plus_remainder(m) <= m;
    lemma n_bound: \forall integer n, m; 0 <= n <= 100 && 0 <= m <= 100 ==> n <= m || n <= n;
*/

size_t bounded_min(size_t n, size_t m)
{
    size_t result;
    size_t half_plus_rem = (m / 2) + (m % 2);

    //@ assert half_plus_rem <= m;
    if (n > half_plus_rem)
    {
        result = half_plus_rem;
    }
    else
    {
        result = n;
    }

    //@ assert result <= m;
    //@ assert result >= 0;
    //@ assert result == half_plus_rem || result == n;
    return result;
}

/* Synthesized function: Game score validation and adjustment
   Real-world scenario: In a game scoring system, we validate that three player scores
   (1-10 range) form a winning combination, then adjust the winning score based on
   parity and bounded constraints for final score storage. */
size_t process_game_scores(int a, int b, int c)
{
    bool win_status;
    size_t final_score;
    size_t adjusted_score;
    
    win_status = check_win(a, b, c);
    
    if (win_status)
    {
        if (is_odd((unsigned int)a))
        {
            final_score = (size_t)a;
        }
        else if (is_odd((unsigned int)b))
        {
            final_score = (size_t)b;
        }
        else
        {
            final_score = (size_t)c;
        }
    }
    else
    {
        size_t min_ab = (a < b) ? (size_t)a : (size_t)b;
        final_score = (min_ab < (size_t)c) ? min_ab : (size_t)c;
    }
    
    adjusted_score = bounded_min(final_score, 100);
    
    //@ assert adjusted_score <= 100;
    //@ assert adjusted_score >= 0;
    return adjusted_score;
}
