#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

class solution {
  public:
    std::vector<int> countBits(int num) {
        std::vector<int> bits{0,1};
        while (bits.size() <= num)
            bits = expand(bits);

        return std::vector<int>(bits.begin(), bits.begin()+num+1);
    }

  private:
    std::vector<int> expand(const std::vector<int> & vec) {
        std::vector<int> result;
        result = vec;
        std::transform(vec.begin(), vec.end(), std::inserter(result,result.end()), [](int i){return i+1;});
        return result;
    }
};

int main() {
    int num = 55;

    solution soln;
    auto bitVec = soln.countBits(num);
    std::copy(bitVec.begin(), bitVec.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
}
