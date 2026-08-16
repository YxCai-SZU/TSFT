#include <stdbool.h>

/*@
    predicate in_range(integer x) = -100 <= x && x <= 100;
    predicate within_bounds(integer A, integer B, integer C) =
        in_range(A) && in_range(B) && in_range(C) && A <= B;
    predicate is_between(integer A, integer C, integer B) = A <= C && C <= B;
*/

/*@
    requires within_bounds(A, B, C);
    ensures \result == true <==> is_between(A, C, B);
*/
bool func(long long A, long long B, long long C)
{
    //@ assert within_bounds(A, B, C);
    if (A <= C && C <= B) {
        return true;
    } else {
        return false;
    }
}

/*@
    requires within_bounds(A, B, C);
    ensures \result == true <==> is_between(A, C, B);
*/
bool func2(long long A, long long B, long long C)
{
    int state = 0;
    //@ assert within_bounds(A, B, C);
    
    if (A <= C) {
        state += 1;
    }
    if (C <= B) {
        state += 1;
    }
    
    //@ assert state == 2 ==> is_between(A, C, B);
    //@ assert state == 0 ==> !is_between(A, C, B);
    
    return state == 2;
}

/*@
    requires within_bounds(A, B, C);
    ensures \result == true <==> is_between(A, C, B);
*/
bool func3(long long A, long long B, long long C)
{
    int state = 0;
    //@ assert within_bounds(A, B, C);
    
    if (A <= C) {
        state += 1;
    }
    if (C <= B) {
        state += 2;
    }
    
    //@ assert state == 3 ==> is_between(A, C, B);
    //@ assert state == 0 ==> !is_between(A, C, B);
    
    return state == 3;
}

/*@
    requires within_bounds(A, B, C);
    ensures \result == true <==> is_between(A, C, B);
*/
bool func4(long long A, long long B, long long C)
{
    int state = 0;
    //@ assert within_bounds(A, B, C);
    
    if (A <= C) {
        state = 1;
    }
    if (C <= B) {
        state = state + 2;
    }
    
    //@ assert state == 3 ==> is_between(A, C, B);
    //@ assert state == 0 ==> !is_between(A, C, B);
    
    return state == 3;
}

/*@
    requires within_bounds(A, B, C);
    ensures \result == true <==> is_between(A, C, B);
*/
bool func5(long long A, long long B, long long C)
{
    bool first = false;
    bool second = false;
    //@ assert within_bounds(A, B, C);
    
    if (A <= C) {
        first = true;
    }
    if (C <= B) {
        second = true;
    }
    
    //@ assert first && second ==> is_between(A, C, B);
    //@ assert !first && !second ==> !is_between(A, C, B);
    
    return first && second;
}
