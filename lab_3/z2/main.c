#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* get_path();
int search(char *path);

int main()
{
    printf("Enter file name: ");
    char *path = get_path();

    if (search(path))
    {
        printf("Error!");
        exit(1);
    }
    
    free(path);
    return 0;
}

char* get_path()
{
    char *s = (char*)calloc(200, sizeof(char));
    fgets(s, 200, stdin);
    s[strlen(s) - 1] = 0;
    s = (char*)realloc(s, strlen(s) * sizeof(char));
    return s;
}

int search(char *path)
{
    FILE *f = NULL;
    if ((f = fopen(path, "rb")) == NULL) return 1;

    int a, b;
    if (fread(&a, sizeof(int), 1, f) > 0)
    {
        while (fread(&b, sizeof(int), 1, f) > 0 && b > a) a = b;
        printf("This number: %d", a);
    }
    else
        printf("The file is empty.");

    fclose(f);
    return 0;
}