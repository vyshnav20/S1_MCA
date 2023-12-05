#include <stdio.h>

int main() {
    int matrix[4][2] = {{1, 2}, {2, 4}, {5, 6}, {4, 3}};
    int new_element[2] = {1, 3};
    int can_insert = 1;
        
    for (int i = 0; i < 4; i++) {
        
        if (matrix[i][1] == new_element[1] && matrix[i][0] != new_element[0]) {
            printf("%d %d %d %d",matrix[i][1],matrix[i][0],new_element[1],new_element[0]);
            can_insert = 0;
            break;
        }
        printf("\n");
    }

    if (can_insert) {
        matrix[4][0] = new_element[0];
        matrix[4][1] = new_element[1];
        printf("Element inserted successfully.\n");
    } else {
        printf("Element cannot be inserted.\n");
    }

    return 0;
}
