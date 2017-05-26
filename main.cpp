#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <cstdint>

// 2 <= n <= 2 * 10^5
using YearType = int;
// 1 <= p_i <= 10^16
using PriceType = std::int64_t;

// This one times out on Test Case 11
// sort by year (they're already sorted so that's nice)
PriceType naive()
{
    std::vector<PriceType> prices;
    YearType n;
    PriceType p;
    std::cin >> n;
    prices.reserve(n);
    // std::cout << n << '\n';
    for(YearType i = 0; i < n; ++i)
    {
        std::cin >> p;
        // std::cout << p << ' ';
        prices.push_back(p);
    }
    // std::cout << '\n';

    PriceType minimum_loss = std::numeric_limits<int>::max();
    for(YearType i = 0; i < n; ++i)
    {
        for(YearType j = i + 1; j < n; ++j)
        {
            PriceType price_1 = prices[i];
            PriceType price_2 = prices[j];
            // std::cout << "price_1: " << price_1 << " " << "price_2: " << price_2 << '\n';
            if (price_2 < price_1)
            {
                PriceType loss = price_1 - price_2;
                if (loss < minimum_loss)
                {
                    minimum_loss = loss;
                    // std::cout << "minimum_loss: " << minimum_loss << '\n';
                }
            }
        }
    }
    // std::cout << '\n' << minimum_loss << '\n';
    return minimum_loss;
}


int main()
{
#ifdef NAIVE
    PriceType minimum_loss = naive();
#endif
    std::cout << minimum_loss;

// Finally compare them if I can
#ifdef COMPARE
#endif
}
