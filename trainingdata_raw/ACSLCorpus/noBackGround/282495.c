#include <stdbool.h>
#include <stddef.h>

/*@
  requires ((v[0]) == (v[1]) || (v[1]) == (v[2]) || (v[0]) == (v[2])) &&
           (-100 <= (v[0]) <= 100) &&
           (-100 <= (v[1]) <= 100) &&
           (-100 <= (v[2]) <= 100);
  ensures (\result == v[0] || \result == v[1] || \result == v[2]) &&
          (-100 <= (\result) <= 100);
*/
int func(int v[3])
{
    int s[3];
    int i = 0;

    /*@ loop invariant 0 <= i <= 3;
        loop invariant \forall integer k; 0 <= k < i ==> v[k] == s[k];
        loop assigns i, s[0..2];
    */
    while (i < 3)
    {
        s[i] = v[i];
        i = i + 1;
    }

    int res = s[0];
    i = 1;

    /*@ loop invariant 0 <= i <= 3;
        loop invariant res == s[0] || res == s[1] || res == s[2];
        loop invariant (-100 <= (res) <= 100);
        loop assigns i, res;
    */
    while (i < 3)
    {
        if (s[i] == res)
        {
            res = s[i];
        }
        i = i + 1;
    }

    //@ assert res == s[0] || res == s[1] || res == s[2];
    //@ assert (-100 <= (res) <= 100);
    return res;
}
