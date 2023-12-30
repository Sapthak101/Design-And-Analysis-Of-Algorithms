#include <stdio.h>
#include <string.h>

int main() {
    char input[10000];
    printf("Enter a input: ");
    fgets(input, sizeof(input), stdin);

    int t_char = 0;
    int t_word = 0;
    int w_length = 0;
    int i = 0;

    while (input[i] != '\0') 
    {
        if (input[i] != ' ' && input[i] != '\n') 
        {
            w_length++;
        }
        else
        {
            if (w_length > 0) 
            {
                t_char += w_length;
                t_word++;
                w_length = 0;
            }
        }
        i++;
    }

    if (w_length > 0) 
    {
        t_char += w_length;
        t_word++;
    }

    if (t_word > 0) 
    {
        double average = (double) t_char / t_word;
        printf("Average number of characters in each word: %.2lf\n", average);
    } 
    else 
    {
        printf("No words found.\n");
    }
    return 0;
}