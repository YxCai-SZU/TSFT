#include <stdbool.h>

/* ====== First underlying function (triangle inequality) ====== */
/*@
    predicate is_valid_range_tri(integer x) = 1 <= x <= 100;
    logic integer square(integer x) = x * x;
    predicate triangle_inequality(integer a, integer b, integer c) =
        square(c) + square(b) > square(a) ||
        square(c) + square(a) > square(b) ||
        square(b) + square(a) > square(c);
    lemma square_bound:
        \forall integer x; is_valid_range_tri(x) ==> square(x) <= 10000;
    lemma sum_squares_bound_two:
        \forall integer x, integer y;
            is_valid_range_tri(x) && is_valid_range_tri(y) ==>
            square(x) + square(y) <= 20000;
    lemma sum_squares_bound_three:
        \forall integer x, integer y, integer z;
            is_valid_range_tri(x) && is_valid_range_tri(y) && is_valid_range_tri(z) ==>
            square(x) + square(y) + square(z) <= 30000;
*/
bool func_tri(unsigned int a, unsigned int b, unsigned int c)
{
    bool result;
    //@ assert is_valid_range_tri(a);
    //@ assert is_valid_range_tri(b);
    //@ assert is_valid_range_tri(c);
    //@ assert square(a) <= 10000;
    //@ assert square(b) <= 10000;
    //@ assert square(c) <= 10000;
    //@ assert square(a) + square(b) <= 20000;
    //@ assert square(a) + square(c) <= 20000;
    //@ assert square(b) + square(c) <= 20000;
    //@ assert square(a) + square(b) + square(c) <= 30000;
    result = (c * c + b * b > a * a) || 
             (c * c + a * a > b * b) || 
             (b * b + a * a > c * c);
    //@ assert result == true <==> triangle_inequality(a, b, c);
    return result;
}

/* ====== Second underlying function (sum threshold check) ====== */
/*@
    predicate is_valid_range_sum(int val) = 1 <= val <= 13;
    logic integer sum3(integer a, integer b, integer c) = a + b + c;
*/
bool func_sum(int v[3])
{
    int a;
    int b;
    int c;
    bool result;
    a = v[0];
    b = v[1];
    c = v[2];
    //@ assert is_valid_range_sum(a);
    //@ assert is_valid_range_sum(b);
    //@ assert is_valid_range_sum(c);
    result = (a + b + c) >= 22;
    return result;
}

/* ====== Third underlying function (sorted sum with bound) ====== */
/*@
    predicate sorted(integer a, integer b, integer c) = a <= b && b <= c;
    logic integer total_sum(integer a, integer b, integer c) = a + b + c;
    lemma ans_bound: \forall integer a, b, c, ans;
        a >= 0 && b >= 0 && c >= 0 && a <= 10 && b <= 10 && c <= 10 && ans >= 0 && ans <= total_sum(a, b, c) + 1 ==>
        ans >= 0 && ans <= total_sum(a, b, c) + 1;
*/
int func_sort_sum(int a, int b, int c)
{
    int a_local = a;
    int b_local = b;
    int c_local = c;
    int ans = 0;
    int temp;
    if (a_local > b_local)
    {
        temp = a_local;
        a_local = b_local;
        b_local = temp;
    }
    if (b_local > c_local)
    {
        temp = b_local;
        b_local = c_local;
        c_local = temp;
    }
    if (a_local > b_local)
    {
        temp = a_local;
        a_local = b_local;
        b_local = temp;
    }
    if (b_local > c_local)
    {
        temp = b_local;
        b_local = c_local;
        c_local = temp;
    }
    //@ assert sorted(a_local, b_local, c_local);
    ans += a_local;
    b_local -= a_local;
    if (b_local > 0)
    {
        ans += b_local + c_local;
    }
    else
    {
        ans += c_local;
    }
    //@ assert ans >= 0;
    //@ assert ans <= a_local + b_local + c_local + 1;
    return ans;
}

/* ====== Synthesized function: card hand strength evaluator ====== */
/* Scenario: In a card game (e.g., modified Blackjack), 
   three cards are drawn. Their values (1-10) are checked for:
   - They must form a valid triangle (side lengths 1-100) to be "balanced".
   - Their sum must be >= 22 to be "strong".
   - A sorted sum heuristic computes a "score" (0 to sum+1).
   The function returns the score if the hand is both balanced and strong,
   otherwise returns -1.
*/

/*@
    predicate hand_valid(int a, int b, int c) =
        1 <= a <= 10 && 1 <= b <= 10 && 1 <= c <= 10;
    predicate hand_balanced(int a, int b, int c) =
        triangle_inequality(a, b, c);
    predicate hand_strong(int a, int b, int c) =
        sum3(a, b, c) >= 22;
    predicate hand_score_valid(int score, int a, int b, int c) =
        score >= 0 && score <= total_sum(a, b, c) + 1;
*/

int evaluate_hand(int a, int b, int c)
{
    int result;
    bool balanced;
    bool strong;
    int v[3];
    int score;

    //@ assert is_valid_range_tri((unsigned int)a);
    //@ assert is_valid_range_tri((unsigned int)b);
    //@ assert is_valid_range_tri((unsigned int)c);
    balanced = func_tri((unsigned int)a, (unsigned int)b, (unsigned int)c);

    v[0] = a;
    v[1] = b;
    v[2] = c;
    //@ assert is_valid_range_sum(v[0]);
    //@ assert is_valid_range_sum(v[1]);
    //@ assert is_valid_range_sum(v[2]);
    strong = func_sum(v);

    if (balanced && strong)
    {
        //@ assert 0 <= a <= 10 && 0 <= b <= 10 && 0 <= c <= 10;
        score = func_sort_sum(a, b, c);
        //@ assert score >= 0 && score <= a + b + c + 1;
        result = score;
    }
    else
    {
        result = -1;
    }

    //@ assert (result >= 0) ==> (balanced && strong && hand_score_valid(result, a, b, c));
    return result;
}
