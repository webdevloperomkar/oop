#include <iostream>
#include <string>
using namespace std;

class Music {
    int id;
    float duration;
    string song_title, artist_name, genre;

public:
    // Default constructor
    Music() {
        id = 0;
        duration = 0.0;
        song_title = "";
        artist_name = "";
        genre = "";
    }

    // Parameterized constructor
    Music(int song_id, float dur, string title, string artist,
          string album, string genr) {
        id = song_id;
        duration = dur;
        song_title = title;
        artist_name = artist;
        genre = genr;

        cout << "Parameterized constructor called" << endl;
    }

    // Copy constructor
    Music(const Music &x) {
        id = x.id;
        artist_name = x.artist_name;
        song_title = x.song_title;
        genre = x.genre;
        duration = x.duration;

        cout << "Copy constructor called" << endl;
    }

    void input() {
        cout << "Enter the name of song: ";
        cin.ignore();
        getline(cin, song_title);

        cout << "Enter the name of artist: ";
        getline(cin, artist_name);

        cout << "Enter the Genre of song: ";
        getline(cin, genre);

        cout << "Enter the song ID: ";
        cin >> id;

        cout << "Enter the duration of song: ";
        cin >> duration;
    }

    void display() {
        cout << "\nThe Song: " << song_title << endl;
        cout << "The artist name: " << artist_name << endl;
        cout << "The genre: " << genre << endl;
        cout << "The id: " << id << endl;
        cout << "The Duration: " << duration << endl;
    }
};

int main() {
    Music song1;
    song1.input();
    song1.display();

    Music song2(102, 4.24, "Shape of You",
                "Ed Sheeran", "Pop", "Popular");
    song2.display();

    Music song3(song2);
    song3.display();

    return 0;
}