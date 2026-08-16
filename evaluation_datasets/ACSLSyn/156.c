#include <stdbool.h>

/*@
    predicate distributive(integer x, integer y) = x * (y + 1) == x * y + x;
    predicate subtraction(integer x, integer y) = x + y - y == x;
    predicate double_addition(integer x) = x + x == 2 * x;
    predicate subtraction_addition(integer x, integer y) = x + y - x == y;
*/

/*@
    lemma lemma_distributive: \forall integer x, y; distributive(x, y);
    lemma lemma_subtraction: \forall integer x, y; subtraction(x, y);
    lemma lemma_double_addition: \forall integer x; double_addition(x);
    lemma lemma_subtraction_addition: \forall integer x, y; subtraction_addition(x, y);
*/

/*@
    predicate a_in_range(integer a) = 3 <= a && a <= 20;
    predicate b_in_range(integer b) = 3 <= b && b <= 20;
    predicate result_range(integer result, integer a, integer b) =
        result >= 0 && result <= a + b + 1 && (result >= b + 1 || result >= a + 1);
*/

int calc_example_5(int x)
{
    int result = 0;
    int i = 0;
    for (i = 0; i < x; ++i)
    {
        //@ assert 2 * (i + 1) == 2 * i + 2;
        result = 2 * (i + 1);
    }
    //@ assert result == x * 2;
    return result;
}

int calc_example_6(int x)
{
    int result = 0;
    int i = 0;
    for (i = 0; i < x; ++i)
    {
        //@ assert 3 * (i + 1) == 3 * i + 3;
        result = 3 * (i + 1);
    }
    //@ assert result == x * 3;
    return result;
}

int func(int a, int b)
{
    int result;
    
    //@ assert a_in_range(a);
    //@ assert b_in_range(b);
    
    if (a < b) {
        result = a + (b - 1);
    } else {
        result = b + (a - 1);
    }
    
    //@ assert result >= 0 || result < 0;
    
    if (result < 0) {
        result = 0;
    } else {
        //@ assert result >= 0;
        //@ assert result <= a + b + 1;
        //@ assert result >= b + 1 || result >= a + 1;
    }
    
    //@ assert result_range(result, a, b);
    return result;
}

int process_data(int a, int b, int mode)
{
    int intermediate = func(a, b);
    int result;
    
    //@ assert result_range(intermediate, a, b);
    
    if (mode == 0) {
        result = calc_example_5(intermediate);
        //@ assert result == intermediate * 2;
    } else {
        result = calc_example_6(intermediate);
        //@ assert result == intermediate * 3;
    }
    
    //@ assert result >= 0;
    //@ assert result <= (a + b + 1) * 3;
    
    return result;
}
