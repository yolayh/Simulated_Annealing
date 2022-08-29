#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <math.h>
#include <cstdio>

using namespace std;

typedef vector<bool> vec;

//宣告變數
vec solution;
int result;
double temperature;

//宣告function
void initialization(int);
int evaluation(vec);
vec transition(vec);
void determination(vec);
void execution(double, double, int, int, int);

void print_vec(vec);

//print
void print_vec(vec v){
    for(auto i: v){
        cout << i;
    }
}



//Initialize
void initialization(int bit){
    solution.assign(bit,0);         
    for (int i =0; i < bit; i++)
        solution[i] = rand() % 2;       //initial result
    
}

//Evaluation
int evaluation(vec v){
    int size = v.size();
    int vec_sum = 0;
    for (int i=0; i< size; i++){
        vec_sum += v[i];
    }
    return vec_sum;
}

//transition
vec transition(vec v){
    int size = v.size();
    int pick = rand() % size;
    if (v[pick] == 1)
        v[pick] = 0;
    else
        v[pick] = 1; 
    
    return v;
}

//Determination
void determination(vec trans){
    int f2 = evaluation(trans);
    if (f2 >= result){
        solution = trans;
        result = f2;
    }
    else{
        double ran_prob = (double)rand()/(RAND_MAX);
        double accept = exp((f2-result)/temperature);
        if (accept > ran_prob){
            solution = trans;
            result = f2;
        }

    }
}

//(初始溫度; 降溫係數; bit; run; iteration)
void execution(double t, double r, int bit, int run, int iter){
    
    srand((unsigned)time(NULL));
    vector<int> all_result;
    all_result.assign(run,0);
    double run_sum = 0;

    for (int i = 0; i < run; i++){

        temperature = t;
        
        cout << "run-" << i+1 << endl;

        initialization(bit);
        result = evaluation(solution);

        print_vec(solution);
        cout << "\n" ;

        for(int k = 0; k < iter; k++){
            vec new_solu = transition(solution);
            determination(new_solu);
            temperature *= r;

            print_vec(new_solu);
            cout << " ( CURRENT: " ;
            print_vec(solution);
            cout << " " << result << ")" << endl;
        }

        
        all_result [i] = result;
        run_sum += result;
        cout << "\n" ;

    }

    cout << "\nEND: ";
    for (auto i: all_result)
        cout << i << " ";
        
    double average = run_sum / run;
    cout << "\n";
    printf("average: %.2f",average);
}