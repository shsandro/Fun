#include <iostream>
#include <memory>
#include <map>

using namespace std;

class Solution{
    public:
        Solution(){
            cin >> array_size >> target;

            if (array_size < 0) throw "Tamanho negativo.";

            array = make_unique<int[]>(array_size);

            for (int i = 0; i < array_size; ++i){
                cin >> array[i];
            }

        }

    public:
        unique_ptr<int[]> array;
        int array_size;
        int target;
        int solution[2];
};

int main(int argc, char const *argv[]){
    Solution solution;

    map<int, int> map_solution;

    for (int i = 0; i < solution.array_size; ++i){
        int val = map_solution[solution.target - solution.array[i]];
        cout << val;
    }

    return 0;
}
