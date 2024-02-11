#include <QApplication>
#include <QPlainTextEdit>
#include <vector>
#include <iostream>

class Neurona {
private:
    int id;
    int posicion_x;
    int posicion_y;
    int red;
    int green;
    int blue;
    float voltaje;

public:
    Neurona(int _id, int _posicion_x, int _posicion_y, int _red, int _green, int _blue, float _voltaje) :
        id(_id), posicion_x(_posicion_x), posicion_y(_posicion_y),
        red(_red), green(_green), blue(_blue), voltaje(_voltaje) {}

    int getId() const {
        return id;
    }

    int getPosicionX() const {
        return posicion_x;
    }

    int getPosicionY() const {
        return posicion_y;
    }

    int getRed() const {
        return red;
    }

    int getGreen() const {
        return green;
    }

    int getBlue() const {
        return blue;
    }

    float getVoltaje() const {
        return voltaje;
    }

    void print() const {
        std::cout << "Neurona ID: " << id << std::endl;
        std::cout << "Posicion X: " << posicion_x << std::endl;
        std::cout << "Posicion Y: " << posicion_y << std::endl;
        std::cout << "Color (RGB): " << red << ", " << green << ", " << blue << std::endl;
        std::cout << "Voltaje: " << voltaje << std::endl;
    }
};

class NeuronaManager {
private:
    std::vector<Neurona> Neuronas;
    QPlainTextEdit* textEdit;

public:
    NeuronaManager(QPlainTextEdit* _textEdit) : textEdit(_textEdit) {}

    void agregarInicio(const Neurona& neurona) {
        Neuronas.insert(Neuronas.begin(), neurona);
    }

    void agregarFinal(const Neurona& neurona) {
        Neuronas.push_back(neurona);
    }

    void mostrar() const {
        textEdit->clear();
        for (const Neurona& neurona : Neuronas) {
            textEdit->appendPlainText("Neurona ID: " + QString::number(neurona.getId()));
            textEdit->appendPlainText("Posicion X: " + QString::number(neurona.getPosicionX()));
            textEdit->appendPlainText("Posicion Y: " + QString::number(neurona.getPosicionY()));
            textEdit->appendPlainText("Color (RGB): " + QString::number(neurona.getRed()) + ", "
                                      + QString::number(neurona.getGreen()) + ", " + QString::number(neurona.getBlue()));
            textEdit->appendPlainText("Voltaje: " + QString::number(neurona.getVoltaje()));
            textEdit->appendPlainText("----------------------");
        }
    }
};

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    QPlainTextEdit textEdit;
    textEdit.setWindowTitle("Neuronas");
    textEdit.resize(400, 300);
    textEdit.show();

    NeuronaManager manager(&textEdit);
    manager.agregarInicio(Neurona(1, 10, 20, 255, 0, 0, 3.5));
    manager.agregarInicio(Neurona(2, 15, 25, 0, 255, 0, 2.8));
    manager.agregarFinal(Neurona(3, 8, 12, 0, 0, 255, 4.2));
    manager.mostrar();

    return a.exec();
}

