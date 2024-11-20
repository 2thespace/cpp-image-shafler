
#include <algorithm>
#include <queue>
#include <random>
#include <iterator>


namespace Shuffle {
template<typename T>
class Worker {
public:        
        std::vector<T> shaffleSequence(std::vector<T>  const& input, std::size_t key);
        std::vector<T> deshaffleSequence(std::vector<T>  const& input);
    };

} // namespace shuffle



template <typename T>
inline std::vector<T> Shuffle::Worker<T>::shaffleSequence(std::vector<T> const &input, std::size_t key) {
    std::random_device rd;
    std::mt19937 g(key);
    std::vector<T> result{input};
    std::shuffle(result.begin(), result.end(), g);
    return result;    
}

template <typename T>
inline std::vector<T> Shuffle::Worker<T>::deshaffleSequence(std::vector<T> const &input) {
    std::vector<T> result(input.size());
    for(auto i =0; i < input.size(); i++) {
        result[input[i]] = input[i];
    }
    return result;       
}