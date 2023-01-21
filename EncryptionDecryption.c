#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <math.h>

void encrypt();
void decrypt();

char ch;
int main(int argc, char *argv[])
{
char choice[2];

printf("Select -E or -e if you want to encrypt and -D or -d if you want to decrypt:\n");
printf("\nEnter Your Choice:\t");
scanf("%s", &choice);
if (strcmp(choice,"-D")==0||strcmp(choice,"-d")==0){

 decrypt();
 
}
else {
 encrypt();
   
}


printf("\n");
return 0;
}

void encrypt() {
 char x,nFile[40],nFileO[40],characters[120];
    int ASCII, outchar;
    FILE *file1, *fileTXT;
   
     printf("Please enter the name of the text file that contains your code:");
        scanf("%s", nFile);
        char *copy = nFileO;
        strcpy(copy,nFile);
        if(!strchr(nFile, '.')){
            strcat(nFile, ".crp");
        }
        
        else {
            char *replace;
            replace = strchr(nFile, '.');
                if (replace != NULL) {
                *replace = '\0';
                    strcat(nFile, ".crp");
                }
        }
        
        fileTXT = fopen(copy, "r");

        if (fileTXT == NULL) {
            printf("Cannot open the file");
        }

        else {
            file1 = fopen(nFile,"w+");


            while (fgets(characters, sizeof(characters), fileTXT)) 
            {

                for(int i=0; i<sizeof(characters) ; i++){
                    ASCII = characters[i];

                    if(ASCII == '\0'){
                        break;
                    } else if (ASCII == 10){
                        fprintf(file1, "\n");
                    }else if (ASCII == 9) {
                    fprintf(file1, "TT");
                    
                    }else if(ASCII != -1){
                        outchar = ASCII - 16;
                        if(outchar < 32){
                            outchar = (outchar -32) + 144;
                        }
                        fprintf(file1, "%X", outchar);
                    }
                }
            }   
            fclose(file1);
            fclose(fileTXT);
}
}

void decrypt()
{
FILE *file1, *fileCRP;
    char nFileI[40], nFileO[40], characters[255], c1, c2;
    int ASCII, fChar1, fChar2, outchar;
   
   
   printf("Please enter the name of the text file that contains your password:");
    scanf("%s", nFileI);
    char *copy = nFileO;
    strcpy(copy,nFileI);
    if(!strchr(nFileI, '.')){
        strcat(nFileI, ".txt");
                                       
    }
    else {
         char *replace;
            replace = strchr(nFileI, '.');
                if (replace != NULL) {
                *replace = '\0';
                    strcat(nFileI, ".txt");
                }

    }
    
        fileCRP = fopen(copy, "r");
        if (fileCRP == NULL) {
          printf("Cannot open the file");  
        }
        else {
            
            file1 = fopen(nFileI,"w+");
        

            while (fgets(characters, sizeof(characters), fileCRP)) 
            {
                for(int i=0; i<sizeof(characters) ; i+=2){
                    
                    c1 = characters[i];
                    c2 = characters[i+1];
                    ASCII = characters[i];
                    if(ASCII == '\0'){
                        break;
                    } else if(strcmp(&c1, "T")==0  && strcmp(&c2, "T")==0)
                    {
                        fprintf(file1, "\t");
                    }else if (ASCII == 10){
                        fprintf(file1, "\n");
                    }
                    else
                    {
                        fChar1 = (c1 - '0') * 16;

                        switch(c2){
                            case 'A':
                            fChar2 = 10;
                            break;

                            case 'B':
                            fChar2 = 11;
                            break;

                            case 'C':
                            fChar2 = 12;
                            break;

                            case 'D':
                            fChar2 = 13;
                            break;

                            case 'E':
                            fChar2 = 14;
                            break;

                            case 'F':
                            fChar2 = 15;
                            break;

                            default: 
                            fChar2 = (c2 - '0');
                        }
                        outchar = fChar1 + fChar2 +16;


                        if(outchar>127)
                        {
                            outchar = (outchar -144) + 32;
                        }
                        fprintf(file1, "%c", outchar);
                    }
                }
            }      
            
            fclose(fileCRP);
            fclose(file1);
            }
            
}
