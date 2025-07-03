#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QFile>
#include <QTextStream> // czyt tekstu z pliku
#include <QMessageBox> // komunikaty dla użytko
#include <QDebug>
#include <queue> // (dla Dijkstry) do pokazania najbliższego miasto (z najmniejszą odległością)
#include <limits> // do nieskończoności (max int)
#include <QGraphicsEllipseItem>
#include <QGraphicsTextItem>
#include <QGraphicsLineItem>

MainWindow::MainWindow(QWidget *parent) // gł okno apk
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this); // nowa scena do rys
    ui->graphicsView->setScene(scene); // przyp sceny do widoku

    loadGraphFromFile("miasta.txt");
    setupScene(); // ustaw współ miast na mapie
    drawGraph();

    // po kliknięciu przycisku "znajdź trasę" wywołaj funkcję
    connect(ui->buttonFindPath, &QPushButton::clicked, this, &MainWindow::on_buttonFindPath_clicked);

    this->setWindowIcon(QIcon("ikona.png")); // ikona apk

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadGraphFromFile(const QString& filename) // dodanie trasy (połączenie między miastami)
{
    QFile file(filename);  // otwórz plik
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Błąd", "Nie można otworzyć pliku: " + filename);
        return;
    }

    QTextStream in(&file);  // czyta linia po linii
    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();  // wczytaj linię bez spacji
        if (line.isEmpty()) continue; // pomiń puste linie

        QStringList parts = line.split(" "); // podziel na 3 części (z czego, dokąd, ile km) - strk pliku
        if (parts.size() != 3) continue; // jak nie ma 3 cz – pomiń

        QString from = parts[0];  // M początkowe
        QString to = parts[1]; // M końcowe
        int distance = parts[2].toInt(); // odl jako liczba

        // droga w obie strony
        graph[from].append(qMakePair(to, distance));
        graph[to].append(qMakePair(from, distance));
    }

    fillCityComboBoxes();
}

void MainWindow::fillCityComboBoxes()
{
    ui->comboBoxStart->clear();  // czyści liste startową
    ui->comboBoxEnd->clear();    // -//- liste końcową

    QStringList cities = graph.keys();  // pobiera wszystkie miasta

    // + każdego miasta do obu list
    for (const QString& city : cities) {
        ui->comboBoxStart->addItem(city);
        ui->comboBoxEnd->addItem(city);
    }
}


QVector<QString> MainWindow::findShortestPath(const QString& start, const QString& end)
{
    QMap<QString, int> dist;  // zapisujemy odl z M startowego
    QMap<QString, QString> prev; // zapisujemy skąd przyszliśmy do danego M
    QSet<QString> visited; // Ms które już odwiedziliśmy

    // ustaw każde M jest "bardzo daleko"=nieskonczonosc
    for (const QString& node : graph.keys()) {
        dist[node] = std::numeric_limits<int>::max();
    }
    dist[start] = 0;  // ale do siebie = 0 km

    using Pair = QPair<int, QString>;
    std::priority_queue<Pair, std::vector<Pair>, std::greater<>> pq;
    pq.push({0, start}); // kolejka do sprawdzania Ms (zaczynamy od M start 0)

    // dopóki mamy coś w kolejce (czyli są jeszcze Ms do sprawdzenia)
    while (!pq.empty()) {
        QString current = pq.top().second;  // weź najbliższe M z kolejki
        pq.pop();                           // usuń je z kolejki

        if (visited.contains(current)) continue; // jeśli już je sprawdzaliśmy – pomiń
        visited.insert(current);                 // zapisz ze sprawdzone

        // sprawdź wszystkie drogi z tego M
        for (const auto& neighbor : graph[current]) {
            QString next = neighbor.first;       // sąsiednie M
            int weight = neighbor.second;        // odl do niego

            if (dist[current] + weight < dist[next]) { //  dla każdego sąsiada M sprawdzamy czy lepiej iść przez to M
                dist[next] = dist[current] + weight; // nowa krótsza odl
                prev[next] = current;                // zapisz skąd przyszedłeś
                pq.push({dist[next], next});         // + to sąsiednie M do kolejki
            }
        }
    }

    // bud sciezka od końca do pocz
    QVector<QString> path;
    QString node = end;

    while (prev.contains(node)) {
        path.prepend(node);   // + M na początek listy
        node = prev[node];    // idź wstecz (skąd tu przyszedłeś)
    }

    if (node == start) {
        path.prepend(start); // na końcu dodaj start, jeśli ścieżka istnieje
    } else {
        path.clear(); // jeśli nie dało się dojść – zwróć pustą
    }

    return path;  // gotowa lista Ms (trasa)
}



void MainWindow::setupScene()
{
    cityPositions.clear();

    for (const QString& city : graph.keys()) {
        if (city == "Szczecin")   cityPositions[city] = QPointF(100, 100);
        else if (city == "Gdansk")     cityPositions[city] = QPointF(450,  50);
        else if (city == "Olsztyn")    cityPositions[city] = QPointF(580, 100);
        else if (city == "Bialystok")  cityPositions[city] = QPointF(700, 130);
        else if (city == "Poznan")     cityPositions[city] = QPointF(250, 200);
        else if (city == "Warszawa")   cityPositions[city] = QPointF(530, 220);
        else if (city == "Lodz")       cityPositions[city] = QPointF(370, 230);
        else if (city == "Lublin")     cityPositions[city] = QPointF(630, 300);
        else if (city == "Wroclaw")    cityPositions[city] = QPointF(260, 330);
        else if (city == "Katowice")   cityPositions[city] = QPointF(370, 370);
        else if (city == "Krakow")     cityPositions[city] = QPointF(470, 380);
        else if (city == "Rzeszow")    cityPositions[city] = QPointF(580, 400);
    }
}

void MainWindow::drawGraph()
{
    scene->clear();

    // styl grafu
    QPen edgePen(QColor(180, 180, 180), 1.5);
    QFont edgeFont("Segoe UI", 9);
    QFont cityFont("Segoe UI", 12, QFont::Bold);
    QSet<QString> drawnEdges;

    // przejdź po wszystkich miastach
    for (const QString& from : graph.keys()) {
        // jeśli M nie ma pozycji na mapie – pomiń
        if (!cityPositions.contains(from)) continue;

        // przejdź po sąsiadach(edge(połączeniach)) tego M
        for (const auto& edge : graph[from]) {
            QString to = edge.first;
            int distance = edge.second;    // odl

            // jeśli sąsiad też nie ma pozycji – pomiń
            if (!cityPositions.contains(to)) continue;

            // żeby nie rysować tego samego 2x
            QString edgeKey = from < to ? from + "-" + to : to + "-" + from;
            if (drawnEdges.contains(edgeKey)) continue;

            drawnEdges.insert(edgeKey);  // zapamiętaj że już narysowane

            QPointF p1 = cityPositions[from];  // współrz M 1
            QPointF p2 = cityPositions[to];    // współrz M 2
            scene->addLine(QLineF(p1, p2), edgePen);  // linia pomiedzy M1 i M2

            // odległość (km) na śr drogi
            QPointF mid = (p1 + p2) / 2 + QPointF(4, -12);
            QGraphicsTextItem* label = scene->addText(QString::number(distance) + " km", edgeFont);
            label->setDefaultTextColor(Qt::darkGray);
            label->setPos(mid);
        }
    }

    // kołka Ms z nazwa
    for (const QString& city : graph.keys()) {
        if (!cityPositions.contains(city)) continue;
        QPointF pos = cityPositions[city];

        // niebieskie kółko
        scene->addEllipse(pos.x() - 5, pos.y() - 5, 10, 10,
                          QPen(Qt::darkBlue), QBrush(QColor("#55AAFF")));

        // napis z nazwą M
        QGraphicsTextItem* label = scene->addText(city, cityFont);
        label->setDefaultTextColor(Qt::black);
        label->setPos(pos + QPointF(10, -18));
    }
}

void MainWindow::drawPath(const QVector<QString>& path) // najkrótsza trasa linia czerwona
{
    QPen pathPen(QColor("#FF3333"), 3, Qt::SolidLine, Qt::RoundCap); // gruba czerwona linia

    for (int i = 0; i < path.size() - 1; ++i) {
        QPointF p1 = cityPositions[path[i]];
        QPointF p2 = cityPositions[path[i + 1]];
        scene->addLine(QLineF(p1, p2), pathPen);
    }
}

void MainWindow::on_buttonFindPath_clicked()
{
    QString start = ui->comboBoxStart->currentText();  // M startowe
    QString end = ui->comboBoxEnd->currentText();      // M końcowe

    if (!graph.contains(start) || !graph.contains(end)) {
        QMessageBox::warning(this, "Błąd!", "Miasto nie istnieje w grafie.");
        return;
    }

    QVector<QString> path = findShortestPath(start, end);
    if (path.isEmpty()) {
        ui->textBrowserPath->setText("Brak dostępnej ścieżki.");
        ui->textBrowserLength->clear();
        return;
    }

    QString result;
    int totalDistance = 0;

    // "M1 -> M2 -> M3" napis
    for (int i = 0; i < path.size(); ++i) {
        result += path[i];
        if (i < path.size() - 1) {
            result += " → ";

            // + odległości
            const auto& neighbors = graph[path[i]];
            for (const auto& neighbor : neighbors) {
                if (neighbor.first == path[i + 1]) {
                    totalDistance += neighbor.second;
                    break;
                }
            }
        }
    }

    // wypisuje trase i długosc
    ui->textBrowserPath->setText(result);
    ui->textBrowserLength->setText(QString::number(totalDistance) + " km");

    drawGraph();
    drawPath(path);
}
