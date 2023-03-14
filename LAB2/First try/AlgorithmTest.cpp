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

#include "nonCount.h"

// Masurare Algoritmi

void masuarareBubleSort(unsigned long long* MS, unsigned long long* US)
{
    short i = 0;
    short j = 0;

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

        bubbleSortN(vec, N);

        end = std::chrono::system_clock::now();

        MS[i] = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        US[j] = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

        ++i;
        ++j;

        delete[] vec;
    }
}
void masuarareSelectionSort(unsigned long long* MS, unsigned long long* US)
{
    short i = 0;
    short j = 0;

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

        selectionSortN(vec, N);

        end = std::chrono::system_clock::now();

        MS[i] = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        US[j] = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

        ++i;
        ++j;

        delete[] vec;
    }
}

void masuarareInsertionSort(unsigned long long* MS, unsigned long long* US)
{
    short i = 0;
    short j = 0;

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

        insertionSortN(vec, N);

        end = std::chrono::system_clock::now();

        MS[i] = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        US[j] = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

        ++i;
        ++j;

        delete[] vec;
    }
}
void masuarareBruteForce(unsigned long long* MS, unsigned long long* US)
{
    short i = 0;
    short j = 0;

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

        bool test = BruteForce_searchN(vec, N, 1024);

        end = std::chrono::system_clock::now();

        MS[i] = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        US[j] = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

        ++i;
        ++j;

        delete[] vec;
    }
}
void masuarareBinarySearch(unsigned long long* MS, unsigned long long* US)
{
    short i = 0;
    short j = 0;

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

        int y = binarySearchN(vec, 1, N-1, 1);

        end = std::chrono::system_clock::now();

        MS[i] = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        US[j] = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

        ++i;
        ++j;

        delete[] vec;
    }
}