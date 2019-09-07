#include <iostream>
#include <memory>

using namespace std;

class Solution{
    public:
        Soluion(int argc, char const *argv[]){
            array = make_unique<int[]>(--argc);
        }
    public:
        unique_ptr<int[]> array;
        int solution[2];
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
