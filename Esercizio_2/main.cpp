#include<iostream>
#include<iomanip>
#include<vector>
#include<chrono>
#include"SortingAlgorithm.hpp"
#include<algorithm>
using namespace std;
using namespace SortLibrary;
using namespace std::chrono;



// Prendo tempi di BubbleSort

double BubbleDuration(vector<double>& v){

    //duration<double, nano> t_endB;
    steady_clock::time_point t_beginB = std::chrono::steady_clock::now();
    BubbleSort(v);
    steady_clock::time_point t_endB = std::chrono::steady_clock::now();

    double bubbleDuration = duration_cast<nanoseconds>(t_endB-t_beginB).count();
    return bubbleDuration;

}


// Prendo tempi di MergeSort

double MergeDuration(vector<double>& v,
                     const unsigned int& sx,
                     const unsigned int& dx){

   steady_clock::time_point t_beginM = std::chrono::steady_clock::now();
    MergeSort(v, sx, dx);
   steady_clock::time_point t_endM = std::chrono::steady_clock::now();

    double MergeDuration = duration_cast<nanoseconds>(t_endM-t_beginM).count();
    return MergeDuration;

}



// genero i vettori con funzione rand
vector<double> generate_vectors1(unsigned int size){
    srand(size);
    vector<double> v(size);
    for (unsigned int i = 0; i < size ; ++i){
        v[i] = rand()%1000;
    }
    return v;
}


// genero vettori con funzione generate
vector<double> generate_vectors2(unsigned int size){
    vector<double> v(size);
    int decrement = size*20;
    generate(v.begin(), v.end(), [&decrement] () {decrement-= 20; return decrement;});
    return v;
}

double mediaDuration(vector<double> &v){
    double sum = 0;
    for(double duration : v){
        sum+= duration;
    }
     double media = sum/ v.size();
    return media;
}


int main(int argc, char *argv[])
{
    vector<double> durationBubble(3);
    vector<double> durationMerge(3);
    double durationB;
    double durationM;
    //duration<double,nano> durationM;


    // Faccio 3 prove con vettori di piccole dimensioni
    for(unsigned int i = 1; i<4; ++i ){
        unsigned int size = atoi(argv[i]);
        vector<double> v = generate_vectors1(size);
        vector<double> v_bubble = v;
        vector<double> v_merge = v;

        // prendo tempo BubbleSort
        durationB =  BubbleDuration(v_bubble);
        durationBubble[i-1]= durationB;

        //Prendo tempo MergeSort
        durationM = MergeDuration(v_merge, 0, size-1);
        durationMerge[i-1]=durationM;


        cout<< "per lunghezza "<< size << "  tempo Merge="<< durationM<< "   tempo Bubble="<< durationB<< endl;


    }
    double media_bubble = mediaDuration(durationBubble);
    double media_merge = mediaDuration(durationMerge);

    cout<< "Media tempo per vettori di dimensioni piccole: "<< endl;
    cout<<"media BubbleSort =" << media_bubble<< endl;
    cout<<"media MergeSort=" << media_merge<< endl;


        vector<double> durationBubble2(3);
        vector<double> durationMerge2(3);
        double durationB2;
        double durationM2;

        //Faccio 3 prove con vettori di dimensioni maggiori
        for(unsigned int j = 4; j<7; ++j ){
            unsigned int size2 = atoi(argv[j]);
            vector<double> v2 = generate_vectors2(size2);
            vector<double> v2_bubble = v2;
            vector<double> v2_merge = v2;

            // prendo tempo BubbleSort
            durationB2 =  BubbleDuration(v2_bubble);
            durationBubble2[j-4]= durationB2;



            //Prendo tempo MergeSort
            durationM2 = MergeDuration(v2_merge, 0, size2-1);
            durationMerge2[j-4]=durationM2;


            cout<< "per lunghezza "<< size2 << "  tempo Merge="<< durationM2 << "   tempo Bubble="<< durationB2 << endl;


    }
        double media_bubble2 = mediaDuration(durationBubble2);
        double media_merge2 = mediaDuration(durationMerge2);

        cout<< "Media tempo per vettori di dimensioni maggiori: "<< endl;
        cout<<"media BubbleSort =" << media_bubble2<< endl;
        cout<<"media MergeSort=" << media_merge2<< endl;

    return 0;
}

