// using fseek we cam print data from last char to 1st char in file( rev order)
#include<stdio.h>
int main()
{
    char ch;
    FILE *fp;
  
    fp=fopen("abc.txt","r");
    if(fp==NULL)
    	printf("\n File is not present");
    else    
    {
	    //fseek(fp,-1l,2);  /* Postion to the last chararter */
        fseek(fp,-1l,SEEK_END);  /* Postion to the last chararter */
	    do
	    {
	    	ch=fgetc(fp);
            /*if( ch=='\n')   in window for multiple lines
                //fseek(fp, -1l, 1); // skip new line char '\n'
                fseek(fp, -1l, SEEK_CUR); // skip new line char '\n'
            */
		    printf("%c", ch);
        }while(!fseek(fp,-2L,SEEK_CUR));
	    //}while(!fseek(fp,-2L,1));
	}	 
    return 0;
}
// 2.1f  2.1F  float
// 10l   10L   long int