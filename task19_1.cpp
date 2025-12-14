#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int main() {
    int n;
    cout << "Enter number of customers: ";
    cin >> n;
    
    vector<int> t(n);
    vector<int> c(n);
    
    cout << "Enter arrival times t1, t2, ..., tn:\n";
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }
    
    cout << "Enter service times c1, c2, ..., cn:\n";
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    
    int minWaitCustomer = -1;
    int minWaitTime = numeric_limits<int>::max();
    int maxWaitCustomer = -1;
    int maxWaitTime = -1;
    
    int currentTime = 0;
    
    for (int i = 0; i < n; i++) {
        if (currentTime < t[i]) {
            currentTime = t[i];
        }
        
        int waitTime = currentTime - t[i];
        
        if (waitTime < minWaitTime) {
            minWaitTime = waitTime;
            minWaitCustomer = i + 1;
        }
        
        if (waitTime > maxWaitTime) {
            maxWaitTime = waitTime;
            maxWaitCustomer = i + 1;
        }
        
        currentTime += c[i];
    }
    
    cout << "Customer with minimum wait: " << minWaitCustomer << " (time: " << minWaitTime << ")\n";
    cout << "Customer with maximum wait: " << maxWaitCustomer << " (time: " << maxWaitTime << ")\n";
    
    return 0;
}