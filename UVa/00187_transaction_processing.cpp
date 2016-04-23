/**
 * Author: Daniel Furelos Blanco (Ertsiger)
 * 23/04/2016
 * Time: 0.000
 */
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <utility>
#include <iomanip>
#include <cstdio>

using namespace std;

int main()
{
    map<string, string> accounts;

    string line = "";

    while (getline(cin, line))
    {
        string number = line.substr(0, 3);

        if (number[0] == '0' && number[1] == '0' && number[2] == '0')
        {
            break;
        }
        else
        {
            string name = line.substr(3, string::npos);
            accounts[number] = name;
        }
    }
    
    string number = "";
    int quantity = 0;
    int accQuantity = 0;
    string lastTransactionNumber = "-1";
    bool firstTransaction = true;
    vector< pair<string, int> > transactions;

    while (cin >> number >> quantity)
    {
        string transactionNumber = number.substr(0, 3);

        if (transactionNumber != lastTransactionNumber)
        {
            if (firstTransaction)
            {
                firstTransaction = false;
            }
            else
            {
                if (accQuantity != 0)
                {
                    cout << "*** Transaction " << lastTransactionNumber << " is out of balance ***\n";

                    for (auto it = transactions.begin(); it != transactions.end(); ++it)
                    {
                        //cout << it->first << " " << accounts[it->first] << " " << setprecision(2) << fixed << 0.01 * double(it->second) << endl;
                        printf("%-3s %-30s %10.2f\n", it->first.c_str(), accounts[it->first].c_str(), 0.01 * double(it->second));
                    }
                    
                    //cout << "999 Out of Balance " << setprecision(2) << fixed << -0.01 * double(accQuantity) << "\n\n";
                    printf("%-3s %-30s %10.2f\n\n", "999", "Out of Balance", -0.01 * double(accQuantity));
                }
            }

            accQuantity = 0;
            lastTransactionNumber = transactionNumber;
            transactions.clear();
        }

        if (transactionNumber[0] == '0' && transactionNumber[1] == '0' && transactionNumber[2] == '0')
        {
            break;
        }
        else
        {
            string accountNumber = number.substr(3, string::npos);
            transactions.push_back(make_pair(accountNumber, quantity));
            accQuantity += quantity;
        }
    }

    return 0;
}


