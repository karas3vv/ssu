#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Song {
public:
    string title;
    string artist;

    Song(string t, string a) : title(t), artist(a) {}
};

class CompactDisc {
public:
    string title;
    string artist;
    vector<Song> songs;

    CompactDisc(string t, string a) : title(t), artist(a) {}

    // ���������� ����� �� ����
    void addSong(Song song) {
        songs.push_back(song);
    }

    // �������� ����� � �����
    void removeSong(Song song) {
        for (auto it = songs.begin(); it != songs.end(); ++it) {
            if (it->title == song.title && it->artist == song.artist) {
                songs.erase(it);
                break;
            }
        }
    }
};

class MusicCatalog {
public:
    vector<CompactDisc> discs;

    // ���������� ����� � �������
    void addDisc(CompactDisc disc) {
        discs.push_back(disc);
    }

    // �������� ����� �� ��������
    void removeDisc(CompactDisc disc) {
        for (auto it = discs.begin(); it != discs.end(); ++it) {
            if (it->title == disc.title && it->artist == disc.artist) {
                discs.erase(it);
                break;
            }
        }
    }

    // ����� ����� ����������� �������� �� �����
    void displayCatalog() {
        cout << "Catalog:" << endl;
        for (const auto& disc : discs) {
            cout << "Title: " << disc.title << ", Artist: " << disc.artist << endl;
            cout << "Songs:" << endl;
            for (const auto& song : disc.songs) {
                cout << "  - " << song.title << " by " << song.artist << endl;
            }
        }
    }

    // ����� ����� �������� ����������� � ��������
    void searchArtist(const string& artist) {
        cout << "Search results for artist '" << artist << "':" << endl;
        for (const auto& disc : discs) {
            for (const auto& song : disc.songs) {
                if (song.artist == artist) {
                    cout << "  - " << song.title << " on " << disc.title << endl;
                }
            }
        }
    }
};

int main() {
    MusicCatalog catalog;

    // �������� � ���������� ������
    CompactDisc disc1("Album 1", "Artist 1");
    disc1.addSong(Song("Song 1", "Artist 1"));
    disc1.addSong(Song("Song 2", "Artist 2"));
    catalog.addDisc(disc1);

    CompactDisc disc2("Album 2", "Artist 2");
    disc2.addSong(Song("Song 3", "Artist 2"));
    disc2.addSong(Song("Song 4", "Artist 1"));
    catalog.addDisc(disc2);

    // ����� ����� ��������
    catalog.displayCatalog();

    cout << endl;

    // ����� ����� ��������� �����������
    catalog.searchArtist("Artist 1");

    return 0;
}