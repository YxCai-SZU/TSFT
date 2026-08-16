#include <stdbool.h>
#include <stddef.h>

/*@ requires ((0 <= ((a)) <= 123) && (0 <= ((b)) <= 123) && (0 <= ((c)) <= 123) &&
      (0 <= ((d)) <= 123) && (0 <= ((e)) <= 123) && (0 <= ((k)) <= 123) &&
      (a) < (b) && (b) < (c) && (c) < (d) && (d) < (e));
    assigns \nothing;
    ensures \result == true;
*/
bool func(long a, long b, long c, long d, long e, long k) {
    long p[5];
    size_t n;
    size_t i;
    size_t j;
    long diff;
    
    //@ assert ((0 <= ((a)) <= 123) && (0 <= ((b)) <= 123) && (0 <= ((c)) <= 123) &&       (0 <= ((d)) <= 123) && (0 <= ((e)) <= 123) && (0 <= ((k)) <= 123) &&       (a) < (b) && (b) < (c) && (c) < (d) && (d) < (e));
    
    p[0] = a;
    p[1] = b;
    p[2] = c;
    p[3] = d;
    p[4] = e;
    n = 5;
    
    //@ assert (\forall integer i; 0 <= i < (n)-1 ==> (&p[0])[i] < (&p[0])[i+1]);
    
    i = 0;
    /*@ loop invariant 0 <= i <= n;
        loop invariant (\forall integer i; 0 <= i < (n)-1 ==> (&p[0])[i] < (&p[0])[i+1]);
        loop assigns i, j, diff;
        loop variant n - i;
    */
    while (i < n) {
        j = i + 1;
        /*@ loop invariant i < j <= n;
            loop invariant (\forall integer i; 0 <= i < (n)-1 ==> (&p[0])[i] < (&p[0])[i+1]);
            loop assigns j, diff;
            loop variant n - j;
        */
        while (j < n) {
            //@ assert p[j] > p[i];
            diff = p[j] - p[i];
            //@ assert diff >= 0;
            
            if (diff > k) {
                //@ assert diff > k;
            }
            j += 1;
        }
        i += 1;
    }
    
    //@ assert \true;
    return true;
}
