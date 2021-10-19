#include "my_lib.h"

//Funció que retorna la longutid de la cadena passada per paràmetre.
size_t my_strlen(const char *str)
{
    //Declaracions i inicialització de varibales.
    size_t len = 0;
    //Recorrrem la cadena passada per paràmetre mentre no trobem '\0'.
    while (*str)
    {
        str++;
        len++;
    }
    //Retornam la longuitd de la cadena.
    return len;
}

//Funció que copia la cadena src dins la memoria pauntada per dest.
char *my_strcpy(char *dest, const char *src)
{
    //Declaració i inicialització de variables.
    int i = 0;
    //Recorrem la cadena a copiar (Mentre no '\0').
    while (src[i])
    {
        //Copiam src dins dest.
        dest[i] = src[i];
        i++;
    }
    //Assifnam al darrer valor de la cadena destí el caràcter '\0'.
    dest[i] = '\0';
    //Retornam un punter la cadena resultant.
    return dest;
}

//funció que recorr la cadena passada per paràmetre cercant la primera aparició del caràcter passat per paràmetre.
char *my_strchr(const char *str, int c)
{

    //Recorrem la cadena (mentre no '\0').
    while (*str)
    { //si el caràcter analitzat és el cercat.
        if (*str == c)
        { //Retornam el punter associat a la seva aparició.
            return (char *)str;
        }
        str++;
    }
    //En cas contrari, retornam NULL
    return NULL;
}

//funció que concatena la cadena1 a la cadena2 (cadena2cadena1).
char *my_strcat(char *dest, const char *src)
{
    //Declaració i inicialització de variables.
    int i = 0;
    int j = 0;
    //Recorrem la cadena2.
    while (dest[i])
    {
        i++;
    }
    //Mentres no '\0', concatenam caràcter a caràcter la cadena1 al final de la cadena2.
    while (src[j])
    {
        dest[i] = src[j];
        i++;
        j++;
    }
    //Retornam el punter.
    return dest;
}

//Funció que compara si dues cadenes passades per maràmetre són iguals.
//En cas afirmatiu, retorna 0.
//En cas de que la cadena1 sigui major que la cadena2, retorna 1.
//En cas contrari, retorna -1.
int my_strcmp(const char *str1, const char *str2)
{
    //Iteram mentres els caràcters analitzas siguin iguals o trobem fi de acdena
    while (*str1 == *str2 && *str1 != '\0')
    {
        str1++;
        str2++;
    }
    //Si hem arribat a fi de cadena d'ambdues.
    if ((*str1 == '\0') && (*str2 == '\0'))
    {
        return 0;
    }
    else
    {
        //Cas contrari, retornam la resta.
        return *str1 - *str2;
    }
}

//Funció que copia n caràcters de src a la memòria apuntada per dest.
char *my_strncpy(char *dest, const char *src, size_t n)
{   
    //Obtenim la longitud de src.
    size_t longitud = my_strlen(src);
    //comprovació cas 1.
    if(longitud < n){
        for(int i = 0; i < longitud; i++){
            dest[i] = src[i];
        }
    }else{
        //Cas2.
        for(int i = 0; i< n; i++){
            dest[i] = src[i];
        }
    }
    //Retornam el punter que conté el resultat.
    return dest;
}

