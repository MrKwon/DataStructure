#include <iostream>
#include "Polynomial.h"
#include <math.h>
#define ABS(a) ((a)<0 ? -(a):(a))

using namespace std;

// Term *termArray; // 0�� �ƴ� ���� �迭
// int capacity; // termArray�� ũ��
// int terms; // 0�� �ƴ� ���� ��

Polynomial::Polynomial() : capacity(4), terms(0)
{
    termArray = new Term[capacity];
}

Polynomial Polynomial::Add(Polynomial b) {
// *this �� b�� ���� ����� ��ȯ
    Polynomial c;
    int aPos = 0, bPos = 0;
    while ((aPos < terms) && (bPos < b.terms)) {
        if (termArray[aPos].exp == b.termArray[bPos].exp) {
            float tmpCoef = termArray[aPos].coef + termArray[bPos].coef;
            if (tmpCoef) {
                c.NewTerm(tmpCoef, termArray[aPos].exp);
            }
            aPos++;
            bPos++;
        }
        else if(termArray[aPos].exp > b.termArray[bPos].exp) {
            c.NewTerm(termArray[aPos].coef, termArray[aPos].exp);
            aPos++;
        }
        else {
            c.NewTerm(termArray[bPos].coef, termArray[bPos].exp);
            bPos++;
        }
    }

    for( ; aPos < terms; aPos++ ) {
        c.NewTerm(termArray[aPos].coef, termArray[aPos].exp);
    }

    for( ; bPos < b.terms; bPos++ ) {
        c.NewTerm(termArray[bPos].coef, termArray[bPos].exp);
    }

    return c;
}

Polynomial Polynomial::Mult(Polynomial b) {
// *this �� b�� ���� ����� ��ȯ
    Polynomial c;
    int aPos = 0, bPos = 0;
    
    while (bPos < b.terms) {
        while (aPos < terms) {
            Polynomial tmp;
            float tmpCoef = termArray[aPos].coef * b.termArray[bPos].coef;
            int tepExp = termArray[aPos].exp + b.termArray[bPos].exp;
            tmp.NewTerm(tmpCoef, tmpExp);
            c.Add(tmp);
            aPos++;
        }
        bPos++;
    }

    return c;
}

void Polynomial::NewTerm(const float addCoef, const int addExp) {
// ���ο� ���� termArray ���� ÷��
    if (terms == capacity) {
        capacity *= 2;
        Term *temp = new Term[capacity];
        copy(termArray, termArray + terms, temp);
        delete [] termArray;
        termArray = temp;
    }

    termArray[terms].coef = addCoef;
    termArray[terms].exp = addExp;
}

float Polynomial::Eval(float x){
    float result;

    for(int pos = 0; pos < terms; pos++) {
        float tmp = termArray[pos].coef * pow(x, termArray[pos].exp);
        result += tmp;
    }

    return result;
}

ostream& operator<<(ostream& os, Polynomial& p) {
    for (int i = 0; i < p.terms; i++)
	{
		if ((i != 0) && (p.termArray[i].coef > 0))
			os << "+";
		else if ((i != 0)&&(p.termArray[i].coef < 0))
			os << "-";
		else
			os;
		
		if ((p.termArray[i].coef == 1) || (p.termArray[i].coef == -1))
			os << "x^" << p.termArray[i].exp << ' ';
		else if (p.termArray[i].exp == 0)
			os << ABS(p.termArray[i].coef);
		else
			os << ABS(p.termArray[i].coef) << "x^" << p.termArray[i].exp << ' ';
	}
	return os;
}

istream& operator>>(istream& is, Polynomial& p) {
    int noofterms; float coef; int exp;
	is >> noofterms;
	for (int i = 0; i < noofterms; i++) {
		is >> coef >> exp;
		p.NewTerm(coef, exp);
	}
	return is;
}

using namespace std;

int main(void) {
    Polynomial p1, p2, p3;

	printf("p1 �Է� : "); 
	cin >> p1;
	cout << endl;
	
	printf("p2 �Է� : "); 
	cin >> p2;
	cout << endl;
	
	p3 = p1.Add(p2);
	cout << p1 << p2 << p3;
	
	return 0;
}
