#include <stdbool.h>

/*@ requires (\valid((v)) && \valid((v)+4));
    requires (\forall integer i; 0 <= i < 5 ==> 0 <= (v)[i] <= 123);
    requires ((v)[0] < (v)[1] && (v)[1] < (v)[2] && (v)[2] < (v)[3] && (v)[3] < (v)[4]);
    requires 0 <= k <= 123;
    ensures \result == true <==> (\forall integer i, j; 0 <= i < j < 5 ==> (v)[j] - (v)[i] <= (k));
*/
bool func(int *v, int k) {
    int i = 0;
    int j = 0;
    
    /*@ loop invariant 0 <= i <= 5;
        loop invariant (\valid((v)) && \valid((v)+4));
        loop invariant (\forall integer i; 0 <= i < 5 ==> 0 <= (v)[i] <= 123);
        loop invariant ((v)[0] < (v)[1] && (v)[1] < (v)[2] && (v)[2] < (v)[3] && (v)[3] < (v)[4]);
        loop invariant (\forall integer x, y; 0 <= x < (i) && 0 <= y < 5 ==> (v)[y] - (v)[x] <= (k));
        loop assigns i, j;
        loop variant 5 - i;
    */
    while (i < 5) {
        j = 0;
        
        /*@ loop invariant 0 <= j <= 5;
            loop invariant 0 <= i < 5;
            loop invariant (\valid((v)) && \valid((v)+4));
            loop invariant (\forall integer i; 0 <= i < 5 ==> 0 <= (v)[i] <= 123);
            loop invariant ((v)[0] < (v)[1] && (v)[1] < (v)[2] && (v)[2] < (v)[3] && (v)[3] < (v)[4]);
            loop invariant (\forall integer x, y; 0 <= x < (i) && 0 <= y < 5 ==> (v)[y] - (v)[x] <= (k));
            loop invariant (\forall integer y; 0 <= y < (j) ==> (v)[y] - (v)[(i)] <= (k));
            loop assigns j;
            loop variant 5 - j;
        */
        while (j < 5) {
            //@ assert 0 <= v[j] <= 123;
            //@ assert 0 <= v[i] <= 123;
            //@ assert v[j] - v[i] <= 123;
            
            int diff = (v[i] > v[j]) ? (v[i] - v[j]) : (v[j] - v[i]);
            if (diff > k) {
                return false;
            }
            j++;
        }
        i++;
    }
    return true;
}
