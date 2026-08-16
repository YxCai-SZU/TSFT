#include <stdbool.h>
/*@
    requires 1 <= n <= 9;
    ensures \result == n * n * n;
    assigns \nothing;
*/
int func(int n)
{
    int result;
    //@ assert 1 <= n && n <= 9;
    //@ assert 1 <= n * n && n * n <= 81;
    //@ assert 1 <= n * n * n && n * n * n <= 729;
    result = n * n * n;
    return result;
}

/*@
    assigns \nothing;
*/
void main2(void)
{
    int v[5] = {1, 2, 3, 4, 5};
    //@ ghost int s[5] = {1, 2, 3, 4, 5};
    //@ assert s[2] == 3;
    //@ assert s[3] == 4;
    //@ assert ((s[2]) <= (s[3]) && (s[3]) <= (4));
}

/*@
    assigns \nothing;
*/
void main3(void)
{
    int v[5] = {1, 2, 3, 4, 5};
    //@ ghost int s[5] = {1, 2, 3, 4, 5};
    //@ assert ((s[2]) <= (s[3]) && (s[3]) <= (4));
}
