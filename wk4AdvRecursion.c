#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FIRST 1
#define SECOND 5
#define THIRD 9
#define FOURTH 2

#define MAXLEN 20

#define ARRAYSIZE 5
#define TARGETSUM 22 /*6 may present a full test case*/

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

/*list enum*/
struct int_list {
    int nums[MAXLEN];
    long len;
};

/*ensure the array is empty by zeroing it out*/
void intlist_init(struct int_list *thelist) {
    memset(thelist, 0, sizeof(*thelist));
}

/*adds a number to the array OR returns false if the array is full*/
BOOLEAN intlist_add(struct int_list *thelist, int new_num) {
    if (thelist->len >= MAXLEN) {
        return FALSE;
    }
    thelist->nums[thelist->len++] = new_num;
    return TRUE;
}

/*print out each list of numbers*/
void intlist_print(const struct int_list *alist) {
    int count;
    for (count = 0; count < alist->len; ++count) {
        printf("%d,", alist->nums[count]);
    }
    /*b=backspace, n=newline-this gets rid of the last comma*/
    printf("\b \n");
}

/*test to see if any of the list of numbers when a
dded together matches teh required sum*/
static BOOLEAN sum_equals(const struct int_list *thelist, int desired_sum) {
    long count;
    int sum = 0;
    intlist_print(thelist);
    /*add up the array elements*/
    for (count = 0; count < thelist->len; ++count) {
        sum += thelist->nums[count];
    }
    return sum == desired_sum;
}

BOOLEAN matching_sum(const struct int_list *thelist, int desired_sum) {
    int skip_count;
    /*base case (finishing condition)-is the list empty?*/
    if (thelist->len == 0) {
        return FALSE;
    }

    /*check the sum-is it a match
    use an existing function to do this*/
    if (sum_equals(thelist, desired_sum)) {
        return TRUE;
    }

    /*creates the new list - each list features one less
    number than the parent list*/
    /*initialise the new list*/
    for (skip_count = 0; skip_count < thelist->len; ++skip_count) {
        int inner_count;
        struct int_list newlist;
        intlist_init(&newlist);
        /*2 populate the new list*/
        for (inner_count = 0; inner_count < thelist->len; ++inner_count) {
            /*2a only put the number in the list if the temp
            list is on e less than the parent list*/
            if (skip_count != inner_count) {
                intlist_add(&newlist, thelist->nums[inner_count]);
            }
        }
        /*if the newlist presents the desired sum, leave the loop*/
        if (matching_sum(&newlist, desired_sum)) {
            return TRUE;
        }
    }
    /*final breajout when there is nothing to do*/
    return FALSE;
}

int main(void) {
    struct int_list number_list;
    /*the numbers for the sum*/
    int nums[] = {1, 3, 5, 7, 9};
    long count;

    /*initialise the list-remember the pointer and hence the need for the
     * address*/
    intlist_init(&number_list);
    /*add the numbers to the int list*/
    for (count = 0; count < ARRAYSIZE; ++count) {
        intlist_add(&number_list, nums[count]);
    }
    /*check to see if there is a matching sum in the subset/new list of the int
     * list*/

    if ((matching_sum(&number_list, TARGETSUM))) {
        printf("Matching sum is found \n");
    } else {
        printf("matching sum is not found\n");
    }
    return EXIT_SUCCESS;
}
