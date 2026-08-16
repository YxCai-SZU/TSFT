/*@
predicate is_palindrome{L}(char *s, integer len) =
    \forall integer i; 0 <= i < len / 2 ==> s[i] == s[len - i - 1];

lemma palindrome_property{L}:
    \forall char *s, integer len;
    is_palindrome(s, len) ==>
    \forall integer i; 0 <= i < len / 2 ==> s[i] == s[len - i - 1];
*/

/*@
requires \valid(s + (0 .. len-1));
requires is_palindrome(s, len);
ensures \forall integer i; 0 <= i < len / 2 ==> s[i] == s[len - i - 1];
*/
void test_palindrome(char *s, int len) {
    //@ assert is_palindrome(s, len);
}

int main() {
    return 0;
}
