// Generated C + ACSL

struct Node {
  int value;
};

/*@
    assigns \nothing;
*/
void Main(void)
{
  struct Node node;
  node.value = 5;
  int x = ((((22 + node.value) + -(2 * 7)) + 1) + 7);
  int y = node.value;
}