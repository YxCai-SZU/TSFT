#include <stdint.h>

/*@
    requires ((A) != (B) &&
        (A) >= -1000000000 && (A) <= 1000000000 &&
        (B) >= -1000000000 && (B) <= 1000000000);
    ensures \result >= 0;
*/
int64_t func(int64_t A, int64_t B)
{
    int64_t max_val;
    int64_t min_val;
    int64_t diff;
    int64_t abs_diff;
    int64_t ans;

    //@ assert ((A) != (B) &&         (A) >= -1000000000 && (A) <= 1000000000 &&         (B) >= -1000000000 && (B) <= 1000000000);

    if (A > B) {
        max_val = A;
    } else {
        max_val = B;
    }

    if (A < B) {
        min_val = A;
    } else {
        min_val = B;
    }

    //@ assert max_val == (((A) > (B)) ? (A) : (B));
    //@ assert min_val == (((A) < (B)) ? (A) : (B));

    if (max_val - min_val < 0) {
        diff = -max_val + min_val;
        abs_diff = max_val - min_val;
    } else {
        diff = max_val - min_val;
        abs_diff = max_val - min_val;
    }

    //@ assert diff == ((((((A)) > ((B))) ? ((A)) : ((B))) - ((((A)) < ((B))) ? ((A)) : ((B))) < 0) ?          (-((((A)) > ((B))) ? ((A)) : ((B))) + ((((A)) < ((B))) ? ((A)) : ((B)))) :          (((((A)) > ((B))) ? ((A)) : ((B))) - ((((A)) < ((B))) ? ((A)) : ((B)))));
    //@ assert abs_diff == (((((A)) > ((B))) ? ((A)) : ((B))) - ((((A)) < ((B))) ? ((A)) : ((B))));
    //@ assert diff >= 0;
    //@ assert abs_diff >= 0;

    if (A + diff == B) {
        ans = diff;
    } else if (A + abs_diff == B) {
        ans = abs_diff;
    } else {
        ans = abs_diff + 1;
    }

    //@ assert ans >= 0;
    return ans;
}
