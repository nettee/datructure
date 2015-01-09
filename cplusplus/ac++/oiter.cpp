#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

int main()
{
    vector<float> nums;
    float f;
    while (cin >> f) {
        nums.push_back(f);
    }

    copy(nums.begin(), nums.end(), ostream_iterator<float>(cout, "\n"));

    return 0;
}
