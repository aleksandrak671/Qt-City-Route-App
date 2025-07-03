#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow> // gł okno apk
#include <QMap>
#include <QVector> // lista miast z algo
#include <QString>
#include <QSet> // zbiór bez potórzeń (miasta, które już odwiedziłeś w Dijkstrze)
#include <QPair>
#include <QGraphicsScene>
#include <QPointF> // punkt na płaszczyźnie (x, y)

// przyciski, pola itp z pliku ui
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

// gł klasa okna apk
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    // konstruktor do tworzenia okna
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

private slots:
    void on_buttonFindPath_clicked();

private:
    Ui::MainWindow *ui;

    // graf miast (miasto, odległosc w km)
    QMap<QString, QVector<QPair<QString, int>>> graph;

    QMap<QString, QPointF> cityPositions;

    QGraphicsScene* scene; // gł scena do rysowania mapy

    void loadGraphFromFile(const QString& filename);

    void fillCityComboBoxes();

    QVector<QString> findShortestPath(const QString& start, const QString& end);

    void setupScene();

    void drawGraph();

    void drawPath(const QVector<QString>& path);

};

#endif // MAINWINDOW_H
