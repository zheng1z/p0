#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    /*Method to store argv[1] to a string
    size_t len = strlen(argv[1]);
    char *name = malloc(len + 1);
    if (name != NULL){
        strcpy(name, argv[1]);
    } else {printf("ERROR1");}*/
    FILE *file;
    file = fopen(argv[1],"r");

    size_t buffer;
    fseek(file, 0, SEEK_END);
    size_t endPtr = ftell(file); // the end index of file
    size_t index = 15;  // index start at 15
    int arr[361][641];
    int x, y;  // x row, y col

    while(1) { // read img in 2D arr
        for (x = 1; x <= 360; x++) {
            for (y = 1; y <= 640; y++) { // read row by row, start w/ col index 1
                fseek(file, index, SEEK_SET);
                fread(&buffer, 1, 1, file);
                arr[x][y] = buffer;
                index++;
            }
        }
        if (index == endPtr) {
            break;
        }
    }
    // printf("%d\n", arr[360][640]);
    // begin adding unicode stuf
    size_t row, col, curRow, curCol, uniRow, uniCol;
    size_t uni[100][100];
    size_t sum = 0;
    for(col = 1; col <= 640){
        if(col % 4 != 0 && col != 640) { // 1-3, 5-7
            for (size_t i = 1; i <= 8; i++) {
                curRow += i;
                sum += arr[col][curRow];
            }
            col++;
        } else if (col % 4 == 0){ // 4, 8, 12...
            for (size_t i = 1; i <= 8; i++) {
                curRow += i;
                sum += arr[col][curRow];
            }
            col++;

        } else if (col == 640){   // 640 end of col index

        }
    }

    return 0;
}
