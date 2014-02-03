#include <stdio.h>

int main(int argc,char** argv)
{
    //call fopen with the file name passed into argv
    FILE * fp;
    fp = fopen ("myfile.txt","w");
    if (fp!=NULL)
    {
        puts("Some message about not being able to open the file");
    }
    int c;
    do {
      c = fgetc (fp);
      if (c == '$') n++;
    } while (c != EOF);
    return 0;
}
