#include <iostream>
#include <locale> // Language library
#include <windows.h>
using namespace std;
struct Node
{
    string nameMusicalMaqam;
    int duration;
    string musicName;
    Node *next;
    Node *prev;
};
Node *head = NULL;
Node *Last = NULL;
Node *current = NULL;
void insertNode(int dur, string nameMaqam, string nameMusic)
{
    Node *newNode = new Node;
    newNode->duration = dur;
    newNode->nameMusicalMaqam = nameMaqam;
    newNode->musicName = nameMusic;
    newNode->next = NULL;
    if (head == NULL)
    {
        head = newNode;
        Last = head;
        newNode->next = NULL;
        newNode->prev = NULL;
    }
    else
    {
        newNode->prev = Last;
        Last->next = newNode;
        Last = newNode;
    }
}
void display()
{
    Node *Ptr = head;
    if (Ptr == NULL)
    {
        cout << "List is empty" << endl;
    }
    else
    {
        while (Ptr != NULL)
        {
            cout << "Maqam: " << Ptr->nameMusicalMaqam << endl;
            cout << "Duration: " << Ptr->duration << " seconds" << endl;
            cout << "Music: " << Ptr->musicName << endl;
            cout << "-------------------------" << endl;
            Ptr = Ptr->next;
        }
    };
}
void playNext()
{
    if (head == NULL)
    {
        cout << "Playlist is empty" << endl;
        return;
    }

    // Is there a track ahead of us?
    if (current->next != NULL)
    {
        current = current->next;
        cout << "Moved to the next track: " << current->nameMusicalMaqam << endl;
    }
    else
    {
        cout << "You are at the last track!" << endl;
    }
}

void playPrevious()
{
    if (head == NULL)
    {
        cout << "Playlist is empty" << endl;
        return;
    }

    // Is there a track behind us?
    if (current->prev != NULL)
    {
        current = current->prev;
        cout << "Moved back to the previous track: " << current->nameMusicalMaqam << endl;
    }
    else
    {
        cout << "You are at the first track, cannot go back!" << endl;
    }
}
void loobMode()
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    else
    {
        Last->next = head;
    }
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    insertNode(120, "Rast", "Introductory Taqasim");
    insertNode(180, "Nahawand", "Longa Farahfaza");
    insertNode(240, "Bayati", "Sama'i Ibrahim Al-Aryan");

    // 1. Start the player (place the needle on the first track)
    current = head;

    cout << "--- Current List ---" << endl;
    display();

    cout << "\n--- Player Test ---" << endl;
    cout << "Current track: " << current->nameMusicalMaqam << endl;

    playNext(); // Will move to Nahawand
    playNext(); // Will move to Bayati
    playNext(); // Will tell you: You are at the last track

    playPrevious(); // Will move back to Nahawand
    playPrevious(); // Will move back to Rast

    return 0;
}