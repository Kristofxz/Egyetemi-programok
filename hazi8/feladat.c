#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 100
#define MAX_COLS 100

int main() {
    FILE* be = fopen("be.txt", "r");
    FILE* ki = fopen("ki.txt", "w");

    int hegy_tavolsag, vizforras_tavolsag, homokvihar_tavolsag;
    int rows, cols;

    fscanf(be, "%d %d %d", &hegy_tavolsag, &vizforras_tavolsag, &homokvihar_tavolsag);
    fscanf(be, "%d %d", &rows, &cols);

    char map[MAX_ROWS][MAX_COLS];
    for (int i = 0; i < rows; ++i) {
        fscanf(be, "%s", map[i]);
    }

    int suitable_locations = 0;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (map[i][j] == '0') {
                int hegy_distance = rows + cols; // Kezdetben nagy érték, hogy megfelelő legyen a minimum kereséshez
                int vizforras_distance = rows + cols;
                int homokvihar_nearby = 0;

                for (int x = 0; x < rows; ++x) {
                    for (int y = 0; y < cols; ++y) {
                        if (map[x][y] == 'A') {
                            int distance = abs(x - i) + abs(y - j); // Manhattan távolság

                            if (distance < hegy_distance) {
                                hegy_distance = distance;
                            }
                        }

                        if (map[x][y] == '~') {
                            int distance = abs(x - i) + abs(y - j); // Manhattan távolság

                            if (distance < vizforras_distance) {
                                vizforras_distance = distance;
                            }
                        }

                        if (map[x][y] == 'X') {
                            int distance = abs(x - i) + abs(y - j); // Manhattan távolság

                            if (distance <= homokvihar_tavolsag) {
                                homokvihar_nearby = 1;
                            }
                        }
                    }
                }

                if (hegy_distance <= hegy_tavolsag && vizforras_distance <= vizforras_tavolsag && !homokvihar_nearby) {
                    suitable_locations++;
                }
            }
        }
    }

    fprintf(ki, "%d\n", suitable_locations);

    fclose(be);
    fclose(ki);
    return 0;
}
