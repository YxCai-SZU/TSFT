#include <stdbool.h>
#include <stddef.h>

/*@ requires (1 <= (n) <= 20);
    requires \valid(v + (0 .. n-1)) && \valid(c + (0 .. n-1));
    requires (\forall integer i; 0 <= i < (n) ==> (1 <= ((v)[i]) <= 50)) && (\forall integer i; 0 <= i < (n) ==> (1 <= ((c)[i]) <= 50));
    ensures \result >= 0;
    assigns \nothing;
*/
int func(int n, int *v, int *c) {
    int sum = 0;
    int i = 0;
    
    /*@ loop invariant ((1 <= ((n)) <= 20) &&
      0 <= (i) <= (n) &&
      0 <= (sum) <= (i) * 50 &&
      (\forall integer i; 0 <= i < ((n)) ==> (1 <= (((v))[i]) <= 50)) &&
      (\forall integer i; 0 <= i < ((n)) ==> (1 <= (((c))[i]) <= 50)) &&
      (\forall integer k; 0 <= k < (i) ==> ((v)[k] - (c)[k] >= 1 ==> (sum) >= (v)[k] - (c)[k])));
        loop invariant \forall integer k; 0 <= k < i ==> (1 <= (v[k]) <= 50);
        loop invariant \forall integer k; 0 <= k < i ==> (1 <= (c[k]) <= 50);
        loop assigns sum, i;
        loop variant n - i;
    */
    while (i < n) {
        //@ assert (1 <= (v[i]) <= 50);
        //@ assert (1 <= (c[i]) <= 50);
        //@ assert -49 <= v[i] - c[i] <= 49;
        
        if (v[i] - c[i] >= 1) {
            sum += v[i] - c[i];
        }
        i++;
    }
    return sum;
}

int main() {
    return 0;
}
