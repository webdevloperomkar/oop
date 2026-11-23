#include <iostream>
#include <cstdlib>
using namespace std;

// Function template for sorting
template <typename T>
void sortArray(T a[], int n) {
    int pos;
    T temp;

    // Selection sort
    for (int i = 0; i < n - 1; i++) {
        pos = i;

        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[pos])
                pos = j;
        }

        if (pos != i) {
            temp = a[i];
            a[i] = a[pos];
            a[pos] = temp;
        }
    }

    cout << "Sorted elements are ";

    for (int k = 0; k < n; k++) {
        cout << "\n" << a[k];
    }
}

int main() {
    int ch, no, ele, fno;

    while (1) {
        cout << "\nMenu";
        cout << "\n1. Integer sorting";
        cout << "\n2. Character sorting";
        cout << "\n3. Float sorting";
        cout << "\n4. Exit";
        cout << "\nEnter choice: ";
        cin >> ch;

        switch (ch) {
            case 1: {
                cout << "\nInteger sorting\n";
                cout << "\nEnter number of elements: ";
                cin >> no;

                if (no <= 0 || no > 100) {
                    cout << "Invalid number of elements.";
                    break;
                }

                int sor1[100];

                cout << "\nEnter elements:\n";

                for (int i = 0; i < no; i++)
                    cin >> sor1[i];

                sortArray<int>(sor1, no);
                break;
            }

            case 2: {
                cout << "\nCharacter sorting\n";
                cout << "\nEnter number of elements: ";
                cin >> ele;

                if (ele <= 0 || ele > 100) {
                    cout << "Invalid number of elements.";
                    break;
                }

                char sor2[100];

                cout << "\nEnter elements:\n";

                for (int i = 0; i < ele; i++)
                    cin >> sor2[i];

                sortArray<char>(sor2, ele);
                break;
            }

            case 3: {
                cout << "\nFloating type sorting\n";
                cout << "\nEnter number of elements: ";
                cin >> fno;

                if (fno <= 0 || fno > 100) {
                    cout << "Invalid number of elements.";
                    break;
                }

                float sor3[100];

                cout << "\nEnter elements:\n";

                for (int i = 0; i < fno; i++)
                    cin >> sor3[i];

                sortArray<float>(sor3, fno);
                break;
            }

            case 4:
                exit(0);

            default:
                cout << "\nInvalid choice!";
        }
    }

    return 0;
}