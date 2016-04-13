/*
 *   10026  -  Shoemaker's Problem
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

struct Job {
    int num;
    int t, s;
    
    void read(int i) {
        num = i;
        scanf("%d %d", &t, &s);
    }
};


Job jobs[MAX+1];


int compare(Job *job1, Job *job2)
{
    int d =  job2->s * job1->t - job1->s * job2->t;
    if (d != 0) return d;
    return (job1->num - job2->num);
}


int main()
{
    int cases, n;
    scanf("%d", &cases);
    for (int i = 0; i < cases; i++)
    {
        scanf("%d", &n);
        for (int j = 1; j <= n; j++) {
            jobs[j].read(j);
        }
        qsort(jobs+1, n, sizeof(Job), (int(*)(const void *, const void *))compare);
        if (i > 0) putchar('\n');
        printf("%d", jobs[1].num);
        for (int j = 2; j <= n; j++) {
            printf(" %d", jobs[j].num);
        }
        putchar('\n');
    }
    return 0;
}

