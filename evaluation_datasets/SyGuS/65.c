int main() {
    int x = 1;
    int y = 0;

    while (x <= 100) {
        y = 100 - x;
        x = x +1;
    }

    /*@ assert y >= 0; */

}
