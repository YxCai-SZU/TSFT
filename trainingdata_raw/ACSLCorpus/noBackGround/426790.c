#include <limits.h>

/*@
    requires (1 <= (a) <= 10000 &&
        1 <= (b) <= 10000 &&
        1 <= (c) <= 10000 &&
        1 <= (d) <= 10000);
    ensures \result >= 0;
    ensures \result <= 2 * (a + b + c + d);
    assigns \nothing;
*/
int func(unsigned int a, unsigned int b, unsigned int c, unsigned int d)
{
    int tmp;
    int ans;
    int min1;
    int min2;
    int min3;

    tmp = (int)(a + b + c + d);
    ans = INT_MAX;

    //@ assert tmp == (int)(a + b + c + d);
    min1 = tmp < (int)(a + b + c + d - b) ? tmp : (int)(a + b + c + d - b);
    //@ assert min1 == (tmp < (int)(a + b + c + d - b) ? tmp : (int)(a + b + c + d - b));
    ans = ans < min1 ? ans : min1;
    //@ assert ans == (ans < min1 ? ans : min1);

    tmp = (int)(a + b + c + d - c);
    //@ assert tmp == (int)(a + b + c + d - c);
    min2 = tmp < (int)(a + b + c + d - b - c) ? tmp : (int)(a + b + c + d - b - c);
    //@ assert min2 == (tmp < (int)(a + b + c + d - b - c) ? tmp : (int)(a + b + c + d - b - c));
    ans = ans < min2 ? ans : min2;
    //@ assert ans == (ans < min2 ? ans : min2);

    tmp = (int)(a + b + c + d - d);
    //@ assert tmp == (int)(a + b + c + d - d);
    min3 = tmp < (int)(a + b + c + d - b - c - d) ? tmp : (int)(a + b + c + d - b - c - d);
    //@ assert min3 == (tmp < (int)(a + b + c + d - b - c - d) ? tmp : (int)(a + b + c + d - b - c - d));
    ans = ans < min3 ? ans : min3;
    //@ assert ans == (ans < min3 ? ans : min3);

    //@ assert ans >= 0;
    //@ assert ans <= 2 * (int)(a + b + c + d);
    return ans;
}
