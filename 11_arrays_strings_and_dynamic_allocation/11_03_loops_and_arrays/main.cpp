#include <iterator>

int main()
{
    constexpr int scores[]{84, 92, 76, 81, 56};
    constexpr int numStudents{static_cast<int>(std::size(scores))};
// const int numStudents{ sizeof(scores) / sizeof(scores[0]) }; // use this instead if not C++17 capable
    int totalScore{0};

// use a loop to calculate totalScore
    for (int student{0}; student < numStudents; ++student)
    {
        totalScore += scores[student];
    }


    auto averageScore{static_cast<double>(totalScore) / numStudents};
}