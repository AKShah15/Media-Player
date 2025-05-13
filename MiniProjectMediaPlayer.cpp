#include <iostream>
#include <vector>
#include <memory>
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")
using namespace std;

// Base class
class MediaFile {
protected:
    string title;
    float duration;
    string filePath; // Added to store the actual media file path
public:
    MediaFile(string t, float d, string path) : title(t), duration(d), filePath(path) {}
    virtual void play() = 0;
    virtual void pause() = 0;
    virtual void stop() = 0;
    virtual void displayInfo() = 0;
    virtual ~MediaFile() {}
};

// Audio file
class AudioFile : public MediaFile {
    string artist;
    bool isPlaying;
public:
    AudioFile(string t, float d, string a, string path) : MediaFile(t, d, path), artist(a), isPlaying(false) {}
    void play() override {
        cout << "Playing audio: " << title << " by " << artist << endl;
        if (!filePath.empty()) {
            // Convert string to wstring for PlaySoundW
            wstring wpath(filePath.begin(), filePath.end());
            PlaySoundW(wpath.c_str(), NULL, SND_FILENAME | SND_ASYNC);
            isPlaying = true;
        } else {
            cout << "Error: No audio file path specified!" << endl;
        }
    }
    void pause() override {
        if (isPlaying) {
            PlaySound(NULL, NULL, 0); // Stop the current sound
            cout << "Audio paused: " << title << endl;
            isPlaying = false;
        }
    }
    void stop() override {
        if (isPlaying) {
            PlaySound(NULL, NULL, 0); // Stop the current sound
            cout << "Audio stopped: " << title << endl;
            isPlaying = false;
        }
    }
    void displayInfo() override {
        cout << "Audio - Title: " << title << ", Artist: " << artist << ", Duration: " << duration << " mins" << endl;
    }
};

// Video file
class VideoFile : public MediaFile {
    string resolution;
public:
    VideoFile(string t, float d, string res) : MediaFile(t, d, ""), resolution(res) {}
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

    // Note: Replace these paths with actual .wav files on your system
    player.addMedia(make_shared<AudioFile>("Believer", 3.5, "Imagine Dragons", "C:\\Users\\AYUSH\\Downloads\\Believer.wav"));
    player.addMedia(make_shared<VideoFile>("Nature Documentary", 10.0, "1080p"));
    player.addMedia(make_shared<AudioFile>("Ding", 1.0, "Windows", "C:\\Windows\\Media\\ding.wav"));

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
