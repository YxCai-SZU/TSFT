#include <stdbool.h>
#include <stddef.h>

/*@
    requires ((A_len) >= 1 && (A_len) <= 200000 &&
        \forall integer k; 0 <= k < (A_len) ==> (A)[k] >= 1 && (A)[k] <= 1000000000);
    requires ((B_len) >= 1 && (B_len) <= 200000 &&
        \forall integer k; 0 <= k < (B_len) ==> (B)[k] >= 1 && (B)[k] <= 1000000000);
    ensures 0 <= \result <= B_len;
    assigns \nothing;
*/
int func(const int *A, size_t A_len, const int *B, size_t B_len) {
    int ans = 0;
    size_t i = 0;

    /*@
        loop invariant (0 <= (i) <= (B_len) &&
        0 <= (ans) <= (i));
        loop invariant ((A_len) >= 1 && (A_len) <= 200000 &&
        \forall integer k; 0 <= k < (A_len) ==> (A)[k] >= 1 && (A)[k] <= 1000000000);
        loop invariant ((B_len) >= 1 && (B_len) <= 200000 &&
        \forall integer k; 0 <= k < (B_len) ==> (B)[k] >= 1 && (B)[k] <= 1000000000);
        loop assigns i, ans;
        loop variant B_len - i;
    */
    while (i < B_len) {
        bool ok = false;
        size_t j = 0;

        /*@
            loop invariant (0 <= (j) <= (A_len));
            loop invariant ((A_len) >= 1 && (A_len) <= 200000 &&
        \forall integer k; 0 <= k < (A_len) ==> (A)[k] >= 1 && (A)[k] <= 1000000000);
            loop invariant ((B_len) >= 1 && (B_len) <= 200000 &&
        \forall integer k; 0 <= k < (B_len) ==> (B)[k] >= 1 && (B)[k] <= 1000000000);
            loop assigns j, ok;
            loop variant A_len - j;
        */
        while (j < A_len) {
            //@ assert 0 <= j < A_len ==> A[j] >= 1 && A[j] <= 1000000000;
            if (A[j] == B[i]) {
                ok = true;
                break;
            }
            j++;
        }

        if (ok) {
            ans++;
        }
        i++;
    }

    //@ assert 0 <= ans <= B_len;
    return ans;
}
