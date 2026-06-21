// Problem: Given a target distance and cars’ positions & speeds, compute the number of car fleets reaching the destination.
// Sort cars by position in descending order and calculate time to reach target.
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int position;
    int speed;
} Car;

int compare(const void *a, const void *b)
{
    return ((Car *)b)->position - ((Car *)a)->position; // Descending position
}

int main()
{
    int target, n;

    scanf("%d", &target);
    scanf("%d", &n);

    Car cars[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &cars[i].position);

    for (int i = 0; i < n; i++)
        scanf("%d", &cars[i].speed);

    qsort(cars, n, sizeof(Car), compare);

    int fleets = 0;
    double maxTime = 0.0;

    for (int i = 0; i < n; i++)
    {
        double time = (double)(target - cars[i].position) / cars[i].speed;

        if (time > maxTime)
        {
            fleets++;
            maxTime = time;
        }
    }

    printf("%d\n", fleets);

    return 0;
}