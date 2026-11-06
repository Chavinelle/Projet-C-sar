#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "cesar.h"

int ft_strlen (const char *texte) {
int i;
for (i=0; texte[i] != '\0'; i++) {
    }
    return i;
}

static void affichage (int i, const char *str) {
write(i, str, ft_strlen(str));
write(i, "\n", 1);
}

int conversion (char *str, int *nombre_final){
int i = 0;
int nombre_neg = 0;
int nombre = 0;

if (str[i] == '-' || str[i] == '+') {
    if (str[i] == '-')
        nombre_neg++;
    i++;
}
    if (str[i] == '\0')
        return (0);
    while (str[i]) {
    if (str[i] < '0' || str[i] > '9')
        return (0);
    nombre = (nombre * 10 + (str[i] - '0'))%26;
    i++;
    }
    if (nombre_neg) {
        *nombre_final = -nombre;
    }
    else {
        *nombre_final = nombre;
    }
    return (1);
     }

static int erreur_message (const char *message) {
    affichage(2, message);
    return(1);
}

/*static int comparaison (const char *text, const char *texte) {
int i;
for (i=0; text[i] != '\0' && text[i] = texte [i]; i++) {
    if ( text[i] = texte [i]) {
    }
}
while (text[i] != '\0' && text[i] = texte [i] ) {}*/

int main(int argc, char **argv)
{
    int decalage;
    if(argc != 4)
    return(erreur_message("Erreur : Format :./cesar encode|decode decalage \"texte\" \n"));
    if (!conversion(argv[2], &decalage))
        return(erreur_message("Erreur : La clé de décalage doit être un entier. \n"));
    if (strcmp(argv[1], "encode") == 0) {
        ft_cesar_encode (argv[3], decalage);
        }
    else if (strcmp(argv[1], "decode") == 0) {
        ft_cesar_decode (argv[3], decalage);
        }

    else {
        return (erreur_message("Erreur : Le mode doit être encode ou decode. "));
    }
    affichage(1, argv[3]);
    write(1, "\n", 1);
return 0;
}

