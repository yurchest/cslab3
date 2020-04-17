#include <iostream>
#include <vector>

using namespace std;



vector<double>
input_numbers(size_t count) {
    vector<double> result(count);
    for (size_t i = 0; i < count; i++) {
        cin >> result[i];
    }
    return result;
}


void
find_minmax(const vector<double>& numbers, double& min, double& max){
    min = numbers[0];
    for (double x : numbers) {
        if (x < min) {
            min = x;
        }
        else if (x > max) {
            max = x;
        }
    }
}


vector<size_t>
make_histogram(const vector<double>& numbers, size_t& bin_count){

    vector<size_t> bins(bin_count, 0);
    double min, max;
    find_minmax(numbers, min, max);
    for (double x : numbers){
        size_t bin_index = (size_t)((x - min)/(max - min) * bin_count);
        if (bin_index == bin_count){
            bin_index--;
        }
    bins[bin_index]++;
    }
    return bins;
}

void
show_histogram_text(const vector<size_t>& bins){

    double max_count = bins[0];
    for(size_t bin : bins){
        if (bin > max_count) {
            max_count = bin;
        }
     }

     const size_t SCREEN_WIDTH = 80;
     size_t max_asterisk;
     if (max_count < 10)  max_asterisk = SCREEN_WIDTH - 1 - 1;
     if (max_count >= 10 && max_count < 100) max_asterisk = SCREEN_WIDTH - 1 - 2;
     if (max_count >= 100) max_asterisk = SCREEN_WIDTH - 1 - 3;

      double koeff = 1;
         if (max_count > max_asterisk){
     koeff = (double)(max_asterisk)/max_count;
     }




    for(size_t bin : bins){

            if(max_count < 10){
                cout << bin << "|";
            }

            if (max_count >= 10 && max_count < 100){
                 if(bin >= 10 && bin < 100) cout<< bin <<"|";
                 if(bin < 10) cout<<" "<< bin <<"|";
            }

            if (max_count >= 100){
                if(bin >= 100) cout<< bin <<"|";
                if(bin >= 10 && bin < 100) cout<<" "<< bin <<"|";
                if(bin < 10) cout<<"  "<< bin <<"|";
            }

        for(int i=0;i<bin*koeff;i++){
            cout<<"*";}
        cout<<endl;
        }
    return;
}


int main()
{


    size_t number_count;
    cerr<<"Enter number count ";
    cin>>number_count;

    cerr<<"Enter massive"<<endl;
    const auto numbers = input_numbers(number_count);

    size_t bin_count;
    cerr<<"Enter bin count ";
    cin>>bin_count;

    //MAKE HISTOGRAM
    const auto bins = make_histogram(numbers, bin_count);

    //SHOW HISTOGRAM
    show_histogram_text(bins);

    return 0;
}
