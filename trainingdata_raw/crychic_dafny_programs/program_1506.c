// Generated C + ACSL

typedef struct {
  int value;
} Node;

/*@
    assigns \nothing;
*/
void Main(void)
{
  Node node;
  node.value = 5;
  int x = ((((22 + node.value) + -(2 * 7)) + 1) + 7);
  int y = node.value;
}