#include <limits.h>

/*@
    requires (1 <= (a) <= 100);
    requires (1 <= (b) <= 100);
    requires (1 <= (c) <= 100);
    ensures \result <= a + b + c;
    ensures \result == a + b + c || \result == b + c || \result == a + c || \result == a + b;
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int result;
    int sum;
    int ab;
    int bc;
    int ca;

    result = INT_MAX;
    sum = a + b + c;
    
    //@ assert sum == a + b + c;
    
    if (a + b < sum)
        ab = a + b;
    else
        ab = sum;
    
    //@ assert ab == (a + b < sum ? a + b : sum);
    
    if (b + c < sum)
        bc = b + c;
    else
        bc = sum;
    
    //@ assert bc == (b + c < sum ? b + c : sum);
    
    if (c + a < sum)
        ca = c + a;
    else
        ca = sum;
    
    //@ assert ca == (c + a < sum ? c + a : sum);
    
    if (sum < result)
        result = sum;
    
    //@ assert result == (sum < INT_MAX ? sum : INT_MAX);
    
    if (ab < result)
        result = ab;
    
    //@ assert result == \min(sum, ab);
    
    if (bc < result)
        result = bc;
    
    //@ assert result == \min(\min(sum, ab), bc);
    
    if (ca < result)
        result = ca;
    
    //@ assert result == \min(\min(\min(sum, ab), bc), ca);
    
    //@ assert result == ((a) + (b) + (c) == \min((a) + (b) + (c), \min((a) + (b), \min((b) + (c), (a) + (c)))) ? (a) + (b) + (c) :         (b) + (c) == \min((a) + (b) + (c), \min((a) + (b), \min((b) + (c), (a) + (c)))) ? (b) + (c) :         (a) + (c) == \min((a) + (b) + (c), \min((a) + (b), \min((b) + (c), (a) + (c)))) ? (a) + (c) :         (a) + (b));
    
    return result;
}
