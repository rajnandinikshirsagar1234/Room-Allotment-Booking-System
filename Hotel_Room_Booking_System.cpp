#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

class Reservation
{
public:
    string room_number, host, start, send, from, to;
    string chair[10][4];

    void booking();
    void allotment();
    void empty();
    void display();
    void avail();
    void position(int t);
};
int q = 0;
Reservation hotel[10];

void design(string todraw)
{
    for (int i = 0; i < 100; i++)
        cout << todraw;
}

void Reservation::booking()
{
    cout << "Please enter room number : ";
    cin >> room_number;

    cout << "Please enter Customer's name : ";
    cin >> host;

    cout << "Enter start time : ";
    cin >> start;

    cout << "Enter Session end time : ";
    cin >> send;

    cout << "From : ";
    cin >> from;

    cout << "To : ";
    cin >> to;

    empty();

    ofstream file("rooms.txt", ios::app);

    if (file.is_open())
    {
        file << room_number << " "
             << host << " "
             << start << " "
             << send << " "
             << from << " "
             << to << endl;

        file.close();
    }
    else
    {
        cout << "Error opening file!\n";
    }
}

void Reservation::allotment()
{
    string num;
    cout << "Enter Room Number: ";
    cin >> num;

    int n;
    for (n = 0; n < q; n++)
    {
        if (hotel[n].room_number == num)
            break;
    }

    if (n == q)
    {
        cout << "Room Not Found\n";
        return;
    }

    int chairNo;
    cout << "Enter Chair Number (1-40): ";
    cin >> chairNo;

    if (chairNo < 1 || chairNo > 40)
    {
        cout << "Invalid chair number\n";
        return;
    }

    int row = (chairNo - 1) / 4;
    int col = (chairNo - 1) % 4;

    if (hotel[n].chair[row][col] == "Empty")
    {
        cout << "Enter Customer Name: ";
        cin >> hotel[n].chair[row][col];
        cout << "Chair Booked Successfully!\n";
    }
    else
    {
        cout << "Chair already booked\n";
    }
}

void Reservation::empty()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            chair[i][j] = "Empty";
        }
    }
}
void Reservation::display()
{
    int a;
    string num;
    cout << "Enter room no : ";
    cin >> num;

    for (a = 0; a < q; a++)
    {
        if (hotel[a].room_number == num)
            break;
    }

    if (a < q)
    {
        design("#");
        cout << "\nRoom number \t" << hotel[a].room_number
             << "\nHost: \t" << hotel[a].host
             << "\nStart time: \t" << hotel[a].start
             << "\nEnd time: \t" << hotel[a].send
             << "\nFrom: \t\t" << hotel[a].from
             << "\nTo: \t\t" << hotel[a].to << "\n";
        design("#");

        position(a);
    }
    else
    {
        cout << "Room not found!\n";
    }
}

void Reservation::position(int l)
{
    int s = 0;
    int emptyCount = 0;

    for (int i = 0; i < 10; i++)
    {
        cout << endl;
        for (int j = 0; j < 4; j++)
        {
            s++;
            cout.width(5);
            cout << s << ". ";
            cout.width(10);
            cout << hotel[l].chair[i][j];

            if (hotel[l].chair[i][j] == "Empty")
                emptyCount++;
        }
    }

    cout << "\n\nTotal Empty Chairs: " << emptyCount << endl;
}

void Reservation::avail()
{
    for (int n = 0; n < q; n++)
    {
        design("#");
        cout << "Room no: \t" << hotel[n].room_number << "\nHost: \t" << hotel[n].host << "\t\tStart time: \t" << hotel[n].start << "\tEnd  Time: \t"
             << hotel[n].send << "\nFrom: \t\t" << hotel[n].from << "\t\tTo: \t\t\t"
             << hotel[n].to << "\n";
        design("#");
        design("_");
    }
}

void searchRoom()
{
    string num;
    cout << "Enter Room Number: ";
    cin >> num;

    for (int n = 0; n < q; n++)
    {
        if (hotel[n].room_number == num)
        {
            cout << "Room Found\n";
            return;
        }
    }

    cout << "Room Not Found\n";
}

int main()
{

    int w;

    while (true)
    {

        cout << "\n\n\n\n\n";
        design("#");
        cout << "\n\n";
        cout << "\t\t\t\t\t\t\t\t\t Hotel Room Booking System";
        cout << "\n\n\n\t\t\t\t\t\t1.Booking\n\t\t\t\t\t\t"
             << "2.Reservation\n\t\t\t\t\t\t"
             << "3.Show\n\t\t\t\t\t\t"
             << "4.Rooms Available. \n\t\t\t\t\t\t"
             << "5.Exit";

        cout << "\n\t\t\t\t\t\tEnter your choice:-> ";
        cin >> w;

        switch (w)
        {

        case 1:
            if (q >= 10)
            {
                cout << "Maximum rooms reached!\n";
                break;
            }
            hotel[q].booking();
            q++; // increase here
            break;

        case 2:
            if (q == 0)
            {
                cout << "No rooms booked yet!\n";
            }
            else
            {
                hotel[0].allotment();
            }
            break;

        case 3:
            if (q == 0)
            {
                cout << "No rooms booked yet!\n";
            }
            else
            {
                hotel[0].display();
            }
            break;

        case 4:
            if (q == 0)
            {
                cout << "No rooms booked yet!\n";
            }
            else
            {
                hotel[0].avail();
            }
            break;

        case 5:
            exit(0);
        }
    }
    return 0;
}
