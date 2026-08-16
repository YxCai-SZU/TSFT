#include <limits.h>

/*@
    requires (1 <= (a) <= 5000);
    requires (1 <= (b) <= 5000);
    requires (1 <= (c) <= 5000);
    requires (1 <= (d) <= 5000);
    ensures \result >= (a < b ? a : b);
    ensures \result >= (c < d ? c : d);
    ensures \result <= a + c;
    ensures \result <= b + d;
    assigns \nothing;
*/
int func(int a, int b, int c, int d)
{
    int min_ab;
    int min_cd;
    int min_sum;
    int max_val;
    int ans;

    //@ assert (1 <= (a) <= 5000);
    //@ assert (1 <= (b) <= 5000);
    //@ assert (1 <= (c) <= 5000);
    //@ assert (1 <= (d) <= 5000);

    min_ab = (a < b) ? a : b;
    //@ assert min_ab == (((((a)) < ((b))) ? ((a)) : ((b))));

    min_cd = (c < d) ? c : d;
    //@ assert min_cd == (((((c)) < ((d))) ? ((c)) : ((d))));

    min_sum = min_ab + min_cd;
    //@ assert min_sum == (((((((a))) < (((b)))) ? (((a))) : (((b))))) + ((((((c))) < (((d)))) ? (((c))) : (((d))))));

    max_val = (a + c < b + d) ? a + c : b + d;
    //@ assert max_val == (((((a) + (c)) < ((b) + (d))) ? ((a) + (c)) : ((b) + (d))));

    ans = (min_sum < max_val) ? min_sum : max_val;
    //@ assert ans == ((((((((((((a)))) < ((((b))))) ? ((((a)))) : ((((b)))))) + (((((((c)))) < ((((d))))) ? ((((c)))) : ((((d)))))))) < (((((((a)) + ((c))) < (((b)) + ((d)))) ? (((a)) + ((c))) : (((b)) + ((d))))))) ? (((((((((a)))) < ((((b))))) ? ((((a)))) : ((((b)))))) + (((((((c)))) < ((((d))))) ? ((((c)))) : ((((d)))))))) : (((((((a)) + ((c))) < (((b)) + ((d)))) ? (((a)) + ((c))) : (((b)) + ((d))))))));

    //@ assert ans >= (((((a)) < ((b))) ? ((a)) : ((b))));
    //@ assert ans >= (((((c)) < ((d))) ? ((c)) : ((d))));
    //@ assert ans <= a + c;
    //@ assert ans <= b + d;

    return ans;
}
