#include <stdbool.h>
#include <stddef.h>

/*@
  requires \valid_read(arr + (0..N-1));
  requires ((N) >= 1 && (N) <= 100000 &&
      (K) >= 1 && (K) <= 500);
  requires (\forall integer i; 0 <= i < (N) ==> (arr)[i] >= 1 && (arr)[i] <= 500);
  assigns \nothing;
  ensures 0 <= \result <= N;
*/
int count_expeditions(int *arr, size_t N, int K) {
    int count = 0;
    size_t index = 0;
    
    /*@
      loop invariant 0 <= index <= N;
      loop invariant 0 <= count <= (int)index;
      loop invariant ((N) >= 1 && (N) <= 100000 &&
      (K) >= 1 && (K) <= 500);
      loop invariant (\forall integer i; 0 <= i < (N) ==> (arr)[i] >= 1 && (arr)[i] <= 500);
      loop invariant \forall integer i; 0 <= i < (int)index ==> 
                    arr[i] >= K ==> count > 0;
      loop assigns index, count;
      loop variant N - index;
    */
    while (index < N) {
        int a = arr[index];
        if (a >= K) {
            count += 1;
        }
        index += 1;
    }
    return count;
}
