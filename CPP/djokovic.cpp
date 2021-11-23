#include <cmath>
#include <iostream>
using namespace std;

#define PAYMENT_RATIO 1 / 8
#define SHOE_PRICE_RATIO 1 / 6
#define ADDITIONAL_COSTS 120 / 100

int main() {
    unsigned int racket_price, racket_count, shoe_count;
    cin >> racket_price >> racket_count >> shoe_count;

    float price = (racket_price * racket_count +
                   (float)racket_price * SHOE_PRICE_RATIO * shoe_count) *
                  ADDITIONAL_COSTS;

    cout << "Price to be paid by Djokovic " << floor(price * PAYMENT_RATIO)
         << endl
         << "Price to be paid by sponsors "
         << ceil(price - price * PAYMENT_RATIO) << endl;

    return 0;
}
