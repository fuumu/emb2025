#include <stdio.h>
#include <string.h>

#if 0
typedef struct {
    char name[50];
    int age;
    char occupation[50];
} Person;
int main() {
    FILE* file = fopen("sample.csv", "r");
    char buffer[1024];
    Person people[100];
    int count = 0;
    if (file == NULL) {
        printf("ファイルを開けませんでした。\n");
        return 1;
    }
    // ヘッダー行を読み飛ばす
    fgets(buffer, sizeof(buffer), file);
    while (fgets(buffer, sizeof(buffer), file) && count < 100) {
        char* name = strtok(buffer, ",");
        char* age = strtok(NULL, ",");
        char* occupation = strtok(NULL, ",");
        if (name && age && occupation) {
            strncpy(people[count].name, name, sizeof(people[count].name) - 1);
            people[count].age = atoi(age);
            strncpy(people[count].occupation, occupation, sizeof(people[count].occupation) - 1);
            count++;
        }
    }
    fclose(file);
    // 構造体に格納されたデータを表示
    for (int i = 0; i < count; i++) {
        printf("名前: %s, 年齢: %d, 職業: %s\n", people[i].name, people[i].age, people[i].occupation);
    }
    return 0;
}


#endif