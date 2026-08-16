
int min_numbers(int a, int b, int c)
{
    int result;
    //@ assert \true;
    if (a <= b && a <= c) {
        result = a;
        //@ assert result == (((a) <= (b) && (a) <= (c)) ? (a) :         ((b) <= (a) && (b) <= (c)) ? (b) : (c));
    } else if (b <= a && b <= c) {
        result = b;
        //@ assert result == (((a) <= (b) && (a) <= (c)) ? (a) :         ((b) <= (a) && (b) <= (c)) ? (b) : (c));
    } else {
        result = c;
        //@ assert result == (((a) <= (b) && (a) <= (c)) ? (a) :         ((b) <= (a) && (b) <= (c)) ? (b) : (c));
    }
    //@ assert result <= a && result <= b && result <= c;
    return result;
}

int main() {
    return 0;
}
