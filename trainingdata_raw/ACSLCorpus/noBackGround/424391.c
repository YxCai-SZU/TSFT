#include <stdint.h>
#include <stdbool.h>

/*@
    requires ((n) >= 2 && (n) <= 100 &&
    \valid((weights) + (0 .. (n)-1)) &&
    \forall integer i; 0 <= i < (n) ==> (weights)[i] >= 1 && (weights)[i] <= 100);
    ensures ((\result) >= 0 && (\result) <= (n));
    assigns \nothing;
*/
int64_t func(int64_t n, int64_t *weights) {
    int64_t ans = n;
    int64_t i = 1;
    
    /*@
        loop invariant 1 <= i <= n;
        loop invariant ((n) >= 2 && (n) <= 100 &&
    \valid((weights) + (0 .. (n)-1)) &&
    \forall integer i; 0 <= i < (n) ==> (weights)[i] >= 1 && (weights)[i] <= 100);
        loop invariant ((ans) >= 0 && (ans) <= (n));
        loop assigns i, ans;
        loop variant n - i;
    */
    while (i < n) {
        int64_t s1 = 0;
        int64_t j = 0;
        
        /*@
            loop invariant 0 <= j <= i;
            loop invariant ((n) >= 2 && (n) <= 100 &&
    \valid((weights) + (0 .. (n)-1)) &&
    \forall integer i; 0 <= i < (n) ==> (weights)[i] >= 1 && (weights)[i] <= 100);
            loop invariant s1 >= 0;
            loop invariant s1 <= j * 100;
            loop assigns j, s1;
            loop variant i - j;
        */
        while (j < i) {
            //@ assert 0 <= j < n;
            s1 += weights[j];
            j++;
        }
        
        int64_t s2 = 0;
        j = i;
        
        /*@
            loop invariant i <= j <= n;
            loop invariant ((n) >= 2 && (n) <= 100 &&
    \valid((weights) + (0 .. (n)-1)) &&
    \forall integer i; 0 <= i < (n) ==> (weights)[i] >= 1 && (weights)[i] <= 100);
            loop invariant s2 >= 0;
            loop invariant s2 <= (j - i) * 100;
            loop assigns j, s2;
            loop variant n - j;
        */
        while (j < n) {
            //@ assert i <= j < n;
            s2 += weights[j];
            j++;
        }
        
        int64_t s;
        if (s1 > s2) {
            s = s1 - s2;
        } else {
            s = s2 - s1;
        }
        
        //@ assert s >= 0;
        if (ans < s) {
            ans = ans;
        } else {
            ans = s;
        }
        
        i++;
    }
    
    //@ assert ((ans) >= 0 && (ans) <= (n));
    return ans;
}

int main() {
    return 0;
}
