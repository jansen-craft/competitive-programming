#include <iostream>
#include <vector>
//#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int num_books, max_total_price;
    cin >> num_books >> max_total_price;
    vector<int> book_price(num_books+1);
    vector<int> book_page(num_books+1);
    
    int most_pages[num_books + 1][max_total_price + 1];
    for (int i = 1; i <= num_books; i++){
        cin >> book_price[i];
    }
 
    for (int i = 1; i <= num_books; i++){
        cin >> book_page[i];
    }
 
    for (int j = 0; j <= max_total_price; j++){
        most_pages[0][j] = 0;
    }
 
 
    
 
    for (int i = 1; i <= num_books; i++){
        for (int j = 0; j <= max_total_price; j++){
            most_pages[i][j] = most_pages[i-1][j];  // most pages
            int leftover = j - book_price[i];
            if(leftover >= 0){  // you can buy it!
                most_pages[i][j] = max(most_pages[i][j], book_page[i] + most_pages[i-1][leftover]);
            }
        }
    }    
    
    cout << most_pages[num_books][max_total_price] << endl;
 
    return 0;
}
