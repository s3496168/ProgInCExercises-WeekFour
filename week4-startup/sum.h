#ifndef SUM_H
#define SUM_H

#define MAXLEN 20
struct int_list {
    int nums[MAXLEN];
    long len;
};

typedef enum {
    FALSE,
    TRUE
} BOOLEAN;

void intlist_init(struct int_list *);
BOOLEAN intlist_add(struct int_list *, int);
BOOLEAN matching_sum(const struct int_list *, int);
#endif
