#include <limits.h>

/*@
    predicate ans_range(integer ans) = 0 <= ans && ans <= 8;

    predicate ans_implies_8(integer ans, integer x) = ans == 8 ==> x < 600;
    predicate ans_implies_7(integer ans, integer x) = ans == 7 ==> (x < 800 && x >= 600);
    predicate ans_implies_6(integer ans, integer x) = ans == 6 ==> (x < 1000 && x >= 800);
    predicate ans_implies_5(integer ans, integer x) = ans == 5 ==> (x < 1200 && x >= 1000);
    predicate ans_implies_4(integer ans, integer x) = ans == 4 ==> (x < 1400 && x >= 1200);
    predicate ans_implies_3(integer ans, integer x) = ans == 3 ==> (x < 1600 && x >= 1400);
    predicate ans_implies_2(integer ans, integer x) = ans == 2 ==> (x < 1800 && x >= 1600);
    predicate ans_implies_1(integer ans, integer x) = ans == 1 ==> (x < 2000 && x >= 1800);
*/

/*@
    requires 400 <= x && x < 2000;
    ensures \result >= 0;
    ensures \result <= 8;
    ensures \result == 8 ==> x < 600;
    ensures \result == 7 ==> (x < 800 && x >= 600);
    ensures \result == 6 ==> (x < 1000 && x >= 800);
    ensures \result == 5 ==> (x < 1200 && x >= 1000);
    ensures \result == 4 ==> (x < 1400 && x >= 1200);
    ensures \result == 3 ==> (x < 1600 && x >= 1400);
    ensures \result == 2 ==> (x < 1800 && x >= 1600);
    ensures \result == 1 ==> (x < 2000 && x >= 1800);
    assigns \nothing;
*/
int func(int x)
{
    int ans;

    ans = 8;

    if (x < 600)
    {
        ans = 8;
    }
    else if (x < 800)
    {
        ans = 7;
    }
    else if (x < 1000)
    {
        ans = 6;
    }
    else if (x < 1200)
    {
        ans = 5;
    }
    else if (x < 1400)
    {
        ans = 4;
    }
    else if (x < 1600)
    {
        ans = 3;
    }
    else if (x < 1800)
    {
        ans = 2;
    }
    else if (x < 2000)
    {
        ans = 1;
    }

    //@ assert ans >= 0 && ans <= 8;

    return ans;
}
