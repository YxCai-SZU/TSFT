#include <stdint.h>

/*@
    requires (0 <= (a) <= 1000000000 &&
        0 <= (b) <= 1000000000 &&
        0 <= (c) <= 1000000000 &&
        1 <= (k) <= 1000000000 &&
        (a) + (b) + (c) >= (k));
    ensures \result >= -c;
    ensures \result <= a;
    ensures \result == ((k) <= (a) ? (k) :
        (k) <= (a) + (b) ? (a) :
        (k) <= (a) + (b) + (c) ? (a) - ((k) - (a) - (b)) :
        (a) - (c));
*/
int64_t func(int64_t a, int64_t b, int64_t c, int64_t k)
{
    int64_t cnt;
    int64_t ans;
    
    cnt = k;
    ans = 0;
    
    //@ ghost int64_t original_a = a;
    //@ ghost int64_t original_c = c;
    
    if (cnt > a)
    {
        ans += a;
        cnt -= a;
    }
    else
    {
        ans += cnt;
        //@ assert ans == ((k) <= (original_a) ? (k) :         (k) <= (original_a) + (b) ? (original_a) :         (k) <= (original_a) + (b) + (original_c) ? (original_a) - ((k) - (original_a) - (b)) :         (original_a) - (original_c));
        return ans;
    }
    
    if (cnt > b)
    {
        cnt -= b;
    }
    else
    {
        //@ assert ans == ((k) <= (original_a) ? (k) :         (k) <= (original_a) + (b) ? (original_a) :         (k) <= (original_a) + (b) + (original_c) ? (original_a) - ((k) - (original_a) - (b)) :         (original_a) - (original_c));
        return ans;
    }
    
    if (cnt > c)
    {
        ans -= c;
    }
    else
    {
        ans -= cnt;
    }
    
    //@ assert ans == ((k) <= (original_a) ? (k) :         (k) <= (original_a) + (b) ? (original_a) :         (k) <= (original_a) + (b) + (original_c) ? (original_a) - ((k) - (original_a) - (b)) :         (original_a) - (original_c));
    return ans;
}
