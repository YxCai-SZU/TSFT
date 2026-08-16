#include <limits.h>

/*@ requires (1 <= (a) && (a) <= 12) && (1 <= (b) && (b) <= 31);
    ensures \result >= 1 && \result <= 12;
    ensures \result == a || \result == a - 1;
    assigns \nothing;
 */
int func(int a, int b)
{
    //@ assert a >= 1 && a <= 12;
    //@ assert b >= 1 && b <= 31;
    //@ assert a - 1 >= 0 && a - 1 <= 11;
    
    int ans;
    if (a <= b) {
        ans = a;
    } else {
        ans = a - 1;
    }
    
    //@ assert ans >= 1 && ans <= 12;
    //@ assert ans == a || ans == a - 1;
    
    return ans;
}

/*@ assigns \nothing;
    ensures \result == 3;
 */
int read_i(void)
{
    return 3;
}

/*@ assigns \nothing;
    ensures \result == 5;
 */
int read_j(void)
{
    return 5;
}

int main(void)
{
    int i = read_i();
    int j = read_j();
    
    //@ assert (1 <= (i) && (i) <= 12) && (1 <= (j) && (j) <= 31);
    int res = func(i, j);
    
    return 0;
}
