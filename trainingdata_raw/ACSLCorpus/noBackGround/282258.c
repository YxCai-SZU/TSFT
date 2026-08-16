#include <stdbool.h>

/*@
    requires (1 <= (n) && (n) <= 20) && (1 <= (m) && (m) <= 20);
    ensures \result == ((m) * 2 + ((n) - 1) * 4);
*/
int func(int n, int m)
{
    int result = 0;
    int temp_n = n;
    int temp_m = m;
    int m_two = 0;
    int count = 0;
    
    //@ ghost int original_m = m;
    
    /*@
        loop invariant 0 <= count <= m;
        loop invariant m_two == count * 2;
        loop invariant (1 <= (m) && (m) <= 20);
        loop assigns m_two, count;
        loop variant m - count;
    */
    while (count < m)
    {
        m_two += 2;
        count += 1;
        //@ assert m_two == count * 2;
    }
    
    int n_four = 0;
    count = 0;
    int n_minus_1 = n - 1;
    
    /*@
        loop invariant 0 <= count <= n_minus_1;
        loop invariant n_four == count * 4;
        loop invariant (1 <= (n) && (n) <= 20);
        loop assigns n_four, count;
        loop variant n_minus_1 - count;
    */
    while (count < n_minus_1)
    {
        n_four += 4;
        count += 1;
        //@ assert n_four == count * 4;
    }
    
    result = m_two + n_four;
    //@ assert result == ((m) * 2 + ((n) - 1) * 4);
    return result;
}

int main()
{
    return 0;
}
