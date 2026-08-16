#include <stdbool.h>
#include <limits.h>

/*@
    predicate valid_range(int* arr, integer len) =
        len >= 3 &&
        \forall integer i; 0 <= i < len ==> 1 <= arr[i] <= 100;

    logic integer sum_triplet(integer a, integer b, integer c) =
        a + b + c;

    lemma sum_bounds:
        \forall integer a, b, c;
            1 <= a <= 100 && 1 <= b <= 100 && 1 <= c <= 100 ==>
            3 <= sum_triplet(a, b, c) <= 300;
*/

/*@
    requires \valid_read(v + (0 .. len-1));
    requires valid_range(v, len);
    ensures \result >= 0;
*/
int func(int* v, int len) {
    int min = INT_MAX;
    int index = 0;
    int i = 0;
    
    //@ ghost int old_min = min;
    //@ ghost int old_index = index;
    //@ ghost int old_i = i;
    
    /*@
        loop invariant 0 <= i <= len - 2;
        loop invariant valid_range(v, len);
        loop invariant min >= 0;
        loop invariant index >= 0;
        loop invariant \forall integer j; 0 <= j < i ==> 
            sum_triplet(v[j], v[j+1], v[j+2]) >= min;
        loop assigns i, min, index;
        loop variant len - 2 - i;
    */
    while (i < len - 2) {
        int a = v[i];
        int b = v[i + 1];
        int c = v[i + 2];
        
        //@ assert 1 <= a <= 100;
        //@ assert 1 <= b <= 100;
        //@ assert 1 <= c <= 100;
        //@ assert 3 <= a + b + c <= 300;
        
        int s = a + b + c;
        if (s < min) {
            min = s;
            index = i;
        }
        i++;
    }
    return min;
}

int main() {
    return 0;
}
