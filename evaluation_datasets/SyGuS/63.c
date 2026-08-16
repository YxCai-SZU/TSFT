int main() {
    int x = 1;
    int y = 0;

    while (x <= 10) {
        y = 10 - x;
        x = x +1;
    }

    /*@ assert y >= 0; */

}
