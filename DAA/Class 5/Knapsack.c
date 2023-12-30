#include <stdio.h>

int main()
{
    int n, m, w[100], p[100], i;
    float x[100], ratio[100], total_profit = 0;

    // Reading number of items
    printf("Enter the number of items(n): ");
    scanf("%d", &n);

    // Reading the capacity of the knapsack
    printf("Enter the capacity of the Knapsack(m): ");
    scanf("%d", &m);

    // Reading the Weights and Profit values
    printf("Enter the Weights and Profit Values of items:\n");
    for (i = 0; i < n; i++)
    {
        printf("Item %d:\n", i + 1);
        printf("Weight: ");
        scanf("%d", &w[i]);
        printf("Profit: ");
        scanf("%d", &p[i]);
        ratio[i] = (float)p[i] / w[i];
    }

    // Sorting items based on the ratio in descending order
    for (i = 0; i < n; i++)
    {
        int j;
        for (j = i + 1; j < n; j++)
        {
            if (ratio[i] < ratio[j])
            {
                // Swap items based on ratio
                float tempRatio = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = tempRatio;

                int tempWeight = w[i];
                w[i] = w[j];
                w[j] = tempWeight;

                int tempProfit = p[i];
                p[i] = p[j];
                p[j] = tempProfit;
            }
        }
    }

    // Initialize solution array x to zeros
    for (i = 0; i < n; i++)
    {
        x[i] = 0.0;
    }

    // Calculate the solution array x
    for (i = 0; i < n; i++)
    {
        if (w[i] <= m)
        {
            x[i] = 1.0; // Take the whole item
            m -= w[i];
        }
        else
        {
            x[i] = (float)m / w[i]; // Take a fraction of the item
            m = 0;
        }
    }

    // Calculate the total profit
    for (i = 0; i < n; i++)
    {
        total_profit += x[i] * p[i];
    }

    // Display the results
    printf("The Table After Sorting based on the Ratio:\n");
    printf("Item:\t\t");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", i + 1);
    }
    printf("\nProfit:\t\t");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", p[i]);
    }
    printf("\nWeights:\t");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", w[i]);
    }
    printf("\nRATIO:\t\t");
    for (i = 0; i < n; i++)
    {
        printf("%.3f\t", ratio[i]);
    }
    printf("\nX = [");
    for (i = 0; i < n; i++)
    {
        printf("%.3f, ", x[i]);
    }
    printf("]\n");
    printf("Total Profit = %.2f\n", total_profit);

    return 0;
}