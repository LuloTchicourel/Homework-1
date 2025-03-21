#include <iostream>
#include <chrono>
#include <string>   

using namespace std;

constexpr const bool recursive_comparision(const char *string1, const char *string2){
    if (*string1 == '\0' && *string2 == '\0') return true;
    if (*string1 != *string2) return false;
    return recursive_comparision(string1 + 1, string2 + 1);
}

int main() {
    // textos randoms generdos por chatGPT para probar.
    constexpr const char *text1 = "This is a very long string to test recursive comparison properly!"; 
    constexpr const char *text2 = "This is a very long string to test recursive comparison properly!";
    constexpr const char *text3 = "This is a different long string with some changes in it!";

    auto start1 = chrono::high_resolution_clock::now();
    constexpr const bool result1 = recursive_comparision(text1, text2);
    auto end1 = chrono::high_resolution_clock::now();
    auto time1 = chrono::duration_cast<chrono::nanoseconds>(end1 - start1);

    auto start2 = chrono::high_resolution_clock::now();
    constexpr const bool result2 = recursive_comparision(text1, text3);
    auto end2 = chrono::high_resolution_clock::now();
    auto time2 = chrono::duration_cast<chrono::nanoseconds>(end2 - start2);

    cout << "Comparing text1 and text2: " << result1 << " (Execution time: " << time1.count() << " ns)\n";
    cout << "Comparing text1 and text3: " << result2 << " (Execution time: " << time2.count() << " ns)\n";

    return 0;
}