#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    // require the user for in
    cout << "Enter the original bill amount:";
    float base;
    cin >> base;

    cout << "Enter the tax rate %:";
    float tax_rate;
    cin >> tax_rate;

    cout << "Enter tip level (1=10%, 2=15%, 3=20%, 4=25%):";
    int tip_level;
    cin >> tip_level;

    cout << "Tip on post-tax amount? (1=yes, 2=no):";
    int post_tax;
    cin >> post_tax;

    // compute the total bill pre-tip
    float total_bill_pre_tip = base * (1+(tax_rate / 100));

    // initialize total_tip for the following code
    float total_tip;

    // first case tip on post-tax amount
    if (post_tax == 1) {
        // switch to four cases with different tip level
        switch (tip_level) {
            case 1:
                total_tip = total_bill_pre_tip * 0.1;
                break;
            case 2:
                total_tip = total_bill_pre_tip * 0.15;
                break;
            case 3:
                total_tip = total_bill_pre_tip * 0.2;
                break;
            case 4:
                total_tip = total_bill_pre_tip * 0.25;
                break;
        }
    }
    // second case: tip not on post-tax
    else if (post_tax == 2) {
        // switch to four cases with different tip level
        switch (tip_level) {
            case 1:
                total_tip = base * 0.1;
                break;
            case 2:
                total_tip = base * 0.15;
                break;
            case 3:
                total_tip = base * 0.2;
                break;
            case 4:
                total_tip = base * 0.25;
                break;
        }
    }

    cout << "The total bill pre-tip is: $" << fixed << setprecision(2) << total_bill_pre_tip << endl;
    cout << "The total tip is: $" << fixed << setprecision(2) << total_tip << endl;
    cout << "The total bill post-tip is: $" << fixed << setprecision(2) << (total_bill_pre_tip + total_tip) << endl;

}