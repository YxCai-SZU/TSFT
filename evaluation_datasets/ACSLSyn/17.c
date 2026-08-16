#include <stdbool.h>
#include <stdint.h>

/* First function: checks if a move is valid in a Shogi-like game */
/*@
    predicate is_valid_range(integer x, integer y) =
        1 <= x <= 100 && 1 <= y <= 100;

    predicate condition1(integer y) = y % 2 != 0;
    predicate condition2(integer x, integer y) = 
        x * 2 <= y && y <= x * 4 && y % 2 == 0;

    predicate expected_result(integer x, integer y) = 
        condition1(y) || condition2(x, y);
*/

bool shogi_move_valid(unsigned int x, unsigned int y)
{
    bool is_even;
    bool condition1_val;
    bool condition2_val;
    bool is_shogi;

    //@ assert is_valid_range(x, y);
    
    is_even = (y % 2 == 0);
    condition1_val = (y % 2 != 0);
    condition2_val = (x * 2 <= y && y <= x * 4 && y % 2 == 0);

    if (is_even)
    {
        is_shogi = condition1_val || condition2_val;
    }
    else
    {
        is_shogi = true;
    }

    //@ assert is_shogi == (condition1_val || condition2_val);
    
    return is_shogi;
}

/* Second function: computes the third value in a set of three distinct values */
/*@
    predicate valid_inputs(integer a, integer b) =
        1 <= a <= 3 && 1 <= b <= 3 && a != b;

    logic integer answer_val(integer a, integer b) = 6 - a - b;

    lemma answer_range: \forall integer a, b; valid_inputs(a, b) ==> 1 <= answer_val(a, b) <= 3;
*/

int64_t compute_third_value(uint64_t a, uint64_t b) {
    uint64_t answer;
    
    answer = 6 - a - b;
    
    //@ assert answer == 6 - a - b;
    //@ assert 1 <= answer <= 3;
    
    return (int64_t)answer;
}

/* Synthesized function: Game move processor */
int64_t process_game_move(unsigned int x, unsigned int y, uint64_t a, uint64_t b)
{
    bool move_valid;
    int64_t response;
    
    /* Step 1: Validate the move */
    move_valid = shogi_move_valid(x, y);
    
    /* Step 2: If move is valid, compute the opponent's response value */
    if (move_valid) {
        response = compute_third_value(a, b);
        //@ assert expected_result(x, y) && (response == 1 || response == 2 || response == 3);
    } else {
        response = -1;
        //@ assert !expected_result(x, y);
    }
    
    return response;
}
