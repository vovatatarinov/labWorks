#include <iostream>

using namespace std;

int main() {
    cout << endl << "Вводите числа. Признак конца - \";\"." << endl;
    string num;
    double* res;
    bool first = true;
    int counter = 0;
    while(true) {
        cin >> num;
	if (num == ";")
		break;
	if (first) {
		res = (double*)malloc(sizeof(double));
		first = false;
	}
	else {
            res = (double)realloc(res, (counter + 1)*sizeof(double));
	}
        res[counter] = atof(str.c_str());
	++counter;
    }
    double med = 0;
    for (int i = 0; i < counter ; ++i)
	    med += res[i];
    med /= (counter + 1);
    cout << "\nСреднее значение: " << med << endl;
    for (int i = 0; i < counter; ++i) {

    }
}
