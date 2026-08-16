#include <stdbool.h>

/*@ requires ((a) >= 2 && (b) >= 3 && (a) > (b));
    ensures ((a) + (b) - 1 < (a) + (b));
    assigns \nothing;
*/
void calc_example_8(int a, int b) {
    //@ assert ((a) >= 2 && (b) >= 3 && (a) > (b));
    //@ assert ((a) + (b) - 1 < (a) + (b));
}

/*@ requires ((a) >= 2 && (b) >= 3 && (a) < (b));
    ensures ((a) + (b) < (a) + (b) + 1);
    assigns \nothing;
*/
void calc_example_9(int a, int b) {
    //@ assert ((a) >= 2 && (b) >= 3 && (a) < (b));
    //@ assert ((a) + (b) < (a) + (b) + 1);
}

int main() {
    return 0;
}
