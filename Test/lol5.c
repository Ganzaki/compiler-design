
/*

author ganzaki aka K Shrinidhi Bhagavath

*/


int main()
{
  int a=0;
  char c = 'a';
  while(a<9){
    printf("First while a = %d, c = %c\n", a, c);
    switch(a){
        case 1:
            printf("case 1 a = %d\n", a);
            a = 2;
            while(a<7){
              printf("Second while a = %d, c = %c\n", a, c);
              ++a;++c;
            }
            break;
        default:
            printf("default a = %d, c = %c\n", a, c);
            int x = a++;
            ++c;
    }
  }
  printf("out a = %d, c = %c\n", a, c);
}

/*
author ganzaki

*/
/*
author ganzaki

*/