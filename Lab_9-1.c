#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int golosna(char c)
{
    char str = tolower(c);
    return str == 'a' || str == 'e' || str == 'i' || str == 'o' || str == 'u' || str == 'y';
}

void rem_slova(char *str)
{
    char *poch_sloava = str;
    char *dst = str;
    while (*poch_sloava != '\0')
    {
        while (*poch_sloava != '\0' && isspace(*poch_sloava))
        {
            *dst++ = *poch_sloava++;
        }
        if (*poch_sloava == '\0')
        {
            break;
        }
        char *kin_slova = poch_sloava;
        while (*kin_slova != '\0' && !isspace(*kin_slova))
        {
            kin_slova++;
        }
        if (!golosna(*poch_sloava))
        {
            memmove(dst, poch_sloava, kin_slova - poch_sloava);
            dst += kin_slova - poch_sloava;
        }
        poch_sloava = kin_slova;
    }

    *dst = '\0';
}

int kil_sliv(char *c)
{
    int i = 0;
    char *p = c;
    while (*p)
    {
        while (*p && isspace(*p))
        {
            p++;
        }
        if (*p)
        {
            i++;
            while (*p && !isspace(*p))
            {
                p++;
            }
        }
    }
    return i;
}

void menu()
{
    char c[100];
    printf("Введіть рядок: ");
    gets(c);
    printf("Ваш рядок: ");
    puts(c);
    int h;
    do
    {

        printf("\n1. Вивести кількість слів в рядку");
        printf("\n2. Видалити слова що починаються з голосної букви");
        printf("\n0. Вихід з програми\n");
        printf("\nВведіть номер (0-2): ");
        scanf("%d", &h);

        if (h == 1)
        {
            int first = kil_sliv(c);
            printf("Кількість слів у тексті: %d\n", first);
        }
        else if (h == 2)
        {
            rem_slova(c);
            printf("Текст після видалення слів, що починаються з голосних літер: \n%s", c);
        }

        else if (h == 0)
        {
            printf("Вихід з програми\n");
        }
        else
            printf("Неправильна цифра\n");

    } while (h != 0);
}
int main(void)
{
    menu();
}