#include "my_lib.h"

int my_stack_purge(struct my_stack *stack)
{
    // Total de bytes alliberats
    int ret = 0;

    if (stack && stack->top)
    {
        // Variable amb la que recorrerem tota la pila
        struct my_stack_node *aux = stack->top;
        while (aux)
        {

            //Alliberam i sumam el que ocupa el camp data
            ret += stack->size;
            free(aux->data);
            // Top ara apunta al seguent node
            stack->top = aux->next;
            // Alliberam al node amb el que hem treballat
            ret += sizeof(*aux);
            free(aux);
            // Agafam top com el seguent node (l'hem canviat abans)
            aux = stack->top;
        }
        // Alliberam la pila
        ret+=sizeof(*stack);
        free(stack);

        // Retornam la suma de tots els bytes
        return ret;
    }
}

int my_stack_len(struct my_stack *stack)
{
    // Variable comptadora
    int ret = 0;

    if (stack && stack->top)
    {
        // Ens situam damunt el primer node
        struct my_stack_node *aux = stack->top;
        // Recorrem tota la pila fins al final, sumant 1 al comptador a cada iteracio
        while (aux)
        {
            aux = aux->next;
            ret++;
        }
        return ret;
    }
    // Si la pila no es valida retorn -1
    return -1;
}

void *my_stack_pop(struct my_stack *stack)
{

    // Punter que retornarem
    void *ret;

    if (stack && stack->top)
    {
        // Ens guardam el node superior de la pila per despres esborrar-lo
        struct my_stack_node *aux = stack->top;
        // Actualitzam top
        stack->top = aux->next;
        // Ens guardam la info
        ret = aux->data;
        // Alliberam el que abans era el primer node i retornam la info
        free(aux);
        return ret;
    }
    return NULL;
}

int my_stack_push(struct my_stack *stack, void *data)
{

    struct my_stack_node *aux = malloc(sizeof(struct my_stack_node));

    // Si s'ha pogut reservar espai per aux i stack te una direccio valida, proseguim a ficar el node
    if (aux && stack)
    {
        //Ficam la data i assignam el node top com a node que vendra despres d'aux
        aux->data = data;
        aux->next = stack->top;
        //Actualitzar top
        stack->top = aux;
        return 0;
    }
    // Si no s'ha pogtu reservar espai per aux o stack no era una direccio valida, ERROR
    return -1;
}

struct my_stack *my_stack_init(int size)
{

    //Punter que retornarem
    struct my_stack *ret;
    //Reserva d'espai
    ret = malloc(sizeof(struct my_stack));
    //Donam valors als atributs de la pila
    ret->size = size;
    ret->top = NULL;

    return ret;
}

char *my_strchr(const char *str, int c)
{
    char *ret = NULL;

    // mentre no acabi l'string i metnre que no s'hagi trobat la primera lletra coicident
    for (int i = 0; str[i] && !ret; i++)
    {
        if (str[i] == c)
        {
            //Assignam punter
            ret = &str[i];
        }
    }

    return ret;
}

char *my_strcat(char *dest, const char *src)
{
    int i = 0;
    for (; dest[i]; i++)
    { // Obtenim la posició de dest on hi ha \0
    }
    for (int j = 0; src[j]; j++, i++)
    {
        dest[i] = src[j];
    }

    return dest;
}

char *my_strncpy(char *dest, const char *src, size_t n)
{
    int i = 0;

    //bulce per copiar n lletres sempre i quan no trobem el final de src
    for (; (i < n) && (src[i]); i++)
    {
        dest[i] = src[i];
    }
    // Si volíem copiar més lletres de les que té src, posam un \0 després de la darrera lletra copiada
    if ((i < n) && !src[i])
    {
        dest[i] = '\0';
    }
    return dest;
}

char *my_strcpy(char *dest, const char *src)
{
    int i = 0;
    //Copiam totes les lletres
    while (src[i])
    {
        dest[i] = src[i];
        i++;
    }
    //Marca de final
    dest[i] = '\0';

    return dest;
}

size_t my_strlen(const char *str)
{
    size_t len = 0;
    int i = 0;

    while (str[i])
    { // o while (str[i]!='\0')
        i++;
        len++;
    }
    return len;
}

int my_strcmp(const char *str1, const char *str2)
{
    int ret = 0; //variable de retorn
    int i = 0;
    //Comprovar lletra a lletra
    while (str1[i] && str2[i] && (!ret))
    {
        ret = str1[i] - str2[i];
        i++;
    }
    return ret;
}
