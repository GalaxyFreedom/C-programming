#include <iostream>
#include <queue>

using namespace std;

class Image {
private:
    string m_camType;
    int m_fps;
public:
    Image(const string& camType, int fps) : m_camType(camType), m_fps(fps) {}
    void describe() const {
        cout << "Image Camera Type: " << m_camType;
        cout << " Fps: " << m_fps << endl;
    }
};

class CameraProcess {
private:
    queue<Image> m_images;
    int m_capacity;
public:
    CameraProcess(int capacity) : m_capacity(capacity) {}
    void addImage(Image image) {
        if (!(m_images.size() <= m_capacity)) {
            cout << "Queue is full!" << endl;
        }
        else {
            m_images.push(image);
        }
    }

    Image getImage() {
        Image image = m_images.front();
        m_images.pop();
        return image;
    }

    void describe() {
        queue<Image> copyImages(m_images);
        while ( !copyImages.empty() ) {
            Image image = copyImages.front();
            image.describe();

            copyImages.pop();
        }
    }
};

int main() {
    Image image1("Canon", 60);
    Image image2("Nikon", 30);
    Image image3("Sony", 120);
    int capacity = 10;
    CameraProcess numOfImages(capacity);

    numOfImages.addImage(image1);
    numOfImages.addImage(image2);
    numOfImages.addImage(image3);

    numOfImages.describe();
}