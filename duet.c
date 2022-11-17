
int main(int argc, char *argv[])
{
  unsigned char a, b, c, d;
  unsigned char *p;
  int i;
  a = 0x01;
  b = 0x01;
  c = 0x01;
  d = 0x01;
  p = &a;
  for(i=0;i<256;i++) {
    b = *p;
    c = *(p+1);
    a = a+3;
    if(a>=0x20) {
      a = 0x20;
    }
    if(b==1) {
      b = 0x49;
    }
    if(c==1) {
      c = 0xC9;
    }
    printf("%c%c",b,c);
    p = p+2;
  }
  return 0;
}
