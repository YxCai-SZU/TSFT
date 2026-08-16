#include <stdbool.h>

/*@ predicate is_even_def(integer y, bool is_even) = 
      is_even == (y % 2 == 0); */

/*@ lemma func_lemma: 
      \forall integer x, y, bool is_even;
      1 <= x <= 100 && 1 <= y <= 100 && is_even_def(y, is_even) ==>
      (is_even && x * 2 <= y) == (x * 2 <= y && y % 2 == 0); */

/*@ requires 1 <= x <= 100 && 1 <= y <= 100;
    ensures \result == (x * 2 <= y && y % 2 == 0);
    assigns \nothing; */
bool func(int x, int y)
{
    bool is_even;
    //@ ghost bool is_even_proof;
    
    is_even = (y % 2 == 0) ? true : false;
    //@ ghost is_even_proof = is_even;
    
    //@ assert is_even_def(y, is_even_proof);
    
    if (is_even && x * 2 <= y) {
        return true;
    } else {
        return false;
    }
}

/*@ requires 1 <= x <= 100 && 1 <= y <= 100;
    ensures \result == (x * 2 <= y && y % 2 == 0);
    assigns \nothing; */
bool func2(int x, int y)
{
    bool is_even;
    //@ ghost bool is_even_proof;
    
    is_even = (y % 2 == 0) ? true : false;
    //@ ghost is_even_proof = is_even;
    
    //@ assert is_even_def(y, is_even_proof);
    
    if (is_even && x * 2 <= y) {
        return true;
    } else {
        return false;
    }
}

/*@ requires 1 <= x <= 100 && 1 <= y <= 100;
    ensures \result == (x * 2 <= y && y % 2 == 0);
    assigns \nothing; */
bool func3(int x, int y)
{
    bool is_even;
    //@ ghost bool is_even_proof;
    
    is_even = (y % 2 == 0) ? true : false;
    //@ ghost is_even_proof = is_even;
    
    //@ assert is_even_def(y, is_even_proof);
    
    if (is_even && x * 2 <= y) {
        return true;
    } else {
        return false;
    }
}
