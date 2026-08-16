#include <limits.h>

/*@
    requires (1 <= (b) && (b) <= (a) && (a) <= 20 &&
        1 <= (c) && (c) <= 20);
    ensures \result >= 0;
    ensures \result <= c;
    ensures \result == c - (a - b) || \result == 0;
*/
int func(int a, int b, int c)
{
    int min_val;
    int max_val;
    int ans;
    int final_ans;

    //@ assert (1 <= (b) && (b) <= (a) && (a) <= 20 &&         1 <= (c) && (c) <= 20);

    min_val = a < c ? a : c;
    //@ assert min_val == ((a) < (c) ? (a) : (c));

    max_val = (a - b) < 0 ? 0 : (a - b);
    //@ assert max_val == (((a) - (b)) < 0 ? 0 : ((a) - (b)));

    ans = min_val < max_val ? min_val : max_val;
    //@ assert ans == (((a) < (c) ? (a) : (c)) < (((a) - (b)) < 0 ? 0 : ((a) - (b))) ? ((a) < (c) ? (a) : (c)) : (((a) - (b)) < 0 ? 0 : ((a) - (b))));

    ans = c - ans;
    //@ assert ans == ((c) - ((((a)) < ((c)) ? ((a)) : ((c))) < ((((a)) - ((b))) < 0 ? 0 : (((a)) - ((b)))) ? (((a)) < ((c)) ? ((a)) : ((c))) : ((((a)) - ((b))) < 0 ? 0 : (((a)) - ((b))))));

    //@ assert ans >= 0;
    //@ assert ans <= c;
    //@ assert ans == c - (a - b) || ans == 0;

    final_ans = ans < 0 ? 0 : ans;
    //@ assert final_ans >= 0;
    //@ assert final_ans <= c;
    //@ assert final_ans == c - (a - b) || final_ans == 0;

    return final_ans;
}
