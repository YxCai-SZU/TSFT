#include <stdbool.h>

/*@
    requires 1 <= k <= 1000;
    requires 1 <= a <= b <= 1000;
    ensures \result == true <==> ((a) % (k) == 0 || (b) % (k) == 0 || (b) - (a) >= (k) || (a) % (k) > (b) % (k));
 */
bool func(unsigned int k, unsigned int a, unsigned int b)
{
    // Variable declarations at top of scope
    unsigned int i;
    bool result;

    if (a % k == 0 || b % k == 0)
    {
        result = true;
        //@ assert ((a) % (k) == 0 || (b) % (k) == 0 || (b) - (a) >= (k) || (a) % (k) > (b) % (k));
        return result;
    }
    else if (b - a >= k)
    {
        result = true;
        //@ assert ((a) % (k) == 0 || (b) % (k) == 0 || (b) - (a) >= (k) || (a) % (k) > (b) % (k));
        return result;
    }
    else if (a % k > b % k)
    {
        result = true;
        //@ assert ((a) % (k) == 0 || (b) % (k) == 0 || (b) - (a) >= (k) || (a) % (k) > (b) % (k));
        return result;
    }
    else
    {
        i = a;
        /*@
            loop invariant a <= i <= b + 1;
            loop invariant 1 <= k <= 1000;
            loop invariant 1 <= a <= b <= 1000;
            loop invariant !((a) % (k) == 0 || (b) % (k) == 0 || (b) - (a) >= (k) || (a) % (k) > (b) % (k));
            loop assigns i;
            loop variant b - i;
         */
        while (i < b)
        {
            i = i + 1;
        }
        result = false;
        //@ assert !((a) % (k) == 0 || (b) % (k) == 0 || (b) - (a) >= (k) || (a) % (k) > (b) % (k));
        return result;
    }
}
