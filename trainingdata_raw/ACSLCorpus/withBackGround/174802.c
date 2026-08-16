#include <stdbool.h>

/*@ logic integer volume_rectangular_prism(integer length, integer width, integer height) =
      (length <= 0 || width <= 0 || height <= 0) ? 0 : length * width * height;
*/

/*@ lemma broadcast_volume_rectangular_prism:
      \forall integer length, width, height;
        length >= 0 && width >= 0 && height >= 0 ==>
        volume_rectangular_prism(length, width, height) >= 0;
*/

/*@ lemma specific_volume_rectangular_prism:
      volume_rectangular_prism(2, 3, 4) >= 0 &&
      volume_rectangular_prism(10, 20, 30) >= 0 &&
      volume_rectangular_prism(100, 200, 300) >= 0;
*/

int main() {
    int length;
    int width;
    int height;
    int result;

    // Verify specific cases using the lemma
    //@ assert volume_rectangular_prism(2, 3, 4) >= 0;
    //@ assert volume_rectangular_prism(10, 20, 30) >= 0;
    //@ assert volume_rectangular_prism(100, 200, 300) >= 0;

    return 0;
}
