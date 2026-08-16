#include <stdbool.h>
#include <stddef.h>

/*@ predicate nonnegative(integer x) = x >= 0;

lemma linear_arithmetic_lemma:
    \forall integer x; nonnegative(x) ==> 3*x + 4 >= x + 4;

lemma subtract_negate_lemma:
    \forall integer x; nonnegative(x) ==> x - (-x) == 2*x;
*/

int linear_arithmetic(int x)
{
    //@ assert x >= 0;
    //@ assert x <= x + 3;
    //@ assert 3*x >= x;
    //@ assert 3*x + 4 >= x + 4;
    return 3 * x + 4;
}

int subtract_negate(int x)
{
    //@ assert x - (-x) == 2*x;
    return x - (-x);
}

/*@ predicate valid_input(integer x, integer y) =
      1 <= x && x <= 205 &&
      1 <= y && y <= 205;
*/

/*@ predicate case_1_1(integer x, integer y) =
      x == 1 && y == 1;
*/

/*@ predicate case_1_other(integer x, integer y) =
      x == 1 && y != 1;
*/

/*@ predicate case_other_1(integer x, integer y) =
      x != 1 && y == 1;
*/

/*@ predicate case_other_other(integer x, integer y) =
      x != 1 && y != 1;
*/

/*@ lemma postcondition_holds:
      \forall integer x, y, r;
      valid_input(x, y) ==>
      (case_1_1(x, y) ==> r == 1000000) &&
      (case_1_other(x, y) ==> r == 600000) &&
      (case_other_1(x, y) ==> r == 600000) &&
      (case_other_other(x, y) ==> r == 0) ==>
      r >= 0;
*/

int func(int x, int y)
{
    int result;
    
    //@ assert valid_input(x, y);
    
    if (x == 1 && y == 1) {
        //@ assert case_1_1(x, y);
        result = 1000000;
        //@ assert result >= 0;
        return result;
    }
    
    if (x == 1 || y == 1) {
        //@ assert case_1_other(x, y) || case_other_1(x, y);
        result = 600000;
        //@ assert result >= 0;
        return result;
    }
    
    //@ assert case_other_other(x, y);
    int v[4];
    int index;
    
    v[0] = 1000000;
    v[1] = 600000;
    v[2] = 600000;
    v[3] = 0;
    
    index = (x - 1) * 2 + (y - 1);
    
    if (index < 4) {
        result = v[index];
        //@ assert result >= 0;
        return result;
    } else {
        //@ assert case_other_other(x, y);
        result = 0;
        //@ assert result >= 0;
        return result;
    }
}

int process_bonus(int x, int y)
{
    int base = func(x, y);
    
    int a = linear_arithmetic(base);
    
    int b = subtract_negate(base);
    
    //@ assert a >= base + 4 && b == 2 * base;
    
    int combined = a + b;
    
    //@ assert combined >= 3 * base + 4;
    //@ assert combined >= 0;
    
    return combined;
}
