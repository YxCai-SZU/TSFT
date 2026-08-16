typedef struct {
    int *arr;
    int len;
} Seq;


Seq reverse_array(int *arr, int len) {
    Seq result;
    int i;
    int j;

    result.arr = arr;
    result.len = len;

    //@ assert reverse_array_len: ((len)) == len;

    return result;
}

int main() {
    return 0;
}
