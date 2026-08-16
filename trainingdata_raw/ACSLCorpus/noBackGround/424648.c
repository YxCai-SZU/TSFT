/*@
    requires 0 <= lst1 <= 100;
    requires 0 <= lst2 <= 100;
    ensures \result >= lst1;
    ensures \result >= lst2;
    ensures \result <= lst1 + lst2;
    assigns \nothing;
*/
int max_list_func(int lst1, int lst2) {
    int result;
    
    //@ ghost int original_lst1 = lst1;
    //@ ghost int original_lst2 = lst2;
    
    if (lst1 <= 0) {
        result = lst2;
        //@ assert ((original_lst1) <= 0 ? (original_lst2) : ((original_lst1) > (original_lst2) ? (original_lst1) : (original_lst2))) == original_lst2;
    } else if (lst1 > lst2) {
        result = lst1;
        //@ assert ((original_lst1) <= 0 ? (original_lst2) : ((original_lst1) > (original_lst2) ? (original_lst1) : (original_lst2))) == original_lst1;
    } else {
        result = lst2;
        //@ assert ((original_lst1) <= 0 ? (original_lst2) : ((original_lst1) > (original_lst2) ? (original_lst1) : (original_lst2))) == original_lst2;
    }
    
    //@ assert result == ((original_lst1) <= 0 ? (original_lst2) : ((original_lst1) > (original_lst2) ? (original_lst1) : (original_lst2)));
    //@ assert result >= original_lst1;
    //@ assert result >= original_lst2;
    //@ assert result <= original_lst1 + original_lst2;
    
    return result;
}

int main() {
    return 0;
}
