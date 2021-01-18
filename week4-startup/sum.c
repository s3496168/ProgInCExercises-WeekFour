#include "sum.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * zeroes out the array (writes zeroes into the memory to make the array an
 * empty array
 **/
void intlist_init(struct int_list *thelist) {
    memset(thelist, 0, sizeof(*thelist));
}

/**
 * adds a number to our list of numbers. Will return FALSE if there is no
 * space left in the array.
 **/
BOOLEAN intlist_add(struct int_list *thelist, int new_num) {
    if (thelist->len >= MAXLEN) {
        return FALSE;
    }
    thelist->nums[thelist->len++] = new_num;
    return TRUE;
}

void intlist_print(const struct int_list *alist) {
    int count;
    for (count = 0; count < alist->len; ++count) {
        printf("%d,", alist->nums[count]);
    }
    printf("\b \n");
}

/**
 * tests wther the sum calculated from the array provided matches the required
 * sum
 **/
static BOOLEAN sum_equals(const struct int_list *thelist, int desired_sum) {
    long count;
    int sum = 0;
    intlist_print(thelist);
    /* add up the array elements */
    for (count = 0; count < thelist->len; ++count) {
        sum += thelist->nums[count];
    }
    return sum == desired_sum;
}

/**
 * define your algorithm here to check wheter any subset of the numbers in the
 * array match the target sum. This is the only function you need to implement
 * for tutorial 4
 **/
BOOLEAN matching_sum(const struct int_list *thelist, int desired_sum) {
    int skip_count;
    /* base case - is the list empty? */
    if (thelist->len == 0) {
        return FALSE;
    }
    /* check the sum - is it a match ? */
    if (sum_equals(thelist, desired_sum)) {
        return TRUE;
    }
    /* create new lists - each list is missing just one number that is
     * in the parent list */
    for (skip_count = 0; skip_count < thelist->len; ++skip_count) {
        int inner_count;
        struct int_list newlist;
        intlist_init(&newlist);
        for (inner_count = 0; inner_count < thelist->len; ++inner_count) {
            if (skip_count != inner_count) {
                intlist_add(&newlist, thelist->nums[inner_count]);
            }
        }
        if (matching_sum(&newlist, desired_sum)) {
            return TRUE;
        }
    }
    return FALSE;
}

#define ARRAYSIZE 5
#define TARGETSUM 19 /* try 6 for a fail case */

int main(void) {
    struct int_list number_list;
    /* numbers to find the sum on */
    int nums[] = {3, 4, 5, 7, 9};
    long count;

    intlist_init(&number_list);
    /* add the numbers to the int list */
    for (count = 0; count < ARRAYSIZE; ++count) {
        intlist_add(&number_list, nums[count]);
    }
    /* check for a matching sum in the subset of the int list */
    if ((matching_sum(&number_list, TARGETSUM))) {
        printf("matching sum is found\n");
    } else {
        printf("matching sum is not found\n");
    }
    return EXIT_SUCCESS;
}
