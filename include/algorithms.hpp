#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP

#include <stdexcept>
#include <vector>

void SelectionSort(std::vector<int>& vect) {
    int len = vect.size();

    for (int i = 0; i < len - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < len; j++) {
            if (vect.at(j) < vect.at(min_idx)) {
                min_idx = j;
            }
        }

        int temp = vect.at(i);
        vect.at(i) = vect.at(min_idx);
        vect.at(min_idx) = temp;
    }
}

void InsertionSort(std::vector<int>& vect) {
    int len = vect.size();

    for (int i = 0; i < len; i++) {
        int key = vect.at(i);
        int j = i - 1;

        while (j >= 0 && vect.at(j) > key) {
            vect.at(j + 1) = vect.at(j);
            j--;
        }
        vect.at(j + 1) = key;
    }
    /*  
    ALTERNATIVE VERSION WITH SWAPPING:

    int len = vect.size();

    for (int i = 0; i < len; i++) {
        int j = i;

        while (j > 0 && vect.at(j) < vect.at(j - 1)) {
            int temp = vect.at(j);
            vect.at(j) = vect.at(j - 1);
            vect.at(j - 1) = temp;
            j--;
        }
    }
    */  
}

void BubbleSort(std::vector<int>& vect) {

}

void QuickSort(std::vector<int>& vect) {

}

void MergeSort(std::vector<int>& vect) {
    
}

#endif