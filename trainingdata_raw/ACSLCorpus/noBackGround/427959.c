#include <stdbool.h>
#include <stddef.h>

/*@
  requires \valid(v+(0..len-1));
  requires len > 0;
  requires \forall integer i; 0 <= i < len ==> ((v[i]) > 0);
  ensures \result == true;
*/
bool process_list(const int* v, size_t len) {
    size_t j = 0;
    /*@
      loop invariant 0 <= j <= len;
      loop invariant \forall integer i; 0 <= i < j ==> ((v[i]) > 0);
      loop assigns j;
      loop variant len - j;
    */
    while (j < len) {
        //@ assert ((v[j]) > 0);
        if (!(v[j] > 0)) {
            return false;
        }
        j++;
    }
    return true;
}

void test_concat_list(void) {
    int list1[2] = {1, 2};
    int list2[2] = {3, 4};
    int concatenated_list[4];
    size_t i = 0;
    
    /*@
      loop invariant 0 <= i <= 2;
      loop invariant \forall integer j; 0 <= j < i ==> concatenated_list[j] == list1[j];
      loop assigns i, concatenated_list[0..1];
      loop variant 2 - i;
    */
    while (i < 2) {
        concatenated_list[i] = list1[i];
        i++;
    }
    
    i = 0;
    /*@
      loop invariant 0 <= i <= 2;
      loop invariant \forall integer j; 0 <= j < 2 ==> concatenated_list[j] == list1[j];
      loop invariant \forall integer j; 0 <= j < i ==> concatenated_list[2 + j] == list2[j];
      loop assigns i, concatenated_list[2..3];
      loop variant 2 - i;
    */
    while (i < 2) {
        concatenated_list[2 + i] = list2[i];
        i++;
    }
    
    //@ assert concatenated_list[0] == 1;
}

int main(void) {
    return 0;
}
