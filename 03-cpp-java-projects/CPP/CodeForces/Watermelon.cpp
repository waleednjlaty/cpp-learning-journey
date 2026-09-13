#include <iostream>
using namespace std;

int main()
{
    // تحسين سرعة الإدخال والإخراج للمسابقة
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N = 0;
    cin >> N;
    char m = '0';
    while (N)
    {
        int byn = 0;
        byn = N % 2;
        N /= 2;
        m = (char)byn;
        cout
            << byn;
    }
    cout << endl;
    cout << (char)m;
    return 0;
}