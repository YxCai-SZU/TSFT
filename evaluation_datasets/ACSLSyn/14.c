#include <stdbool.h>
#include <stdint.h>

/* First function: determines if distance between two points is even */
/*@
    predicate valid_params(integer N, integer A, integer B) =
        1 <= N && N <= 10000 &&
        0 <= A && A < N &&
        0 <= B && B < N &&
        A < B;

    logic integer distance(integer A, integer B) = B - A;

    lemma distance_even_iff:
        \forall integer A, B;
        valid_params(10000, A, B) ==>
        (distance(A, B) % 2 == 0 <==> (B - A) % 2 == 0);
*/

bool func(unsigned int N, unsigned int A, unsigned int B)
{
    unsigned int diff;
    bool result;

    diff = B - A;

    //@ assert diff == B - A;

    if (diff % 2 == 0)
    {
        result = true;
        //@ assert result == true && (B - A) % 2 == 0;
        return result;
    }
    else
    {
        //@ assert (B - A) % 2 != 0;
        result = false;
        //@ assert result == false && (B - A) % 2 != 0;
        return result;
    }
}

/* Second function: computes X + Y/2 for even Y */
/*@
    predicate X_in_range(integer x) = 1 <= x <= 100;
    predicate Y_in_range(integer y) = 1 <= y <= 100;
    predicate Y_even(integer y) = y % 2 == 0;
*/

/*@
    logic integer half(integer y) = y / 2;
*/

/*@
    lemma half_property:
        \forall integer y;
            Y_even(y) ==> half(y) * 2 == y;
*/

int32_t func2(int32_t X, int32_t Y)
{
    uint32_t Y_unsigned;
    uint32_t half_Y_unsigned;
    int32_t half_Y;
    int32_t result;

    //@ assert Y >= 0;
    Y_unsigned = (uint32_t)Y;
    
    half_Y_unsigned = Y_unsigned / 2;
    
    half_Y = (int32_t)half_Y_unsigned;
    
    //@ assert half_Y == half(Y);
    
    result = X + half_Y;
    
    //@ assert result == X + half(Y);
    return result;
}

/* Synthesized function: 
   Scenario: Grid-based game resource calculation
   Given a grid of size N, a segment from position A to B, 
   and a resource multiplier X with base Y (must be even),
   compute the total resource cost if the segment distance is even,
   otherwise return 0.
   
   Data flow:
   1. Check if distance between A and B is even using func()
   2. If even, compute resource cost as X + Y/2 using func2()
   3. If odd, cost is 0
*/

/*@
    predicate valid_game_params(integer N, integer A, integer B, integer X, integer Y) =
        valid_params(N, A, B) &&
        X_in_range(X) &&
        Y_in_range(Y) &&
        Y_even(Y);
*/

int32_t compute_game_cost(unsigned int N, unsigned int A, unsigned int B, 
                          int32_t X, int32_t Y)
{
    bool is_even_distance;
    int32_t cost;
    
    is_even_distance = func(N, A, B);
    
    //@ assert is_even_distance == true <==> (B - A) % 2 == 0;
    
    if (is_even_distance)
    {
        cost = func2(X, Y);
        //@ assert cost == X + half(Y);
    }
    else
    {
        cost = 0;
        //@ assert cost == 0;
    }
    
    //@ assert (is_even_distance && cost == X + half(Y)) || (!is_even_distance && cost == 0);
    
    return cost;
}
