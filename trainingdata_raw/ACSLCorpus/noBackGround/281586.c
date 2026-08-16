#include <stdbool.h>
/*@
    requires 1 <= n <= 9;
    ensures \result == n * n * n;
*/
unsigned int func(unsigned int n)
{
    //@ assert 1 <= n && n <= 9;
    //@ assert n * n <= 81;
    //@ assert n * n * n <= 729;
    return n * n * n;
}

/*@
    requires 1 <= n <= 100;
    requires 1 <= m <= n;
    ensures \result == n - m;
*/
int func2(int n, int m)
{
    //@ assert 1 <= n && n <= 100;
    //@ assert 1 <= m && m <= n;
    return n - m;
}

/*@
    requires 1 <= n <= 100;
    requires 1 <= m <= n;
    ensures \result == n - m;
*/
int func3(int n, int m)
{
    //@ assert 1 <= n && n <= 100;
    //@ assert 1 <= m && m <= n;
    return n - m;
}

/*@
    requires 1 <= n <= 100;
    requires 1 <= m <= n;
    ensures \result == n - m;
*/
int func4(int n, int m)
{
    //@ assert 1 <= n && n <= 100;
    //@ assert 1 <= m && m <= n;
    return n - m;
}

/*@
    requires 1 <= n <= 100;
    requires 1 <= m <= n;
    ensures \result == n - m;
*/
int func5(int n, int m)
{
    //@ assert 1 <= n && n <= 100;
    //@ assert 1 <= m && m <= n;
    return n - m;
}

int main()
{
    return 0;
}
