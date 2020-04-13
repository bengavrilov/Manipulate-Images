#include <stdio.h>
#include <stdlib.h>

/*
 * Include the function prototypes of all those functions implemented in
 image_processing.c.
 * Do not remove or modify them in any way.
 */

void remove_red();
void convert_to_black_and_white();
void instagram_square();

int main(int argc, char *argv[]) {
    /* Task 1 needs to be completed here: Make sure that the command line
     arguments are correct. In case an error exists,
     * print the error message and terminate the program. Otherwise, invoke the
     corresponding
     * image processing function . */

    // Check whether the command line input is valid and choose one of the functions to call
    if (argc != 2) {
        printf("Expecting one command-line argument, which needs to be either 1, 2, or 3.");
    }
    else if ((atoi(argv[1]) != 1) && (atoi(argv[1]) != 2) && (atoi(argv[1]) != 3)) {
        printf("Expecting one command-line argument, which needs to be either 1, 2, or 3.");
    }
    else if (atoi(argv[1]) == 1 && atol(argv[1]) == atoi(argv[1])) {
        remove_red();
    }
    else if (atoi(argv[1]) == 2 && atol(argv[1]) == atoi(argv[1])) {
        convert_to_black_and_white();
    }
    else if (atoi(argv[1]) == 3 && atol(argv[1]) == atoi(argv[1])) {
        instagram_square();
    }

    return 0;
}