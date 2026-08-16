#include <stdbool.h>

/*@ requires 1 <= a <= 9;
    requires 1 <= b <= 9;
    requires 1 <= c <= 9;
    ensures \result == (((a == b) && (b != c)) || ((b == c) && (c != a)) || ((c == a) && (a != b)));
*/
bool func(int a, int b, int c)
{
    bool bc = false;
    bool ac = false;
    bool ab = false;
    int i = 0;
    
    // First loop: check a == b
    /*@ loop invariant 0 <= i <= 9;
        loop invariant 1 <= a <= 9;
        loop invariant 1 <= b <= 9;
        loop invariant 1 <= c <= 9;
        loop invariant ((ab) == ((i) > 0 && (a) == (b)));
        loop assigns i, ab;
        loop variant 9 - i;
    */
    while (i < 9)
    {
        if (a == b)
        {
            ab = true;
            break;
        }
        i = i + 1;
    }
    
    // Second loop: check b == c
    i = 0;
    /*@ loop invariant 0 <= i <= 9;
        loop invariant 1 <= a <= 9;
        loop invariant 1 <= b <= 9;
        loop invariant 1 <= c <= 9;
        loop invariant ((bc) == ((i) > 0 && (b) == (c)));
        loop assigns i, bc;
        loop variant 9 - i;
    */
    while (i < 9)
    {
        if (b == c)
        {
            bc = true;
            break;
        }
        i = i + 1;
    }
    
    // Third loop: check c == a
    i = 0;
    /*@ loop invariant 0 <= i <= 9;
        loop invariant 1 <= a <= 9;
        loop invariant 1 <= b <= 9;
        loop invariant 1 <= c <= 9;
        loop invariant ((ac) == ((i) > 0 && (c) == (a)));
        loop assigns i, ac;
        loop variant 9 - i;
    */
    while (i < 9)
    {
        if (c == a)
        {
            ac = true;
            break;
        }
        i = i + 1;
    }
    
    // Combine results
    bool result = false;
    if (ab && !bc)
    {
        result = true;
    }
    else if (bc && !ac)
    {
        result = true;
    }
    else if (ac && !ab)
    {
        result = true;
    }
    
    //@ assert result == (((a == b) && (b != c)) || ((b == c) && (c != a)) || ((c == a) && (a != b)));
    return result;
}

int main()
{
    return 0;
}
