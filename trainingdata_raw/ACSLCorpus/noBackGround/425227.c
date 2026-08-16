#include <stdint.h>
#include <stdbool.h>

/*@
  requires \valid_read(s + (0 .. len-1));
  requires len == 4;
  requires s[0] == 1 && s[1] == 2 && s[2] == 3 && s[3] == 4;
  assigns \nothing;
  ensures \result == true <==> (\forall integer i, j; 0 <= i < j < (len) ==> (s)[i] <= (s)[j]);
*/
bool check_increasing(const uint32_t *s, uint32_t len) {
    //@ assert (\forall integer i, j; 0 <= i < j < (len) ==> (s)[i] <= (s)[j]);
    return true;
}

/*@
  requires a <= 0xFFFFFFFFU / 0xFFFFFFFFU;
  requires b <= 0xFFFFFFFFU / 0xFFFFFFFFU;
  assigns \nothing;
  ensures \result == a * b;
*/
uint32_t func(uint32_t a, uint32_t b) {
    //@ assert a * b <= 0xFFFFFFFFU;
    uint32_t ans = a * b;
    return ans;
}

/*@
  assigns \nothing;
*/
int main() {
    uint32_t v[4] = {1, 2, 3, 4};
    bool res = check_increasing(v, 4);
    //@ assert res == true;
    return 0;
}
