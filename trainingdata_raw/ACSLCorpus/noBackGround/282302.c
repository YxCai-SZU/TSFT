#include <stdbool.h>

enum ShapeTag { Circle, Square };

struct Shape {
    enum ShapeTag tag;
    int value;
};

/*@
    requires 1 <= r <= 100;
    ensures \result == 3 * r * r;
    assigns \nothing;
*/
long func(long r) {
    long result;
    //@ assert 1 <= r && r <= 100;
    result = 3 * r * r;
    //@ assert result == 3 * r * r;
    return result;
}

int main() {
    return 0;
}
