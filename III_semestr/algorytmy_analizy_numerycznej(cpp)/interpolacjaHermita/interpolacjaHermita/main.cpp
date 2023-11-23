#include <iostream>
#include <vector>

int main() {
    int n;
    std::cout << "Enter the number of nodes: ";
    std::cin >> n;

    std::vector<double> nodes(n), functionValues(n), derivatives(n);
    std::cout << "Enter the values of nodes: ";
    for(int i = 0; i < n; i++)
        std::cin >> nodes[i];

    std::cout << "Enter the function values at these nodes: ";
    for(int i = 0; i < n; i++)
        std::cin >> functionValues[i];

    std::cout << "Enter the derivatives at these nodes: ";
    for(int i = 0; i < n; i++)
        std::cin >> derivatives[i];

    std::vector<std::vector<double>> dividedDifferences(n, std::vector<double>(n));
    for(int i = 0; i < n; i++) {
        dividedDifferences[i][0] = functionValues[i];
        dividedDifferences[i][1] = derivatives[i];
    }

    for(int i = 2; i < 2*n; i++) {
        for(int j = 0; j < n; j++) {
            if(j + i/2 < n) {
                dividedDifferences[j][i] = (dividedDifferences[j+1][i-1] - dividedDifferences[j][i-1]) / (nodes[j+i/2] - nodes[j]);
            }
        }
    }

    std::cout << "Divided differences: " << std::endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= i; j++) {
            std::cout << dividedDifferences[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
