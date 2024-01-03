#include <iostream>
#include <ctype.h>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <cstdlib>
#include <sstream>

using namespace std;
int id = 1;

struct Creature{
    int id;
    string namecomm;
    string namelat;
    string genus;
    string familia;
    string ordo;
    string status;
    string date;
    string place;
    string comment;
    Creature* next;
    Creature* prev;

};

Creature* head = NULL;
Creature* tail = NULL;

void menu();
void add();
void delete_record();
void display(int);
void search();
void data_entry(int);
void save_records();
void load_records();
void disp(Creature*);
void modify_record();
int get_number(string);

int main()
{
    while(1)
    menu();
    return 0;
}

void menu(){

    cout<<"1. Add record"<<endl;
    cout<<"2. Delete record"<<endl;
    cout<<"3. Modify record"<<endl;
    cout<<"4. Display all records"<<endl;
    cout<<"5. Search"<<endl;
    cout<<"6. Save"<<endl;
    cout<<"7. Load"<<endl;
    cout<<"8. Exit"<<endl;
    cout<<"Choice: "<<endl;


    string choice;
    cin >> choice;
    int x = get_number(choice);

    switch(x){

    case 1:
        add();
        break;
    case 2:
        delete_record();
        break;
    case 3:
        modify_record();
        break;
    case 4:
        display(1);//"1" in the brackets is for the switch case in display func.
        break;
    case 5:
        search();
        break;
    case 6:
        save_records();
        cout<<"Saved."<<endl;
        break;
    case 7:
        load_records();
        break;
    case 8:
        exit(0);
        break;
    default:
        cout<<"Enter a value between 1 and 8."<<endl;
    }
}

void add(){

    if(head == NULL){
        Creature *temp = new Creature;
        temp -> prev = NULL;
        temp -> next = NULL;
        head = temp;
        tail = temp;

        temp -> id = id;
        data_entry(id);
        id++;
    }
    else{
        Creature *temp = new Creature;
        tail -> next = temp;
        temp -> prev = tail;
        tail = temp;
        temp -> next = NULL;

        temp->id = id;
        data_entry(id);
        id++;
    }
}


void delete_record(){

    int idd;
    string checker;
    cout<<"Input an ID of the record to be deleted: "<<endl;
    cin>>checker;
    idd = get_number(checker);

    if(idd){ // If id was correct
        Creature *temp = head;
        while (idd != temp->id){
            temp = temp -> next;
        }
        string checker2;
        int choice;
        cout<<"Are you sure you want to delete this record? This operation cannot be undone."<<endl;
        cout<<"1. Yes 2. No";
        cin>>checker2;
        choice = get_number(checker2);

        switch(choice){
            case 1:

            if (temp->prev != NULL && temp -> next != NULL){ // in the middle
            (temp->prev)-> next = temp -> next;
            (temp->next)-> prev = temp -> prev;
            }
            else if(temp->prev == NULL && temp -> next != NULL){ // at the beggining, more than 1 element
                    (temp -> next) -> prev = NULL;
                    head = temp -> next;
            }
            else if(temp-> prev != NULL && temp -> next == NULL){ // trailing
                (temp -> prev) -> next = NULL;
                tail = temp -> prev;
            }
            else if(temp->prev == NULL && temp -> next == NULL){ // only element
                head = NULL;
                tail = NULL;
            }

            break;

            case 2:

                cout<<"Record not deleted";
                menu();
                break;

            default:

                cout<<"Enter 1 or 2"<<endl;
                break;
        }
    }

}

void display(int kejs){
    Creature *temp = head;
    int idd;
    string name;
    string genus;
    string familia;
    string order;
    string conservation;
    string data;
    string miejsce;

    int counter = 0;

    switch(kejs){

    case 1:

        while (temp != NULL){
            disp(temp);
            temp = temp -> next;

        }
        break;

    case 2:

        cout<<"Enter id: ";
        cin>>idd;
        while (temp != NULL){

            if(idd == temp -> id){
            ++counter;
            disp(temp);}
            temp = temp -> next;}

        if (counter == 0)
        cout<<"No object(s) of given id!"<<endl;

        else cout<<"Found " << counter << " obiektow"<<endl;
        counter = 0;
        break;

    case 3:

        cout<<"Enter common/latin name: "<<endl;
        cin>> name;
        while (temp != NULL){
            if(name == temp -> namecomm || name == temp -> namelat){
                ++counter;
                disp(temp);
            }
            temp = temp -> next;
                }
        if(counter == 0)
        cout<<"No object(s) of given name found!"<<endl;

        else cout<<"Found " << counter << " object(s)"<<endl;
        counter = 0;
        break;

    case 4:

        cout<<"Enter family: "<<endl;
        cin>>familia;
        while (temp != NULL){
            if(familia == temp -> familia){
                disp(temp);
                ++counter;}
            temp = temp -> next;}
        if(counter == 0)
        cout<<"No object(s) of given family found!"<<endl;

        else cout<<"Found " << counter << " object(s)"<<endl;
        counter = 0;
        break;


    case 5:

        cout<<"Enter genus: "<<endl;
        cin>>genus;
        while (temp != NULL){
            if(genus == temp -> genus){
                ++counter;
                disp(temp);}
            temp = temp -> next;}

        if(counter == 0)
        cout<<"No object(s) of given genus found!"<<endl;

        else cout<<"Found " << counter << " object(s)"<<endl;
        counter = 0;
        break;

    case 6:

        cout<<"Enter order: "<<endl;
        cin>> order;
        while (temp != NULL){
            if(order == temp -> ordo){
            ++counter;
            disp(temp);}
            temp = temp -> next;}

        if (counter == 0)
        cout<<"No object(s) of given order found!"<<endl;

        else cout<<"Found " << counter << " object(s)"<<endl;
        counter = 0;
        break;

    case 7:

        cout<<"Enter conservation status: "<<endl;
        cin>>conservation;
        while (temp != NULL){
            if(conservation == temp -> status)
                disp(temp);
            temp = temp -> next;
        }
        if (counter == 0)
        cout<<"No object(s) of given conservation status found!"<<endl;

        else cout<<"Found " << counter << " object(s)"<<endl;
        counter = 0;
        break;

    case 8:

        cout<<"Enter observation date: "<<endl;
        cin>>data;
        while (temp != NULL){
            if(data == temp -> status)
                disp(temp);
            temp = temp -> next;}
        if (counter == 0)
        cout<<"No object(s) of given observation date found!"<<endl;

        else cout<<"Found " << counter << " object(s)"<<endl;
        counter = 0;
        break;

    case 9:

        cout<<"Enter observation place: "<<endl;
        cin>>miejsce;
        while (temp != NULL){
            if(miejsce == temp -> status)
                disp(temp);
            temp = temp -> next;

    }
        if (counter == 0)
        cout<<"No object(s) of given observation place!"<<endl;

        else cout<<"Found " << counter << " object(s)"<<endl;
        counter = 0;
        break;
    }
}

void search(){

    cout<<"Search records"<<endl;
    cout<<"1. By id"<<endl;
    cout<<"2. By common/latin name"<<endl;
    cout<<"3. By familiy"<<endl;
    cout<<"4. By genus"<<endl;
    cout<<"5. By order"<<endl;
    cout<<"6. By conservation status"<<endl;
    cout<<"7. By observation date"<<endl;
    cout<<"8. By observation place"<<endl;
    cout<<"Choice: ";
    int choice;
    string checker;
    cin>> checker;
    choice = get_number(checker);

    switch(choice){

        case 1:
            display(2);
            break;
        case 2:
            display(3);
            break;
        case 3:
            display(4);
            break;
        case 4:
            display(5);
            break;
        case 5:
            display(6);
            break;
        case 6:
            display(7);
            break;
        case 7:
            display(8);
            break;
        case 8:
            display(9);
            break;
        }
}

void modify_record(){

    int idd;
    string checker;
    cout<<"Enter ID: ";
    cin>>checker;
    idd = get_number(checker);
    data_entry(idd);
}


void disp(Creature* temp){

    cout<< "ID: "<<temp->id <<endl;
    cout<< "Common name: "<<temp->namecomm <<endl;
    cout<< "Latin name: "<<temp->namelat <<endl;
    cout<< "Genus: "<<temp->genus <<endl;
    cout<< "Family: "<<temp->familia <<endl;
    cout<< "Order: "<<temp->ordo <<endl;
    cout<< "Conservation status: "<<temp -> status <<endl;
    cout<< "Observation data: "<<temp -> date<<endl;
    cout<< "Observation place: "<<temp -> place<<endl;
    cout<< "Comment: "<<temp -> comment<<endl;

    cout<< "------------------------------------"<<endl;

}

void data_entry(int ident){
    if ( head != NULL ){
        Creature *temp = head;
        while (ident != temp->id){
            temp = temp -> next;
            if( temp == NULL ){
                cout << "No record of given ID." << endl;
                break;
            }
        }
        string garbage;

        if( temp != NULL ){ // Znalezlismy owada o podanym id
            cout<<"Enter common name: "<<endl;
            getline(cin,garbage);
            getline(cin, temp -> namecomm);
            cout<<"Enter latin name: "<<endl;
            getline(cin, temp -> namelat);
            cout<<"Enter genus: "<<endl;
            getline(cin, temp -> genus);
            cout<<"Enter family: "<<endl;
            getline(cin, temp -> familia);
            cout<<"Enter order: "<<endl;
            getline(cin, temp -> ordo);
            cout<<"Enter conservation status: "<<endl;
            getline(cin, temp -> status);
            cout<<"Enter observation date: "<<endl;
            getline(cin, temp -> date);
            cout<<"Enter observation place: "<<endl;
            getline(cin, temp -> place);
            cout<<"Comment: "<<endl;
            getline(cin, temp -> comment);

        }
    }
    else{
        cout << "List empty!" << endl;
    }

}

void save_records(){
    ofstream file;
    file.open("output.txt");

    Creature *temp = head;
    while(temp != NULL){
        file << temp -> id<<endl;
        file << temp -> namecomm<<endl;
        file << temp -> namelat<<endl;
        file << temp -> genus<<endl;
        file << temp -> familia<<endl;
        file << "--------------------------"<<endl;
        temp = temp -> next;
    }
    file.close();
}

void load_records(){
    ifstream file;
    file.open("input.txt");

    if(file.good() == false){
        cout<<"File does not exist!"<<endl;
    }
    else{
    string line;
    int i = 1;

    while(1){

        Creature *temp = new Creature;
        if( head == NULL ){
            head = temp;
            tail = temp;
            temp -> next = NULL;
            temp -> prev = NULL;
        }
        else{
        tail -> next = temp;
        temp -> prev = tail;
        tail = temp;
        temp -> next = NULL;
        }
        temp->id = id;
        id++;
            while (getline(file, line) && line !="#" && line != "$"){
                switch(i){
                    case 1: temp -> namecomm = line; break;
                    case 2: temp -> namelat = line; break;
                    case 3: temp -> genus = line; break;
                    case 4: temp -> familia = line; break;
                    case 5: temp -> ordo = line; break;
                    case 6: temp -> status = line; break;
                    case 7: temp -> date = line; break;
                    case 8: temp -> place = line; break;
                    case 9: temp -> comment = line; break;
                }
                i++;
            }
                if (line == "$"){
                    cout<<"End of record file"<<endl;
                    break;
                }
                else{
                    i = 1;
                    continue;
                }
        }
    }
    file.close();
}

int get_number(string a){
    int i;
    for(i = 0; i < a.length(); i++){
        if (isdigit(a[i]) == false){
            cout<<"Wrong value entered"<<endl;
            return false;
        }
        int x;
        istringstream ( a ) >> x;
        return x;
    }
}
