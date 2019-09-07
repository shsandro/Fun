#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<math.h>

using namespace std;

template <class T>
class Individual{
    private:
        string class_name;
        T attr_1, attr_2, attr_3, attr_4; 
    public:
        Individual(T a, T b, T c, T d, string name = ""){
            attr_1 = a;
            attr_2 = b;
            attr_3 = c;
            attr_4 = d;
            class_name = name;
        }

        string get_class_name(){
            return class_name;
        }

        T get_attr_1(){
            return attr_1;
        }

        T get_attr_2(){
            return attr_2;
        }

        T get_attr_3(){
            return attr_3;
        }

        T get_attr_4(){
            return attr_4;
        }
};

template<class T>
double euclidean_distance(Individual<T>& a, Individual<T>& b){
    T sum = pow(a.get_attr_1() - b.get_attr_1(), 2) +  
            pow(a.get_attr_2() - b.get_attr_2(), 2) +  
            pow(a.get_attr_3() - b.get_attr_3(), 2) +  
            pow(a.get_attr_4() - b.get_attr_4(), 2);

    return sqrt(sum);
}

template<class T>
string classify(vector<Individual<T>>& population, Individual<T>& new_individual, int K){
    // Deixa o K ímpar
    if(K % 2 == 0){ 
        --K;
        if (K <= 0) K = 1;
    }
    
    //Tamanho da população
    int pop_size = population.size();

    //Distância do novo indivíduo para os outros
    //Por padrão a comparação do set é '<'
    set<pair<double, int>> individuals_distance;

    for (int i = 0; i < pop_size; ++i){
        double distance = euclidean_distance(population[i], new_individual);
        individuals_distance.insert(make_pair(distance, i));
    }
    
    //Por enquanto temos só três classes
    int count_classes[3];

    int count_K = 0;

    set<pair<double, int>>::iterator it; // Também poderia usar for each

    for (it = individuals_distance.begin(); it != individuals_distance.end(); ++it){
        string individual_class = population[it->second].get_class_name();

        int i = (individual_class == "Iris-setosa") ? 0 : (individual_class == "Iris-versicolor" ? 1 : 2);
        count_classes[i]++;

        ++count_K;
        if (count_K > K) break;
    }

    string new_individual_class = (count_classes[0] >= count_classes[1]) ? ((count_classes[0] >= count_classes[2]) ? "Iris-setosa" : "Iris-virginica") : ((count_classes[1] >= count_classes[2]) ? "Iris-versicolor" : "Iris-virginica");

    cout << "A classe do novo indivíduo é " << new_individual_class << endl;

    return new_individual_class;
}

int main(int argc, char* argv[]){
    vector<Individual<double>> population;

    int K = 3;
    int trainnig_size = 50;

    for (int i = 0; i < trainnig_size; ++i){
        string class_name;
        double a, b, c, d;
        cin >> a >> b >> c >> d >> class_name;
        population.push_back(Individual<double>(a, b, c, d, class_name));
    }

    int hits = 0;
    //Arquivo utilizado tem 150 indivíduos
    int tests_size = 150 - trainnig_size;

    for (int i = 0; i < tests_size; ++i){
        string class_name;
        double a, b, c, d;
        cin >> a >> b >> c >> d >> class_name;

        Individual<double> ind(a, b, c, d, class_name);

        if (ind.get_class_name() == classify(population, ind, K)){
            ++hits;
        }
    }

    cout << "Total de acertos: " << hits << endl;

    return 0;
}

