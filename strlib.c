#include <stdio.h>
#include <stdlib.h>
#include <time.h>

size_t my_strlen(const char *str);
int my_strcmp(const char *str1, const char *str2);
char *my_strcpy(char *dest, const char *src);
char *my_strncpy(char *dest, const char *src, size_t n);
char *my_strcat(char *dest, const char *src);
char *my_strchr(const char *str, int c);

char *punt;
char *punt2;


int main(){
    char string[20]={"holaaaaaaaaaa\0"};
    char string2[20]={"elpepe\0"};
    printf("%s    %s", string, string2);
    punt = string;
    punt2 = string2;


    my_strcat(punt, punt2);
    printf("\n%s    %s", string, string2);

    printf("\n%s", my_strchr(punt, 'e'));
    return 0;
}

char *my_strchr(const char *str, int c){
    char *ret=NULL;

    // mentre no acabi l'string i metnre que no s'hagi trobat la primera lletra coicident
    for(int i = 0;str[i]&&!ret;i++){
        if(str[i]==c){
            //Assignam punter
            ret=&str[i];
        }
    }


    return ret;
}

char *my_strcat(char *dest, const char *src){
    int i=0;
    for(;dest[i];i++){// Obtenim la posició de dest on hi ha \0
    }
    for(int j=0;src[j];j++, i++){
        dest[i]=src[j];
    }

    return dest;
}

char *my_strncpy(char *dest, const char *src, size_t n){
    int i = 0;

    //bulce per copiar n lletres sempre i quan no trobem el final de src
    for(;(i<n)&&(src[i]);i++){
        dest[i]=src[i];
    }
    // Si volíem copiar més lletres de les que té src, posam un \0 després de la darrera lletra copiada
    if((i<n)&&!src[i]){
        dest[i]='\0';
    }
    return dest;
}

char *my_strcpy(char *dest, const char *src){
    int i =0;
    //Copiam totes les lletres
    while(src[i]){
        dest[i]=src[i];
        i++;
    }
    //Marca de final
    dest[i]='\0';

    return dest;
}

size_t my_strlen(const char *str) {
   size_t len = 0;
   int i = 0;
 
   while (str[i]) { // o while (str[i]!='\0')
           i++;
           len++;
   }
   return len;
}

int my_strcmp(const char *str1, const char *str2){
    int ret=0; //variable de retorn
    int i=0;
    //Comprovar lletra a lletra
    while(str1[i]&&str2[i]&&(!ret)){
        ret=str1[i]-str2[i];
        i++;
    }
    return ret;
}






