int main()
{
  int a=0;
  a++;
  while(a < 10){
    switch (a)
    {
        case 1:
            printf("In case one with a = %d\n", a);
            a = 7;
            break;
        case 7:
            printf("In case seven with a = %d\n", a);
            ++a;
        default:
            printf("In default with a = %d\n", a);
            ++a;
    }
  }
  printf("Out of while\n");
}