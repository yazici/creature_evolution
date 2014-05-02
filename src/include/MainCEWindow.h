#ifndef MAINCEWINDOW_H
#define MAINCEWINDOW_H

#include <QtWidgets/QApplication>

#include <QtWidgets/QWidget>
#include <QFutureWatcher>
#include <CreatureEvolution.h>
#include <QtConcurrent/QtConcurrent>

#include <QtWidgets/QGroupBox>
#include <CreatureEvolution.h>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QLabel>
#include <QtDebug>
#include <QtGui>
#include "Transwindow.h"
#include "SliderWidget.h"

QT_BEGIN_NAMESPACE
class QSlider;
QT_END_NAMESPACE

class GLWidget;

class MainCEWindow : public QWidget
{
    Q_OBJECT

public:
    MainCEWindow(CreatureEvolution* ce);

signals:
    void valueChanged(int value);

public slots:
    void testPrint();
    void startEvolution();
    void loadCreature();
    void renderWorm();

    void evoDone();

    void setValueMut(int value);
    static void setValueGen(int value);
    void setValuePop(int value);
    void setValueCO(int value);
    void setValueElit(int value);
    void setBodyDimension(int value);

    void changePressed();
    void changeReleased();

protected:
    void keyPressEvent(QKeyEvent *event);

private:
    //QVBoxLayout *createSliderLayout(QSlider *slider, int range, int step, int page, int tick, std::string label, void (*function)(int));

    QSlider *slide_gen;
    QSlider *slide_pop;
    QSlider *slide_CO;
    QSlider *slide_elit;
    QSlider *slide_mut;
    QSlider *slide_change_dim;

    QFutureWatcher<void> evolution_thread_starter_;

    QBoxLayout *box_gen;
    QBoxLayout *box_pop;
    QBoxLayout *box_CO;
    QBoxLayout *box_elit;
    QBoxLayout *box_mut;
    QBoxLayout *box_change_dim;

    GLWidget *glWidget;
    CreatureEvolution* creature_evo_;

    QPoint _mousePosition;

    static const int normalize = 100;
    static const int number_of_sliders = 6;
    bool _mousePressed;
};

#endif // MAINCEWINDOW_H
