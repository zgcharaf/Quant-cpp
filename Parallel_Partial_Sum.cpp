#include <iostream>
#include <thread>
#include <vector>
#include <chrono>  // Include the chrono library for time measurement

void partial_sum(const std::vector<int>& arr, int start, int end, int& result) {
    result = 0;
    for (int i = start; i < end; ++i) {
        result += arr[i]%arr[i+1];
    }
}

int main() {
    const int num_threads = 4;
    const int num_elements = 1000000;
    std::vector<int> arr(num_elements);
    for (int i = 0; i < num_elements; ++i) {
        arr[i] = i + 1;  // Initializing array with values 1 to 100
    }

    std::vector<std::thread> threads;
    std::vector<int> results(num_threads);

    int chunk_size = num_elements / num_threads;

    auto start_time = std::chrono::high_resolution_clock::now();  // Start time

    for (int i = 0; i < num_threads; ++i) {
        int start = i * chunk_size;
        int end = (i + 1) * chunk_size;
        if (i == num_threads - 1) {
            end = num_elements;  // Last thread takes any remaining elements
        }
        threads.emplace_back(partial_sum, std::cref(arr), start, end, std::ref(results[i]));
    }

    for (auto& t : threads) {
        t.join();
    }

    auto end_time = std::chrono::high_resolution_clock::now();  // End time

    int total_sum = 0;
    for (int result : results) {
        total_sum += result;
    }

    std::chrono::duration<double> elapsed_time = end_time - start_time;  // Calculate elapsed time

    std::cout << "Total sum: " << total_sum << std::endl;
    std::cout << "Elapsed time: " << elapsed_time.count() << " seconds" << std::endl;

    return 0;
}
