#include <stddef.h>
#include <stdbool.h>

/*@
  requires (1 <= (n) <= 200000);
  requires (\valid((numbers) + (0 .. (n)-1)) &&
      \forall integer i; 0 <= i < (n) ==> -1000000000 <= (numbers)[i] <= 1000000000);
  assigns \nothing;
  ensures 0 <= \result <= n;
*/
int func(size_t n, const int *numbers) {
    int ans = 0;
    size_t index = 0;
    
    /*@
      loop invariant 0 <= index <= n;
      loop invariant 0 <= ans <= index;
      loop invariant index > 0 ==> 
        \forall integer i; 0 <= i < index ==> -1000000000 <= numbers[i] <= 1000000000;
      loop invariant (1 <= (n) <= 200000);
      loop invariant (\valid((numbers) + (0 .. (n)-1)) &&
      \forall integer i; 0 <= i < (n) ==> -1000000000 <= (numbers)[i] <= 1000000000);
      loop invariant ans <= index;
      loop assigns ans, index;
      loop variant n - index;
    */
    while (index < n) {
        int a = numbers[index];
        if (a < 0) {
            ans += 1;
        }
        index += 1;
        //@ assert ans <= index;
    }
    return ans;
}

int main() {
    return 0;
}
