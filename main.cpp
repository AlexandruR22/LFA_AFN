#include <iostream>
#include <map>

using namespace std;

int main() {
    int i, nrStariFinale, nrMuchii, lunCuvant;
    char Stare, StareInceput;

    map<pair<char, char>, char> Automat;

    cout << "Introduceti numarul de legaturi: ";
    cin >> nrMuchii;

    char c1, c2, c3;
    cout << "Introduceti simbolul pentru fiecare stare si starea in care trece (Exemplu s a p): " << endl;
    for (i = 0; i < nrMuchii; i++) {
        cin >> c1 >> c2 >> c3;
        Automat[make_pair(c1, c2)] = c3;
    }

    cout << "Introduceti lungimea cuvantului: ";
    cin >> lunCuvant;

    char cuvant[lunCuvant];
    cout << "Introduceti cuvantul: ";
    cin >> cuvant;

    cout << "Introduceti starea de inceput: ";
    cin >> StareInceput;

    map<pair<char, char>, char>::iterator it = Automat.begin();

    Stare = StareInceput;

    for (i = 0; i < lunCuvant; i++) {
        it = Automat.find(make_pair(Stare, cuvant[i]));
        Stare = (*it).second;
        if (Stare == NULL) {
            cout << "Cuvantul nu apartine limbajului" << endl;
            return 0;
        }
    }

    cout << "Introduceti numarul starilor finale: ";
    cin >> nrStariFinale;

    char StariFinale[nrStariFinale];
    cout << "Introduceti starile finale: ";
    for (i = 0; i < nrStariFinale; i++)
        cin >> StariFinale[i];

    for (i = 0; i < nrStariFinale; i++)
        if (Stare == StariFinale[i]) {
            cout << "Cuvantul apartine limbajului" << endl;
            return 0;
        }

    cout << "Cuvantul nu apartine limbajului" << endl;

    return 0;

}