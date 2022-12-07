#include <iostream>
#include "windows.h"
using namespace std;

struct book
{
    string name;
    string author;
    string publisher;
    string genre;
};

void FillLibrary(book library[], const int size);
void PrintLibrary(book library[], const int size);
void ChooseOptions(book library[], const int size);
void EditBook(book library[], int count, int choise);
void SearchByName(book library[], const int size);
void SearchByAuthor(book library[], const int size);
void SortByName(book library[], const int size);
void SortByAuthor(book library[], const int size);
void SortByPublisher(book library[], const int size);

int main()
{
    const int size = 10;
    int choice = 1;

    book library[size];

    FillLibrary(library, size);
    system("cls");

    while (choice != 0)
    {
        cout << "Choose option:\n\n[1] Print library \n[2] Edit book \n[3] Search book by name\
                     \n[4] Search book by author \n[5] Sort books by name \n[6] Sort books by author\
                     \n[7] Sort books by publisher\n[0] Exit\n\n";
        cin >> choice;

        if (choice == 1)
        {
            PrintLibrary(library, size);
        }
        else if (choice == 2)
        {
            ChooseOptions(library, size);
        }
        else if (choice == 3)
        {
            SearchByName(library, size);
        }
        else if (choice == 4)
        {
            SearchByAuthor(library, size);
        }
        else if (choice == 5)
        {
            SortByName(library, size);
        }
        else if (choice == 6)
        {
            SortByAuthor(library, size);
        }
        else if (choice == 7)
        {
            SortByPublisher(library, size);
        }
    }
}

void FillLibrary(book library[], const int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "\nBook " << i + 1 << "\n\n";

        cout << "Enter name of book: ";
        cin >> library[i].name;

        cout << "Enter author of book: ";
        cin >> library[i].author;

        cout << "Enter publisher of book: ";
        cin >> library[i].publisher;

        cout << "Enter genre of book: ";
        cin >> library[i].genre;
    }
}

void PrintLibrary(book library[], const int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << i + 1 << " - Name: " << library[i].name << "\nAuthor: "
            << library[i].author << "\nPublisher: " << library[i].publisher
            << "\nGenre: " << library[i].genre << "\n\n";
    }
}

void ChooseOptions(book library[], const int size)
{
    int number, choise;

    cout << "Choose number of book to edit: ";
    cin >> number;

    if (number >= 1 && number <= 10)
    {
        cout << "Choose what to change: \n[1] name \n[2] author \n[3] publisher \n[4] genre\n";
        cin >> choise;
        EditBook(library, number, choise);
    }
    else
    {
        system("cls");
        ChooseOptions(library, size);
    }
}

void EditBook(book library[], int count, int choise)
{
    switch (choise)
    {
    case 1:
    {
        cout << "Enter new name: ";
        cin >> library[count - 1].name;
        break;
    }
    case 2:
    {
        cout << "Enter new author: ";
        cin >> library[count - 1].author;
        break;
    }
    case 3:
    {
        cout << "Enter new publisher: ";
        cin >> library[count - 1].publisher;
        break;
    }
    case 4:
    {
        cout << "Enter new genre: ";
        cin >> library[count - 1].genre;
        break;
    }
    default:
    {
        break;
    }
    }
}

void SearchByName(book library[], const int size)
{
    string name;

    cout << "Enter name of book:\n";
    cin >> name;

    for (int i = 0; i < size; i++)
    {
        if (name == library[i].name)
        {
            cout << "Name: " << library[i].name << "\nAuthor: " << library[i].author << "\nPublisher: " << library[i].publisher
                << "\nGenre: " << library[i].genre;
            break;
        }
        else if (i == size - 1)
        {
            cout << "Not found!\n";
        }
    }
}

void SearchByAuthor(book library[], const int size)
{
    string author;

    cout << "Enter name of book:\n";
    cin >> author;

    for (int i = 0; i < size; i++)
    {
        if (author == library[i].author)
        {
            cout << "Name: " << library[i].name << "\nAuthor: " << library[i].author << "\nPublisher: " << library[i].publisher
                << "\nGenre: " << library[i].genre;
            break;
        }
        else if (i == size - 1)
        {
            cout << "Not found!\n";
        }
    }
}

void SortByName(book library[], const int size)
{
    book temp;

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j > size - 1 - i; j++)
        {
            if (library[j].name > library[j + 1].name)
            {
                temp = library[j + 1];
                library[j + 1] = library[j];
                library[j] = temp;
            }
        }
    }
}

void SortByAuthor(book library[], const int size)
{
    book temp;

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j > size - 1 - i; j++)
        {
            if (library[j].author > library[j + 1].author)
            {
                temp = library[j + 1];
                library[j + 1] = library[j];
                library[j] = temp;
            }
        }
    }
}

void SortByPublisher(book library[], const int size)
{
    book temp;

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j > size - 1 - i; j++)
        {
            if (library[j].publisher > library[j + 1].publisher)
            {
                temp = library[j + 1];
                library[j + 1] = library[j];
                library[j] = temp;
            }
        }
    }
}
