#include <stdbool.h>

/*@
  requires (1 <= (A) && (A) <= 100 &&
      1 <= (B) && (B) <= 100 &&
      1 <= (C) && (C) <= 100);
  ensures \result == (A + B + 1 >= C);
*/
bool func(unsigned int A, unsigned int B, unsigned int C)
{
    unsigned int a_performance;
    unsigned int b_performance;
    unsigned int c_performance;
    bool result;

    a_performance = A;
    b_performance = B;
    c_performance = C;

    //@ assert a_performance == A;
    //@ assert b_performance == B;
    //@ assert c_performance == C;

    result = (a_performance + b_performance + 1 >= c_performance);

    //@ assert result == (A + B + 1 >= C);

    return result;
}
