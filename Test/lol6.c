int main(){
    int a = 0;
    int b = 1;
    a = b * 1;
    switch(a){
        case 1:
            a = b = 2;
            while(a<7){
                ++a;
            }
            break;
        default:
            a++;
    }
}