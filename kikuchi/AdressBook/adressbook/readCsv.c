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
        printf("�t�@�C�����J���܂���ł����B\n");
        return 1;
    }
    // �w�b�_�[�s��ǂݔ�΂�
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
    // �\���̂Ɋi�[���ꂽ�f�[�^��\��
    for (int i = 0; i < count; i++) {
        printf("���O: %s, �N��: %d, �E��: %s\n", people[i].name, people[i].age, people[i].occupation);
    }
    return 0;
}


#endif