#include <stdbool.h>

/*@ requires 1 <= n <= 100;
    requires 1 <= m <= 100;
    ensures \result >= 0;
    ensures \result == n - 2 * m || \result == 0;
*/
int func(int n, int m)
{
    int result;
    result = n - 2 * m;
    if (result > 0)
    {
        //@ assert result == n - 2 * m;
        return result;
    }
    else
    {
        //@ assert result == n - 2 * m;
        return 0;
    }
}

/*@ requires \valid(s + (0..2));
    requires \valid(t + (0..2));
    requires \forall integer i; 0 <= i < 3 ==> ('A' <= (s[i]) && (s[i]) <= 'Z');
    requires \forall integer i; 0 <= i < 3 ==> ('A' <= (t[i]) && (t[i]) <= 'Z');
    ensures \result == (s[0] == t[2] && s[1] == t[1] && s[2] == t[0]);
*/
bool func2(char *s, char *t)
{
    //@ assert \valid(s + (0..2));
    //@ assert \valid(t + (0..2));
    //@ assert \forall integer i; 0 <= i < 3 ==> ('A' <= (s[i]) && (s[i]) <= 'Z');
    //@ assert \forall integer i; 0 <= i < 3 ==> ('A' <= (t[i]) && (t[i]) <= 'Z');
    return s[0] == t[2] && s[1] == t[1] && s[2] == t[0];
}
