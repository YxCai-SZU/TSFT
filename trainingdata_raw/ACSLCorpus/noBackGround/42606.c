#include <stdbool.h>

/*@
    requires (1 <= (A) <= 9) && (1 <= (B) <= 9) && (1 <= (C) <= 9);
    ensures \result == (((B * 10 + C) - A) >= 0 && ((B * 10 + C) - A) <= 10);
*/
bool func(unsigned int A, unsigned int B, unsigned int C)
{
    unsigned int c;
    int diff;
    bool result;

    c = B * 10 + C;
    //@ assert c >= 10;
    //@ assert c <= 99;
    diff = (int)c - (int)A;
    result = (diff >= 0 && diff <= 10);
    return result;
}
