// Problem: Given intervals, merge all overlapping ones.
// Sort first, then compare with previous.
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int start;
    int end;
} Interval;

int compare(const void *a, const void *b)
{
    return ((Interval *)a)->start - ((Interval *)b)->start;
}

int main()
{
    int n;
    scanf("%d", &n);

    Interval intervals[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &intervals[i].start, &intervals[i].end);
    }

    qsort(intervals, n, sizeof(Interval), compare);

    Interval merged[n];
    int k = 0;

    merged[k] = intervals[0];

    for (int i = 1; i < n; i++)
    {
        if (intervals[i].start <= merged[k].end)
        {
            if (intervals[i].end > merged[k].end)
                merged[k].end = intervals[i].end;
        }
        else
        {
            k++;
            merged[k] = intervals[i];
        }
    }

    for (int i = 0; i <= k; i++)
    {
        printf("%d %d\n", merged[i].start, merged[i].end);
    }

    return 0;
}