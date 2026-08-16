#include <stdint.h>
#include <stddef.h>

/*@
  requires (\valid((nums1) + (0 .. (len1)-1))) && (\valid((nums2) + (0 .. (len2)-1)));
  requires ((len1) == (len2));
  requires ((len1) < 0x80000000);
  requires (\forall size_t i; 0 <= i < (len1) ==> (nums1)[i] <= 0x7FFFFFFF);
  requires (\forall size_t i; 0 <= i < (len2) ==> (nums2)[i] >= 0x80000000);
  ensures \result >= 0;
  ensures \result <= (int32_t)len1;
  ensures \forall size_t i; 0 <= i < len1 && nums1[i] > nums2[i] ==> \result >= 1;
  ensures \forall size_t i; 0 <= i < len1 && nums1[i] <= nums2[i] ==> \result >= 0;
*/
int32_t count_greater_than(int32_t* nums1, size_t len1, int32_t* nums2, size_t len2)
{
    int32_t count = 0;
    size_t i = 0;
    
    /*@ loop invariant 0 <= i <= len1;
        loop invariant 0 <= i <= len2;
        loop invariant count >= 0;
        loop invariant count <= (int32_t)i;
        loop invariant \forall size_t j; 0 <= j < i && nums1[j] > nums2[j] ==> count >= 1;
        loop invariant \forall size_t j; 0 <= j < i && nums1[j] <= nums2[j] ==> count >= 0;
        loop invariant len1 == len2;
        loop invariant len1 < 0x80000000;
        loop invariant (\forall size_t i; 0 <= i < (len1) ==> (nums1)[i] <= 0x7FFFFFFF);
        loop invariant (\forall size_t i; 0 <= i < (len2) ==> (nums2)[i] >= 0x80000000);
        loop assigns i, count;
        loop variant len1 - i;
    */
    while (i < len1 && i < len2) {
        //@ assert i < len1 && i < len2;
        if (nums1[i] > nums2[i]) {
            //@ assert nums1[i] > nums2[i];
            count += 1;
        }
        i += 1;
    }
    //@ assert count >= 0;
    return count;
}
