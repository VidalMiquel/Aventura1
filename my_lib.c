/*
AUTORS : Miquel Vidal Cortés , Aina Maria Tur Serrano, Xavier Vives Marcus.
*/
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
    //Assignam al darrer valor de la cadena destí el caràcter '\0'.
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
    //Copiam els n caràcters de src a dest.
    for (int i = 0; i < n; i++)
    {
        dest[i] = src[i];
    }
    //Cas en que els caràcters a copiar son mes que la longitud de src.
    if (longitud < n)
    {
        size_t longitud_dest = my_strlen(dest);
        for (int j = longitud; j < longitud_dest; j++)
        {
            dest[j] = '\0';
        }
    }
    //Retornam dest.
    return dest;
}

//Funció ecarregada d'inicilaitzar la pila.
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
    return -1;
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
    //Cas no existeix node superior.
    return NULL;
}

//Funció que determina la quantitat d'elements que té la pila.
int my_stack_len(struct my_stack *stack)
{
    //Declaració i inicialització de la variable de retorn.
    int elements = 0;
    //Declaració d'una varibale de tipus my_stack_node auxiliar.
    struct my_stack_node *aux;
    aux = stack->top;
    //Comprovam l'existència de la pila.
    if (stack)
    {
        //Mentres hi hagi elements.
        while (aux)
        {
            //Incrementam el nombre d'elements.
            elements++;
            //apuntam al següent element.
            aux = aux->next;
        }
        //Retornam elements presents dins la pila.
        return elements;
    }
    //Cas error.
    return -1;
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
    //Comprovam l'existència de la pila.
    if (stack)
    {
        //Mentres quedin elements dins la pila.
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
    //Cas error.
    return -1;
}

//funció que llegeix un fitxer passat per paràmetre.
struct my_stack *my_stack_read(char *filename)
{
    //Declaracions de les variables.
    int fd, size;
    struct my_stack *pila;
    void *data;
    //Obrim el fitxer.
    fd = open(filename, O_RDONLY);
    //Control d'errors a l'obertura del fitxer.
    if (fd == -1)
    {
        fprintf(stderr, "Error %d: %s\n", errno, strerror(errno));
        return NULL;
    }
    //Obtenim el tamany de les dades.
    if ((read(fd, &size, sizeof(int))) == -1)
    {
        //Control d'errors.
        fprintf(stderr, "Error %d: %s\n", errno, strerror(errno));
        return NULL;
    }
    //Inicialitzam la pila auxiliar.
    pila = my_stack_init(size);
    data = malloc(size);
    //Llegim fins a EOF.
    while (read(fd, data, size) > 0)
    {
        //Introduim un nou node amb les dades obtingudes de la lectura.
        my_stack_push(pila, data);
        data = malloc(size);
    }
    //lliberam memòria associat a data.
    free(data);
    //Tancam el fitxer.
    if (close(fd) == -1)
    {
        //Control d'errors al tancar fitxer.
        fprintf(stderr, "Error %d: %s\n", errno, strerror(errno));
        return NULL;
    }
    //Retornam pila.
    return pila;
}

//Funció encarregada de copiar la pila original.
void copiarPila(struct my_stack *stack, struct my_stack *copiar)
{
    //Declaració de les variables.
    struct my_stack_node *node;
    node = stack->top;
    //Mentre hi hagi elements dins la pila original, copiam.
    while (node)
    {
        //Introduim un nou node a la pila auxiliar.
        my_stack_push(copiar, node->data);
        node = node->next;
    }
    //Lliberam la memoria reservada anteriorment.
    free(node);
}

//funció encarregada d'escriure el contingut de la pila original dins el fitxer passat per paràmetre.
int my_stack_write(struct my_stack *stack, char *filename)
{
    //Declaracions de variables.
    int fd, elementsInserts;
    struct my_stack *copiar;
    void *data;
    int size = stack->size;
    //Obrim el fitxer.
    fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if (fd == -1)
    {
        //Control d'errors a l'oberutra del fitxer.
        fprintf(stderr, "Error %d: %s\n", errno, strerror(errno));
        return -1;
    }
    if (stack)
    {
        //Escrivim la mida de les dades
        if (write(fd, &(stack->size), sizeof(int)) == -1)
        {
            //Control d'errors a l'escritura.
            fprintf(stderr, "Error %d: %s\n", errno, strerror(errno));
            return -1;
        };
        elementsInserts = 0;
        //Inicialitzam la pila auxiliar.
        copiar = my_stack_init(stack->size);
        //Copiam la pila original dins la auxiliar.
        copiarPila(stack, copiar);
        while (copiar->top)
        {
            data = my_stack_pop(copiar);
            //Escrivim cada data dins el fitxer.
            if (write(fd, data, size) == -1)
            {
                //Control d'erros en la escritura.
                fprintf(stderr, "Error %d: %s\n", errno, strerror(errno));
                return -1;
            }
            //Incrementam el nombre d'elements escrits.
            elementsInserts++;
        }
        //Tancam el fitxer.
        if (close(fd) == -1)
        {
            //Control d'erros al tancar fitxer.
            fprintf(stderr, "Error %d: %s\n", errno, strerror(errno));
            return -1;
        }
        //Retorn elements escrits.
        return elementsInserts;
    }
    return -1;
}
