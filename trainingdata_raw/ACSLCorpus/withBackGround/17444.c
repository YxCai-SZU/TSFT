#include <stdbool.h>

/*@ logic integer volume_cube(integer l) = l * l * l; */

/*@ lemma volume_cube_is_nonlinear:
      \forall integer l; volume_cube(l) == l * l * l; */

int main() {
    //@ assert volume_cube(3) == 27;
    return 0;
}
