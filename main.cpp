#include <iostream>
#include <vector>

using namespace std;




int main()
{
     const size_t SCREEN_WIDTH = 80;
    size_t max_asterisk = SCREEN_WIDTH - 4;

    size_t number_count;
    cerr<<"Enter number count ";
    cin>>number_count;

    vector<double> numbers(number_count);


    cerr<<"Enter massive"<<endl;
    for(size_t i = 0;i < number_count; i++){
        cin>>numbers[i];
    }

    size_t bin_count;
    cerr<<"Enter bin count ";
    cin>>bin_count;

    vector<size_t> bins(bin_count, 0);

    //Ïîèñê max,min
    double min = numbers[0];
    double max = numbers[0];
    for (double x : numbers) {
            if (x < min) {
                min = x;
            }
            else if (x > max) {
                max = x;
            }
    }



    for (double x : numbers){
    size_t bin_index = (size_t)(x - min)* bin_count / (max- min);


    if (bin_index == bin_count){
        bin_index--;
    }

    bins[bin_index]++;
    }

    /*
    for(size_t b:bins)
    cout<<b;
    */
      double max_count = bins[0];

      for(size_t bin : bins){
         if (bin > max_count) {
                max_count = bin;
            }
         }

         if (max_count < 10) const int max_asterisk = SCREEN_WIDTH - 1 - 1;
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
/*
        size_t number;
        double sr;
        vector<size_t> massive(number);

        for(size_t x : massive){
            sr=sr+x;
        }

        sr = sr/number;
*/
    return 0;
}
