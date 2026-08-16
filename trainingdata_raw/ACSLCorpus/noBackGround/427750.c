#include <stdbool.h>
/*@
    requires (-1000000000 <= (a) <= 1000000000) && (-1000000000 <= (b) <= 1000000000) && (-1000000000 <= (c) <= 1000000000) && (-1000000000 <= (d) <= 1000000000);
    requires a <= b && c <= d;
    ensures \result == b * d || \result == b * c || \result == a * d || \result == a * c;
    ensures (-1000000000000000000 <= (\result) <= 1000000000000000000);
*/
long long func(long long a, long long b, long long c, long long d) {
    long long tmp[4];
    long long max_val;
    int i;
    
    //@ assert (-1000000000 <= (a) <= 1000000000);
    //@ assert (-1000000000 <= (b) <= 1000000000);
    //@ assert (-1000000000 <= (c) <= 1000000000);
    //@ assert (-1000000000 <= (d) <= 1000000000);
    
    //@ assert (-1000000000000000000 <= (a * c) <= 1000000000000000000);
    tmp[0] = a * c;
    
    //@ assert (-1000000000000000000 <= (a * d) <= 1000000000000000000);
    tmp[1] = a * d;
    
    //@ assert (-1000000000000000000 <= (b * c) <= 1000000000000000000);
    tmp[2] = b * c;
    
    //@ assert (-1000000000000000000 <= (b * d) <= 1000000000000000000);
    tmp[3] = b * d;
    
    max_val = tmp[0];
    i = 1;
    
    /*@
        loop invariant 0 <= i <= 4;
        loop invariant 1 <= 4 <= 4;
        loop invariant \exists integer k; 0 <= k < i && max_val == tmp[k];
        loop invariant \forall integer j; 0 <= j < i ==> max_val >= tmp[j];
        loop invariant (-1000000000 <= (a) <= 1000000000) && (-1000000000 <= (b) <= 1000000000) && (-1000000000 <= (c) <= 1000000000) && (-1000000000 <= (d) <= 1000000000);
        loop invariant a <= b && c <= d;
        loop invariant \forall integer k; 0 <= k < 4 ==> (-1000000000000000000 <= (tmp[k]) <= 1000000000000000000);
        loop invariant (-1000000000000000000 <= (max_val) <= 1000000000000000000);
        loop invariant (-1000000000000000000 <= (a * c) <= 1000000000000000000) && (-1000000000000000000 <= (a * d) <= 1000000000000000000) &&
                      (-1000000000000000000 <= (b * c) <= 1000000000000000000) && (-1000000000000000000 <= (b * d) <= 1000000000000000000);
        loop assigns max_val, i;
    */
    while (i < 4) {
        if (tmp[i] > max_val) {
            max_val = tmp[i];
        }
        i++;
    }
    return max_val;
}
