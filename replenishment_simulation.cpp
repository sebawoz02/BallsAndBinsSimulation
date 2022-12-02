#include <iostream>
#include <random>
#include <fstream>


int * replenishment_sim(int num_of_bins){
    int n = num_of_bins;
    int bins[n];
    for(int i=0;i<num_of_bins;i++){
        bins[i] = 0;
    }
    std::random_device rd{};
    std::mt19937 mt{rd()};
    static std::uniform_int_distribution<int> dist;
    dist.param(std::uniform_int_distribution<int>::param_type(0,num_of_bins-1));
    int empty_bins = n;
    int bins_w1 = 0;
    int bins_w2 = 0;
    bool full = false;    //pelne oznacza conajmniej dwie kule we wszystkich urnach
    int dn = 0;      //liczba rzutow po ktorej w kazdej z urn sa conajmniej dwie kule
    int bn = 0;      //moment pierwszej kolizji
    int cn = 0;      //minimalna liczba rzutow po ktorej w kazdej z urn jest conajmniej jedna kula
    int un = 0;      //liczba pustych urn po wrzuceniu n kul
    int ln = 0;     //maksymalna liczba kul w jednej urnie po wrzuczeniu n kul
    while(!full){
        dn += 1;
        //liczba calkowita z przedzialu od 0 do n-1
        int add_ball_at = dist(mt);
        bins[add_ball_at] += 1;
        int cur_val = bins[add_ball_at];
        if (cur_val == 2){
            bins_w2 += 1;
            if (bn == 0){
                bn = dn;
            }
            if (bins_w2 == num_of_bins){
                full = true;
            }
        }
        else if (cur_val == 1){
            bins_w1 += 1;
            empty_bins -= 1;
        }
        // jezeli jeszcze nie pobrano liczby to sprawdzam czy wszystkie urny maja conajmniej jedna kule
        if (dn > num_of_bins){
            if(cn==0 && empty_bins==0) {
                cn = dn;
            }
        }
        else if(dn==num_of_bins){
            if(empty_bins==0){
                cn=dn;
            }
            un = empty_bins;
            if(cur_val>ln){
                ln+=1;
            }
        }
        else if(cur_val>ln){
            ln+=1;
        }
    }
    int results [6]= {bn, un, ln, cn, dn, dn-cn};
    int *res;
    res = results;
    return res;
}

int main() {
    time_t start, end;
    time(&start);
    std::ofstream myfile("E:/STUDIA/MPiS/ZADDOM2/BallAndBinsCPP/results.txt");
    for(int n=1000;n<100001;n+=1000){
        for(int k=0;k<50;k++){
            int* result = replenishment_sim(n);
            myfile << std::to_string(*(result+0)) << " ";
            myfile << std::to_string(*(result+1)) << " ";
            myfile << std::to_string(*(result+2)) << " ";
            myfile << std::to_string(*(result+3)) << " ";
            myfile << std::to_string(*(result+4)) << " ";
            myfile << std::to_string(*(result+5)) << std::endl;
        }
    }
    myfile.close();
    time(&end);
    auto time_taken = double(end - start);
    std::cout << "Time taken by program is : " << time_taken << "sec " << std::endl;
    return 0;
}
