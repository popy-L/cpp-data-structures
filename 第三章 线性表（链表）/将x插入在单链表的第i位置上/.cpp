#include <iostream>
using namespace std;

template<typename T>
class SeqList {
public:
    SeqList() {
        length = 0;
        data = new T[1000];
    };

    ~SeqList() {
        delete[] data;
    }

    void CreateList(T a[], int n) {
        int i;
        for (i = 0; i < n; i++) {
            data[i] = a[i];
        }
        length = n;
    }

    bool ListInsert(int i, T e) {
        if (i < 1 || i > length + 1) {
            return false;
        }

        for (int j = length; j >= i; j--) {
            data[j] = data[j - 1];
        }

        data[i - 1] = e;
        length++;
        return true;
    }

    int GetLength() {
        return length;
    }

    T GetElem(int idx) {
        return data[idx];
    }

private:
    T* data;
    int length;
};

int main() {
    SeqList<int> list;
    int arr[1000];
    int n = 0;

    while (cin.peek() != '\n' && cin >> arr[n]) {
        n++;
    }
    cin.ignore();

    int i, x;
    cin >> i >> x;

    list.CreateList(arr, n);

    bool success = list.ListInsert(i, x);
    if (!success) {
        cout << "error" << endl;
        return 0;
    }

    for (int j = 0; j < list.GetLength(); j++) {
        if (j != 0) {
            cout << " ";
        }
        cout << list.GetElem(j);
    }
    cout << endl;

    return 0;
}