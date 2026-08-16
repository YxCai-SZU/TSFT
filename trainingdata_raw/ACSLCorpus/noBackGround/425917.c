#include <stdbool.h>
#include <stddef.h>

typedef struct {
    int* age;
    int* height;
    int* weight;
    size_t len;
} DataFrame;

/*@
    assigns \nothing;
*/
void main() {
    //@ assert \true;
}
