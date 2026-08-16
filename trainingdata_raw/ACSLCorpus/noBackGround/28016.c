#include <stdbool.h>
#include <stddef.h>

/*@
  requires \valid_read(v + (0 .. 4));
  requires v[0] < v[1] && v[1] < v[2] && v[2] < v[3] && v[3] < v[4];
  ensures \result == true <==> (v[0] == 1 && v[1] == 2 && v[2] == 3 && v[3] == 4 && v[4] == 5);
*/
bool func(int *v) {
    bool result;
    //@ assert v[0] < v[1] && v[1] < v[2] && v[2] < v[3] && v[3] < v[4];
    if (v[0] == 1 && v[1] == 2 && v[2] == 3 && v[3] == 4 && v[4] == 5) {
        result = true;
    } else {
        result = false;
    }
    //@ assert result == true <==> (v[0] == 1 && v[1] == 2 && v[2] == 3 && v[3] == 4 && v[4] == 5);
    return result;
}

int main() {
    int pattern[2];
    int s[4];
    pattern[0] = 3;
    pattern[1] = 4;
    s[0] = 1;
    s[1] = 2;
    s[2] = 3;
    s[3] = 4;
    //@ assert ((4) >= (2) &&       \forall integer i; 0 <= i < (2) ==> (&s[0])[(4) - (2) + i] == (&pattern[0])[i]);
    return 0;
}
