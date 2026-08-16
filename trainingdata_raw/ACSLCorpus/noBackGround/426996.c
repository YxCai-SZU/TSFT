#include <stdint.h>

/*@
    requires (0 <= (x) <= 1000000000);
    ensures ((\result) >= 0 && (\result) <= 2 * (x));
    assigns \nothing;
*/
int64_t func(int64_t x)
{
    int64_t result;
    
    if (x <= 0) {
        result = 0;
    } else {
        result = 2 * x - 1;
    }
    
    //@ assert result >= 0;
    //@ assert result <= 2 * x;
    
    return result;
}

/*@
    requires (0 <= (x) <= 1000000000);
    ensures ((\result) >= 0 && (\result) <= 2 * (x));
    assigns \nothing;
*/
int64_t func_unreachable(int64_t x)
{
    int64_t result;
    
    if (x <= 0) {
        result = 0;
    } else {
        result = 2 * x - 1;
        //@ assert result >= 0;
        //@ assert result <= 2 * x;
    }
    
    return result;
}

/*@
    requires (0 <= (x) <= 1000000000);
    ensures ((\result) >= 0 && (\result) <= 2 * (x));
    assigns \nothing;
*/
int64_t func_assertion(int64_t x)
{
    int64_t result;
    
    if (x <= 0) {
        result = 0;
    } else {
        result = 2 * x - 1;
        //@ assert result >= 0;
        //@ assert result <= 2 * x;
    }
    
    return result;
}

/*@
    requires (0 <= (x) <= 1000000000);
    ensures ((\result) >= 0 && (\result) <= 2 * (x));
    assigns \nothing;
*/
int64_t func_unreachable_neg(int64_t x)
{
    int64_t result;
    
    if (x <= 0) {
        result = 0;
    } else {
        result = 2 * x - 1;
        //@ assert result >= 0;
        //@ assert result <= 2 * x;
    }
    
    return result;
}
