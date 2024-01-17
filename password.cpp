#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

void printTitle() {
cout << R"(
ooooooooo.                                                                         .o8
`888   `Y88.                                                                      "888
 888   .d88'  .oooo.    .oooo.o  .oooo.o oooo oooo    ooo  .ooooo.  oooo d8b  .oooo888
 888ooo88P'  `P  )88b  d88(  "8 d88(  "8  `88. `88.  .8'  d88' `88b `888""8P d88' `888
 888          .oP"888  `"Y88b.  `"Y88b.    `88..]88..8'   888   888  888     888   888
 888         d8(  888  o.  )88b o.  )88b    `888'`888'    888   888  888     888   888
o888o        `Y888""8o 8""888P' 8""888P'     `8'  `8'     `Y8bod8P' d888b    `Y8bod88P"
---------------------------------------------------------------------------------------
@altwolff
)";
}

string passwordCharacters() {
    return "abcdefghijklmnopqrstuvwxyz!@#$%&*?ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
}

int passwordLength() {
    int n = 0;
    do {
        cout << "\nEnter desired password length: ";
        cin >> n;
        if (n <= 0)
            cout << "Invalid input. Please enter a natural number.";
    }
    while (n <= 0);
        return n;
}

string passwordCreation(const string& pool, int n) {
    srand(time(0));
    string newPassword;
    for (int i = 0; i < n; i++) {
        int position = rand() % pool.length();
        newPassword += pool[position];
    }
    return newPassword;
}

int main() {
    printTitle();
    string pool = passwordCharacters();
    int n = passwordLength();
    string password = passwordCreation(pool, n);
    cout << "Generated password: " << password << endl;
    system("pause");
}
