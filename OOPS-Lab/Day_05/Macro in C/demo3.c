#define A(x)((x)*(x))
int main( void )
{
    int a, b=3;
    a = 75 / (b* A((b+2)));
    //  a = 75 / (b* (((b+2))*((b+2))));
    //  a=  75 / (3* (((3+2))*((3+2))));
    //   a=  75/ (3* (((5))))*((5) ))))   // a=   75/(3*5*5)  =  75/75 = 1
    printf("%d\n", a); // a= 1
    return 0;
} // out put a=1
/*
A. 1
B. 625
C. 75
D. 225
*/



