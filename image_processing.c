//
// Created by Ben Gavrilov on 2020-01-25.
//

#include <stdio.h>

/*
 * Read an image from the standard input and set the red value of each pixel to
 * zero.
 */
void remove_red()
{
    char input[70];
    int total_digits = 0;

    // Reads the first group of characters for every iteration
    while (scanf("%69s", input) != EOF) {
        total_digits++;

        // Outputs the character just found
        if (total_digits <= 3) {
            printf("%s ", input);
        }
        else if (total_digits == 4) {
            printf("%s\n", input);
        }
        else if (total_digits == 5) {
            // Print 0 for the first R value of every pixel
            printf("0 ");
        }
        else if (total_digits == 6) {
            printf("%s ", input);
        }
        else if (total_digits == 7) {
            printf("%s\n", input);
            total_digits = 4;
        }
    }
}

/*
 * Read an image from the standard input and convert it from colour to black and
 * white.
 */
void convert_to_black_and_white()
{
    char first_word[70];
    int total_digits = 0;
    int input;

    int total_pixels = 0;
    int average;

    // Scan the first P3 using a character input
    scanf("%69s", first_word);
    printf("%s ", first_word);
    total_digits++;

    // Scan for each number appearing in the file
    while (scanf("%d", &input) != EOF) {
        total_digits++;

        // Increment the value of each pixel to the total pixel amount
        if (total_digits <= 3) {
            printf("%d ", input);
        }
        else if (total_digits == 4) {
            printf("%d\n", input);
        }
        else if (total_digits == 5) {
            total_pixels += input;
        }
        else if (total_digits == 6) {
            total_pixels += input;
        }
        else if (total_digits == 7) {
            total_pixels += input;

            // Calculate the average pixel colour
            average = total_pixels / 3;

            // Print the average color for the RGB of the pixel
            printf("%d %d %d\n", average, average, average);
            total_pixels = 0;
            total_digits = 4;
        }
    }
}

/*
 * Read an image from the standard input and convert it to a square image.
 */
void instagram_square()
{
    char first_word[70];
    int total_digits = 0;
    int input;

    int num_of_rows;
    int num_of_columns;
    int last_pixel;
    int current_pixel = 1;
    int current_column = 0;

    // Scan the first P3 using a character input
    scanf("%69s", first_word);
    printf("%s ", first_word);
    total_digits++;

    // Scan for each number appearing in the file
    while (scanf("%d", &input) != EOF) {
        total_digits++;

        if (total_digits <= 3) {

            // Store the number of columns and rows
            if (total_digits == 2) {
                num_of_columns = input;
            }
            else if (total_digits == 3) {
                num_of_rows = input;
            }
        }
        else if (total_digits == 4) {

            // Set the last pixel depending on the dimensions of the ppm
            if (num_of_rows > num_of_columns) {

                // If the number of rows > number of columns then the last pixel that should be outputted is:
                last_pixel = (num_of_columns * num_of_rows) - (num_of_columns * (num_of_rows - num_of_columns));

                // The number of columns and rows should be the same
                printf("%d %d %d\n", num_of_columns, num_of_columns, input);
            }
            else if (num_of_columns > num_of_rows) {

                // If the number of columns > number of rows then refer to the next if statement
                last_pixel = (num_of_columns * num_of_rows);
                printf("%d %d %d\n", num_of_rows, num_of_rows, input);
            } else if (num_of_columns == num_of_rows) {

                // If the ppm is already square then retain everything and output per usual
                last_pixel = (num_of_columns * num_of_rows);
                printf("%d %d %d\n", num_of_columns, num_of_rows, input);
            }
        }

        // If the number of columns > number of rows then do the following:
        if (num_of_columns > num_of_rows) {

            // Reset the total digits counter to 5 since it's required for calculations
            if (total_digits == 8 && last_pixel == 0) {
                total_digits = 5;
            }

            // If we are on the first value of a pixel then increase the column count
            if (total_digits == 5) {
                current_column++;
            }

            // Check if the current column surpassed the number of rows in the ppm then display the pixels accordingly
            if (current_column > num_of_rows && current_column <= num_of_columns) {
                last_pixel = 0;
            }
            else if (current_column > num_of_rows && current_column > num_of_columns) {
                current_column = 1;
                last_pixel = num_of_columns * num_of_rows;
            }
        }

        // Display all 3 pixel values depending on the current pixel
        if (total_digits == 5 && (current_pixel <= last_pixel)) {
            printf("%d ", input);
        }
        else if (total_digits == 6 && (current_pixel <= last_pixel)) {
            printf("%d ", input);
        }
        else if (total_digits == 7 && (current_pixel <= last_pixel)) {
            printf("%d\n", input);
            total_digits = 4;
            current_pixel++;
        }
    }
}