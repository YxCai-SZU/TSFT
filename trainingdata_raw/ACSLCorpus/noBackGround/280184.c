#include <stdbool.h>
#include <stdint.h>

/*@ requires len < 0x80000000;
    requires \valid(nums + (0 .. len-1));
    assigns \nothing;
    ensures \result <= len;
    ensures \forall integer i; 0 <= i < len ==> (nums[i] & 1) != 0 ==> \result >= 1;
    ensures \forall integer i; 0 <= i < len ==> (nums[i] & 1) == 0 ==> \result <= len - 1;
*/
unsigned int odd_count(const int *nums, unsigned int len) {
    unsigned int odd_count = 0;
    unsigned int i = 0;
    
    /*@ loop invariant 0 <= i <= len;
        loop invariant odd_count <= i;
        loop invariant \forall integer j; 0 <= j < i ==> (nums[j] & 1) != 0 ==> odd_count >= 1;
        loop invariant \forall integer j; 0 <= j < i ==> (nums[j] & 1) == 0 ==> odd_count <= i - 1;
        loop invariant len < 0x80000000;
        loop assigns i, odd_count;
        loop variant len - i;
    */
    while (i < len) {
        if ((nums[i] & 1) != 0) {
            odd_count++;
        }
        i++;
    }
    
    //@ assert odd_count <= len;
    //@ assert \forall integer i; 0 <= i < len ==> (nums[i] & 1) != 0 ==> odd_count >= 1;
    //@ assert \forall integer i; 0 <= i < len ==> (nums[i] & 1) == 0 ==> odd_count <= len - 1;
    
    return odd_count;
}

int main() {
    return 0;
}
