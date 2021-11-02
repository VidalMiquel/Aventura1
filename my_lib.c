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
    if (longitud < n)
    {
        for (int i = 0; i < longitud; i++)
        {
            dest[i] = src[i];
        }
    }
    else
    {
        //Cas2.
        for (int i = 0; i < n; i++)
        {
            dest[i] = src[i];
        }
    }
    //Retornam el punter que conté el resultat.
    return dest;
}

//funció ecarregada d'inicilaitzar la pila.
struct my_stack *my_stack_init(int size)
{
    //Declaram una varibale punter de tipus struct my_stack.
    struct my_stack *pila;
    //Reservam espai de memoria i li assigna al punter.
    pila = malloc(sizeof(struct my_stack));
    //Inicialitzam es valors.
    pila->top = NULL;
    pila->size = size;
    //Retornm el punter a la pila incialitzada.
    return pila;
}

//Funció que introdueix un node dins la pila.
int my_stack_push(struct my_stack *stack, void *data)
{
    //Declaram una variable punter de tipus my_stack_node.
    struct my_stack_node *nuevoNodo;
    //Reservam espai de memoria i li assigna al punter.
    nuevoNodo = malloc(sizeof(struct my_stack_node));
    //comprovam si la pila ha estat inicialitzada correctament.
    if (stack && stack->size > 0)
    {
        nuevoNodo->data = data;
        //L'element introduit apunta al mateix lloc que top.
        nuevoNodo->next = stack->top;
        //Top apunta al l'element introduït.
        stack->top = nuevoNodo;
        return 0;
    }
    //Retornam error si la pila no ha estat ben inicialitzada.
    return ERROR;
}

//Funció que treu el primer element de la pila.
void *my_stack_pop(struct my_stack *stack)
{
    //Declaram una varibale punter de tipus my_stack_node.
    struct my_stack_node *temporal;
    //Declaram una varible punter void.
    void *data;
    //Apunta al mateix lloc que top(primer element de la pila).
    temporal = stack->top;
    //Si la pila no està buida.
    if (stack && stack->top)
    {
        //Recuperam data.
        data = stack->top->data;
        //Top apunta allà on apunta l'element a extreure.
        stack->top = stack->top->next;
        //alliberam temporal (eliminam el primer element de la pila).
        free(temporal);
        //retornm data (infomració associada a l'element eliminat).
        return data;
    }
    return NULL;
}

int my_stack_len(struct my_stack *stack)
{
    int elements = 0;
    struct my_stack_node *aux;
    aux = stack->top;
    if (stack)
    {
        while (aux)
        {
            elements++;
            aux = aux->next;
        }
        return elements;
    }

    return ERROR;
}

//Funció que allibera tot l'espai reservat anteriorment (pila, nodes i data).
int my_stack_purge(struct my_stack *stack)
{
    //declaració i inicialització de  la variable que emmagatzemarà els bytes alliberats.
    int liberados = 0;
    //DEclaració d'una varibale punter de tipus my_stack_node.
    struct my_stack_node *aux;
    //Aux apunta, on apunta top.
    aux = stack->top;
    //Mentres quedin elements dins la pila.
    if (stack)
    {
        while (aux)
        {
            liberados += stack->size;
            //Alliberam data.
            free(aux->data);
            liberados += sizeof(*aux);
            //Top apunta al següent element.
            stack->top = stack->top->next;
            //Alliberam aux (node)
            free(aux);
            //Aux apunta, on apunta top.
            aux = stack->top;
        }
        liberados += sizeof(*stack);
        //Alliberam la pila.
        free(stack);
        //Retornam els bytes alliberats.
        return liberados;
    }
    return ERROR;
}
