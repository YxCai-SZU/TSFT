#include <stdbool.h>

/*@
    requires 1 <= A <= 100;
    requires 1 <= B <= 100;
    ensures \result == (A > B);
    assigns \nothing;
*/
bool func(int A, int B)
{
    bool ans = false;
    //@ assert 1 <= A <= 100 && 1 <= B <= 100;
    
    if (A > B) {
        ans = true;
    } else {
        ans = false;
    }
    
    //@ assert ans == (A > B);
    return ans;
}

/*@
    requires 1 <= N <= 100;
    ensures \result == (((N) + 1) / 2);
    assigns \nothing;
*/
int func2(int N)
{
    int result = 0;
    int temp = N;
    int count = 0;
    //@ assert 1 <= N <= 100;
    
    /*@
        loop invariant 0 <= temp <= N;
        loop invariant 0 <= count <= N / 2;
        loop invariant temp == N - 2 * count;
        loop invariant 1 <= N <= 100;
        loop assigns temp, count;
        loop variant temp;
    */
    while (temp > 1) {
        temp -= 2;
        count += 1;
    }
    
    result = count + (temp == 1 ? 1 : 0);
    //@ assert result == (N + 1) / 2;
    return result;
}

/*@
    requires 0 <= X <= 1;
    ensures \result == (1 - (X));
    assigns \nothing;
*/
int func3(int X)
{
    int result = 0;
    //@ assert 0 <= X <= 1;
    
    if (X == 0) {
        result = 1;
    } else {
        result = 0;
    }
    
    //@ assert result == 1 - X;
    return result;
}
