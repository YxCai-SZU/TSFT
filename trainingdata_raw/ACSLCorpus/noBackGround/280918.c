#include <stddef.h>
#include <stdbool.h>

/*@
  requires min <= max;
  requires \valid_read(arr + (0 .. len-1));
  assigns \nothing;
  ensures \result <= len;
  ensures \forall integer i; 0 <= i < len && ((min) <= (arr[i]) && (arr[i]) <= (max)) ==> 
            (\exists integer j; 0 <= j < (len) && (((min)) <= ((arr)[j]) && ((arr)[j]) <= ((max))));
*/
size_t count_integers_in_range(const int *arr, size_t len, int min, int max) {
    size_t count = 0;
    size_t i = 0;
    
    /*@
      loop invariant i <= len;
      loop invariant count <= i;
      loop invariant \forall integer j; 0 <= j < i && ((min) <= (arr[j]) && (arr[j]) <= (max)) ==> 
                      (\exists integer j; 0 <= j < (i) && (((min)) <= ((arr)[j]) && ((arr)[j]) <= ((max))));
      loop invariant min <= max;
      loop assigns i, count;
      loop variant len - i;
    */
    while (i < len) {
        //@ assert 0 <= i < len;
        if (arr[i] >= min && arr[i] <= max) {
            //@ assert ((min) <= (arr[i]) && (arr[i]) <= (max));
            count = count + 1;
        }
        i = i + 1;
    }
    return count;
}

/*@ assigns \nothing; */
int main() {
    return 0;
}
