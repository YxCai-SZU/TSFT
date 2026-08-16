#include <limits.h>

/*@ requires (1 <= (a) <= (b) <= 20);
    ensures ((\result) == (a) + (b) || (\result) == (b) - (a));
 */
long long func(long long a, long long b)
{
    long long result = 0;
    long long temp_a = a;
    long long temp_b = b;
    long long max = 0;
    long long min = 0;
    int is_even = 1;
    long long count = 0;
    
    //@ assert 1 <= a <= b <= 20;
    
    if (temp_a < 0) {
        temp_a = -temp_a;
    }
    if (temp_b < 0) {
        temp_b = -temp_b;
    }
    
    //@ assert temp_a >= 0 && temp_b >= 0;
    
    if (temp_a > temp_b) {
        max = temp_a;
        min = temp_b;
    } else {
        max = temp_b;
        min = temp_a;
    }
    
    //@ assert max >= 0 && min >= 0;
    //@ assert max >= min;
    
    /*@ loop invariant 0 <= count <= min;
        loop invariant is_even == (count % 2 == 0 ? 1 : 0);
        loop invariant max >= 0 && min >= 0;
        loop assigns count, is_even;
        loop variant min - count;
    */
    while (count < min) {
        if (is_even) {
            is_even = 0;
        } else {
            is_even = 1;
        }
        count = count + 1;
    }
    
    //@ assert count == min;
    //@ assert is_even == (min % 2 == 0 ? 1 : 0);
    
    if (is_even) {
        result = max + min;
        //@ assert result == max + min;
    } else {
        result = max - min;
        //@ assert result == max - min;
    }
    
    //@ assert result == a + b || result == b - a;
    return result;
}
