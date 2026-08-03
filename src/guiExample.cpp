/*
Date: 08/03/2026
Title: GUI Example / test file
Author: Cavan Ray Theiss
Email: cavanrt@gmail.com

Description: I'm starting with a bare bones gui written in c++
using the QT library and then messing with that to both learn
more about writing gui programs and eventually come up with 
something that works for my car-catalogue program

*/

#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>

class Window : public QWidget {
public:
    Window() {
        // Create a button
        QPushButton* button = new QPushButton("Click Me!", this);
        
        // Connect the button's clicked signal to a lambda or slot
        connect(button, &QPushButton::clicked, []() {
            // Handle click event
        });

        // Set up layout
        QVBoxLayout* layout = new QVBoxLayout(this);
        layout->addWidget(button);
        
        // Set window properties
        resize(300, 200);
        show();
    }
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    Window window;
    return app.exec();
}
