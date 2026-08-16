#include <stdbool.h>
#include <stddef.h>

/*@
    requires \valid(arr + (0 .. len-1));
    requires len > 0;
    assigns \nothing;
    ensures \exists integer i; 0 <= i < len && arr[i] == \result;
    ensures \forall integer j; 0 <= j < len ==> arr[j] <= \result;
*/
unsigned int max_element(const unsigned int* arr, size_t len) {
    unsigned int max = arr[0];
    size_t i = 1;
    
    /*@
        loop invariant 1 <= i <= len;
        loop invariant \exists integer j; 0 <= j < i && arr[j] == max;
        loop invariant \forall integer j; 0 <= j < i ==> arr[j] <= max;
        loop assigns max, i;
        loop variant len - i;
    */
    while (i < len) {
        if (arr[i] > max) {
            max = arr[i];
        }
        i = i + 1;
    }
    return max;
}

/*@
    requires (1 <= (k) <= 1000 && 1 <= (a) <= (b) <= 1000);
    assigns \nothing;
    ensures \result == (b / k * k >= a);
*/
bool func(unsigned int k, unsigned int a, unsigned int b) {
    //@ assert b / k <= 1000;
    //@ assert (b / k) * k <= 1000 * 1000;
    
    bool ans = (b / k) * k >= a;
    return ans;
}
