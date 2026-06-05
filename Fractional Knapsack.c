#include <stdio.h>

typedef struct
{
    int profit;
    int weight;
    float ratio;
} Item;

void sort(Item items[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (items[j].ratio < items[j + 1].ratio)
            {
                Item temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int n, capacity;
    float totalProfit = 0.0;

    printf("Enter number of items: ");
    scanf("%d", &n);

    Item items[n];

    printf("Enter profits and weights:\n");

    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &items[i].profit, &items[i].weight);
        items[i].ratio = (float)items[i].profit / items[i].weight;
    }

    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    sort(items, n);

    for (int i = 0; i < n; i++)
    {
        if (items[i].weight <= capacity)
        {
            totalProfit += items[i].profit;
            capacity -= items[i].weight;
        }
        else
        {
            totalProfit += items[i].ratio * capacity;
            break;
        }
    }

    printf("Maximum profit = %.2f\n", totalProfit);

    return 0;
}
