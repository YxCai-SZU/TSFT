// Generated C + ACSL

// Structure to hold canvas state
typedef struct {
    int isOpen;
    int width;
    int height;
    int shapes;
    int lineThickness;
    int currentColor;
} Canvas;

Canvas* this;

/*@
    requires width_prime > 0;
    requires height_prime > 0;
    requires \valid(this);
    assigns *this;
    ensures \result == 1 ==> this->isOpen == 1;
    ensures \result == 0 ==> this->isOpen == \old(this->isOpen);
    ensures \result == 1 ==> this->shapes == 0;
    ensures \result == 1 ==> this->shapes >= 0;
*/
int Open(int width_prime, int height_prime)
{
  int success;
  if (!(this->isOpen))
  {
    this->width = width_prime;
    /*@ assert this->width >= 0 && this->width <= 2147483647; */
    this->height = height_prime;
    /*@ assert this->height >= 0 && this->height <= 2147483647; */
    this->isOpen = 1;
    /*@ assert this->isOpen >= 0 && this->isOpen <= 2147483647; */
    this->shapes = 0;
    /*@ assert this->shapes >= 0 && this->shapes <= 2147483647; */
    success = 1;
    /*@ assert success >= 0 && success <= 2147483647; */
  }
  else
  {
    success = 0;
  }
  return success;
}

/*@
    requires \valid(this);
    requires this->isOpen;
    assigns this->isOpen, this->shapes;
    ensures this->isOpen == 0;
    ensures this->shapes == 0;
*/
void Close(void)
{
  this->isOpen = 0;
  /*@ assert this->isOpen >= 0 && this->isOpen <= 2147483647; */
  this->shapes = 0;
  /*@ assert this->shapes >= 0 && this->shapes <= 2147483647; */
}

/*@
    requires \valid(this);
    requires this->isOpen;
    assigns this->shapes;
    ensures this->shapes == 0;
*/
void Clear(void)
{
  this->shapes = 0;
  /*@ assert this->shapes >= 0 && this->shapes <= 2147483647; */
}

/*@
    requires \valid(this);
    requires this->isOpen;
    requires thickness > 0;
    assigns this->lineThickness;
    ensures this->lineThickness == thickness;
    ensures this->lineThickness > 0;
*/
void SetLineThickness(int thickness)
{
  this->lineThickness = thickness;
  /*@ assert this->lineThickness >= 0 && this->lineThickness <= 2147483647; */
}

/*@
    requires \valid(this);
    requires this->isOpen;
    requires color != 0;
    requires color > 0;
    requires color <= 2147483647;
    assigns this->currentColor;
    ensures this->currentColor == color;
    ensures this->currentColor > 0;
*/
void SetColor(int color)
{
  /*@ assert color > 0 && color <= 2147483647; */
  this->currentColor = color;
  /*@ assert this->currentColor >= 0 && this->currentColor <= 2147483647; */
}

/*@
    requires \valid(this);
    requires this->isOpen;
    requires center != 0;
    requires radius > 0;
    requires this->lineThickness > 0;
    requires this->shapes >= 0;
    requires this->shapes < 2147483647;
    assigns this->shapes;
    ensures this->shapes == \old(this->shapes) + 1;
    ensures this->shapes > 0;
*/
void DrawCircle(int center, int radius)
{
  int circle; /* unsupported init: Microsoft.Dafny.AllocateClass */
  /*@ assert this->shapes >= 0 && this->shapes < 2147483647; */
  this->shapes = (this->shapes + 1);
  /*@ assert this->shapes >= 0 && this->shapes <= 2147483647; */
}

/*@
    requires \valid(this);
    requires this->isOpen;
    requires center != 0;
    requires radius > 0;
    requires this->shapes >= 0;
    requires this->shapes < 2147483647;
    assigns this->shapes;
    ensures this->shapes == \old(this->shapes) + 1;
    ensures this->shapes > 0;
*/
void DrawFilledCircle(int center, int radius)
{
  int circle; /* unsupported init: Microsoft.Dafny.AllocateClass */
  /*@ assert this->shapes >= 0 && this->shapes < 2147483647; */
  this->shapes = (this->shapes + 1);
  /*@ assert this->shapes >= 0 && this->shapes <= 2147483647; */
}