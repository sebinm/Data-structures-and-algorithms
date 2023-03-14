#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <random>
#include <chrono>


using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::sort;
using std::swap;
using std::setw;
using std::setfill;

#include "count.h"
#include "nonCount.h"


int main(void)
{
    for (auto N = 10; N <= 10000; N *= 10)
    {
        int* vec = new int[N];

        std::random_device rd; //Will be used to obtain a seed for the random number engine
        std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
        std::uniform_int_distribution<> dis(1, 10 * N);

        for (int index = 0; index < N; ++index)
        {
            vec[index] = dis(gen);
        }
        std::chrono::time_point<std::chrono::system_clock> start, end;

        int b = 0;
        int a = binarySearch(vec, 0, N, 1224, b);

        end = std::chrono::system_clock::now();

        // cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << endl;
        // cout << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << endl << endl;
        cout << b << endl;
        delete[] vec;
    }

	return 0;
}