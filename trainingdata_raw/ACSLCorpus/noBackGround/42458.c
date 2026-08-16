#include <stdbool.h>

/*@
    requires (3 <= (n) <= 20);
    requires (\valid((p) + (0 .. (n)-1)));
    requires (\forall integer j; 0 <= j < (n) ==> 1 <= (p)[j] <= (n));
    requires (\forall integer j; 0 <= j < (n)-1 ==> (p)[j] != (p)[j+1]);
    assigns \nothing;
    ensures \result >= 0;
*/
int func(int n, int *p) {
    int res = 0;
    int i = 1;
    
    /*@
        loop invariant 1 <= i <= n-1;
        loop invariant 3 <= n <= 20;
        loop invariant (\valid((p) + (0 .. (n)-1)));
        loop invariant (\forall integer j; 0 <= j < (n) ==> 1 <= (p)[j] <= (n));
        loop invariant (\forall integer j; 0 <= j < (n)-1 ==> (p)[j] != (p)[j+1]);
        loop invariant res >= 0;
        loop invariant res <= i-1;
        loop assigns i, res;
        loop variant n-i;
    */
    while (i < n - 1) {
        //@ assert 0 <= i-1 < n;
        //@ assert 0 <= i < n;
        //@ assert 0 <= i+1 < n;
        
        if ((p[i - 1] < p[i] && p[i] < p[i + 1]) || 
            (p[i - 1] > p[i] && p[i] > p[i + 1])) {
            //@ assert res >= 0;
            res = res + 1;
        }
        i += 1;
    }
    return res;
}

int main() {
    return 0;
}
