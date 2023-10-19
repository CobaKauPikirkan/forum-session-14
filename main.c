#include <stdio.h>

int main () {
    FILE *file;
    int pemisah, id;
    char name[100];
    double amount;

    file = fopen("text.txt", "r");
    if (file == NULL)
    {
        printf("cant read file  \n");
        return 1;
    }

    char line[100]; // Variabel untuk menyimpan setiap baris dalam file
    while (fgets(line, sizeof(line), file))
    {
        // Memisahkan data dari setiap baris
        if (sscanf(line, "%d %99[^0-9] %lf", &id, name, &amount) == 3)
        {
            printf("====================\n");
            printf("ID: %d\n", id);
            printf("Nama: %s\n", name);
            printf("Jumlah: %.2lf\n", amount);
            printf("====================\n");
        }
        else
        {
            printf("Format tidak sesuai: %s", line);
        }
    }
    fclose(file);
    return 0;
}