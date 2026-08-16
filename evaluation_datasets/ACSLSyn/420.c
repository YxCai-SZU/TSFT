#include <limits.h>
#include <stdbool.h>

/* Original function 1: maps 1-179 to categories 1-5 */
/*@
    predicate in_range(integer x) = 1 <= x <= 179;
    
    logic integer func_result(integer x) =
        (1 <= x <= 59) ? 1 :
        (60 <= x <= 89) ? 2 :
        (90 <= x <= 119) ? 3 :
        (120 <= x <= 149) ? 4 :
        (150 <= x <= 179) ? 5 : -1;
    
    lemma result_range: \forall integer x; in_range(x) ==> 
        func_result(x) == 1 || func_result(x) == 2 || func_result(x) == 3 || 
        func_result(x) == 4 || func_result(x) == 5;
    
    lemma result_implications: \forall integer x; in_range(x) ==>
        (func_result(x) == 1 ==> x <= 59) &&
        (func_result(x) == 2 ==> x <= 89) &&
        (func_result(x) == 3 ==> x <= 119) &&
        (func_result(x) == 4 ==> x <= 149) &&
        (func_result(x) == 5 ==> x <= 179);
*/

int func1(int x)
{
    unsigned int x_unsigned;
    int result;
    
    //@ assert in_range(x);
    
    if (x < 0) {
        x_unsigned = (unsigned int)(-x);
    } else {
        x_unsigned = (unsigned int)x;
    }
    
    //@ assert 1 <= x_unsigned <= 179;
    
    if (1 <= x_unsigned && x_unsigned <= 59) {
        result = 1;
    } else if (60 <= x_unsigned && x_unsigned <= 89) {
        result = 2;
    } else if (90 <= x_unsigned && x_unsigned <= 119) {
        result = 3;
    } else if (120 <= x_unsigned && x_unsigned <= 149) {
        result = 4;
    } else if (150 <= x_unsigned && x_unsigned <= 179) {
        result = 5;
    } else {
        result = -1;
    }
    
    //@ assert result == func_result(x);
    
    if (result == -1) {
        return -1;
    } else {
        //@ assert result == 1 || result == 2 || result == 3 || result == 4 || result == 5;
        //@ assert result == 1 ==> x <= 59;
        //@ assert result == 2 ==> x <= 89;
        //@ assert result == 3 ==> x <= 119;
        //@ assert result == 4 ==> x <= 149;
        //@ assert result == 5 ==> x <= 179;
        return result;
    }
}

/* Original function 2: range check */
/*@
    predicate is_valid_range(integer a, integer b, integer x) =
        1 <= a <= 100 && 1 <= b <= 100 && 1 <= x <= 200;

    lemma final_condition_lemma:
        \forall integer a, b, x;
            is_valid_range(a, b, x) && x <= a + b && a <= x ==>
            (x == a + b || (x - a) <= b);
*/

bool func2(unsigned long long a, unsigned long long b, unsigned long long x)
{
    bool result;

    if (x < a)
    {
        result = false;
        return result;
    }

    if (x > a + b)
    {
        result = false;
        return result;
    }

    //@ assert x <= a + b && a <= x;

    if (x == a + b || (x - a) <= b)
    {
        result = true;
        return result;
    }
    else
    {
        result = false;
        return result;
    }
}

/* Original function 3: consecutive digit check */
/*@ predicate is_consecutive_pair(integer a, integer b, integer c) =
      (a == b + 1 || b == c + 1 || a + 1 == c) &&
      !(a == b && b == c);
*/

/*@ predicate is_consecutive_triple(integer a, integer b, integer c) =
      a + 1 == b && b + 1 == c;
*/

/*@ lemma consecutive_pair_implies_result:
      \forall integer a, b, c;
        1 <= a <= 9 && 1 <= b <= 9 && 1 <= c <= 9 &&
        is_consecutive_pair(a, b, c) ==>
        is_consecutive_pair(a, b, c) || is_consecutive_triple(a, b, c);
*/

/*@ lemma consecutive_triple_implies_result:
      \forall integer a, b, c;
        1 <= a <= 9 && 1 <= b <= 9 && 1 <= c <= 9 &&
        is_consecutive_triple(a, b, c) ==>
        is_consecutive_pair(a, b, c) || is_consecutive_triple(a, b, c);
*/

bool func3(int a, int b, int c)
{
    bool result;
    
    if (a + 1 == b && b + 1 == c) {
        //@ assert is_consecutive_triple(a, b, c);
        return true;
    }

    if ((a == b + 1 || b == c + 1 || a + 1 == c) && !(a == b && b == c)) {
        //@ assert is_consecutive_pair(a, b, c);
        return true;
    }

    //@ assert !is_consecutive_pair(a, b, c) && !is_consecutive_triple(a, b, c);
    return false;
}

/* Original function 4: special property check */
/*@
    predicate condition_holds(integer n) =
        (n % 100) * 21 / 100 == n % 100;

    predicate condition_fails(integer n) =
        (n % 100) * 21 / 100 != n % 100;
*/

unsigned int func4(unsigned int n)
{
    unsigned int num;
    bool condition;
    unsigned int result;

    num = n % 100;
    condition = (num * 21 / 100) == num;

    //@ assert condition == true || condition == false;

    if (condition)
    {
        result = 1;
    }
    else
    {
        result = 0;
    }

    return result;
}

/* Synthesized function: Validates a sequence of three digits (1-9) and computes a score based on their properties.
   Scenario: In a game, three digits (1-9) are drawn. The function checks if they form a valid range pattern
   (using func2 to verify the digits are within a valid range), then checks if they are consecutive (func3),
   and finally computes a score category based on a secret property (func4). The score category is derived
   from the first digit using func1. The final assertion ensures that if the digits are consecutive and
   satisfy the secret property, the category is always 1 (lowest category), representing a special "jackpot"
   condition where the score is minimal despite the consecutive pattern. */

int synthesized_func(int a, int b, int c)
{
    unsigned long long a_ull = (unsigned long long)a;
    unsigned long long b_ull = (unsigned long long)b;
    unsigned long long c_ull = (unsigned long long)c;
    
    //@ assert 1 <= a <= 9 && 1 <= b <= 9 && 1 <= c <= 9;
    //@ assert is_valid_range(a_ull, b_ull, c_ull);
    bool range_valid = func2(a_ull, b_ull, c_ull);
    
    bool consecutive = func3(a, b, c);
    
    unsigned int special = func4((unsigned int)a);
    
    //@ assert in_range(a);
    int category = func1(a);
    
    //@ assert (is_consecutive_triple(a, b, c) && condition_holds((unsigned int)a)) ==> category == 1;
    
    return category;
}
