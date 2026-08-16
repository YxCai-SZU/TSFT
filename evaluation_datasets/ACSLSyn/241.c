#include <stdbool.h>
#include <stdint.h>

/* ===== First function (card sorting) ===== */
/*@
    predicate valid_vector(int *v, integer len) =
        len >= 3 &&
        \forall integer i; 0 <= i < 3 ==> (v[i] >= 1 && v[i] <= 13);
*/

/*@
    logic integer sorted_value(integer a, integer b, integer c) =
        (c < 2 * b - a) ? 1 :
        (c < 2 * b) ? 2 : 3;
*/

/*@
    lemma result_range:
        \forall integer a, b, c;
        a >= 1 && a <= 13 && b >= 1 && b <= 13 && c >= 1 && c <= 13 ==>
        sorted_value(a, b, c) >= 1 && sorted_value(a, b, c) <= 3;
*/

int func1(int *v)
{
    int a;
    int b;
    int c;
    int temp;

    a = v[0];
    b = v[1];
    c = v[2];

    //@ assert a >= 1 && a <= 13;
    //@ assert b >= 1 && b <= 13;
    //@ assert c >= 1 && c <= 13;

    if (a > b)
    {
        temp = a;
        a = b;
        b = temp;
    }

    //@ assert a <= b;

    if (b > c)
    {
        temp = b;
        b = c;
        c = temp;
    }

    //@ assert b <= c;

    if (a > b)
    {
        temp = a;
        a = b;
        b = temp;
    }

    //@ assert a <= b && b <= c;

    if (c < 2 * b - a)
    {
        //@ assert sorted_value(a, b, c) == 1;
        return 1;
    }
    else if (c < 2 * b)
    {
        //@ assert sorted_value(a, b, c) == 2;
        return 2;
    }
    else
    {
        //@ assert c >= 2 * b;
        //@ assert sorted_value(a, b, c) == 3;
        return 3;
    }
}

/* ===== Second function (score calculation) ===== */
/*@
    predicate is_valid_input(integer a, integer b, integer c) =
        1 <= a && a <= 100 &&
        1 <= b && b <= 100 &&
        1 <= c && c <= 100;

    logic integer calculate_min(integer a, integer b, integer c) =
        (a < b ? (a < c ? a : c) : (b < c ? b : c));

    lemma min_bounds:
        \forall integer a, b, c;
        is_valid_input(a, b, c) ==>
        1 <= calculate_min(a, b, c) && calculate_min(a, b, c) <= 100;
*/

uint32_t func2(uint32_t a, uint32_t b, uint32_t c)
{
    uint32_t min;
    uint32_t l;
    uint32_t result;

    //@ assert is_valid_input(a, b, c);
    
    min = (a < b) ? a : b;
    //@ assert min == (a < b ? a : b);
    min = (min < c) ? min : c;
    //@ assert min == calculate_min(a, b, c);
    
    l = min * 2 + 1;
    //@ assert l == calculate_min(a, b, c) * 2 + 1;
    
    if (l > a + b + c)
    {
        result = 3;
        //@ assert result == 3;
    }
    else if (a == b && b == c)
    {
        result = 1;
        //@ assert result == 1;
    }
    else
    {
        //@ assert a != b || b != c;
        result = 2;
        //@ assert result == 2;
    }
    
    //@ assert result >= 1 && result <= 3;
    return result;
}

/* ===== Third function (range check) ===== */
/*@
    predicate is_valid_range(integer a, integer b) =
        1 <= a && a <= b && b <= 1000000000000000000;
    
    predicate is_valid_k(integer k) =
        1 <= k && k <= 1000000000000000000;
    
    logic integer condition_holds(integer a, integer b, integer k) =
        (a % k == 0) ? 1 : ((b % k == 0) ? 1 : ((a / k < b / k) ? 1 : 0));
*/

bool func3(unsigned long long a, unsigned long long b, unsigned long long k)
{
    bool ans = false;
    
    //@ assert is_valid_range(a, b);
    //@ assert is_valid_k(k);
    
    if (a % k == 0 || b % k == 0)
    {
        ans = true;
        //@ assert condition_holds(a, b, k) == 1;
    }
    else if (a / k < b / k)
    {
        ans = true;
        //@ assert condition_holds(a, b, k) == 1;
    }
    
    //@ assert ans == (condition_holds(a, b, k) == 1);
    return ans;
}

/* ===== Synthesized function: Card game score validator ===== */
/*@
    predicate valid_game_state(int *cards, uint32_t score1, uint32_t score2, unsigned long long range_start, unsigned long long range_end, unsigned long long k) =
        valid_vector(cards, 3) &&
        is_valid_input(score1, score2, 1) &&
        is_valid_range(range_start, range_end) &&
        is_valid_k(k);
*/

int process_game(int *cards, uint32_t score1, uint32_t score2, unsigned long long range_start, unsigned long long range_end, unsigned long long k)
{
    int card_rank;
    uint32_t base_score;
    bool range_valid;
    int final_result;
    
    card_rank = func1(cards);
    //@ assert card_rank >= 1 && card_rank <= 3;
    
    base_score = func2(score1, score2, card_rank);
    //@ assert base_score >= 1 && base_score <= 3;
    
    range_valid = func3(range_start, range_end, k);
    //@ assert range_valid == (condition_holds(range_start, range_end, k) == 1);
    
    if (range_valid && base_score == 1)
    {
        final_result = 1;
    }
    else if (range_valid && base_score == 2)
    {
        final_result = 1;
    }
    else if (!range_valid && base_score == 3)
    {
        final_result = 1;
    }
    else
    {
        final_result = 0;
    }
    
    //@ assert (final_result == 1) <==> ((range_valid && (base_score == 1 || base_score == 2)) || (!range_valid && base_score == 3));
    return final_result;
}
