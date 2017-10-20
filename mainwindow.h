#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGroupBox>
#include <QListWidget>
#include <QListWidgetItem>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QGroupBox *Mode;
    QGroupBox *NodeListViewer;
    QGroupBox *Previewer;

public slots:
    void highlightChecked(QListWidgetItem *item);
private:
    Ui::MainWindow *ui;

    QListWidget *mode_widget;
    QListWidget *widget;

    QGroupBox *createMode();
    QGroupBox *createNodeListViewer();
    QGroupBox *createPreviewer();
    void createListWidget();
};

#endif // MAINWINDOW_H
