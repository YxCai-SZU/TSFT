#include <stdbool.h>
#include <stddef.h>

/*@ requires \valid(c + (0 .. len-1));
    requires len > 0 && len <= 100;
    requires \forall integer i; 0 <= i < len ==> (c[i] == '.' || c[i] == '#');
    ensures \result >= 0;
    ensures \result <= len;
    assigns \nothing; */
int max_circular_track_collisions(char* c, int len) {
    int count = 0;
    int i = 0;
    
    /*@ loop invariant 0 <= i <= len;
        loop invariant 0 <= count <= i;
        loop invariant \forall integer j; 0 <= j < len ==> (c[j] == '.' || c[j] == '#');
        loop invariant \forall integer k; 0 <= k < i ==> (c[k] == '#' ==> count > 0);
        loop assigns i, count;
        loop variant len - i; */
    while (i < len) {
        //@ assert 0 <= i < len;
        if (c[i] == '#') {
            count = count + 1;
        }
        i = i + 1;
    }
    //@ assert i == len;
    //@ assert 0 <= count <= len;
    return count;
}
