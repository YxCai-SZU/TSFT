#include <limits.h>

/*@
    requires (-100 <= (A) <= 100) && (-100 <= (B) <= 100);
    ensures \result == A + B || \result == A - B || \result == A * B;
    ensures \result >= A + B && \result >= A - B && \result >= A * B;
    assigns \nothing;
*/
int func(int A, int B)
{
    int add;
    int sub;
    int mul;
    int result;
    
    add = A + B;
    sub = A - B;
    
    //@ assert INT_MIN <= A * B <= INT_MAX;
    mul = A * B;
    
    if (add > sub && add > mul)
    {
        result = add;
    }
    else if (sub > mul)
    {
        result = sub;
    }
    else
    {
        result = mul;
    }
    
    //@ assert result == (((add) >= (sub) && (add) >= (mul)) ? (add) :         ((sub) >= (mul)) ? (sub) : (mul));
    return result;
}
