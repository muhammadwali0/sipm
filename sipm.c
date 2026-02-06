#include <stdio.h>
#include <math.h>
#include <string.h>

#define MAX_DAYS 100

void displayMenu();
void loadData(double *prices, int *n); 
void calculateMetrics(double *prices, int n); 
void sortAndAnalyzeRange(double *prices, int n); 
double calculateRecursiveGrowth(double principal, double rate, int years); 
void saveReport(double mean, double risk, char *status); 
void validateInput(int *choice);

int main() {
    double prices[MAX_DAYS];
    int n = 0;
    int choice;

    do {
        displayMenu();
        validateInput(&choice);

        switch (choice) {
            case 1:
                loadData(prices, &n);
                break;
            case 2:
                if (n < 2) printf("\n[!] Error: Load at least 2 days of data first.\n");
                else calculateMetrics(prices, n);
                break;
            case 3:
                if (n < 2) printf("\n[!] Error: Load at least 2 days of data first.\n");
                else sortAndAnalyzeRange(prices, n);
                break;
            case 4: {
                double p, r;
                int y;
                printf("\nEnter Principal Investment (PKR): ");
                scanf("%lf", &p);
                printf("Enter Expected Annual Return Rate (e.g., 0.07 for 7%%): ");
                scanf("%lf", &r);
                printf("Enter Investment Duration (Years): ");
                scanf("%d", &y);
                
                double total = calculateRecursiveGrowth(p, r, y);
                printf("\n>>> Projected Portfolio Value: PKR%.2f\n", total);
                break;
            }
            case 5:
                printf("\nExiting...\n");
                break;
            default:
                printf("\n[!] Invalid selection. Try again.\n");
        }
    } while (choice != 5);

    return 0;
}

void displayMenu() {
    printf("\n==========================================\n");
    printf("  STRATEGIC INVESTMENT & PORTFOLIO MANAGER \n");
    printf("==========================================\n");
    printf("1. Load Historical Price Data\n");
    printf("2. Statistical Risk & Return Analysis\n");
    printf("3. Price Range Analysis (Sorting)\n");
    printf("4. Future Growth Forecast (Recursion)\n");
    printf("5. Exit\n");
    printf("Selection: ");
}


void validateInput(int *choice) {
    if (scanf("%d", choice) != 1) {
        printf("Non-numeric input detected.");
        while (getchar() != '\n'); 
    }
}


void loadData(double *prices, int *n) {
    FILE *file = fopen("prices.txt", "r");
    if (file == NULL) {
        printf("\n[!] Error: 'prices.txt' not found! Please create it.\n");
        return;
    }
    *n = 0;
    while (fscanf(file, "%lf", &prices[*n]) != EOF && *n < MAX_DAYS) {
        (*n)++;
    }
    fclose(file);
    printf("\n[+] Successfully loaded %d price points.\n", *n);
}


void calculateMetrics(double *prices, int n) {
    double returns[MAX_DAYS];
    double sum = 0, mean, variance = 0, stdDev;


    for (int i = 1; i < n; i++) {
        returns[i] = (prices[i] - prices[i-1]) / prices[i-1];
        sum += returns[i];
    }
    mean = sum / (n - 1);


    for (int i = 1; i < n; i++) {
        variance += pow(returns[i] - mean, 2);
    }
    stdDev = sqrt(variance / (n - 1));


    char status[30];
    if (stdDev > 0.05) {
        strcpy(status, "High Volatility Asset");
    } else if (stdDev > 0.02) {
        strcpy(status, "Balanced Risk Asset");
    } else {
        strcpy(status, "Conservative/Stable Asset");
    }

    printf("\n--- STATISTICAL ANALYSIS ---\n");
    printf("Average Daily Return: %.2f%%\n", mean * 100);
    printf("Risk Level (Std Dev): %.2f%%\n", stdDev * 100);
    printf("Investment Status:    %s\n", status);

    saveReport(mean, stdDev, status);
}

void sortAndAnalyzeRange(double *prices, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (*(prices + j) > *(prices + j + 1)) { 
                double temp = *(prices + j);
                *(prices + j) = *(prices + j + 1);
                *(prices + j + 1) = temp;
            }
        }
    }

    double minPrice = prices[0];
    double maxPrice = prices[n-1];
    double spread = maxPrice - minPrice;

    printf("\n--- PRICE RANGE ANALYSIS ---\n");
    printf("Sorted Prices: ");
    for(int k=0; k<n; k++) printf("%.2f ", prices[k]);
    
    printf("\n\nLowest Recorded Price:  PKR%.2f\n", minPrice);
    printf("Highest Recorded Price: PKR%.2f\n", maxPrice);
    printf("Total Price Spread:      PKR%.2f\n", spread);
}

double calculateRecursiveGrowth(double principal, double rate, int years) {
    if (years <= 0) {
        return principal; 
    }
    return (1 + rate) * calculateRecursiveGrowth(principal, rate, years - 1);
}

void saveReport(double mean, double risk, char *status) {
    FILE *f = fopen("report.txt", "w");
    if (f == NULL) {
        printf("[!] Error saving report.\n");
        return;
    }
    fprintf(f, "INVESTMENT PERFORMANCE SUMMARY\n");
    fprintf(f, "------------------------------\n");
    fprintf(f, "Mean Return: %.4f\n", mean);
    fprintf(f, "Risk Factor: %.4f\n", risk);
    fprintf(f, "Risk Category: %s\n", status);
    fclose(f);
    printf("\n[i] Summary report generated as 'report.txt'\n");
}

