#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER_SIZE 1000

int main(int argc, char *argv[])
{
    if(argc<2)
    {
      printf("Argüman giriniz\n");
      return 0;
    }
    FILE *fptr;
    char *word=argv[1];
    int line=0, col=0,c,counter=0;
    char str[BUFFER_SIZE];
    //Dosyayi aciyoruz.
    fptr = fopen(argv[2],"r");
    if (fptr == NULL)
    {
        printf("Dosya acilamadi.\n");
        exit(EXIT_FAILURE);
    }
    int k=-1;
    //Dosyanin icini str adli diziye atiyoruz.Bunu counter icin kullanicaz.
    while ((c = fgetc(fptr)) != EOF)
    {
      k++;
      str[k]=c;
    }
    //File'i tekrar basa cekiyoruz.
    rewind(fptr);
    int l=0;
    /* Bu kisimda tekrar dosyayi sonuna kadar okuyoruz eger aranan kelimenin ilk harfiyle
      dosyadan okunulan harf eslesirse for ifin icine giriyor burda for dongusuyle tum harfleri
      karsilastiriyoruz. \n karsilasirsa bir sonraki harfla karsilastiriyoruz.
    */
    while ((c = fgetc(fptr)) != EOF)
    {
      counter=0;
      if(c==word[0])
      {
        for(int i=0;i<strlen(word);i++)
        {
          if(str[l+i]=='\n')
          {
            if(word[i]==str[l+i+1])
              counter++;
            else
              break;
          }
          else{
            if(word[i]==str[l+i])
              counter++;
            else
              break;
          }
        }
        if(counter==strlen(word))
        {
          printf("%s Found at %d. row %d. Column\n",word,line+1,col+1 );
        }

      }
      l++;
      col++;//col
      // kelime sonuna gelindeyse line
      if(c=='\n')
        {
          col=0;//col
          line++;
        }
    }
    fclose(fptr);
    return 0;
}
