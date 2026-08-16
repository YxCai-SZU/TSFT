#include <stdbool.h>

/*@ requires ((n) >= 1 && (n) <= 100 &&
    (x) >= 1 && (x) <= 10000 &&
    \valid((ls) + (0 .. (n)-1)) &&
    \forall integer i; 0 <= i < (n) ==> (ls)[i] >= 1 && (ls)[i] <= 100);
    assigns \nothing;
    ensures \result >= 1 && \result <= n + 1;
*/
int func(int n, int x, int *ls) {
    int ans = 1;
    int d = 0;
    int index = 0;
    
    /*@ assert ((index) >= 0 && (index) <= (n) &&
    \valid((ls) + (0 .. (n)-1)) &&
    (d) >= 0 && (d) <= (index) * 100 &&
    (ans) >= 1 && (ans) <= (index) + 1); */
    
    /*@ loop invariant ((index) >= 0 && (index) <= (n) &&
    \valid((ls) + (0 .. (n)-1)) &&
    (d) >= 0 && (d) <= (index) * 100 &&
    (ans) >= 1 && (ans) <= (index) + 1);
        loop assigns d, ans, index;
        loop variant n - index;
    */
    while (index < n) {
        int l = ls[index];
        d = d + l;
        
        /*@ assert d >= 0; */
        
        if (d > x) {
            break;
        }
        
        ans += 1;
        index += 1;
        
        /*@ assert ((index) >= 0 && (index) <= (n) &&
    \valid((ls) + (0 .. (n)-1)) &&
    (d) >= 0 && (d) <= (index) * 100 &&
    (ans) >= 1 && (ans) <= (index) + 1); */
    }
    
    /*@ assert ans >= 1; */
    /*@ assert ans <= n + 1; */
    return ans;
}

int main() {
    return 0;
}
