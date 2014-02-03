#include <stdio.h>

int main(int argc,char** argv)
{
    //call fopen with the file name passed into argv
    FILE * fp;
    fp = fopen ("myfile.txt","w");
    if (fp!=NULL)
    {
        fputs ("fopen example",fp);
        fclose (fp);
    }
    return 0;
}
