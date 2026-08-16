#include <stdbool.h>
#include <stddef.h>

/*@
    requires ((k) >= 2 && (k) <= 1000000 &&
    (n) >= 2 && (n) <= 200000 &&
    \valid((numbers) + (0 .. (n)-1)) &&
    \forall integer i; 0 <= i < (n) ==> (numbers)[i] >= 0 && (numbers)[i] < (k) &&
    \forall integer i; 0 <= i < (n)-1 ==> (numbers)[i] < (numbers)[i+1]);
    assigns \nothing;
    ensures \result >= 0;
    ensures \result <= k;
*/
int func(int k, size_t n, const int *numbers) {
    int m = 0;
    size_t i = 0;
    
    /*@
        loop invariant (0 <= (i) <= (n)-1 &&
    (m) >= 0 &&
    (m) <= (k) &&
    \valid((numbers) + (0 .. (n)-1)) &&
    \forall integer j; 0 <= j < (n) ==> (numbers)[j] >= 0 && (numbers)[j] < (k) &&
    \forall integer j; 0 <= j < (n)-1 ==> (numbers)[j] < (numbers)[j+1] &&
    (k) >= 2 && (k) <= 1000000 &&
    (n) >= 2 && (n) <= 200000);
        loop assigns i, m;
        loop variant n-i;
    */
    while (i < n - 1) {
        int l = numbers[i + 1] - numbers[i];
        //@ assert l >= 0;
        if (l > m) {
            m = l;
        }
        i += 1;
    }
    
    int l = k - numbers[n - 1] + numbers[0];
    //@ assert l >= 0;
    if (l < m) {
        m = l;
    }
    
    int result = k - m;
    //@ assert result >= 0;
    //@ assert result <= k;
    return result;
}
