#include <stdbool.h>
/*@
    requires \valid(s + (0 .. 2));
    requires ((3) == 3 &&
        \forall integer i; 0 <= i < (3) ==> ((s)[i] == 0 || (s)[i] == 1));
    ensures \result <==> (((s)[0] == 0 && (s)[1] == 0 && (s)[2] == 0) ||
        ((s)[0] == 1 && (s)[1] == 1 && (s)[2] == 1) ||
        ((s)[0] == 1 && (s)[1] == 0 && (s)[2] == 1) ||
        ((s)[0] == 0 && (s)[1] == 1 && (s)[2] == 0));
*/
bool func(int *s)
{
    int s0;
    int s1;
    int s2;
    bool result;

    s0 = s[0];
    s1 = s[1];
    s2 = s[2];

    if (s0 == 0 && s1 == 0 && s2 == 0)
    {
        //@ assert s[0] == 0 && s[1] == 0 && s[2] == 0;
        result = true;
        return result;
    }
    if (s0 == 1 && s1 == 1 && s2 == 1)
    {
        //@ assert s[0] == 1 && s[1] == 1 && s[2] == 1;
        result = true;
        return result;
    }
    if (s0 == 1 && s1 == 0 && s2 == 1)
    {
        //@ assert s[0] == 1 && s[1] == 0 && s[2] == 1;
        result = true;
        return result;
    }
    if (s0 == 0 && s1 == 1 && s2 == 0)
    {
        //@ assert s[0] == 0 && s[1] == 1 && s[2] == 0;
        result = true;
        return result;
    }
    result = false;
    return result;
}
