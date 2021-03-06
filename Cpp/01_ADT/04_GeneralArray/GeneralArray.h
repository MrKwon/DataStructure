#ifndef GENERALARRAY_H
#define GENERALARRAY_H
#include <iostream>

using namespace std;

const int defaultValue = 0;

class GeneralArray {
/*
    IndexSet에 있는 각 index의 값에 대하여 float 타입의 value가 존재하는
    <index, value>쌍의 집합. IndexSet는 일차원 또는 다차원의 유한 순서 집합이다.
    예를 들어
    일차원의 경우 {0, ..., n-1},
    이차원의 경우 { (0, 0), (0, 1), (0, 2), (1, 0), (1, 1), (1, 1), ... (2, 2) } 가 된다.
*/

private:
    int j;
    float initValue = defaultValue;

    // for inner operatrion
    float **arr;

public:
    GeneralArray(int, float);

    float Retrieve(int, int);
    void Store(int, int, float);
    
    int getMemberj();
    float getMemberInitValue();

friend ostream& operator << (ostream&, GeneralArray&);
};

GeneralArray::GeneralArray(int _j, float _initValue)
{
    j = _j;
    initValue = _initValue;
/**
 * 이 생성자는 j차원 실수 배열을 생성한다.
 * k번째 인덱스의 범위는 list의 k번째 원소로 정해진다.
 * 인덱스 집합의 인덱스 i에 대해 <i, initValue>를 배열에 삽입한다.
 */

    float **arr = new float *[j];
    for (int i = 0; i < j; ++i) {
        arr[i] = new float [j];
    }

    for (int h = 0; h < j; h++)
        for (int i = 0; i < j; i++){
            arr[h][i] = initValue;
        }
    
    for (int h = 0; h < j; h++)
        for (int i = 0; i < j; i++){
            printf("%d", arr[h][i]);
        }
}

// 2차원 배열이므로 index는 i, j
float GeneralArray::Retrieve(int i, int j) {
    // i가 배열의 index 집합에 있으면 배열에서 i와 쌍이 되는 float를 반환하고,
    // 그렇지 않으면 예외를 발생시킨다.
    try {
        return arr[i][j];
    } catch (int errorCode) {
        printf( "index [%d, %d] is not available", i, j);
    }
}

void GeneralArray::Store(int i, int j, float x) {
    // i가 배열의 index 집합에 있으면 배열에서 i와 쌍이 되는 값을 x로 대체하고
    // 그렇지 않으면 예외를 발생시킨다.
    float tmpx = x;
    try {
        arr[i][j] = tmpx;
    } catch (int errorCode) {
        printf( "index [%d, %d] is not available", i, j);
    }
}

int GeneralArray::getMemberj() {
    return j;
}

float GeneralArray::getMemberInitValue() {
    return initValue;
}

ostream& operator << (ostream& os, GeneralArray& genArr) {
    os << "This is your General Array" << endl;

    printf("j = %f, initValue = %f", genArr.arr[1][1], genArr.arr[1][1]);

    for (int h = 0; h < genArr.j; h++) {
        for (int i = 0; i < genArr.j; i++) {
            // 맨 윗줄 print
            if (h == 0 && i == 0) 
                os << "┌ " << genArr.arr[h][i] << " ";
            else if (h == 0 && i != 0) 
                os << genArr.arr[h][i] << " ";
            else if (h == 0 && i == genArr.j - 1) 
                os << genArr.arr[h][i] << " ┐" << endl;

            // 중간줄 print
            else if(h != 0 && i == 0)
                os << "│ " << genArr.arr[h][i] << " ";
            else if(h != 0 && i != 0)
                os << genArr.arr[h][i] << " ";
            else if(h != 0 && i == genArr.j - 1)
                os << genArr.arr[h][i] << " │" << endl;

            // 마지막 줄 print
            else if(h == genArr.j - 1 && i == 0)
                os << "└ " << genArr.arr[h][i] << " ";
            else if(h == genArr.j - 1 && i != 0)
                os << genArr.arr[h][i] << " ";
            else if(h == genArr.j - 1 && i == genArr.j - 1)
                os << genArr.arr[h][i] << " ┘" << endl;
        }
    }
}

#endif
