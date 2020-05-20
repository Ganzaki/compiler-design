int main()
{
  int a=0;
  a++;
  while(a<10){
    switch(a){
        case 1:
            a=7;
            break;
        case 7: 
            ++a;
        default:
            ++a;
    }
  }
}