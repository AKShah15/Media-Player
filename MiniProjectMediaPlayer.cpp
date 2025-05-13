#include <iostream>
#include <vector>
#include <memory>
using namespace std;

// Base class
class MediaFile {
protected:
    string title;
    float duration;
public:
    MediaFile(string t, float d) : title(t), duration(d) {}
    virtual void play() = 0;
    virtual void pause() = 0;
    virtual void stop() = 0;
    virtual void displayInfo() = 0;
    virtual ~MediaFile() {}
};

// Audio file
class AudioFile : public MediaFile {
    string artist;
public:
    AudioFile(string t, float d, string a) : MediaFile(t, d), artist(a) {}
    void play() override {
        cout << "Playing audio: " << title << " by " << artist << endl;
    }
    void pause() override {
        cout << "Audio paused: " << title << endl;
    }
    void stop() override {
        cout << "Audio stopped: " << title << endl;
    }
    void displayInfo() override {
        cout << "Audio - Title: " << title << ", Artist: " << artist << ", Duration: " << duration << " mins" << endl;
    }
};

// Video file
class VideoFile : public MediaFile {
    string resolution;
public:
    VideoFile(string t, float d, string res) : MediaFile(t, d), resolution(res) {}
    void play() override {
        cout << "Playing video: " << title << " [" << resolution << "]" << endl;
    }
    void pause() override {
        cout << "Video paused: " << title << endl;
    }
    void stop() override {
        cout << "Video stopped: " << title << endl;
    }
    void displayInfo() override {
        cout << "Video - Title: " << title << ", Resolution: " << resolution << ", Duration: " << duration << " mins" << endl;
    }
};

// Media Player
class MediaPlayer {
    vector<shared_ptr<MediaFile>> playlist;
public:
    void addMedia(shared_ptr<MediaFile> media) {
        playlist.push_back(media);
    }

    void showPlaylist() {
        cout << "\n--- Playlist ---\n";
        for (size_t i = 0; i < playlist.size(); i++) {
            cout << "[" << i + 1 << "] ";
            playlist[i]->displayInfo();
        }
    }

    void playMedia(int index) {
        if (index < 1 || index > playlist.size()) {
            cout << "Invalid index!" << endl;
            return;
        }
        playlist[index - 1]->play();
    }

    void pauseMedia(int index) {
        if (index < 1 || index > playlist.size()) {
            cout << "Invalid index!" << endl;
            return;
        }
        playlist[index - 1]->pause();
    }

    void stopMedia(int index) {
        if (index < 1 || index > playlist.size()) {
            cout << "Invalid index!" << endl;
            return;
        }
        playlist[index - 1]->stop();
    }
};

// Main
int main() {
    MediaPlayer player;

    player.addMedia(make_shared<AudioFile>("Believer", 3.5, "Imagine Dragons"));
    player.addMedia(make_shared<VideoFile>("Nature Documentary", 10.0, "1080p"));
    player.addMedia(make_shared<AudioFile>("Lose Yourself", 5.0, "Eminem"));

    player.showPlaylist();

    int choice;
    do {
        cout << "\n1. Play Media\n2. Pause Media\n3. Stop Media\n4. Show Playlist\n0. Exit\nEnter choice: ";
        cin >> choice;
        if (choice >= 1 && choice <= 3) {
            int index;
            cout << "Enter media number: ";
            cin >> index;
            if (choice == 1) player.playMedia(index);
            else if (choice == 2) player.pauseMedia(index);
            else if (choice == 3) player.stopMedia(index);
        } else if (choice == 4) {
            player.showPlaylist();
        }
    } while (choice != 0);

    return 0;
}
