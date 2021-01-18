#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FIRST 1
#define SECOND 3
#define THIRD 5
#define FOURTH 7
#define FIFTH 9

#define TARGETSUM 12

/*notes*/
/*factorial-here it is 4 X 3 X 2 X 1 as there are four numbers-24*/
/*possibilitiies are determined by 2 to the power of n. In this case 2 to the
 * power of n is 16 */
/*end notes*/

/*true/false enum*/
typedef enum {
    FALSE,
    TRUE
} BOOLEAN;
/*end true/false enum*/

int main() {

    /*variables*/
    int nums[] = {1, 5, 9, 2};
    int i, j, k, l, m;
    int sum = 0;
    /*end variables*/

    /*nothing found yet, so boolean is set to false*/
    BOOLEAN foundIT = FALSE;

    /*here we go*/
    for (i = 0; i <= 1; ++i) {
        for (j = 0; j <= 1; ++j) {
            for (k = 0; k <= 1; ++k) {
                for (l = 0; l <= 1; ++l) {
                    for (m = 0; m <= 1; ++m) {
                        /*base case*/
                        sum = i * nums[0] + j * nums[1] + k * nums[2] +
                              l * nums[3] + m * nums[4];
                        printf("i=%d, j=%d, k=%d, l=%d, sum= %d \n", i, j, k, l,
                               sum);
                        /*recursive function*/
                        if (sum == TARGETSUM) {
                            foundIT = TRUE;
                        }
                    }
                }
            }
        }
    }

    /*if and print statements for testing*/
    if (foundIT == TRUE) {
        printf("It's true! The target sum has been found!\n");
    } else {
        printf("It's false! The target sum has not been found!\n");
    }
    return EXIT_SUCCESS;
}
