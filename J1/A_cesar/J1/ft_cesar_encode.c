#include "cesar.h"

void ft_cesar_encode (char *str, int decalage) {
int i;
decalage = ((decalage%26) + 26) % 26;

for (i=0; str[i] != '\0'; i++) {
    if (ft_is_upper(str[i])) {
        str[i] = 'A' + (str[i] - 'A' + decalage) % 26;
        }
    else if (ft_is_lower(str[i]))     {
        str[i] = 'a' + (str[i] - 'a' + decalage) % 26;
    }
    }
}
