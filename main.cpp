#include <iostream>
#include<fstream>
#include<string>
#include<vector>
#include <ctime>
#include <Windows.h>
#include<algorithm>
#include<cmath>
#pragma warning(disable : 4996)

using namespace std;

struct Objects {
    string name;
    float coordinate_x;
    float coordinate_y;
    string type;
    double time;
};

ifstream file;
string file_path;

vector<Objects> v;
Objects form_object;
string obj_str;
float obj_float;
double obj_double;

string user_action;

bool compLength(Objects a, Objects b) {
    return sqrt(pow(a.coordinate_x, 2) + pow(a.coordinate_y, 2)) < sqrt(pow(b.coordinate_x, 2) + pow(b.coordinate_y, 2));
}
bool compName(Objects a, Objects b) {
    return (a.name < b.name&& int(a.name[0]) >= -64 && int(a.name[0]) <= -33 && int(b.name[0]) >= -64 && int(b.name[0]) <= -33);
}
bool compTime(Objects a, Objects b) {
    return a.time > b.time;
}
bool compType(Objects a, Objects b) {
    return a.type < b.type;
}

void outputLength() {
    int i = 0;
    cout << "До 100 ед:\n";
    for (i; i < v.size(); i++) {
        if (sqrt(pow(v[i].coordinate_x, 2) + pow(v[i].coordinate_y, 2)) <= 100) {
            cout << "   " << v[i].name << " " << v[i].coordinate_x << " " << v[i].coordinate_y << " " << v[i].type << " ";
            printf("%f", v[i].time);
            cout << "\n";
        }
        else {
            cout << "\n";
            break;
        }
    }
    if (i == v.size()) return;
    cout << "До 1000 ед:\n";
    for (i; i < v.size(); i++) {
        if (sqrt(pow(v[i].coordinate_x, 2) + pow(v[i].coordinate_y, 2)) <= 1000) {
            cout << "   " << v[i].name << " " << v[i].coordinate_x << " " << v[i].coordinate_y << " " << v[i].type << " ";
            printf("%f", v[i].time);
            cout << "\n";
        }
        else {
            cout << "\n";
            break;
        }
    }
    if (i == v.size()) return;
    cout << "До 10000 ед:\n";
    for (i; i < v.size(); i++) {
        if (sqrt(pow(v[i].coordinate_x, 2) + pow(v[i].coordinate_y, 2)) <= 10000) {
            cout << "   " << v[i].name << " " << v[i].coordinate_x << " " << v[i].coordinate_y << " " << v[i].type << " ";
            printf("%f", v[i].time);
            cout << "\n";
        }
        else {
            cout << "\n";
            break;
        }
    }
    if (i == v.size()) return;
    cout << "Слишком далеко:\n";
    for (i; i < v.size(); i++) {
        cout << "   " << v[i].name << " " << v[i].coordinate_x << " " << v[i].coordinate_y << " " << v[i].type << " ";
        printf("%f", v[i].time);
        cout << "\n";
    }
    cout << "\n";
}

void outputName() {
    int i = 0;
    bool others = 0;
    int current_char = int(v[i].name[0]);
    if (int(v[i].name[0]) >= -64 && int(v[i].name[0]) <= -33) {
        cout << "'" << v[i].name[0] << "'\n";
    }
    for (i; i < v.size(); i++) {
        if ((int(v[i].name[0]) == current_char)||others==1) {
            cout << "   " << v[i].name << " " << v[i].coordinate_x << " " << v[i].coordinate_y << " " << v[i].type << " ";
            printf("%f", v[i].time);
            cout << "\n";
        }
        else if (int(v[i].name[0]) >= -64 && int(v[i].name[0]) <= -33) {
            current_char = int(v[i].name[0]);
            cout << "'" << v[i].name[0] << "'\n";
            cout << "   " << v[i].name << " " << v[i].coordinate_x << " " << v[i].coordinate_y << " " << v[i].type << " ";
            printf("%f", v[i].time);
            cout << "\n";
        }
        else {
            cout << "'#'\n";
            cout << "   " << v[i].name << " " << v[i].coordinate_x << " " << v[i].coordinate_y << " " << v[i].type << " ";
            printf("%f", v[i].time);
            cout << "\n";
            others = 1;
        }
    }
    cout << "\n";
    //-64  -33
}

void outputTime() {
    int i = 0;
    SetConsoleCP(866);
    time_t current_unix = time(nullptr);
    if (current_unix - v[i].time <= 3600) {
        cout << "Сегодня:\n";
        for (i; i < v.size(); i++) {
            if (current_unix - v[i].time <= 3600) {
                cout << "   " << v[i].name << " " << v[i].coordinate_x << " " << v[i].coordinate_y << " " << v[i].type << " ";
                printf("%f", v[i].time);
                cout << "\n";
            }
            else break;
        }
    }
    if (current_unix - v[i].time <= 86400) {
        cout << "Вчера:\n";
        for (i; i < v.size(); i++) {
            if (current_unix - v[i].time <= 86400) {
                cout << "   " << v[i].name << " " << v[i].coordinate_x << " " << v[i].coordinate_y << " " << v[i].type << " ";
                printf("%f", v[i].time);
                cout << "\n";
            }
            else break;
        }
    }
    if (current_unix - v[i].time <= 604800) {
        cout << "На неделе:\n";
        for (i; i < v.size(); i++) {
            if (current_unix - v[i].time <= 604800) {
                cout << "   " << v[i].name << " " << v[i].coordinate_x << " " << v[i].coordinate_y << " " << v[i].type << " ";
                printf("%f", v[i].time);
                cout << "\n";
            }
            else break;
        }
    }
    if (current_unix - v[i].time <= 2629743) {
        cout << "В этом месяце:\n";
        for (i; i < v.size(); i++) {
            if (current_unix - v[i].time <= 2629743) {
                cout << "   " << v[i].name << " " << v[i].coordinate_x << " " << v[i].coordinate_y << " " << v[i].type << " ";
                printf("%f", v[i].time);
                cout << "\n";
            }
            else break;
        }
    }
    if (current_unix - v[i].time <= 31556926) {
        cout << "В этом году:\n";
        for (i; i < v.size(); i++) {
            if (current_unix - v[i].time <= 31556926) {
                cout << "   " << v[i].name << " " << v[i].coordinate_x << " " << v[i].coordinate_y << " " << v[i].type << " ";
                printf("%f", v[i].time);
                cout << "\n";
            }
            else break;
        }
    }
    if (i < v.size()) {
        cout << "Прочее:\n";
        for (i; i < v.size(); i++) {
                cout << "   " << v[i].name << " " << v[i].coordinate_x << " " << v[i].coordinate_y << " " << v[i].type << " ";
                printf("%f", v[i].time);
                cout << "\n";
        }
    }
    cout << "\n";
}

void outputType() {
    int i = 0;
    int n;
    cout << "Введите кол-во элементов для создания группы: ";
    cin >> n;
    vector<Objects>other;
    vector<Objects>prepare_groupe;
    for (int i = 0; i < v.size(); i++) {
        if (prepare_groupe.size() == 0)prepare_groupe.push_back(v[i]);
        else if (v[i].type == prepare_groupe[0].type) {
            prepare_groupe.push_back(v[i]);
        }
        else if (prepare_groupe.size() >= n) {
            cout << prepare_groupe[0].type << ":\n";
            for (int j = 0; j < prepare_groupe.size(); j++) {
                cout << "   " << prepare_groupe[j].name << " " << prepare_groupe[j].coordinate_x << " " << prepare_groupe[j].coordinate_y << " " << prepare_groupe[j].type << " ";
                printf("%f", prepare_groupe[j].time);
                cout << "\n";
            }
            prepare_groupe.clear();
        }
        else {
            other.insert(other.begin(), prepare_groupe.begin(), prepare_groupe.end());
            prepare_groupe.clear();
        }
    }
    if (prepare_groupe.size() >= n) {
        cout << prepare_groupe[0].type << ":\n";
        for (int j = 0; j < prepare_groupe.size(); j++) {
            cout << "   " << prepare_groupe[j].name << " " << prepare_groupe[j].coordinate_x << " " << prepare_groupe[j].coordinate_y << " " << prepare_groupe[j].type << " ";
            printf("%f", prepare_groupe[j].time);
            cout << "\n";
        }
        prepare_groupe.clear();
    }
    if (other.size() != 0) {
        cout << "Разное:\n";
        for (int i = 0; i < other.size();i++) {
            cout << "   " << other[i].name << " " << other[i].coordinate_x << " " << other[i].coordinate_y << " " << other[i].type << " ";
            printf("%f", other[i].time);
            cout << "\n";
        }
    }
    cout << "\n";
}

bool sortComplete(bool again) {
    if(again==0)cout << "Объекты отсортированы!\nВывести в группах?\n 1. Да\n 2. Нет\n\n";
    cin >> user_action;
    cout << "\n";
    if (user_action == "1") return true;
    if (user_action == "2") return false;
    else {
        cout << "Введите число от 1 до 2\n\n";
        sortComplete(1);
    }
}

void sortLength() {
    sort(v.begin(), v.end(), compLength);
    if(sortComplete(0) == true)outputLength();
}

void sortName() {
    sort(v.begin(), v.end(), compName);
    if (sortComplete(0) == true)outputName;
}

void sortTime() {
    sort(v.begin(), v.end(), compTime);
    if (sortComplete(0) == true)outputTime();
}

void sortType() {
    sort(v.begin(), v.end(), compType);
    if (sortComplete(0) == true)outputType();
}

void readList() {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i].name << " " << v[i].coordinate_x << " " << v[i].coordinate_y << " " << v[i].type << " ";
        printf("%f", v[i].time);
        cout << "\n";
    }
    cout << "\n";
}

void addObject() {
    cout << "Введите объект (Имя, Координата X, Координата Y, Тип Объекта): ";
    SetConsoleCP(1251);
    cin >> obj_str >> obj_float;
    form_object.name = obj_str;
    form_object.coordinate_x = obj_float;
    cin >> obj_float >> obj_str;
    form_object.coordinate_y = obj_float;
    form_object.type = obj_str;
    SetConsoleCP(866);
    time_t current_unix = time(nullptr);
    form_object.time = current_unix;
    v.push_back(form_object);
    cout << "\n\n";
    
}

void sortList() {
    cout << "Выберите тип сортировки:\n  1. По расстоянию\n  2. По имени\n  3. По времени создания\n  4. По типу\n\n";
    cin >> user_action;
    cout << "\n";
    if (user_action == "1") {
        sortLength();
    }
    else if (user_action == "2") {
        sortName();
    }
    else if (user_action == "3") {
        sortTime();
    }
    else if (user_action == "4") {
        sortType();
    }
    else {
        cout << "Введите число от 1 до 4" << "\n";
        sortList();
    }
}

void saveChanges() {
    file.clear();
    ofstream file_change;
    file_change.open(file_path);
    for (int i = 0; i < v.size(); i++) {
        file_change << v[i].name << " " << v[i].coordinate_x << " " << v[i].coordinate_y << " " << v[i].type << " "<< v[i].time<<"\n";
    }
    cout << "\nГотово!\n";
    file_change.close();
}

void chooseAction() {
    cout << "Выберте действей:\n1. Прочтитать список\n2. Добавить объект\n3. Группировать объекты с сортировкой внутри групп\n4. Сохранить результаты в файл\n5. Окончить ссесию\n\n";
    cin >> user_action;
    cout << "\n";
    if (user_action == "1") {
        readList();
    }
    else if (user_action == "2") {
        addObject();
    }
    else if (user_action == "3") {
        sortList();
    }
    else if (user_action == "4") {
        saveChanges();
    }
    else if (user_action == "5") {
        exit(0);
    }
    else {
        cout << "Введите число от 1 до 5" << "\n";
    }
    chooseAction();
}

int main() {
    setlocale(LC_ALL, "Russian");

    cout << "Введите путь к файлу: ";
    SetConsoleCP(1251);
    cin >> file_path;
    SetConsoleCP(866);
    file.open(file_path);

    int count = 0;
    
    while (!file.eof()) {
        switch (count) {
        case 0:
            file >> obj_str;
            form_object.name = obj_str;
            count++;
            break;
        case 1:
            file >> obj_float;
            form_object.coordinate_x = obj_float;
            count++;
            break;
        case 2:
            file >> obj_float;
            form_object.coordinate_y = obj_float;
            count++;
            break;
        case 3:
            file >> obj_str;
            form_object.type = obj_str;
            count++;
            break;
        case 4:

        default:
            file >> obj_double;
            form_object.time = obj_double;
            v.push_back(form_object);
            count = 0;
            break;
        }
    }
    file.close();
    chooseAction();
}


//printf("%f", obj_double); из 1e20 в 10000000000.000000